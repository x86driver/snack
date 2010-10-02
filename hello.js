var xmlHttp;

function createXMLHttpRequest() {
    if(window.XMLHttpRequest) {
        xmlHttp = new XMLHttpRequest();
    }
    else if(window.ActiveXObject) {
        xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
}

function startRequest(value) {
    createXMLHttpRequest();
    var url = "/cgi-bin/drink.cgi" + "?temp=" + value;
    xmlHttp.onreadystatechange = handleStateChange;
    xmlHttp.open("GET", url);
    xmlHttp.send(null);
}

function handleStateChange() {
    if(xmlHttp.readyState == 4) {
        if(xmlHttp.status == 200) {
            document.getElementById("response").innerHTML =
                xmlHttp.responseText;
        }
    }
}
