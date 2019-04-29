#include "MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"


void registration(student **st, int *count,int max_num)
{
   student *tmp;
   char name[101];
   char phone[101];
   char birth[101];
   int i=(*count),location=(*count), j,k;
   

   if(*count>=max_num)
	{
		printf("OVERFLOW\n");
		return ;
	}
   st[i] = (student *)malloc(sizeof(student));

   
   //st = (student *)realloc(st, (*count)*sizeof(student));
   printf("Name:");
   scanf("%s", name);
   st[i]->name = (char *)malloc(sizeof(char)*(strlen(name)+1));
   strcpy(st[i]->name, name);

   printf("Phone_number:");
   scanf("%s", phone);
   st[i]->phone = (char *)malloc(sizeof(char)*strlen(phone)+1);
   strcpy(st[i]->phone, phone);

   printf("Birth:");
   scanf("%s", birth);
   st[i]->birth = (char *)malloc(sizeof(char)*strlen(birth)+1);
   strcpy(st[i]->birth, birth);
   

 for (j = 0; j < *count; j++) {
      if (strcmp(st[j]->name, st[i]->name) > 0) { // A < B
         tmp = st[i];
         for (k = i; k > j; k--) {
            st[k] = st[k - 1];
         }
         st[j] = tmp;
         break;
      }
   }

   (*count)++;


   printf("<<%d>>\n", *count);

}