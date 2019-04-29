#include <stdio.h>
#include <stdlib.h>

void down(int heap[], int current, int end);
void heap_sort(int heap[],int start,int end);
void print(int heap[],int leng);
int main() {

	int i,LENGTH;
	int heap[1000];
	scanf("%d",&LENGTH);
	for (i = 0; i < LENGTH; i++)
		{scanf("%d",&heap[i]);

	}

	heap_sort(heap, 1, LENGTH );
	print(heap,LENGTH);

	return 0;
}

void print(int heap[],int leng){
	int i;

	for(i=1;i<=leng;i++){
		printf(" %d",heap[i]);
	}


}
void down(int heap[], int current, int end) {
	int left, right, max;
	int temp;
	
	left = (current + 1) * 2-1 ;
	
	if (left > end) return;
	
	right = left + 1;
	
	max = (right > end) ? left : (heap[left] > heap[right]) ? left : right;
	
	if (heap[current] > heap[max]) return;
	
	temp = heap[current];
	heap[current] = heap[max];
	heap[max] = temp;
	down(heap, max, end);
}


void heap_sort(int heap[], int start, int end) {
	int i;
	int temp;
	
        for (i = end / 2; i >= 0; i--)
		down(heap, i, end);
	
        for (i = 0; i < end; i++) {
		temp = heap[0];
		heap[0] = heap[end - i];
		heap[end - i] = temp;
		down(heap, 0, end - i - 1);
	}
}



