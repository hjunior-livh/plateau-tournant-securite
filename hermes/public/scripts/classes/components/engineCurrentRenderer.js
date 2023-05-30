import { Chart } from "chart.js/auto";
let engineCurrentRenderer;
engineCurrentRenderer = function () {
    if (this.chart === undefined) {
        this.chart = new Chart(this.ctx, {
            type: "line",
            options: {
                scales: {
                    x: {
                        ticks: {
                            autoSkip: false,
                            maxRotation: 90,
                            minRotation: 90,
                            callback: function (value, index) {
                                // Hide every 100th tick label
                                return index % 100 === 0 ? this.getLabelForValue(value) : "";
                                //return index % 2 === 0 && typeof value === 'number' ? this.getLabelForValue(value) : '';
                                // return new Date(this.getLabelForValue(Math.floor((value as number) / 1000))) !== new Date(this.getLabelForValue(Math.floor(((value as number) -1) / 1000))) ? this.get ;
                            }
                        }
                    }
                },
                plugins: {
                    title: {
                        display: true,
                        text: "Courant moteur"
                    }
                },
                elements: {
                    point: {
                        radius: 1
                    }
                }
            },
            data: {
                labels: this.data.map((row) => new Date(Math.floor(row.epoch)).toLocaleString('fr-FR')),
                datasets: [
                    {
                        data: this.data.map((row) => row.valeur),
                        label: "Courant du moteur relevé par le capteur",
                        borderWidth: 1
                    }
                ]
            }
        });
    }
    else {
        this.chart.data.labels = this.data.map((row) => new Date(Math.floor(row.epoch)).toLocaleString('fr-FR'));
        this.chart.data.datasets.forEach((dataset) => dataset.data = this.data.map((row) => row.valeur));
        this.chart.update();
    }
};
export { engineCurrentRenderer };