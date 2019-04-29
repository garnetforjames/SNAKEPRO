#include<stdio.h>

int main() {
	int x, y, z,t;
	int *px, *py, *pz;
	x=*px , y=*py, z = *pz;
	scanf("%d %d %d", px, py, pz);
	t = *px;
	*px = *pz;
	*py = t;
	*pz = *py;
	printf("%d %d %d", *px, *py, *pz);





	return 0;
}