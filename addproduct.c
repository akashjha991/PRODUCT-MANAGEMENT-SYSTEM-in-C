#include "header.h"
void addproduct()
{
    system("cls");
    printf("____________________________ ADD PRODUCT DETAILS ____________________________\n\n");
    product p1;
    FILE *fileptr;
    fileptr = fopen("storage.bin", "ab");

    printf("\n              Enter Product ID :- ");
    scanf("%d%*c", &p1.id);
    printf("\n              Enter product NAME :- ");
    scanf("%[^\n]%*c", &p1.name);
    printf("\n              Enter product PRICE :- ");
    scanf("%f", &p1.price);
    printf("\n              Enter product QUANTITY :- ");
    scanf("%d", &p1.quantity);
    fwrite(&p1, sizeof(product), 1, fileptr);
    fclose(fileptr);
    printf("\n                       Product added successfully !!!\n\n");
}