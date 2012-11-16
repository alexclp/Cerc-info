#include <fstream>
#include <cstdlib>

#define alb 0
#define gri 1
#define negru 2
#define N 50005

using namespace std;

struct list {
    int varf;
    list *next;
};

int color[N];
int n, m;
list *vecini[N], *adresa;

ifstream in ("sortaret.in");
ofstream out ("sortaret.out");

void add(int a, int b)
{
    list *p = new list;
    p -> varf = b;
    p -> next = vecini[a];
    vecini[a] = p;
}

void push (int nod)
{
    list *p = new list;
    p->varf = nod;
    p->next = adresa;
    adresa = p;
}

void dfs(int nod)
{
    color[nod] = gri;
    for (list *p = vecini[nod]; p ; p = p -> next) {
        if (color[p->varf] == alb) {
            dfs(p->varf);
        }
    }
    color[nod] = negru;
    push(nod);
}

void sortTop()
{
    for (int i = 1; i <= n; i++) {
        if (color[i] == alb) {
            dfs(i);
        }
    }
}

void read()
{
    in >> n >> m;
    int x, y;
    for ( ; m > 0; m --) {
        in >> x >> y;
        add (x, y);
    }
}

void write()
{
    for (list *p = adresa; p ; p = p->next) {
        out << p -> varf << " ";
    }
    out << "\n";
}

int main()
{
    read();
    sortTop();
    write();

    return 0;
}