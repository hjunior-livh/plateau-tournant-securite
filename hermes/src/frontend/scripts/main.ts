import { ChartDisplay } from "./classes/ChartDisplay";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors";
import { ChartFactory } from './classes/ChartFactory';


let chartList: ChartDisplay[] = [];
const chartFactory: ChartFactory = new ChartFactory();


for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = chartFactory.produceChart(newChartDescriptor);
    newChart.fetchData();
    chartList.push(newChart);
}

const eventStream = new EventSource("api/stream/");

eventStream.addEventListener("new_data", (event) => {
    for (let chart of chartList.filter((chart) => chart.dataTable === event.data.table)) {
        chart.updateData(event.data);
    }
});
