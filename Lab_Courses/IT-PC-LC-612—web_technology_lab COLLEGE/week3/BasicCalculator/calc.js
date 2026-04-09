function append(val) {
    document.getElementById("result").value += val;
}

function clearDisplay() {
    document.getElementById("result").value = "";
}

function calculate() {
    let exp = document.getElementById("result").value;
    document.getElementById("result").value = eval(exp);
}