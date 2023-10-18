window.onload = init;

function init() {
   document.forms[0].onsubmit = function() {
      if (this.checkValidity()) alert("Data passes initial validation tests");
      return false;
   }
   
   document.getElementById("online").onclick = turnOnOnline;
   document.getElementById("card").onclick = turnOnCard;
   document.getElementById("tng").onclick = turnOnTng;
}

function turnOnOnline() {
   document.getElementById("onlineBox").disabled=false;
   document.getElementById("cardBox").disabled=true;
   document.getElementById("cardBox1").disabled=true;
   document.getElementById("cardBox2").disabled=true;
   document.getElementById("cardBox3").disabled=true;
   document.getElementById("cardBox4").disabled=true;
   document.getElementById("cardBox5").disabled=true;
   document.getElementById("tngBox").disabled=true;
}

function turnOnCard() {
   document.getElementById("onlineBox").disabled=true;
   document.getElementById("cardBox").disabled=false;
   document.getElementById("cardBox1").disabled=false;
   document.getElementById("cardBox2").disabled=false;
   document.getElementById("cardBox3").disabled=false;
   document.getElementById("cardBox4").disabled=false;
   document.getElementById("cardBox5").disabled=false;
   document.getElementById("tngBox").disabled=true;
}

function turnOnTng() {
   document.getElementById("onlineBox").disabled=true;
   document.getElementById("cardBox").disabled=true;
   document.getElementById("cardBox1").disabled=true;
   document.getElementById("cardBox2").disabled=true;
   document.getElementById("cardBox3").disabled=true;
   document.getElementById("cardBox4").disabled=true;
   document.getElementById("cardBox5").disabled=true;
   document.getElementById("tngBox").disabled=false;
}
   