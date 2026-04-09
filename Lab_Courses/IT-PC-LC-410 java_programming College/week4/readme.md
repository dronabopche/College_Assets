# 📘 NEHU Login Application

This is a simple Java Swing-based login GUI developed for the **NEHU (North-Eastern Hill University)** project. It allows users to log in using email and password credentials stored in a database, or create a new account.

---

## 🚀 Features

* Java Swing GUI for login.
* Email and password input fields.
* Connects to a backend database to validate user credentials.
* Provides functionality to create a new user account (redirects to registration form).
* Basic password authentication from database records.

---

## 🛠️ Technologies Used

* **Java SE**
* **Swing** for GUI
* **JDBC** for database connectivity
* **NetBeans IDE** (inferred from template headers)

---

## 📂 Project Structure

```
cherryapp/
│
├── login.java          # Main login GUI logic
├── Database.java       # Handles DB connection and queries (not shown here)
└── regFrom.java        # Registration form (called on "Create New Account")
```

---

## 🔐 Login Functionality

### How it works:

1. User inputs **email** and **password**.
2. Presses the **"login"** button.
3. The application sends a query:

   ```sql
   SELECT PASSWORD FROM login WHERE EMAIL = 'user@example.com';
   ```
4. If the password matches, the login is successful (prints "SUCCESS" to console).

> ⚠️ Note: This application uses **plain text passwords** and is **vulnerable to SQL injection**. See [Security Notes](#-security-notes) below.

---

## ➕ Create Account

* Clicking the **"Create New Account"** button opens the `regFrom` window, allowing users to register.
* Current implementation for registration is not shown, but is assumed to collect user info and insert it into the `login` table.

---

## 🧪 How to Run

1. Open the project in **NetBeans IDE** (or any Java IDE).
2. Ensure `Database.java` is implemented and connects to a valid DB.
3. Compile and run the project.
4. The `login` window should appear.

---

## 🔐 Security Notes

> ⚠️ This application **should not be used in production** in its current form.

* 🚫 Passwords are not encrypted.
* 🚫 Vulnerable to SQL injection:

  ```java
  "select PASSWORD from login where EMAIL = '"+EMAIL+"'"
  ```
* ✅ Consider using **PreparedStatements**.
* ✅ Hash passwords using **bcrypt** or **SHA-256** before storing.
* ✅ Sanitize all user inputs.

---

## 📈 Improvements Suggested

* Implement user feedback via dialog boxes (e.g., "Invalid credentials").
* Use a `PreparedStatement` to prevent SQL injection.
* Improve UI layout and input validation.
* Secure database credentials.
* Display main dashboard on successful login.

---

## 👤 Author

* **EXAM 2025**

---

## 📄 License

This project is for educational purposes and is not licensed for commercial use.


