#include <stdio.h>
#include <stdlib.h>

 

void add(int*, int**);

 

int main(void){
     int size = 5;
     int* arr = (int*)malloc(sizeof(int)*size); //���̰� 5�� �迭 ����
     int i = 0;
	 int j;
 

     //-1�� �Էµ� �� ���� ���ѷ���
     while (1){
       //   printf("������ �Է��ϼ��� : ");
          scanf("%d", &arr[i]);

 

          //����� �Է°��� -1�̸� �ݺ��� Ż��
          if (arr[i] == -1)
              
			  break;

          //i+1��°�� size�� ������ add�Լ��� ȣ��
          if (i + 1 == size)
           add(&size, &arr);

 

          i++;
     }

 

     for ( j = 0; j <= i; j++)
          printf(" %d",  arr[j]);

 

     free(arr);

     return 0;
}

 

//�迭�� ũ�⸦ ������Ű�� �Լ�
void add(int* s, int** ar){
	int i;
     int newsize = *s + 3; //size�� ũ�⸦ 3 ������Ŵ

     //main�� arr���� ���̰� 3�� �迭 ����
     int* temp = (int*)malloc(sizeof(int)*newsize);

 

     //ar�� ���� temp�� ����
     for ( i = 0; i < *s; i++)
          temp[i] = (*ar)[i];

 

     free(*ar); //���� �迭 ����

     *ar = temp;
     *s += 3; //main�� size�� 3������Ŵ
}


