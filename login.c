#include "main.c"

void login()
{
    system("cls");
    char user[20], pword[10], code[10];
    char pass[20];
    int flag = 0, i = 0, c = 0;

    do
    {

        printf("                              login to contnue\n\n");
        printf("\n                           ENTER YOUR USERNAME > ");
        scanf("%s", user);
        printf("\n                           ENTER YOUR PASSWORD > ");
        scanf("%s", pass);

        if ((strcmp(user, "robin") == 0) && (strcmp(pass, "709178") == 0))
        {
            printf("\n                           login successfully\n\n");
            printf("                             loading....");
            Sleep(2000);
            mainpage();
        }
        else
        {
            printf("                         INVALID username or password !!!");
            flag++;
        }
    } while (flag != 3);
    if (flag == 3)
    {
        system("cls");
        printf("                            LOGIN LIMIT EXCEEDED !!!! ");
    }
}