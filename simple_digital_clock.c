#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        time_t rawtime;
        struct tm *timeinfo;

        // getting current time
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // clear terminal
        // system("clear"); use for mac or linux
        system("cls"); // use "cls" for windows Windows

        // display clock
        printf("\n==================== DIGITAL CLOCK ====================\n");
        printf(" Time : %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        printf(" Date : %02d-%02d-%04d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);

        // day of week
        char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        printf(" Day  : %s\n", days[timeinfo->tm_wday]);

        printf("=======================================================\n");
        printf("CREATED BY CYBERBADFIT");

            sleep(1);
    }
    return 0;
}
