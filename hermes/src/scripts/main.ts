import { ChartDisplay } from "./ChartDisplay";


const currentRoutine = new ChartDisplay("engineCurrentGraph");


// currentRoutine.render();

const eventStream = new EventSource("/stream");

eventStream.addEventListener("new_data", (event) => {
    console.log(event.data);
})