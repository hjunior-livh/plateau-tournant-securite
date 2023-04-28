import { ChartDisplay } from "./classes/ChartDisplay";
import { CHART_DESCRIPTORS } from "./classes/ChartDescriptors";
import { ChartFactory } from './classes/ChartFactory';


let chartList: ChartDisplay[] = [];

async function main() {
    const chartFactory:ChartFactory = new ChartFactory();
    for (const newChartDescriptor of CHART_DESCRIPTORS) {
        const newChart = chartFactory.produceChart(newChartDescriptor);
        await newChart.updateData();
        newChart.render();
        chartList.push(newChart);
    }

    const eventStream = new EventSource("api/stream/");

    eventStream.addEventListener("new_data", (event) => {
        console.log(event);
        console.log(event.data);
    })
}

main();