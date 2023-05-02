#include "header.h"

void deleteproduct()
{
    system("cls");
    FILE *fptr, *tempptr;
    char ch;
    product tempprod;
    fptr = fopen("storage.bin", "rb");
    tempptr = fopen("tempstorage.bin", "wb");
    int id, flag = 0;
    printf("\n                                 Enter product ID which you want to delete : ");
    scanf("%d", &id);

    while (fread(&tempprod, sizeof(product), 1, fptr))
    {
        if (tempprod.id != id)
        {
            fwrite(&tempprod, sizeof(product), 1, tempptr);
        }

        else
        {
            flag = 1;
        }
    }

    fclose(fptr);
    fclose(tempptr);
    remove("storage.bin");
    rename("tempstorage.bin", "storage.bin");
    if (!flag)
    {
        printf("                                   Product not found !!");
    }

    else
    {
        printf("                                   Product deleted successfuly\n\n");
    }

    scanf("%c", &ch);
}
