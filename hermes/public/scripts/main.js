"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const ChartDisplay_1 = require("./classes/ChartDisplay");
const ChartDescriptors_1 = require("./classes/ChartDescriptors");
let chartList = [];
for (const newChartDescriptor of ChartDescriptors_1.CHART_DESCRIPTORS) {
    const newChart = new ChartDisplay_1.ChartDisplay(newChartDescriptor);
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
