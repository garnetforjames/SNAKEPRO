#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
   char *name;
   char *phone;
   char *birth;
}student;

void registration(student **, int *,int);
void Delete( student **, int *);
void regfromfile(student **, int *,int);
void save(student **, int *);
void FindByBirth( student **, int);
void print_all(student **st,int count);

int main()
{
   student **st;
   int count = 0, input;
   int max_num;
   int i;
  

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

void print_all(student **st, int count) {
   int i;
   for (i = 0; i < count; i++)
      printf("%s %s %s\n", st[i]->name, st[i]->phone, st[i]->birth);
}



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