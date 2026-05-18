
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 100

// ======================================================
//        HOSPITAL MANAGEMENT SYSTEM
//             Developed by CYBERBADFIT
// ======================================================

// ===================== STRUCTURES =====================

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[20];
    char disease[50];
    char blood[10];
    char phone[20];
};

struct Doctor {
    int id;
    char name[50];
    char department[50];
    char schedule[30];
    int fee;
};

struct Nurse {
    int id;
    char name[50];
    char shift[20];
    char ward[30];
};

struct Ambulance {
    int id;
    char driver[50];
    char vehicle[30];
    char status[20];
};

struct Billing {
    int billId;
    char patient[50];
    float amount;
};

struct Laboratory {
    int testId;
    char patient[50];
    char test[50];
    char result[50];
};

struct Pharmacy {
    int medId;
    char medicine[50];
    int stock;
    float price;
};

struct BloodBank {
    int donorId;
    char donor[50];
    char blood[10];
    int units;
};

struct Security {
    int userId;
    char username[50];
    char role[50];
};

// ===================== GLOBAL ARRAYS =====================

struct Patient patients[MAX] = {
    {101, "Aarav Sharma", 22, "Male", "Fever", "O+", "9876543210"},
    {102, "Priya Singh", 19, "Female", "Asthma", "A+", "9876500000"},
    {103, "Rohan Verma", 35, "Male", "Diabetes", "B+", "9876511111"},
    {104, "Ananya Gupta", 27, "Female", "Migraine", "AB+", "9876522222"},
    {105, "Kabir Khan", 40, "Male", "Heart Issue", "O-", "9876533333"}
};

struct Doctor doctors[MAX] = {
    {1, "Dr. Raj", "Cardiology", "9AM-2PM", 1500},
    {2, "Dr. Sneha", "Neurology", "10AM-5PM", 2000},
    {3, "Dr. Aman", "Orthopedic", "8AM-1PM", 1200},
    {4, "Dr. Neha", "Pediatrics", "11AM-4PM", 1000},
    {5, "Dr. Arjun", "General", "24x7", 800}
};

struct Nurse nurses[MAX] = {
    {1, "Nurse Pooja", "Morning", "Ward A"},
    {2, "Nurse Ravi", "Night", "Ward B"},
    {3, "Nurse Anjali", "Morning", "ICU"},
    {4, "Nurse Deepak", "Evening", "Ward C"},
    {5, "Nurse Simran", "Night", "Emergency"}
};

struct Ambulance ambulances[MAX] = {
    {1, "Rahul", "UP14AB1234", "Available"},
    {2, "Karan", "UP14CD5678", "Busy"},
    {3, "Amit", "UP14EF9012", "Available"},
    {4, "Rohit", "UP14GH3456", "Busy"},
    {5, "Vikas", "UP14IJ7890", "Available"}
};

struct Billing bills[MAX] = {
    {101, "Aarav", 2500},
    {102, "Priya", 3200},
    {103, "Rohan", 1800},
    {104, "Ananya", 5500},
    {105, "Kabir", 7200}
};

struct Laboratory labRecords[MAX] = {
    {1, "Aarav", "Blood Test", "Normal"},
    {2, "Priya", "MRI", "Clear"},
    {3, "Rohan", "Sugar Test", "High"},
    {4, "Ananya", "ECG", "Normal"},
    {5, "Kabir", "X-Ray", "Critical"}
};

struct Pharmacy medicines[MAX] = {
    {1, "Paracetamol", 100, 20},
    {2, "Crocin", 50, 35},
    {3, "Insulin", 70, 120},
    {4, "Vitamin C", 90, 15},
    {5, "Aspirin", 110, 25}
};

struct BloodBank bloods[MAX] = {
    {1, "Rahul", "O+", 5},
    {2, "Karan", "A+", 3},
    {3, "Amit", "B+", 4},
    {4, "Rohit", "AB+", 2},
    {5, "Vikas", "O-", 6}
};

struct Security users[MAX] = {
    {1, "admin", "Administrator"},
    {2, "doctor1", "Doctor"},
    {3, "nurse1", "Nurse"},
    {4, "labstaff", "Lab Staff"},
    {5, "cashier", "Billing Staff"}
};

// ===================== COUNTS =====================

int patientCount = 5;
int doctorCount = 5;
int nurseCount = 5;
int ambulanceCount = 5;
int billCount = 5;
int labCount = 5;
int medicineCount = 5;
int bloodCount = 5;
int userCount = 5;

// ===================== COMMON FUNCTIONS =====================

void header() {
    system("cls");

    printf("##############################################################\n");
    printf("#                                                            #\n");
    printf("#             HOSPITAL MANAGEMENT SYSTEM                     #\n");
    printf("#                 Developed by CYBERBADFIT                   #\n");
    printf("#                                                            #\n");
    printf("##############################################################\n");
}

void loading() {
    system("cls");

    printf("\n\n\n");
    printf("\t\tLoading ");

    for(int i=0; i<30; i++) {
        printf("#");
        Sleep(50);
    }

    printf("\n\n");
}

// ===================== LOGIN =====================

int login() {

    char user[50];
    char pass[50];

    header();

    printf("\n############### ADMIN LOGIN #################\n\n");

    printf("USERNAME : ");
    scanf("%49s", user);

    printf("PASSWORD : ");
    scanf("%49s", pass);

    if(strcmp(user, "CYBERBADFIT") == 0 &&
       strcmp(pass, "CYBER1423") == 0) {

        printf("\nLOGIN SUCCESSFUL!\n");
        Sleep(1000);
        return 1;
    }

    printf("\nINVALID LOGIN!\n");
    Sleep(1000);

    return 0;
}

// ===================== PATIENT FUNCTIONS =====================

void viewPatients() {

    header();

    printf("\n################ PATIENT RECORDS ################\n\n");

    for(int i = 0; i < patientCount; i++) {

        printf("ID       : %d\n", patients[i].id);
        printf("NAME     : %s\n", patients[i].name);
        printf("AGE      : %d\n", patients[i].age);
        printf("GENDER   : %s\n", patients[i].gender);
        printf("DISEASE  : %s\n", patients[i].disease);
        printf("BLOOD GP : %s\n", patients[i].blood);
        printf("PHONE    : %s\n", patients[i].phone);
        printf("#################################################\n");
    }

    system("pause");
}

void addPatient() {

    header();

    printf("\n############### ADD PATIENT ################\n\n");

    printf("ENTER ID : ");
    scanf("%d", &patients[patientCount].id);

    printf("ENTER NAME : ");
    scanf(" %49[^\n]", patients[patientCount].name);

    printf("ENTER AGE : ");
    scanf("%d", &patients[patientCount].age);

    printf("ENTER GENDER : ");
    scanf(" %19[^\n]", patients[patientCount].gender);

    printf("ENTER DISEASE : ");
    scanf(" %49[^\n]", patients[patientCount].disease);

    printf("ENTER BLOOD GROUP : ");
    scanf(" %9[^\n]", patients[patientCount].blood);

    printf("ENTER PHONE : ");
    scanf(" %19[^\n]", patients[patientCount].phone);

    patientCount++;

    printf("\nPATIENT ADDED SUCCESSFULLY!\n");
    system("pause");
}

void editPatient() {

    int id, found = 0;

    header();

    printf("\nENTER PATIENT ID : ");
    scanf("%d", &id);

    for(int i = 0; i < patientCount; i++) {

        if(patients[i].id == id) {

            found = 1;

            printf("ENTER NEW NAME : ");
            scanf(" %49[^\n]", patients[i].name);

            printf("ENTER NEW AGE : ");
            scanf("%d", &patients[i].age);

            printf("ENTER NEW DISEASE : ");
            scanf(" %49[^\n]", patients[i].disease);

            printf("ENTER NEW PHONE : ");
            scanf(" %19[^\n]", patients[i].phone);

            printf("\nPATIENT UPDATED SUCCESSFULLY!\n");
        }
    }

    if(found == 0)
        printf("\nPATIENT NOT FOUND!\n");

    system("pause");
}

void deletePatient() {

    int id, found = 0;

    header();

    printf("\nENTER PATIENT ID : ");
    scanf("%d", &id);

    for(int i = 0; i < patientCount; i++) {

        if(patients[i].id == id) {

            found = 1;

            for(int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }

            patientCount--;

            printf("\nPATIENT DELETED SUCCESSFULLY!\n");
        }
    }

    if(found == 0)
        printf("\nPATIENT NOT FOUND!\n");

    system("pause");
}

// ===================== DOCTOR FUNCTIONS =====================

void viewDoctors() {

    header();

    for(int i = 0; i < doctorCount; i++) {

        printf("\nID         : %d\n", doctors[i].id);
        printf("NAME       : %s\n", doctors[i].name);
        printf("DEPARTMENT : %s\n", doctors[i].department);
        printf("SCHEDULE   : %s\n", doctors[i].schedule);
        printf("FEES       : %d\n", doctors[i].fee);
        printf("#################################################\n");
    }

    system("pause");
}

void addDoctor() {

    header();

    printf("\nENTER ID : ");
    scanf("%d", &doctors[doctorCount].id);

    printf("ENTER NAME : ");
    scanf(" %49[^\n]", doctors[doctorCount].name);

    printf("ENTER DEPARTMENT : ");
    scanf(" %49[^\n]", doctors[doctorCount].department);

    printf("ENTER SCHEDULE : ");
    scanf(" %29[^\n]", doctors[doctorCount].schedule);

    printf("ENTER FEES : ");
    scanf("%d", &doctors[doctorCount].fee);

    doctorCount++;

    printf("\nDOCTOR ADDED SUCCESSFULLY!\n");
    system("pause");
}

void editDoctor() {

    int id, found = 0;

    header();

    printf("\nENTER DOCTOR ID : ");
    scanf("%d", &id);

    for(int i = 0; i < doctorCount; i++) {

        if(doctors[i].id == id) {

            found = 1;

            printf("ENTER NEW NAME : ");
            scanf(" %49[^\n]", doctors[i].name);

            printf("ENTER NEW DEPARTMENT : ");
            scanf(" %49[^\n]", doctors[i].department);

            printf("ENTER NEW SCHEDULE : ");
            scanf(" %29[^\n]", doctors[i].schedule);

            printf("ENTER NEW FEES : ");
            scanf("%d", &doctors[i].fee);

            printf("\nDOCTOR UPDATED SUCCESSFULLY!\n");
        }
    }

    if(found == 0)
        printf("\nDOCTOR NOT FOUND!\n");

    system("pause");
}

void deleteDoctor() {

    int id, found = 0;

    header();

    printf("\nENTER DOCTOR ID : ");
    scanf("%d", &id);

    for(int i = 0; i < doctorCount; i++) {

        if(doctors[i].id == id) {

            found = 1;

            for(int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }

            doctorCount--;

            printf("\nDOCTOR DELETED SUCCESSFULLY!\n");
        }
    }

    if(found == 0)
        printf("\nDOCTOR NOT FOUND!\n");

    system("pause");
}

// ===================== EXTRA MANAGEMENT FUNCTIONS =====================

void nurseManagement() {

    header();

    printf("\n########## NURSE MANAGEMENT ##########\n");

    for(int i = 0; i < nurseCount; i++) {

        printf("\nID    : %d\n", nurses[i].id);
        printf("NAME  : %s\n", nurses[i].name);
        printf("SHIFT : %s\n", nurses[i].shift);
        printf("WARD  : %s\n", nurses[i].ward);

        printf("######################################\n");
    }

    system("pause");
}

void ambulanceManagement() {

    header();

    printf("\n########## AMBULANCE MANAGEMENT ##########\n");

    for(int i = 0; i < ambulanceCount; i++) {

        printf("\nID      : %d\n", ambulances[i].id);
        printf("Driver  : %s\n", ambulances[i].driver);
        printf("Vehicle : %s\n", ambulances[i].vehicle);
        printf("Status  : %s\n", ambulances[i].status);

        printf("##########################################\n");
    }

    system("pause");
}

void billingManagement() {

    header();

    printf("\n########## BILLING MANAGEMENT ##########\n");

    for(int i = 0; i < billCount; i++) {

        printf("\nBill ID : %d\n", bills[i].billId);
        printf("Patient : %s\n", bills[i].patient);
        printf("Amount  : %.2f\n", bills[i].amount);

        printf("########################################\n");
    }

    system("pause");
}

void laboratoryManagement() {

    header();

    printf("\n########## LABORATORY MANAGEMENT ##########\n");

    for(int i = 0; i < labCount; i++) {

        printf("\nTest ID : %d\n", labRecords[i].testId);
        printf("Patient : %s\n", labRecords[i].patient);
        printf("Test    : %s\n", labRecords[i].test);
        printf("Result  : %s\n", labRecords[i].result);

        printf("###########################################\n");
    }

    system("pause");
}

void pharmacyManagement() {

    header();

    printf("\n########## PHARMACY MANAGEMENT ##########\n");

    for(int i = 0; i < medicineCount; i++) {

        printf("\nMedicine ID : %d\n", medicines[i].medId);
        printf("Medicine    : %s\n", medicines[i].medicine);
        printf("Stock       : %d\n", medicines[i].stock);
        printf("Price       : %.2f\n", medicines[i].price);

        printf("###########################################\n");
    }

    system("pause");
}

void bloodBankManagement() {

    header();

    printf("\n########## BLOOD BANK MANAGEMENT ##########\n");

    for(int i = 0; i < bloodCount; i++) {

        printf("\nDonor ID    : %d\n", bloods[i].donorId);
        printf("Donor Name  : %s\n", bloods[i].donor);
        printf("Blood Group : %s\n", bloods[i].blood);
        printf("Units       : %d\n", bloods[i].units);

        printf("###########################################\n");
    }

    system("pause");
}

void securityManagement() {

    header();

    printf("\n########## SECURITY MANAGEMENT ##########\n");

    for(int i = 0; i < userCount; i++) {

        printf("\nUser ID  : %d\n", users[i].userId);
        printf("Username : %s\n", users[i].username);
        printf("Role     : %s\n", users[i].role);

        printf("###########################################\n");
    }

    system("pause");
}

// ===================== MAIN MENU =====================

void menu() {

    int choice;

    while(1) {

        header();

        printf("\n#################### MAIN MENU ####################\n\n");

        printf("1.  View Patients\n");
        printf("2.  Add Patient\n");
        printf("3.  Edit Patient\n");
        printf("4.  Delete Patient\n\n");

        printf("5.  View Doctors\n");
        printf("6.  Add Doctor\n");
        printf("7.  Edit Doctor\n");
        printf("8.  Delete Doctor\n\n");

        printf("9.  Nurse Management\n");
        printf("10. Ambulance Management\n");
        printf("11. Billing & Accounts\n");
        printf("12. Laboratory Management\n");
        printf("13. Pharmacy Management\n");
        printf("14. Blood Bank Management\n");
        printf("15. Security & Role Management\n\n");

        printf("0. Exit Program\n");

        printf("\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                viewPatients();
                break;

            case 2:
                addPatient();
                break;

            case 3:
                editPatient();
                break;

            case 4:
                deletePatient();
                break;

            case 5:
                viewDoctors();
                break;

            case 6:
                addDoctor();
                break;

            case 7:
                editDoctor();
                break;

            case 8:
                deleteDoctor();
                break;

            case 9:
                nurseManagement();
                break;

            case 10:
                ambulanceManagement();
                break;

            case 11:
                billingManagement();
                break;

            case 12:
                laboratoryManagement();
                break;

            case 13:
                pharmacyManagement();
                break;

            case 14:
                bloodBankManagement();
                break;

            case 15:
                securityManagement();
                break;

            case 0:
                header();
                printf("\nTHANK YOU FOR USING HMS!\n");
                printf("\nDeveloped by CYBERBADFIT\n\n");
                exit(0);

            default:
                printf("\nINVALID CHOICE!\n");
                Sleep(1000);
        }
    }
}

// ===================== MAIN FUNCTION =====================

int main() {

    system("color 0B");

    loading();

    if(login()) {
        menu();
    }

    return 0;
}
// ```

// ## Login Details

// * Username: `CYBERBADFIT`
// * Password: `CYBER1423`

// ## Features Included

// * Patient Management
// * Doctor Management
// * Nurse Management
// * Ambulance Management
// * Billing & Accounts
// * Laboratory Management
// * Pharmacy Management
// * Blood Bank Management
// * Security & Role Management
// * Demo Data Included
// * Add / Edit / Delete Features
// * Login System
// * Console UI Design
