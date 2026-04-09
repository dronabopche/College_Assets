let result = "";

for (let i = 2; i <= 10; i++) {
    result += "Table of " + i + "\n";
    for (let j = 1; j <= 10; j++) {
        result += i + " x " + j + " = " + (i * j) + "\n";
    }
    result += "\n";
}

document.getElementById("output").innerText = result;