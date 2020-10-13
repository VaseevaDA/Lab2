#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void strfind(char* a, char* b) {
	
	int len=0;
	for (char* p = b; *p != '\n'; ++p) {
		len++;
	}
	int table[127] = { len };
	for (int i = 0; i < 127; i++) {
		table[i] = len;
	}
	for (char* p = b; *(p + 1) != '\n'; ++p)  {
		table[*p] = len-(p - b + 1);
	}
	for (int i = 0; i<(300-len) && a[i] != '\n'; ) {
		int flag = 1;
		for (int j = 0; b[j] != '\n'; ++j) {

			if ((a[i + j] != b[j]) || (i + j > 299)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d ", i);
		}
		i += table[a[i + len - 1]];
	}
}
int main() {
	char str1[300];
	char str2[300];
	fgets(str1, 300, stdin);
	fgets(str2, 300, stdin);
	strfind(str1, str2);
	return 0;
}
