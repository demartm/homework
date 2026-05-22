#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int str_to_bv(char* str) {
	if (str) {
		unsigned int res = 0;
		unsigned int mask = 1;
		for (int i = 0; str[i] != '\0'; i++) {
			res = res << 1;
			if (str[i] == '1') {
				res = res | mask;
			}
			

		}
		return res;
	}
	return 0;
}

bool is_compl(unsigned int a, unsigned int b) {
	return (a & ~b) && (~a & b);
}

int main() {
	char str1[9] = "00000101";
	char str2[9] = "00000010";//true

	//char str1[9] = "00000000";
	//char str2[9] = "00000010";//false

	//char str1[9] = "00000000";
	//char str2[9] = "00000000";//false

	//char str1[9] = "11111111";
	//char str2[9] = "11111111";//false


	//char str1[9] = "11111111";
	//char str2[9] = "00000000";//false


	//char str1[9] = "11111111";
	//char str2[9] = "00000010";//false

	unsigned int a = str_to_bv(str1);
	unsigned int b = str_to_bv(str2);
	//printf("%d\n", a);
	if (is_compl(a, b)) {
		printf("true");
	}
	else {
		printf("false");
	}
}
