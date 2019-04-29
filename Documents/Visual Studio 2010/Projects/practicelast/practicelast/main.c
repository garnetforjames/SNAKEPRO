#include "my_func.h"
#include "my_struct.h"
#include "my_define.h"



int count;


int main()
{
   student **st;
   int  input;
   int max_num;
   int i;
	count=0;

   printf("Max_num:");
   scanf("%d", &max_num);
   
   st = (student **)malloc(max_num*sizeof(student*));
   
   while(1)
   {
      printf("*****Menu*****\n");
      printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Regfromfile><6.Exit>\n");
      printf("Enter_the_menu_number:");
      scanf("%d", &input);

      switch(input)
      {
         case 1: 
				 registration(st, &count,max_num);
            
				break;

         case 2: print_all(st,count);	

				break;
         
		 case 3:Delete( st, &count); 
                 
			     break;
         case 4: 
				 FindByBirth( st, count);
				
				 break;
         case 5:
				regfromfile(st, &count,max_num);
				
				break;

		 case 6: save(st, &count); 
				 return 0;
      }

       }

  

   return 0;
}
void regfromfile(student **st, int *count,int max_num)
{
   FILE *fp;

   student *tmp;

   int i, j,k;
   char name[101];
   char phone[101];
   char birth[101];


   if(*count==max_num)
	{
		return ;
	}

   fp = fopen("PHONE_BOOK.txt", "r");

   
   while (!feof(fp) && (*count) < max_num)
   {
      fscanf(fp, "%s %s %s\n", name, phone, birth);
      st[*count] = (student *)malloc(sizeof(student));
      st[*count]->name = (char *)malloc(sizeof(char)*(strlen(name) + 1));
      st[*count]->phone = (char *)malloc(sizeof(char)*(strlen(phone) + 1));
      st[*count]->birth = (char *)malloc(sizeof(char)*(strlen(birth) + 1));
      strcpy(st[*count]->name, name);
      strcpy(st[*count]->phone, phone);
      strcpy(st[*count]->birth, birth);
      
      for (j = 0; j < *count; j++) {
         if (strcmp(st[j]->name, st[*count]->name) > 0) { // A < B
            tmp = st[*count];
            for (k = *count; k > j; k--) {
               st[k] = st[k - 1];
            }
            st[j] = tmp;
            break;
         }
      }
      (*count)++;
   }


   fclose(fp);


   
}

void save(student **st, int *count)
{	student *tmp;
   FILE *fp;
   int i,j,k;

   fp = fopen("PHONE_BOOK.txt", "w");


   for(i = 0; i < *count; i++)
   {
      fprintf(fp, "%s %s %s\n", st[i]->name, st[i]->phone, st[i]->birth);
   }

   fclose(fp);

    for(i = 0; i < *count; i++)
   {
      free(st[i]->name);
      free(st[i]->phone);
      free(st[i]->birth);
	  free(st[i]);
   }
   free(st);
}