# 🎓 Student Management System in C

A **console-based Student Management System** written in pure **C language**, designed to help manage student records efficiently.  
You can add, edit, delete, search, and view students — each with their personal info and enrolled courses.

---

## 🚀 Features

- ➕ Add a new student with:
  - ID, Name, Email, Phone Number, and up to 4 courses.
- 📋 View all registered students in a neat table format.
- 🔍 Search student by ID and view all details.
- ✏️ Edit existing student information.
- ❌ Delete a specific student or remove all records at once.
- 💾 In-memory data storage (no external files required).
- 💡 User guidelines and an About section.
- 🎨 Simple and clear terminal UI with optional clear-screen commands.

---

## 🧠 Tech Stack

- **Language:** C  
- **Compiler:** GCC / MinGW / Turbo C  
- **Platform:** Windows / Linux / macOS (cross-platform compatible)

---

## 🧩 How to Run

### 🔧 On Windows
```bash
gcc Student_Management_System.c -o sms
sms.exe
```

### 🐧 On Linux / macOS
```bash
gcc Student_Management_System.c -o sms
./sms
```

If `gcc` is not installed, you can install it using:
```bash
sudo apt install build-essential    # Debian/Ubuntu
sudo dnf install gcc               # Fedora
```

---

## 📂 Project Structure

```
📁 Student-Management-System
│
├── Student_Management_System.c             # Main program file
├── README.md          # Project documentation
└── LICENSE            # (optional)
```

---

## 🧭 Menu Options

| Option | Description |
|--------|--------------|
| 1 | Add a New Student |
| 2 | Show All Students |
| 3 | Search a Student |
| 4 | Edit a Student |
| 5 | Delete a Student |
| 6 | Delete All Students |
| 7 | Clear the Screen |
| 8 | User Guideline |
| 9 | About Us |
| 0 | Exit Program |

---

## 🧰 Example Output

```
*** Student Management System Using C ***

MAIN MENU
=======================
[1] Add A New student.
[2] Show All students.
[3] Search A student.
[4] Edit A student.
[5] Delete A student.
[6] Delete All students.
[7] Clear The window.
[8] User Guideline.
[9] About Us.
[0] Exit the Program.
=======================
Enter The Choice:
```

---

## 💡 Developer Notes

- Each student can have **1–4 courses**.
- Student IDs, emails, and phone numbers must be **unique**.
- Demo data (`Alice` and `Bob`) are preloaded via `DataSeed()` function.
- Data is not saved permanently — all info resets after exit.

---

## 👤 Author

**CyberBadfit (Zaid)**  
🔗 [GitHub Profile](https://github.com/Cyberbadfit)  

---

## 🏷️ License

This project is released under the **MIT License** — free to use and modify with attribution.

---

### ⭐ Don’t forget to star the repo if you find it useful!
