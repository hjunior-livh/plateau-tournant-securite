import { ChartDisplay } from "./classes/ChartDisplay.js";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors.js";
import { StreamMessage } from "./types/CommunicationTypes.js";
import { EventDataEntry } from "./types/DatabaseTypes.js";


let chartList: ChartDisplay[] = [];

for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = new ChartDisplay(newChartDescriptor);
    newChart.fetchData();
    chartList.push(newChart);
}

const eventStream: EventSource = new EventSource("api/stream/");

eventStream.addEventListener("new_data", (event) => {
    const newMessage: StreamMessage = JSON.parse(event.data) as StreamMessage;
    for (let chart of chartList.filter((chart: ChartDisplay) => chart.dataTable === newMessage.table)) {
        chart.updateData(newMessage.entry as EventDataEntry);
    }
});