#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char s[200];
	char d[200];
	fgets(s, 200, stdin);
	fgets(d, 200, stdin);
	for (int i = 0; s[i] != '\n'; ++i) {
		int flag = 1;
		for (int j = 0; d[j] != '\n'; ++j) {
			
			if ((s[i + j] != d[j]) || (i+j>199)) {
				flag = 0;
				break;
			}

		}
		if (flag) {
			printf("%d ", i);

		}
	}
	return 0;
}