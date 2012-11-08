#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 400005
#define INF 1005

using namespace std;

ifstream in ("apm.in");
ofstream out ("apm.out");

struct Muchie {
    int varf;
    int cost;
};

vector <Muchie> a[N];
priority_queue <pair <int, int> > heapMinim;

int n, m;
int d[N];
int marcat[N];
int cost = 0;
int pred[N];

Muchie makeMuchie(int x, int y)
{
    Muchie muchie;
    muchie.varf = x;
    muchie.cost = y;
    return muchie;
}

void citire()
{
    in >> n >> m;
    int x, y, c;
    while (m--) {
        in >> x >> y >> c;
        a[x].push_back(makeMuchie(y, c));
        a[y].push_back(makeMuchie(x, c));
    }
}

int main()
{
    citire();

    d[1] = 0;

    for (int i = 2; i <= n; i++) {
        d[i] = INF;
    }
    heapMinim.push(make_pair(0, 1));
    for (int i = 1; i <= n; i++) {
        while (marcat[heapMinim.top().second]) {
            heapMinim.pop();
        }
        int x = heapMinim.top().second;
        cost += heapMinim.top().first;
        heapMinim.pop();
        marcat[x] = 1;

        for (int i = 0; i < a[x].size(); i++) {
            int distanta = a[x][i].cost;
            if (distanta < d[a[x][i].varf] and !marcat[a[x][i].varf]) {
                d[a[x][i].varf] = distanta;
                pred[a[x][i].varf] = x;
                heapMinim.push(make_pair(-distanta, a[x][i].varf));
            }
        }
    }

    out << -cost << "\n" << n - 1 << "\n";

    for (int i = 2; i <= n; i++) {
        out << i << " " << pred[i] << "\n";
    }

    return 0;
}