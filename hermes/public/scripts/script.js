const http = new XMLHttpRequest();
const url = "http://localhost:3000/data/courant_moteur/10";
http.open("GET", url);
http.send();

http.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        console.log(http.responseText);
    }
}