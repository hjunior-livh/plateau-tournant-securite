import { ChartDisplay } from "./classes/ChartDisplay";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors";
let chartList = [];
for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = new ChartDisplay(newChartDescriptor);
    newChart.fetchData();
    chartList.push(newChart);
}
const eventStream = new EventSource("api/stream/");
eventStream.addEventListener("new_data", (event) => {
    const newMessage = JSON.parse(event.data);
    for (let chart of chartList.filter((chart) => chart.dataTable === newMessage.table)) {
        chart.updateData(newMessage.entry);
    }
});
