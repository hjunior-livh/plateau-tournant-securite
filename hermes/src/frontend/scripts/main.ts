import { ChartDisplay } from "./ChartDisplay";


const currentRoutine = new ChartDisplay("engineCurrentGraph", "courant_moteur", 10);
currentRoutine.updateData();
currentRoutine.render();

const eventStream = new EventSource("/stream/");

// eventStream.addEventListener("test", (event) => {
//     console.log(event);
//     console.log(event.data);
// })