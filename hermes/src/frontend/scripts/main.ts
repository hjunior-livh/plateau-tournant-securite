import { ChartDisplay } from "./classes/ChartDisplay.js";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors.js";
import type { StreamMessage } from "./types/CommunicationTypes.js";
import type { EventDataEntry } from "./types/DatabaseTypes.js";


const rotationSelection = document.getElementById("rotationSelection") as HTMLSelectElement;
let chartList: ChartDisplay[] = [];
const eventStream: EventSource = new EventSource("api/stream/");
const xhr: XMLHttpRequest = new XMLHttpRequest();


// Rotation selection
xhr.open("GET", "/api/get-rotation-files/", true);
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        const filenames = JSON.parse(xhr.responseText);

        filenames.forEach((filename: string) => {
            const optionElement = document.createElement("option");
            optionElement.textContent = filename;
            rotationSelection.appendChild(optionElement);
        });
    }
};
xhr.send();

rotationSelection.addEventListener("change", function () {
    const selectedOption = rotationSelection.options[rotationSelection.selectedIndex];
    const selectedValue = selectedOption.value;

    xhr.open("GET", `/api/get-rotation-file/${selectedValue}`, true);
    xhr.send();
});


// Charts
for (const newChartDescriptor of CHART_DESCRIPTORS) {
    const newChart = new ChartDisplay(newChartDescriptor);
    newChart.fetchData();
    chartList.push(newChart);
}

eventStream.addEventListener("new_data", (event) => {
    const newMessage: StreamMessage = JSON.parse(event.data) as StreamMessage;
    for (let chart of chartList) {
        if (chart.dataType === "sql") {
            if (chart.dataTable === newMessage.table) {
                chart.updateData(newMessage.entry as EventDataEntry);
            }
        }
    }
});