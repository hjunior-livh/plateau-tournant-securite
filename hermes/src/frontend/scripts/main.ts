import { ChartDisplay } from "./classes/ChartDisplay";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors";
import { ChartFactory } from './classes/ChartFactory';
import { StreamMessage } from "./types/ChartDataTypes";


let chartList: ChartDisplay[] = [];
const chartFactory: ChartFactory = new ChartFactory();


for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = chartFactory.produceChart(newChartDescriptor);
    newChart.fetchData();
    chartList.push(newChart);
}

const eventStream = new EventSource("api/stream/");

eventStream.addEventListener("new_data", (event) => {
    const newMessage: StreamMessage = JSON.parse(event.data) as StreamMessage;
    for (let chart of chartList.filter((chart) => chart.dataTable === newMessage.table)) {
        chart.updateData(newMessage.entry);
    }
});
