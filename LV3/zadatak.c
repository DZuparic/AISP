#include <stdio.h>
#include <time.h>

#define MAX 100

typedef struct Stog {
    int V[MAX];
    int sp;
}Stog;

void init(Stog* s);
void clear(Stog* s);
int is_empty(Stog* s);
void push(Stog* s, int x);
int pop(Stog* s);

int povrhRekurzija(int a, int b);

int main(void) {

    time_t pocetakStog, krajStog, pocetakRekurzija, krajRekurzija;
    int a = 13, b = a/2;
    int m, n, r = 0, povrhStog = 0;
    Stog s1, s2;
    init(&s1);
    init(&s2);

    pocetakStog = clock();

    push(&s1, a); push(&s2, b);
    do {
        n = pop(&s1);
        m = pop(&s2);
        if (n == m || m == 0)povrhStog++;
        else {
            push(&s1, n - 1); push(&s2, m - 1);
            push(&s1, n - 1); push(&s2, m);
        }
        r = is_empty(&s1);
    } while (r != 1);

    krajStog = clock();

    pocetakRekurzija = clock();
    int rekurzija = povrhRekurzija(a, b);
    krajRekurzija = clock();


    printf("Rez [rekurzija] = %d\n", rekurzija);
    printf("Vrijeme [rekurzija]: %fms\n", (float)(krajRekurzija)-(float)(pocetakRekurzija));

    printf("Rez [stog] = %d\n", povrhStog);
    printf("Vrijeme [stog]: %fms\n", (float)(krajStog)-(float)(pocetakStog));

    return 0;
}

void init(Stog* s) {
    s->sp = -1;
}

void clear(Stog* s) {
    if (s->sp >= 0) {
        while (s->sp >= 0) {
            s->V[s->sp] = NULL;
            s->sp--;
        }
    }
    else printf("Stack is empty.");
}

int is_empty(Stog* s) {
    if (s->sp < 0) {
        return 1;
    }
    else return 0;
}

void push(Stog* s, int x) {
    if (s->sp >= MAX) {
        printf("Stack overfloww");
    }
    else {
        s->sp++;
        s->V[s->sp] = x;
    }
}

int pop(Stog* s) {
    if (s->sp < 0) {
        printf("Stack underflow.");
        return -1;
    }
    else {
        int x = s->V[s->sp];
        s->V[s->sp] = NULL;
        s->sp--;
        return x;
    }
}

int povrhRekurzija(int a, int b) {
    if (a == b || b == 0) return 1;
    return povrhRekurzija(a - 1, b - 1) + povrhRekurzija(a - 1, b);
}