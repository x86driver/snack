var xmlHttp;

function createXMLHttpRequest() {
    if(window.XMLHttpRequest) {
        xmlHttp = new XMLHttpRequest();
    }
    else if(window.ActiveXObject) {
        xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
}

function query_drink(drink, temp) {
    createXMLHttpRequest();
    var url = "/cgi-bin/drink.cgi" + "?drink=" + drink;
    url = url + "&temp=" + temp;
    xmlHttp.onreadystatechange = handleStateChange;
    xmlHttp.open("GET", url);
    xmlHttp.send(null);
}

function show_temp(drink) {
    if (drink == "jelly") {
	document.getElementById("temp0").disabled=false;
    } else {
	document.getElementById("temp0").disabled=false;
	document.getElementById("temp1").disabled=false;
    }
}

function handleStateChange() {
    if(xmlHttp.readyState == 4) {
        if(xmlHttp.status == 200) {
            document.getElementById("response").innerHTML =
                xmlHttp.responseText;
        }
    }
}
