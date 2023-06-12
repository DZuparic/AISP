#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gen_arr(float* V, int n);
int sekv_pret(float* V, int n, float x);
void sort(float* V, int n);
int bin_pret(float* V, int low, int high, int x);
void swap(int* a, int* b);

int main() {
	time_t t1, t2, t3, t4, t5, t6;
	float x = 10000000000000;
	int n;
	scanf("%d", &n);
	float dg = 5;
	float gg = 30000;
	srand((unsigned)time(NULL));

	float* V = NULL;
	V = (float*)calloc(n, sizeof(float));
	if (V == NULL)
		return 1;
	gen_arr(V, n);

	t1 = clock();
	int sek = sekv_pret(V, n, x);
	t2 = clock();

	
	t3 = clock();
	sort(V, n);
	t4 = clock();

	t5 = clock();

	int rez = bin_pret(V, 0, n - 1, x);

	t6 = clock();
	printf("Rezultat sekvencijalnog pretrazivanja: %d\n", sek);
	printf("Rezultat binarnog pretrazivanja: %d\n", rez);
	printf("Sekvencijalno pretrazivanje: %f ms\n", ((float)(t2)-(float)(t1)));
	printf("Sortiranje: %f ms\n", ((float)(t4)-(float)(t3)));
	printf("Binarno pretrazivanje: %f ms", ((float)(t6)-(float)(t5)));
	free(V);
	return 0;
}

void gen_arr(float* V, int n) {
	for (int i = 0; i < n; i++) {
		V[i] = i;
	}
}

void swap(float* a, float* b) {
	float t = *a;
	*a = *b;
	*b = t;
}


void sort(float* V, int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (V[j] < V[min])
				min = j;
		}
		swap(&V[i], &V[min]);
	}
}

int sekv_pret(float* V, int n, float x) {
	for (int i = 0; i < n; i++) {
		if (V[i] == x)
			return i;
	}
	return -1;
}

int bin_pret(float* V, int low, int high, int x) {
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (V[mid] == x)
			return mid;
		if (V[mid] > x)
			return bin_pret(V, 1, mid - 1, x);

		return bin_pret(V, mid + 1, high, x);
	}
	return -1;
}