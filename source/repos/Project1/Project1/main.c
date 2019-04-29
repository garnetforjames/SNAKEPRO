#include<stdio.h>

int main() {
	int arr[100];
	int i = 0, k, sum = 0, flag = 0, j, cnt;
	int long n;
	scanf("%d", &n);
	while (1) {
		arr[i] = n % 10;
		sum += arr[i];
		n = n / 10;
		if (n == 0) { break; }
		i++;
	}
	k = i;
	if (i % 2 == 0) {
		cnt = i + 2;
	}
	else
		cnt = i + 1;
	for (i = 0, j = k; i <= j; i++, j--) {
		if (arr[i] == arr[j]) {
			flag++;
		}
	}
	printf("%d\n", sum);
	if (flag == (cnt) / 2) {
		printf("yes");
	}
	else
		printf("No");
	return 0;
}