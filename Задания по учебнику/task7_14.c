#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void generateRandomMas(int mas[N][N]) {
	if (mas) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mas[i][j] = rand() % 101;
	}
}

int main() {
	int mas[N][N] = { 0 };
	int x[N] = { 0 };
	int y[N] = { 0 };
	int min[N] = { 0 };
	srand(time(0));
	generateRandomMas(mas);

	for (int i = 0; i < N; i++) {
		x[i] = i;
		min[i] = mas[i][0];
		for (int j = 0; j < N; j++) {
			if (mas[i][j] < min[i]) {
				min[i] = mas[i][j];
				y[i] = j;
			}
		}
	}

	int max = min[0];
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (max < min[i]) {
			max = min[i];
			num = i;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n\n%d %d", x[num]+1, y[num]+1);


}