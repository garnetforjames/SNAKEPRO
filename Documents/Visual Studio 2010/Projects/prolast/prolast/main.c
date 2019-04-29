#include"MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
         
		 case 3:Delete( st, &count); //delete the person
                 
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







