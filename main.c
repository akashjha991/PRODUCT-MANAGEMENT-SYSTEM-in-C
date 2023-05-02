#include "addproduct.c"
#include "delete.c"
#include "view.c"
#include "edit_by_name.c"
#include "search.c"
#include "product_bill.c"

void mainpage()
{
    int choice, i = 10;
    char ch;
    do
    {

        system("cls");
        printf("\n\t\x1b[96m=============================================================================================\x1b[0m");
        printf("\n\t\x1b[31m                             WELCOME TO PRODUCT MANAGEMENT SYSTEM \x1b[0m");
        printf("\n\t\x1b[96m=============================================================================================\x1b[0m");

        printf("\n\n\t\x1b[34m============================================================================================\x1b[0m\n");
        printf("\n\t                                     1.ADD PRODUCT                                                         \n");
        printf("\n\t                                     2.DELETE PRODUCT                                                       \n");
        printf("\n\t                                     3.VIEW PRODUCT                                                         \n");
        printf("\n\t                                     4.EDIT PRODUCT                                                         \n");
        printf("\n\t                                     5.PRODUCT_BILL                                                         \n");
        printf("\n\t                                     5.EXIT                                                                 \n");
        printf("\n\t\x1b[34m==============================================================================================\x1b[0m\n");

        printf("\n\n                 PRESS [1] FOR ADD [ 2 ] FOR DELETE [ 3 ] FOR VIEW [ 4 ] FOR EDIT [ 5 ] FOR EXIT  : ");
        scanf("%d%*c", &choice);

        switch (choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            deleteproduct();
            break;
        case 3:
            viewproduct();
            break;
        case 4:
            editproduct();
            break;
        case 5:
            bill();
            break;
        case 6:
            printf("                                   Exiting system......\n");
            exit(0);
            break;
        default:
            printf("                                   Invalid Choice !!");
            exit(0);
            break;
        }
        printf("\n\n                                   presss Enter to continue.........  ");
        scanf("%c", &ch);
        printf(ANSI_COLOR_RESET "\x1b[0m");
    } while (ch == '\n');
}
