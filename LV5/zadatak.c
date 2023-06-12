#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DG = -100000;
int GG = 100000;

void zamjena(int* a, int* b);
void uhrpi(int* V, int n, int i);
void heapSort(int* V, int n);
void bubbleSort(int* V, int n);
void ispisPolja(int* V, int n);

int main() {
    int n;
    time_t t1, t2;
    long int vrijeme;
    printf("Unesite broj elemenata polja: ");
    scanf_s("%d", &n);

    srand(time(NULL));

    int* V = (float*)malloc(n * sizeof(float));
    if (V == NULL) {
        return 1;
    }

    int* V2 = (float*)malloc(n * sizeof(float));
    if (V2 == NULL) {
        free(V);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        V[i] = DG + (float)rand() / RAND_MAX * (GG - DG);
    }

    for (int i = 0; i < n; i++) {
        V2[i] = V[i];
    }

    t1 = clock();
    heapSort(V, n);
    t2 = clock();
    vrijeme = t2 - t1;

    printf("Vrijeme heap sort: %lims\n", vrijeme);


    t1 = clock();
    bubbleSort(V2, n);
    t2 = clock();
    vrijeme = t2 - t1;

    printf("Vrijeme bubble sort: %lims\n", vrijeme);

    free(V);
    free(V2);
    return 0;
}

void zamjena(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void uhrpi(int* V, int n, int i) {
    int najveci = i;
    int lijevi = 2 * i + 1;
    int desni = 2 * i + 2;

    if (lijevi < n && V[lijevi] > V[najveci])
        najveci = lijevi;

    if (desni < n && V[desni] > V[najveci])
        najveci = desni;

    if (najveci != i) {
        zamjena(&V[i], &V[najveci]);
        uhrpi(V, n, najveci);
    }
}

void heapSort(int* V, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        uhrpi(V, n, i);

    for (int i = n - 1; i > 0; i--) {
        zamjena(&V[0], &V[i]);
        uhrpi(V, i, 0);
    }
}

void bubbleSort(int* V, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1])
                zamjena(&V[j], &V[j + 1]);
        }
    }
}

void ispisPolja(int* V, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    printf("\n");
}