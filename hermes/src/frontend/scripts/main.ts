import { ChartFactory } from "./classes/ChartFactory.js";
import { CHART_DESCRIPTORS } from "./types/ChartDescriptors.js";
import { SQLChart } from "./classes/SQLChart.js";
import type { StreamMessage } from "./types/CommunicationTypes.js";
import type { SQLEventDataEntry } from "./types/SQLDatabaseTypes.js";
import type { Chart } from "./types/Chart.js";
import { CSVChart } from "./classes/CSVChart.js";


const rotationSelection = document.getElementById("rotationSelection") as HTMLSelectElement;
let chartList: {[key: string]: Chart} = {};
let chartFactory = new ChartFactory()
const eventStream: EventSource = new EventSource("api/stream/");
const xhr: XMLHttpRequest = new XMLHttpRequest();


// Rotation selection
xhr.open("GET", "/api/get-rotation-files/", true);
xhr.onreadystatechange = function () {
    if (xhr.readyState === xhr.DONE && xhr.status === 200) {
        const filenames = JSON.parse(xhr.responseText);

        filenames.forEach((filename: string) => {
            const optionElement = document.createElement("option");
            optionElement.textContent = filename;
            rotationSelection.appendChild(optionElement);
        });
    }
};
xhr.send();

rotationSelection.addEventListener("change", function() {
    const selectedOption = rotationSelection.options[rotationSelection.selectedIndex];
    const selectedValue = selectedOption.text;
    (chartList["engine-current"] as CSVChart).updateData(selectedValue);
});


// Charts
for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = chartFactory.produceChart(newChartDescriptor);
    chartList[newChartDescriptor.chartId] = newChart;
}

eventStream.addEventListener("new_data", (event) => {
    const newMessage: StreamMessage = JSON.parse(event.data) as StreamMessage;
    for (let chart of Object.values(chartList)) {
        if (chart instanceof SQLChart) {
            if (chart.dataTable === newMessage.table) {
                chart.updateData(newMessage.entry as SQLEventDataEntry);
            }
        }
    }
});