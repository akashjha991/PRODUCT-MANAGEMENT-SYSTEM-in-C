#include "header.h"

void searchproduct()
{
    system("cls");
    printf(ANSI_COLOR_CYAN);
    FILE *fptr = fopen("storage.bin", "rb");
    FILE *tempfptr = fopen("tempstorage.bin", "wb");

    int id, flag = 0;
    printf("Enter product ID :");
    scanf("%d%*c", &id);

    product tempstr;

    while (fread(&tempstr, sizeof(product), 1, fptr))
    {
        if (tempstr.id == id)
        {
            printf("\x1b[32m%-15s   |   %-15s   |   %-15s  |    %-15s  |   %-15s   |\n", "S.NO", "ID", "PRODUCT NAME", "PRICE", "QUANTITY\x1b[0m");
            printf("%-15d   |   %-15d   |   %-15s  |    %-15f  |   %-13d | \n", tempstr.id, tempstr.name, tempstr.price, tempstr.quantity);

            fwrite(&tempstr, sizeof(product), 1, tempfptr);
            flag = 1;
        }

        else
        {
            fwrite(&tempstr, sizeof(product), 1, tempfptr);
        }
    }

    fclose(fptr);
    fclose(tempfptr);
    remove("storage.bin");
    rename("tempstorage.bin", "storage.bin");

    if (flag == 1)
    {
        printf("\n                                 Product edit successfully !!\n\n");
    }

    else
    {
        printf("\n                                 Product not found !!\n\n");
    }
    char ch;
    scanf("%c%*c", &ch);
    printf(ANSI_COLOR_RESET);
}