#include "header.h"

void editproduct()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW);
    FILE *fptr = fopen("storage.bin", "rb+");

    int id, flag = 0, size = sizeof(product);
    char name[20];
    product tempstr;

    printf("\n                                 Enter product NAME :");
    scanf("%[^\n]s%*c", &name);

    while (fread(&tempstr, sizeof(product), 1, fptr) == 1)
    {
        if (strcmp(tempstr.name, name) == 0)
        {
            printf("                                   Product record found !! \n\n");
            printf("\x1b[32m%-15s   |   %-15s   |   %-15s  |    %-15s  |   %-15s   |\n", "S.NO", "ID", "PRODUCT NAME", "PRICE", "QUANTITY\x1b[0m");
            printf("%-15d   |   %-15d   |   %-15s  |    %-15f  |   %-13d | \n", tempstr.id, tempstr.name, tempstr.price, tempstr.quantity);

            printf("================== ENTER NEW RECORD ==================\n");
            printf("Enter new product ID :");
            scanf("%s%*c", &id);

            printf("                                   Enter product name : ");
            scanf("%[^\n]%*c", &tempstr.name);

            printf("                                   Enter product price : ");
            scanf("%f", &tempstr.price);

            printf("                                   Enter product quantity : ");
            scanf("%d", &tempstr.quantity);
            fseek(fptr, -size, 1);

            fwrite(&tempstr, sizeof(product), 1, fptr);
            flag = 1;
            break;
        }
    }
    fclose(fptr);
    if (flag == 1)
        printf("\n                                 Record Modified \n");
    else
        printf("\n                                 Product not found in file \n");
    printf(ANSI_COLOR_RESET);
}
