#include <stdio.h>

#define MAX 100

typedef struct Stog{
    int V[MAX];
    int sp;
}Stog;

void init(Stog *s);
void clear(Stog *s);
int is_empty(Stog *s);
void push(Stog *s, int x);
int pop(Stog *s);

int main(void) {
    int m, n, r=0, povrh = 0;
    Stog s1, s2;
    init(&s1);
    init(&s2);
    push(&s1, 40); push(&s2, 20);
    do {
        n = pop(&s1);
        m = pop(&s2);
        if (n == m || m == 0)povrh++;
        else {
            push(&s1, n - 1); push(&s2, m - 1);
            push(&s1, n - 1); push(&s2, m);
        }
        r = is_empty(&s1);
    } while (r != 1);

    printf("Rez = %d\n", povrh);

    return 0;
}

void init(Stog *s) {
    s->sp = -1;
}

void clear(Stog *s) {
    if (s->sp >= 0) {
        while (s->sp >= 0) {
            s->V[s->sp] = NULL;
            s->sp--;
        }
    }
    else printf("Stack is empty.");
}

int is_empty(Stog *s) {
    if (s->sp < 0) {
        return 1;
    }
    else return 0;
}

void push(Stog *s, int x) {
    if (s->sp >= MAX) {
        printf("Stack overfloww");
    }
    else {
        s->sp++;
        s->V[s->sp] = x;
    }
}

int pop(Stog *s) {
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