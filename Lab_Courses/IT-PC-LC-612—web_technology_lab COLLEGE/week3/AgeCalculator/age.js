function calcAge() {
    let dob = new Date(document.getElementById("dob").value);
    let today = new Date();

    let age = today.getFullYear() - dob.getFullYear();
    document.getElementById("result").innerText = "Age: " + age;
}