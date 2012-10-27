#include <stdio.h>
#include <stdlib.h>

#define N 100001

FILE *in;
FILE *out;

typedef struct list {
    int data;
    struct list *next;
};

struct list *v[N];
int viz[N];
int n, m;

void add(int x, int y)
{
    struct list *nou = (struct list*)malloc(sizeof(struct list));
    nou->data = y;
    nou->next = v[x];
    v[x] = nou;
}

void citire()
{
    int i, x, y;

    fscanf(in, "%d%d", &n, &m);

    for (i = 1; i <= m; i++) {
        fscanf(in, "%d %d", &x, &y);
        add(y, x);
        add(x, y);
    }
}

void DFS(int x)
{
    viz[x] = 1;
    struct list *p;

    for (p = v[x]; p != NULL; p = p->next) {
        if (!viz[p -> data]) {
            DFS(p -> data);
        }
    }
}

int main()
{
    in = fopen("dfs.in", "r");
    out = fopen("dfs.out", "w");

    citire();

    int i;
    int count = 0;

    for (i = 1; i <= n; i++) {
        if (!viz[i]) {
            count ++;
            DFS(i);
        }
    }

    fprintf(out, "%d\n", count);

    return 0;
}