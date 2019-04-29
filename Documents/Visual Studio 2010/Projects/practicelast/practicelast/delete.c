#include "my_define.h"
#include "my_func.h"
#include "my_struct.h"


void Delete( student **st, int *count)
{
   student *tmp2;
   int i, j, idx;
   int flag=0;
   char temp[100];
   if(*count == 0)
		{
			printf("NO MEMBER\n");
			return;		
		}
   
   printf("Name:");
   
   scanf("%s",temp);



   for(i=0;i<*count;i++)
   {
      if(strcmp(temp , st[i]->name)==0)
      {	 flag=1;
         tmp2=st[i];
         for(j=i+1;j<*count;j++)
            st[j-1]=st[j];
         st[*count-1]=tmp2;
		 (*count)--;
        
      }
   }


   if(flag==1||*count==0){
   free(st[*count]->name);
   free(st[*count]->birth);
   free(st[*count]->phone);
   free(st[*count]);
   }



   
}

void FindByBirth( student **st, int count)
{
   int i, num;
   int N;
	 printf("Birth:");
	 scanf("%d", &N);


   for(i=0;i<count;i++){
      num=0;
      num=(st[i]->birth[4]-'0')*10+(st[i]->birth[5]-'0');
      if(N==num)
         printf("%s %s %s\n",st[i]->name,st[i]->phone,st[i]->birth);
   }
}