window.onload = init;

function init() {
    document.forms[0].onsubmit = function() {
       if (this.checkValidity()) {

        if(confirm("Are you sure would like to submit the details?") == 1)
        {
            window.location.href="submit.html";
        }

       return false;
    }
}

document.getElementById("problem").onclick = turnOnProblem;
document.getElementById("suggestion").onclick = turnOnSuggestion;

}

/* display the problem page hidden the suggestion page */
function turnOnProblem() {
    document.getElementById("problemInfo").hidden=false;
    document.getElementById("suggestionInfo").hidden=true;

    document.getElementById("select").hidden=true;

    document.getElementById("nameBox").required=true;
    document.getElementById("phoneBox").required=true;
    document.getElementById("pmailBox").required=true;
    document.getElementById("problemBox").required=true;
    document.getElementById("suggestionBox").required=false;

    document.getElementById("nameBox").disabled=false;
    document.getElementById("phoneBox").disabled=false;
    document.getElementById("pmailBox").disabled=false;
    document.getElementById("problemBox").disabled=false;
}

/* display the suggestion page and hidden the problem page */
function turnOnSuggestion() {
    document.getElementById("problemInfo").hidden=true;
    document.getElementById("suggestionInfo").hidden=false;

    document.getElementById("select").hidden=true;

    document.getElementById("nameBox").required=false;
    document.getElementById("phoneBox").required=false;
    document.getElementById("pmailBox").required=false;
    document.getElementById("problemBox").required=false;
    document.getElementById("suggestionBox").required=true;
}