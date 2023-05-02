#include "login.c"

int main()
{
    char name[10], pass[10];
    int choice, ch, loginattempt = 0;

    do
    {
        system("cls");
        printf("\n\t\x1b[34m                    <<=============================================>>                    \x1b[0m  ");
        printf("\n\t\x1b[34m                    ||  WELCOME TO OUR LOGIN AND REGISTER PAGE     ||                    \x1b[0m  ");
        printf("\n\t\x1b[34m                    <<=============================================>>                  \x1b[0m\n\n");
        printf("                                                1.LOGIN                                          \n\n");
        printf("                                                2.EXIT                                           \n\n");

        printf("                                            Please select.... \n\n ");
        printf("\n\t                             [1] for LOGIN   [2] for EXIT : ");
        scanf("%d%*c", &choice);

        switch (choice)
        {
        case 1:
            login();
            break;

        case 2:
            exit(0);
            break;
        default:
            printf("                                     Invalid !!");
            break;
        }
        printf("\n                                       PRESS ENTER TO CONTINUE : ");
        scanf("%c%*c", &ch);
    } while (ch == '\n');
    
    return 0;
}