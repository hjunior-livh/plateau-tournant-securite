import Chart from "chart.js/auto"

var engineCurrent;

const xhr = new XMLHttpRequest();
xhr.open("GET", "/data/courant_moteur/10");
xhr.send();
xhr.onload = function () {
  if (xhr.readyState === xhr.DONE) {
    if (xhr.status === 200) {
      engineCurrent = JSON.parse(xhr.responseText);
      engineCurrent.sort((a, b) => (a.id - b.id));
      console.log(engineCurrent);
    }
  }
};



async function displayCurrent() {
  new Chart(
    document.getElementById("engineCurrentGraph"),
    {
      type: "line",
      data: {
        labels: engineCurrent.map(row => `${row.horodatage.split(' ')[1]} (${row.id})`),
        datasets: [
          {
            label: "Courant du moteur relevé par le capteur",
            data: engineCurrent.map(row => row.valeur)
          }
        ]
      }
    }
  );
};

setTimeout(displayCurrent, 5000);

