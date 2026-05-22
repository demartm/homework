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
		for (int j = 0; j < N; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n===================\n\n\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n\n");
		for (int j = i+1; j < N; j++) {
			printf("%d ", mas[j][N - 1 - i]);
		}
		printf("\n\n\n\n");
	}


}