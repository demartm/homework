#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

bool remove_extra(unsigned char* str) {
	if (str) {
		unsigned char Tab[256] = {0};
		int ix = 1;
		for (int i = 0; str[i] != '\0'; i++) {
			if (!Tab[str[i]]) {
				Tab[str[i]] = ix;// +1;
				ix++;
			}
		}
		int size = sizeof(Tab);
		ix = 0;

		for (int i = 0; i < size; i++) {
			if (Tab[i]) {
				str[Tab[i] - 1] = (unsigned char)i;
				ix++;
			}
		}
		str[ix] = '\0';

		return true;
	}

	return false;
}



int main() {
	setlocale(LC_ALL, "Russian");
	unsigned char mass[] = "qwwwweeeerrrrrtttttyyyyyoooo";//qwertyo
	//unsigned char mass[] = "qwwwweeeerrrrrtttttwwwwwwwwwyyyyyoooo";//qwertyo

	//unsigned char mass[] = "qwertyuiop";//qwertyuiop
	//unsigned char mass[] = "{}:?><<>><>>?>:{>:>{::>";//{}:?><
	//unsigned char mass[] = "йййййцукенгшщз";//йцукенгшщз
	//unsigned char mass[] = "йййййййqqqqqqqqqцукенгшщз"//йqцукенгшщз
	if (remove_extra(mass)) {//NULL->invalid pointer

		printf("%s", mass);
	}
	else {
		printf("invalid pointer");
	}


}