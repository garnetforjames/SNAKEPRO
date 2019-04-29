#include "MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"


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