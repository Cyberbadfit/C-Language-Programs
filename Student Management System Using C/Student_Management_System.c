#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000)
#endif

struct StudentInfo
{
    char ID[10];
    char Name[20];
    char Email[30];
    char Phone[20];
    int NumberOfCourse;
};

struct CourseInfo
{
    char StudentID[10];
    char Code[10];
    char Name[20];
};

struct StudentInfo Students[100];
struct CourseInfo Courses[500];

int i, j;
int TotalStudents = 0;
int TotalCourse = 0;
char StudentID[10];
bool IsRunning = true;

// Function Prototypes
void Menu();
void AddNewStudent();
void ShowAllStudents();
int SearchStudent(char StudentID[10]);
void EditStudent(int StudentFoundIndex);
void DeleteStudent(int StudentIndex);
void DeleteAllStudents();
int IsAlreadyExists(char GivenLine[30], char InfoType, char StudentID[300]);
void DeleteCourseByIndex(int CourseIndex);
void DeleteStudentByIndex(int CourseIndex);
void UserGuideline();
void AboutUs();
void GoBackOrExit();
void ExitProject();
void DataSeed();

int main()
{
    DataSeed(); // load some demo data

    while (IsRunning)
    {
        Menu();
        int Option;
        scanf("%d", &Option);
        switch (Option)
        {
        case 0:
            IsRunning = false;
            ExitProject();
            break;
        case 1:
            system("cls||clear");
            printf("\n\t\t **** Add A New Student ****\n\n");
            AddNewStudent();
            GoBackOrExit();
            break;
        case 2:
            system("cls||clear");
            printf("\n\t\t **** All Students ****\n\n");
            ShowAllStudents();
            GoBackOrExit();
            break;
        case 3:
        {
            system("cls||clear");
            printf("\n\t\t **** Search Students ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);
            int IsFound = SearchStudent(StudentID);
            if (IsFound < 0)
            {
                printf(" No Student Found\n\n");
            }
            printf("\n");
            GoBackOrExit();
            break;
        }
        case 4:
        {
            system("cls||clear");
            printf("\n\t\t **** Edit a Student ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);
            int StudentFoundIndex = SearchStudent(StudentID);

            if (StudentFoundIndex >= 0)
            {
                EditStudent(StudentFoundIndex);
            }
            else
            {
                printf(" No Student Found\n\n");
            }
            GoBackOrExit();
            break;
        }
        case 5:
        {
            system("cls||clear");
            printf("\n\t\t **** Delete a Student ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s", StudentID);

            int DeleteStudentFoundIndex = SearchStudent(StudentID);

            if (DeleteStudentFoundIndex >= 0)
            {
                char Sure = 'N';
                getchar();
                printf("\n\n Are you sure want to delete this student? (Y/N): ");
                scanf("%c", &Sure);

                if (Sure == 'Y' || Sure == 'y')
                {
                    DeleteStudent(DeleteStudentFoundIndex);
                }
                else
                {
                    printf(" Your Data is Safe.\n\n");
                    GoBackOrExit();
                }
            }
            else
            {
                printf(" No Student Found\n\n");
                GoBackOrExit();
            }
            break;
        }
        case 6:
        {
            char Sure = 'N';
            getchar();
            system("cls||clear");
            printf("\n\t\t **** Delete ALL Students ****\n\n");
            printf(" Are you sure want to delete all the students? (Y/N): ");
            scanf("%c", &Sure);
            if (Sure == 'Y' || Sure == 'y')
            {
                DeleteAllStudents();
            }
            else
            {
                printf(" Your Data is Safe.\n\n");
                GoBackOrExit();
            }
            break;
        }
        case 7:
            system("cls||clear");
            break;
        case 8:
            system("cls||clear");
            UserGuideline();
            GoBackOrExit();
            break;
        case 9:
            system("cls||clear");
            AboutUs();
            GoBackOrExit();
            break;
        default:
            ExitProject();
            break;
        }
    }
    return 0;
}

// ================= Functions ==================

void Menu()
{
    printf("\n\n\t*** Student Management System Using C ***\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[7] Clear The window.\n");
    printf("\t\t[8] User Guideline.\n");
    printf("\t\t[9] About Us.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
}

void AddNewStudent()
{
    char StudentID[300], Name[300], Phone[300], Email[300];
    int NumberOfCourses;
    char CourseCode[300], CourseName[300];

    // ID
    while (1)
    {
        printf(" Enter The ID: ");
        scanf("%s", StudentID);
        if (IsAlreadyExists(StudentID, 'i', StudentID) > 0)
            printf(" Error: This ID already exists.\n\n");
        else if (strlen(StudentID) > 10)
            printf(" Error: ID cannot be more than 10 characters.\n\n");
        else
            break;
    }

    // Name
    while (1)
    {
        printf(" Enter The Name: ");
        scanf(" %[^\n]", Name);
        if (strlen(Name) > 20)
            printf(" Error: Name cannot be more than 20 characters.\n\n");
        else
            break;
    }

    // Email
    while (1)
    {
        printf(" Enter The Email: ");
        scanf("%s", Email);
        if (IsAlreadyExists(Email, 'e', StudentID) > 0)
            printf(" Error: This Email already exists.\n\n");
        else if (strlen(Email) > 30)
            printf(" Error: Email cannot be more than 30 characters.\n\n");
        else
            break;
    }

    // Phone
    while (1)
    {
        printf(" Enter The Phone: ");
        scanf("%s", Phone);
        if (IsAlreadyExists(Phone, 'p', StudentID) > 0)
            printf(" Error: This Phone already exists.\n\n");
        else if (strlen(Phone) > 20)
            printf(" Error: Phone cannot be more than 20 characters.\n\n");
        else
            break;
    }

    // Number of Courses
    while (1)
    {
        printf(" Number of courses (1-4): ");
        scanf("%d", &NumberOfCourses);
        if (NumberOfCourses >= 1 && NumberOfCourses <= 4)
            break;
        else
            printf(" Error: Must be between 1 and 4.\n\n");
    }

    // Save student
    strcpy(Students[TotalStudents].ID, StudentID);
    strcpy(Students[TotalStudents].Name, Name);
    strcpy(Students[TotalStudents].Phone, Phone);
    strcpy(Students[TotalStudents].Email, Email);
    Students[TotalStudents].NumberOfCourse = NumberOfCourses;
    TotalStudents++;

    // Save courses
    for (i = 0; i < NumberOfCourses; i++)
    {
        printf(" Enter Course %d Code: ", i + 1);
        scanf("%s", CourseCode);
        printf(" Enter Course %d Name: ", i + 1);
        scanf(" %[^\n]", CourseName);

        strcpy(Courses[TotalCourse].StudentID, StudentID);
        strcpy(Courses[TotalCourse].Code, CourseCode);
        strcpy(Courses[TotalCourse].Name, CourseName);
        TotalCourse++;
    }

    printf("\n Student Added Successfully.\n\n");
}

void ShowAllStudents()
{
    printf("|%-10s|%-20s|%-30s|%-20s|%-11s|\n",
           "ID", "Name", "Email", "Phone", "No.Course");
    printf("|----------|--------------------|------------------------------|--------------------|-----------|\n");

    for (i = 0; i < TotalStudents; i++)
    {
        printf("|%-10s|%-20s|%-30s|%-20s|%-11d|\n",
               Students[i].ID,
               Students[i].Name,
               Students[i].Email,
               Students[i].Phone,
               Students[i].NumberOfCourse);
    }
    printf("\n");
}

int SearchStudent(char StudentID[10])
{
    int StudentFoundIndex = -1;
    for (i = 0; i < TotalStudents; i++)
    {
        if (strcmp(StudentID, Students[i].ID) == 0)
        {
            StudentFoundIndex = i;
            printf("\n Found Student: %s\n\n", StudentID);
            printf(" Name:  %s\n", Students[i].Name);
            printf(" Email: %s\n", Students[i].Email);
            printf(" Phone: %s\n", Students[i].Phone);
            printf(" Courses: %d\n", Students[i].NumberOfCourse);
        }
    }
    int CourseCount = 0;
    for (j = 0; j < TotalCourse; j++)
    {
        if (strcmp(StudentID, Courses[j].StudentID) == 0)
        {
            CourseCount++;
            printf(" Course %d Code: %s\n", CourseCount, Courses[j].Code);
            printf(" Course %d Name: %s\n", CourseCount, Courses[j].Name);
        }
    }
    return StudentFoundIndex;
}

void EditStudent(int StudentFoundIndex)
{
    char NewName[300], NewPhone[300], NewEmail[300];
    int NewNumberOfCourses;
    char SID[300];
    strcpy(SID, Students[StudentFoundIndex].ID);
    int OldCourses = Students[StudentFoundIndex].NumberOfCourse;

    // Name
    printf(" Enter The New Name (0 for skip): ");
    scanf(" %[^\n]", NewName);
    if (strcmp(NewName, "0") != 0 && strlen(NewName) <= 20)
    {
        strcpy(Students[StudentFoundIndex].Name, NewName);
    }

    // Email
    printf(" Enter The New Email (0 for skip): ");
    scanf("%s", NewEmail);
    if (strcmp(NewEmail, "0") != 0 && strlen(NewEmail) <= 30 &&
        IsAlreadyExists(NewEmail, 'e', SID) == 0)
    {
        strcpy(Students[StudentFoundIndex].Email, NewEmail);
    }

    // Phone
    printf(" Enter The New Phone (0 for skip): ");
    scanf("%s", NewPhone);
    if (strcmp(NewPhone, "0") != 0 && strlen(NewPhone) <= 20 &&
        IsAlreadyExists(NewPhone, 'p', SID) == 0)
    {
        strcpy(Students[StudentFoundIndex].Phone, NewPhone);
    }

    // Courses
    printf(" Number of New courses (0 for skip): ");
    scanf("%d", &NewNumberOfCourses);
    if (NewNumberOfCourses > 0 && NewNumberOfCourses <= 4)
    {
        Students[StudentFoundIndex].NumberOfCourse = NewNumberOfCourses;

        int FirstCourseIndex = -1;
        for (i = 0; i < TotalCourse; i++)
        {
            if (strcmp(SID, Courses[i].StudentID) == 0)
            {
                FirstCourseIndex = i;
                break;
            }
        }
        for (i = 0; i < OldCourses; i++)
        {
            DeleteCourseByIndex(FirstCourseIndex);
        }

        char CourseCode[300], CourseName[300];
        for (i = 1; i <= NewNumberOfCourses; i++)
        {
            printf(" Enter New Course %d Code: ", i);
            scanf("%s", CourseCode);
            printf(" Enter New Course %d Name: ", i);
            scanf(" %[^\n]", CourseName);
            strcpy(Courses[TotalCourse].StudentID, SID);
            strcpy(Courses[TotalCourse].Code, CourseCode);
            strcpy(Courses[TotalCourse].Name, CourseName);
            TotalCourse++;
        }
    }

    printf(" Student Updated Successfully.\n\n");
}

void DeleteStudent(int StudentIndex)
{
    struct StudentInfo ThisStudent = Students[StudentIndex];
    int FirstCourseIndex = -1;
    for (i = 0; i < TotalCourse; i++)
    {
        if (strcmp(ThisStudent.ID, Courses[i].StudentID) == 0)
        {
            FirstCourseIndex = i;
            break;
        }
    }
    for (i = 0; i < ThisStudent.NumberOfCourse; i++)
    {
        DeleteCourseByIndex(FirstCourseIndex);
    }
    DeleteStudentByIndex(StudentIndex);
    printf(" Student Deleted Successfully.\n\n");
    GoBackOrExit();
}

void DeleteAllStudents()
{
    TotalStudents = 0;
    TotalCourse = 0;
    printf(" All Students Deleted Successfully.\n\n");
    GoBackOrExit();
}

void DeleteCourseByIndex(int CourseIndex)
{
    for (i = CourseIndex; i < TotalCourse - 1; i++)
    {
        Courses[i] = Courses[i + 1];
    }
    TotalCourse--;
}

void DeleteStudentByIndex(int StudentIndex)
{
    for (i = StudentIndex; i < TotalStudents - 1; i++)
    {
        Students[i] = Students[i + 1];
    }
    TotalStudents--;
}

int IsAlreadyExists(char GivenLine[300], char InfoType, char StudentID[300])
{
    int EmailExists = 0, PhoneExists = 0, IDExists = 0;
    for (i = 0; i < TotalStudents; i++)
    {
        if (strcmp(GivenLine, Students[i].ID) == 0 && strcmp(StudentID, Students[i].ID) != 0)
        {
            IDExists++;
        }
        if (strcmp(GivenLine, Students[i].Email) == 0 && strcmp(StudentID, Students[i].ID) != 0)
        {
            EmailExists++;
        }
        if (strcmp(GivenLine, Students[i].Phone) == 0 && strcmp(StudentID, Students[i].ID) != 0)
        {
            PhoneExists++;
        }
    }
    if (InfoType == 'i')
        return IDExists;
    else if (InfoType == 'e')
        return EmailExists;
    else if (InfoType == 'p')
        return PhoneExists;
    else
        return 0;
}

void UserGuideline()
{
    printf("\n\t\t **** How it Works? ****\n\n");
    printf(" -> Store ID, Name, Email, Phone, and Courses.\n");
    printf(" -> Max 4 courses, min 1 course.\n");
    printf(" -> ID max 10 chars (unique).\n");
    printf(" -> Name max 20 chars.\n");
    printf(" -> Email max 30 chars (unique).\n");
    printf(" -> Phone max 20 chars (unique).\n");
    printf(" -> Course code max 10, name max 20.\n\n");
}

void AboutUs()
{
    char url[] = "https://github.com/Cyberbadfit";
    printf("\n\t\t **** About Us ****\n\n");
    printf(" -> Simple student management system in C.\n");
    printf(" -> GITHUB REPO URL is: %s\n", url);
    printf(" -> CREATED BY CYBERBADFIT.\n");
    printf(" -> SIGNATURE >> ZAID ");
}

void GoBackOrExit()
{
    getchar();
    char Option;
    printf(" Go back(b)? or Exit(0)?: ");
    scanf("%c", &Option);
    if (Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls||clear");
    }
}

void ExitProject()
{
    system("cls||clear");
    char ThankYou[] = " ========= Thank You =========\n";
    char SeeYouSoon[] = " ========= See You Soon ======\n";
    char crr[] = " >>>>>>>>>> Creator CYBERBDFIT \n";
    for (i = 0; i < strlen(ThankYou); i++)
    {
        printf("%c", ThankYou[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(SeeYouSoon); i++)
    {
        printf("%c", SeeYouSoon[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(crr); i++)
    {
        printf("%c", crr[i]);
        Sleep(40);
    }
    exit(0);
}

void DataSeed()
{
    // Student 1
    strcpy(Students[0].ID, "S-1");
    strcpy(Students[0].Name, "Alice");
    strcpy(Students[0].Phone, "9991111111");
    strcpy(Students[0].Email, "alice@mail.com");
    Students[0].NumberOfCourse = 2;

    strcpy(Courses[0].StudentID, "S-1");
    strcpy(Courses[0].Code, "CSE101");
    strcpy(Courses[0].Name, "Programming");

    strcpy(Courses[1].StudentID, "S-1");
    strcpy(Courses[1].Code, "CSE102");
    strcpy(Courses[1].Name, "Data Structures");

    // Student 2
    strcpy(Students[1].ID, "S-2");
    strcpy(Students[1].Name, "Bob");
    strcpy(Students[1].Phone, "9992222222");
    strcpy(Students[1].Email, "bob@mail.com");
    Students[1].NumberOfCourse = 1;

    strcpy(Courses[2].StudentID, "S-2");
    strcpy(Courses[2].Code, "CSE201");
    strcpy(Courses[2].Name, "DBMS");

    TotalStudents = 2;
    TotalCourse = 3;
}
