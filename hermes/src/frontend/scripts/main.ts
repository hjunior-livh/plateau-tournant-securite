import { ChartDisplay } from "./ChartDisplay";
import { ChartDescriptor, chartDescriptors } from "./ChartDescriptors";
import { getRenderMethod } from "./chartRenderGenerator";


let chartList: ChartDisplay[] = [];

for (let i = 0; i < chartDescriptors.length; i++) {
    const newChartDescriptor: ChartDescriptor = chartDescriptors[i];
    const newChart = new ChartDisplay(
        newChartDescriptor.HTMLElementId,
        newChartDescriptor.dataTable,
        newChartDescriptor.defaultDataQuantity
    )
    newChart.setRenderMethod(getRenderMethod(newChartDescriptor.chartId));
    newChart.updateData();
    chartList.push(newChart);
}

const eventStream = new EventSource("/stream/");

eventStream.addEventListener("new_data", (event) => {
    console.log(event);
    console.log(event.data);

})