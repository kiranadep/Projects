#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define ENTER 13
#define BKSP 8
#define TAB 9
#define SPACE 32

void signup(void);
void login(void);

struct
{
    char name[100], pwd[100];
} a;
FILE *fp;

int main()
{
    int k;

    while (1)
    {

        printf("\n\n\t\t\t\t____________Welcome Here____________\n");

        printf("\n\t\t\t\t_________Select Your Choice_________ \n");

        printf("\n\t\t\t\t\t__Press s For Signup__\n");

        printf("\n\t\t\t\t\t__Press l For Login__\n");

        printf("\n\t\t\t\t\t__Press e For Exit__\n");

        printf("\n\t\t\t\t___*******_____***********_____*******__\n");
        Sleep(1000); //--> it will consider as 1000 MILLISEC = 1 SEC

        k = getch();
        switch (k)

        {
        case 's':
            signup();
            break;

        case 'l':

            login();
            break;

        case 'e':
            // if(remove(fp)==0)
            exit(1);
            break;

        default:
            printf("\n\t\t\t\t\tchoice correct choice :\n\n\n");
            break;
        }
    }
}
// from here file writing
void signup()
{
    int ch;
    char name[20], pwd[20];

    int i = 0;

    fp = fopen("new.txt", "w");

    printf("\n\n\t\t\t\t_________________signup_________________\n");
    Sleep(1000);

    printf("\n\t\t\t\t\tEnter name :");
    gets(a.name);

    printf("\n\t\t\t\t\tEnter Password :");
    while (1) //------> READ CHARACTER BY CHARACTER
    {
        ch = getch();
        if (ch == ENTER)
        {
            a.pwd[i] = '\0'; // EXIT FROM THE LOOP
            break;
        }
        else if (ch == BKSP)
        {
            if (i > 0)
            {
                i--;
                printf("\b  \b"); // a b c d _
            }                     // 0 1 2 3 4
        }
        else if (ch == SPACE || ch == TAB)
        {
            continue;
        }
        else
        {
            a.pwd[i] = ch;
            i++;
            printf("*");
        }
    }
    printf("\n\n\t\t\t\tInformation Saving ");

    for (int j = 0; j < 5; j++)
    {
        printf(". ");
        Sleep(750);
    }

    fputs(a.name, fp);
    fputs(a.pwd, fp);
    fclose(fp);
}

void login()
{
    int ch;
    char name[20], pwd[20];

    char usn[20], wd[20];

    printf("\n\n\t\t\t\t_______________Login Zone_______________\n");
    Sleep(1000);

    // form here file reading

    fp = fopen("new.txt", "r");
    if (fp == NULL)
    {
        printf("please Sign up First...");
        signup();
    }
    else
    {
        fscanf(fp, "%d %d", a.name, a.pwd);
        printf("\n\t\t\t\t\tEnter Username :");
        gets(usn);
        printf("\n\t\t\t\t\tEnter Possword :");
        gets(wd);
        if ((strcmp(a.name, usn) == 0) && (strcmp(a.pwd, wd) == 0))
        {
            Sleep(1000);
            printf("\n\n\n\t\t_________________________login Access Granted_________________________\n");
            Sleep(1000);
            printf("\n\n\t\t____________________hello %s welcome to Your System___________________\n\n", a.name);
            Sleep(5000);
        }

        else
        {
            if ((strcmp(a.name, usn) == !0) && (strcmp(a.pwd, wd) == !0))
            {
                printf("\n\n\t\t\t\tthe Username and Password both are Incorrect.....");
                Sleep(2000);
            }

            else if (strcmp(a.name, usn) == !0)
            {

                printf("\n\n\t\t\t\tthe username is incorrect.....");
                Sleep(2000);
            }
            else if (strcmp(a.pwd, wd) == !0)
            {
                printf("\n\n\t\t\t\tthe Password is incorrect....");
                Sleep(2000);
            }
            else
            {
                Sleep(2000);
                printf("\n\n\t\t\t\tYOU HAVE NOT SIGNED YET \n\n\t\t\t\tPLEASE DO SIGNUP ");
                Sleep(3000);
            }
        }
    }

    fclose(fp);
}
