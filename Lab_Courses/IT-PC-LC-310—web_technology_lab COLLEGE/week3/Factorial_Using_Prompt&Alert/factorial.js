let num = prompt("Enter a number:");

function factorial(n) {
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

alert("Factorial of " + num + " is " + factorial(num));