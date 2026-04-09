// Stack
let stack = [];

function pushStack() {
    let val = document.getElementById("stackInput").value;
    if (val === "") return;

    stack.push(val);
    displayStack();
}

function popStack() {
    if (stack.length === 0) {
        alert("Stack is empty");
        return;
    }

    stack.pop();
    displayStack();
}

function displayStack() {
    document.getElementById("stackOutput").innerText =
        "Stack: " + stack.join(" -> ");
}

// Queue
let queue = [];

function enqueue() {
    let val = document.getElementById("queueInput").value;
    if (val === "") return;

    queue.push(val);
    displayQueue();
}

function dequeue() {
    if (queue.length === 0) {
        alert("Queue is empty");
        return;
    }

    queue.shift();
    displayQueue();
}

function displayQueue() {
    document.getElementById("queueOutput").innerText =
        "Queue: " + queue.join(" <- ");
}