#include "MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"




void save(student **st, int *count)
{ 
   student *tmp;
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