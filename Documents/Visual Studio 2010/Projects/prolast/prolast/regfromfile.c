#include "MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"

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