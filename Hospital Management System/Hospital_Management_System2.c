#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 100

// ======================================================
// HOSPITAL MANAGEMENT SYSTEM
// Developed by CYBERBADFIT
// ======================================================

// ===================== STRUCTURES =====================

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

// ===================== DEMO DATA =====================

// Ambulance
struct Ambulance ambulances[MAX] = {
    {1, "Rahul", "UP14AB1234", "Available"},
    {2, "Karan", "UP14CD5678", "Busy"},
    {3, "Amit", "UP14EF9012", "Available"},
    {4, "Rohit", "UP14GH3456", "Busy"},
    {5, "Vikas", "UP14IJ7890", "Available"}
};

// Billing
struct Billing bills[MAX] = {
    {101, "Aarav", 2500},
    {102, "Priya", 3200},
    {103, "Rohan", 1800},
    {104, "Ananya", 5500},
    {105, "Kabir", 7200}
};

// Laboratory
struct Laboratory labRecords[MAX] = {
    {1, "Aarav", "Blood Test", "Normal"},
    {2, "Priya", "MRI", "Clear"},
    {3, "Rohan", "Sugar Test", "High"},
    {4, "Ananya", "ECG", "Normal"},
    {5, "Kabir", "X-Ray", "Critical"}
};

// Pharmacy
struct Pharmacy medicines[MAX] = {
    {1, "Paracetamol", 100, 20},
    {2, "Crocin", 50, 35},
    {3, "Insulin", 70, 120},
    {4, "Vitamin C", 90, 15},
    {5, "Aspirin", 110, 25}
};

// Blood Bank
struct BloodBank bloods[MAX] = {
    {1, "Rahul", "O+", 5},
    {2, "Karan", "A+", 3},
    {3, "Amit", "B+", 4},
    {4, "Rohit", "AB+", 2},
    {5, "Vikas", "O-", 6}
};

// Security
struct Security users[MAX] = {
    {1, "admin", "Administrator"},
    {2, "doctor1", "Doctor"},
    {3, "nurse1", "Nurse"},
    {4, "labstaff", "Lab Staff"},
    {5, "cashier", "Billing Staff"}
};

// ===================== COUNTS =====================

int ambulanceCount = 5;
int billCount = 5;
int labCount = 5;
int medicineCount = 5;
int bloodCount = 5;
int userCount = 5;

// ===================== HEADER =====================

void header() {

    system("cls");

    printf("\n#########################################################\n");
    printf("#                                                       #\n");
    printf("#        HOSPITAL MANAGEMENT SYSTEM                     #\n");
    printf("#            Developed by CYBERBADFIT                   #\n");
    printf("#                                                       #\n");
    printf("#########################################################\n");
}

// ======================================================
// AMBULANCE MANAGEMENT
// ======================================================

void ambulanceManagement() {

    int choice, id, found;

    while(1) {

        header();

        printf("\n########## AMBULANCE MANAGEMENT ##########\n");
        printf("1. View Ambulances\n");
        printf("2. Add Ambulance\n");
        printf("3. Edit Ambulance\n");
        printf("4. Delete Ambulance\n");
        printf("0. Back\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                header();

                for(int i=0; i<ambulanceCount; i++) {

                    printf("\nID       : %d\n", ambulances[i].id);
                    printf("Driver   : %s\n", ambulances[i].driver);
                    printf("Vehicle  : %s\n", ambulances[i].vehicle);
                    printf("Status   : %s\n", ambulances[i].status);

                    printf("###########################################\n");
                }

                system("pause");
                break;

            case 2:

                header();

                printf("\nEnter ID : ");
                scanf("%d", &ambulances[ambulanceCount].id);

                printf("Enter Driver : ");
                scanf(" %[^\n]", ambulances[ambulanceCount].driver);

                printf("Enter Vehicle : ");
                scanf(" %[^\n]", ambulances[ambulanceCount].vehicle);

                printf("Enter Status : ");
                scanf(" %[^\n]", ambulances[ambulanceCount].status);

                ambulanceCount++;

                printf("\nAdded Successfully!\n");

                system("pause");
                break;

            case 3:

                header();

                found = 0;

                printf("\nEnter Ambulance ID : ");
                scanf("%d", &id);

                for(int i=0; i<ambulanceCount; i++) {

                    if(ambulances[i].id == id) {

                        found = 1;

                        printf("Enter New Driver : ");
                        scanf(" %[^\n]", ambulances[i].driver);

                        printf("Enter New Vehicle : ");
                        scanf(" %[^\n]", ambulances[i].vehicle);

                        printf("Enter New Status : ");
                        scanf(" %[^\n]", ambulances[i].status);

                        printf("\nUpdated Successfully!\n");
                    }
                }

                if(found == 0)
                    printf("\nRecord Not Found!\n");

                system("pause");
                break;

            case 4:

                header();

                found = 0;

                printf("\nEnter Ambulance ID : ");
                scanf("%d", &id);

                for(int i=0; i<ambulanceCount; i++) {

                    if(ambulances[i].id == id) {

                        found = 1;

                        for(int j=i; j<ambulanceCount-1; j++) {
                            ambulances[j] = ambulances[j+1];
                        }

                        ambulanceCount--;

                        printf("\nDeleted Successfully!\n");
                    }
                }

                if(found == 0)
                    printf("\nRecord Not Found!\n");

                system("pause");
                break;

            case 0:
                return;

            default:
                printf("\nInvalid Choice!\n");
                Sleep(1000);
        }
    }
}

// ======================================================
// BILLING MANAGEMENT
// ======================================================

void billingManagement() {

    int choice, id, found;

    while(1) {

        header();

        printf("\n########## BILLING MANAGEMENT ##########\n");
        printf("1. View Bills\n");
        printf("2. Add Bill\n");
        printf("3. Edit Bill\n");
        printf("4. Delete Bill\n");
        printf("0. Back\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                header();

                for(int i=0; i<billCount; i++) {

                    printf("\nBill ID : %d\n", bills[i].billId);
                    printf("Patient : %s\n", bills[i].patient);
                    printf("Amount  : %.2f\n", bills[i].amount);

                    printf("###########################################\n");
                }

                system("pause");
                break;

            case 2:

                header();

                printf("\nEnter Bill ID : ");
                scanf("%d", &bills[billCount].billId);

                printf("Enter Patient Name : ");
                scanf(" %[^\n]", bills[billCount].patient);

                printf("Enter Amount : ");
                scanf("%f", &bills[billCount].amount);

                billCount++;

                printf("\nBill Added Successfully!\n");

                system("pause");
                break;

            case 3:

                header();

                found = 0;

                printf("\nEnter Bill ID : ");
                scanf("%d", &id);

                for(int i=0; i<billCount; i++) {

                    if(bills[i].billId == id) {

                        found = 1;

                        printf("Enter New Patient Name : ");
                        scanf(" %[^\n]", bills[i].patient);

                        printf("Enter New Amount : ");
                        scanf("%f", &bills[i].amount);

                        printf("\nUpdated Successfully!\n");
                    }
                }

                if(found == 0)
                    printf("\nBill Not Found!\n");

                system("pause");
                break;

            case 4:

                header();

                found = 0;

                printf("\nEnter Bill ID : ");
                scanf("%d", &id);

                for(int i=0; i<billCount; i++) {

                    if(bills[i].billId == id) {

                        found = 1;

                        for(int j=i; j<billCount-1; j++) {
                            bills[j] = bills[j+1];
                        }

                        billCount--;

                        printf("\nDeleted Successfully!\n");
                    }
                }

                if(found == 0)
                    printf("\nBill Not Found!\n");

                system("pause");
                break;

            case 0:
                return;
        }
    }
}

// ======================================================
// LAB MANAGEMENT
// ======================================================

void laboratoryManagement() {

    header();

    printf("\n########## LABORATORY MANAGEMENT ##########\n");

    for(int i=0; i<labCount; i++) {

        printf("\nTest ID : %d\n", labRecords[i].testId);
        printf("Patient : %s\n", labRecords[i].patient);
        printf("Test    : %s\n", labRecords[i].test);
        printf("Result  : %s\n", labRecords[i].result);

        printf("###########################################\n");
    }

    system("pause");
}

// ======================================================
// PHARMACY MANAGEMENT
// ======================================================

void pharmacyManagement() {

    header();

    printf("\n########## PHARMACY MANAGEMENT ##########\n");

    for(int i=0; i<medicineCount; i++) {

        printf("\nMedicine ID : %d\n", medicines[i].medId);
        printf("Medicine    : %s\n", medicines[i].medicine);
        printf("Stock       : %d\n", medicines[i].stock);
        printf("Price       : %.2f\n", medicines[i].price);

        printf("###########################################\n");
    }

    system("pause");
}

// ======================================================
// BLOOD BANK MANAGEMENT
// ======================================================

void bloodBankManagement() {

    header();

    printf("\n########## BLOOD BANK MANAGEMENT ##########\n");

    for(int i=0; i<bloodCount; i++) {

        printf("\nDonor ID    : %d\n", bloods[i].donorId);
        printf("Donor Name  : %s\n", bloods[i].donor);
        printf("Blood Group : %s\n", bloods[i].blood);
        printf("Units       : %d\n", bloods[i].units);

        printf("###########################################\n");
    }

    system("pause");
}

// ======================================================
// SECURITY MANAGEMENT
// ======================================================

void securityManagement() {

    header();

    printf("\n########## SECURITY MANAGEMENT ##########\n");

    for(int i=0; i<userCount; i++) {

        printf("\nUser ID  : %d\n", users[i].userId);
        printf("Username : %s\n", users[i].username);
        printf("Role     : %s\n", users[i].role);

        printf("###########################################\n");
    }

    system("pause");
}

// ======================================================
// MAIN FUNCTION
// ======================================================

int main() {

    int choice;

    system("color 0B");

    while(1) {

        header();

        printf("\n1. Ambulance Management\n");
        printf("2. Billing & Accounts\n");
        printf("3. Laboratory Management\n");
        printf("4. Pharmacy Management\n");
        printf("5. Blood Bank Management\n");
        printf("6. Security & Role Management\n");
        printf("0. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                ambulanceManagement();
                break;

            case 2:
                billingManagement();
                break;

            case 3:
                laboratoryManagement();
                break;

            case 4:
                pharmacyManagement();
                break;

            case 5:
                bloodBankManagement();
                break;

            case 6:
                securityManagement();
                break;

            case 0:
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
                Sleep(1000);
        }
    }

    return 0;
}