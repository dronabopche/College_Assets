const display = document.getElementById('display');

// Adds numbers or operators to the calculator screen
function appendValue(input) {
    display.value += input;
}


function clearDisplay() {
    display.value = "";
}

function calculate() {
    try {
        
        if (display.value !== "") {
            display.value = eval(display.value);
        }
    } catch (error) {
        
        display.value = "Error";
    }
}