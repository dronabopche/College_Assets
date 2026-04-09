function validate() {
    let name = document.getElementById("name").value;
    let phone = document.getElementById("phone").value;
    let roll = document.getElementById("roll").value;
    let email = document.getElementById("email").value;

    let namePattern = /^[A-Za-z ]+$/;
    let phonePattern = /^[0-9]{10}$/;
    let rollPattern = /^(19BTechIT|20BTechLIT)/;
    let emailPattern = /^[A-Za-z0-9._-]+@[A-Za-z0-9]+\.[A-Za-z]+$/;

    if (!name || !phone || !roll || !email) {
        alert("All fields are required");
        return false;
    }

    if (!namePattern.test(name)) {
        alert("Invalid Name");
        return false;
    }

    if (!phonePattern.test(phone)) {
        alert("Invalid Phone");
        return false;
    }

    if (!rollPattern.test(roll)) {
        alert("Invalid Roll Number");
        return false;
    }

    if (!emailPattern.test(email)) {
        alert("Invalid Email");
        return false;
    }

    alert("Form Submitted Successfully");
    return true;
}