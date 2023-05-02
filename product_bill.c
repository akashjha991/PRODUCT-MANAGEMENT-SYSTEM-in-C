#include "header.h"

void bill()
{
   FILE *fileptr = fopen("storage.bin", "rb+");
   FILE *fptr = fopen("tempstorage.bin", "rb+");
   product p1;
   int i = 1, id, quan, total = 0;
   char ch, name[20];
   int billamount = 0;

   while (1)
   {
      printf("                                  Enter product NAME : ");
      scanf("%[^\n]s%*c", &name);
      rewind(fileptr);
      while (fread(&p1, sizeof(product), 1, fileptr))
      {

         if (strcmp(p1.name, name) == 0)
         {
            printf("                            Enter quantity : ");
            scanf("%d%*c", &quan);
            if (p1.quantity >= quan)
            {
               printf("------------------------------------------------------------------------------------------------------\n");
               printf("\x1b[32m|%-15s   |   %-15s   |   %-15s  |    %-15s  |   %-15s  |\n", "S.NO", "ID", "PRODUCT NAME", "PRICE", "QUANTITY\x1b[0m");
               printf("------------------------------------------------------------------------------------------------------\n");

               printf("|%-15d   |   %-15d   |   %-15s  |    %-15f  |   %-13d| \n", i, p1.id, p1.name, p1.price, p1.quantity);
               printf("------------------------------------------------------------------------------------------------------\n");
               p1.quantity--;
               i++;
               total = total + (p1.price * quan);
               fseek(fileptr, -sizeof(product), 1);
               fwrite(&p1, sizeof(product), 1, fptr);
               break;
            }
            else
            {
               printf("quantity not available !\n");
            }
         }
      }
      printf("            press T to generate bill  ");
      scanf("%c%*c", &ch);
      if (ch == 'T')
      {
         break;
      }
   }

   fclose(fileptr);
   fclose(fptr);
   printf("                                                              Total %d", total);
}