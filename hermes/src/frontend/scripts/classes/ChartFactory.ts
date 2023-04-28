import { ChartDisplay } from './ChartDisplay';
import { ChartDescriptor } from './ChartDescriptors';
import { engineCurrentRender } from './components/engineCurrentRender';


export class ChartFactory {
    produceChart(chartDescriptor: ChartDescriptor): ChartDisplay {
        let renderFunction: Function;
        switch (chartDescriptor.chartId) {
            case "engine-current":
                renderFunction = engineCurrentRender;
                break;
            // case "...":
            //     module = ...
            //      break;
            default:
                throw new Error(`Invalid chartId "${chartDescriptor.chartId}": render not found`);
        }
         
    return new ChartDisplay(chartDescriptor, renderFunction);
    }
}