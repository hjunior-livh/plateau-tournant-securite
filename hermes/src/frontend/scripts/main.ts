import { ChartDisplay } from "./ChartDisplay";


const currentRoutine = new ChartDisplay("engineCurrentGraph");
// currentRoutine.render();

// const eventStream = new EventSource("/stream");

// eventStream.addEventListener("test", (event) => {
//     console.log(event);
//     console.log(event.data);
// })

const xhr = new XMLHttpRequest();
xhr.open("GET", "/data/courant_moteur/10");
xhr.send();