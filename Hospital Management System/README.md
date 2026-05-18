# 🏥 Hospital Management System in C

A **console-based Hospital Management System** written in pure **C language**, designed to manage hospital operations efficiently.  
This project helps manage patients, doctors, nurses, billing, ambulance services, pharmacy, laboratory, blood bank, and security records using a simple terminal interface.

---

## 🚀 Features

- 👨‍⚕️ Patient Management
  - Add, edit, delete, and view patient records.
- 🩺 Doctor Management
  - Manage doctor information, departments, schedules, and fees.
- 👩‍⚕️ Nurse Management
  - View nurse shifts and ward details.
- 🚑 Ambulance Management
  - Add, edit, delete, and track ambulance availability.
- 💳 Billing & Accounts
  - Manage patient bills and payment records.
- 🧪 Laboratory Management
  - Store test records and results.
- 💊 Pharmacy Management
  - Manage medicines, stock, and pricing.
- 🩸 Blood Bank Management
  - Track donors, blood groups, and available units.
- 🔐 Security & Role Management
  - Manage system users and staff roles.
- 🔑 Admin Login System
  - Secure login authentication before accessing the system.
- 💾 Demo data included for testing.
- 🎨 Console-based colorful UI using `windows.h`.

---

## 🧠 Tech Stack

- **Language:** C  
- **Compiler:** GCC / MinGW / Turbo C  
- **Platform:** Windows (Recommended)

---

## 🧩 How to Run

### 🔧 On Windows

```bash
gcc Hospital_Management_System1.c -o hms
hms.exe
```

OR

```bash
gcc Hospital_Management_System2.c -o hms
hms.exe
```

---

### 🐧 On Linux / macOS

> ⚠️ Some features like `windows.h`, `Sleep()`, and `system("cls")` are Windows-specific.  
> You may need to modify the code for Linux/macOS compatibility.

```bash
gcc Hospital_Management_System1.c -o hms
./hms
```

---

## 📂 Project Structure

```bash
📁 Hospital-Management-System
│
├── Hospital_Management_System1.c    # Full HMS Project
├── Hospital_Management_System2.c    # Extra HMS Modules
├── README.md                        # Project Documentation
└── screenshots/                     # Project Screenshots
```

---

## 🔑 Login Credentials

```txt
Username : CYBERBADFIT
Password : CYBER1423
```

---

## 🧭 Main Menu Options

| Option | Description |
|--------|--------------|
| 1 | View Patients |
| 2 | Add Patient |
| 3 | Edit Patient |
| 4 | Delete Patient |
| 5 | View Doctors |
| 6 | Add Doctor |
| 7 | Edit Doctor |
| 8 | Delete Doctor |
| 9 | Nurse Management |
| 10 | Ambulance Management |
| 11 | Billing & Accounts |
| 12 | Laboratory Management |
| 13 | Pharmacy Management |
| 14 | Blood Bank Management |
| 15 | Security & Role Management |
| 0 | Exit Program |

---

## 🧰 Example Output

```txt
##############################################################
#                                                            #
#             HOSPITAL MANAGEMENT SYSTEM                     #
#                 Developed by CYBERBADFIT                   #
#                                                            #
##############################################################

#################### MAIN MENU ####################

1.  View Patients
2.  Add Patient
3.  Edit Patient
4.  Delete Patient

5.  View Doctors
6.  Add Doctor
7.  Edit Doctor
8.  Delete Doctor

9.  Nurse Management
10. Ambulance Management
11. Billing & Accounts
12. Laboratory Management
13. Pharmacy Management
14. Blood Bank Management
15. Security & Role Management

0. Exit Program
```

---

## 💡 Developer Notes

- Demo data is already included for testing.
- Maximum storage limit is controlled using:
  
```c
#define MAX 100
```

- Uses structures (`struct`) for managing records.
- CRUD operations are supported in multiple modules.
- Console color and loading animation use:
  
```c
#include <windows.h>
```

- Data is stored temporarily in memory only.
- No database or file handling used yet.

---

## 🔥 Future Improvements

- 💾 File Handling Support
- 🗄️ Database Integration (MySQL)
- 🔍 Search Functionality
- 📅 Appointment Booking
- 📊 Reports & Analytics
- 🖥️ GUI Version
- 🌐 Cross-Platform Support
- 🔐 Encrypted Password System

---

## 👤 Author

**CyberBadfit (Zaid)**  
🔗 GitHub: https://github.com/Cyberbadfit

---

## 🏷️ License

This project is released under the **MIT License** — free to use and modify with attribution.

---

### ⭐ Don’t forget to star the repo if you find it useful!
