function calculateAge() {
    const dobInput = document.getElementById('dob').value;
    const resultDiv = document.getElementById('result');
    
 
    if (!dobInput) {
        resultDiv.innerHTML = "Please select a valid date.";
        resultDiv.style.color = "red";
        return;
    }
    
    const birthDate = new Date(dobInput);
    const today = new Date();
    

    let age = today.getFullYear() - birthDate.getFullYear();
    

    const monthDifference = today.getMonth() - birthDate.getMonth();
    const dayDifference = today.getDate() - birthDate.getDate();
    
    if (monthDifference < 0 || (monthDifference === 0 && dayDifference < 0)) {
        age--;
    }
    
    if (age < 0) {
        resultDiv.innerHTML = "You can't be born in the future!";
        resultDiv.style.color = "red";
    } else {
        resultDiv.innerHTML = `You are ${age} years old.`;
        resultDiv.style.color = "green";
    }
}