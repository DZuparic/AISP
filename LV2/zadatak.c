#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct OE_ {
	float x;
	struct OE_* sljedeci;
}OE;

OE* prvi = NULL;

void kreiraj_polje(float* V, int n, float dg, float gg);
int pretrazivanjeListe(OE* head, int trazeniElement);
int sekv_pret(float* V, int n, float x);

void main() {

	time_t pocetakLista, krajLista, pocetakPolje, krajPolje, pocetakPretrazivanja, krajPretrazivanja, pocetakSek, krajSek;
	OE* novi;
	int n;
	float trazeniElement = 505;
	float dg = 5;
	float gg = 500;

	scanf("%d", &n);

	float* V = NULL;
	V = (float*)calloc(n, sizeof(float));
	if (V == NULL) {
		return 1;
	}
	srand((unsigned)time(NULL));
	pocetakPolje = clock();
	kreiraj_polje(V, n, dg, gg);
	krajPolje = clock();

	pocetakLista = clock();
	for (int i = 0; i < n; i++) {
		novi = (OE*)malloc(sizeof(OE));
		novi->x = V[i];
		novi->sljedeci = prvi;
		prvi = novi;
	}
	krajLista = clock();

	pocetakSek = clock();
	int rezSek = sekv_pret(V, n, trazeniElement);
	krajSek = clock();

	pocetakPretrazivanja = clock();
	int rez = pretrazivanjeListe(prvi, trazeniElement);
	krajPretrazivanja = clock();

	printf("Kreiranje polja: %fms", ((float)(krajPolje)-(float)(pocetakPolje)));
	printf("\nKreiranje liste: %fms", ((float)(krajLista)-(float)(pocetakLista)));
	printf("\nRezultat pretrazivanja polja: %d", rezSek);
	printf("\nPretrazivanje polja: %fms", ((float)(krajSek)-(float)(pocetakSek)));
	printf("\nRezultat pretrazivanja liste: %d", rez);
	printf("\nPretrazivanje liste: %fms", ((float)(krajPretrazivanja)-(float)(pocetakPretrazivanja)));
	return 0;
}

void kreiraj_polje(float* V, int n, float dg, float gg) {
	for (int i = 0; i < n; i++) {
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg);
	}
}

int pretrazivanjeListe(OE* head, int trazeniElement) {
	OE* trenutni = head;
	int i = 0;
	while (trenutni != NULL) {
		if (trenutni->x == trazeniElement) {
			return i;
		}
		trenutni = trenutni->sljedeci;
		i++;
	}
	return -1;
}

int sekv_pret(float* V, int n, float x) {
	for (int i = 0; i < n; i++) {
		if (V[i] == x)
			return i;
	}
	return -1;
}