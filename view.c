#include "header.h"

void viewproduct()
{
	system("cls");
	printf(ANSI_COLOR_RESET);
	int i = 1;
	product vp;

	FILE *ptr = fopen("storage.bin", "rb");
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("\x1b[32m|%-15s   |   %-15s   |   %-15s  |    %-15s  |   %-15s  |\n", "S.NO", "ID", "PRODUCT NAME", "PRICE", "QUANTITY\x1b[0m");
	printf("------------------------------------------------------------------------------------------------------\n");
	while (fread(&vp, sizeof(product), 1, ptr))
	{
		printf(ANSI_COLOR_MAGENTA);
		printf("|%-15d   |   %-15d   |   %-15s  |    %-15f  |   %-13d| \n", i, vp.id, vp.name, vp.price, vp.quantity);
		i++;
	}
	printf("------------------------------------------------------------------------------------------------------\n");
	fclose(ptr);
	printf(ANSI_COLOR_RESET);
}
