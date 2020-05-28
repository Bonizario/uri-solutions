/*
    Union-find algorithm used with the disjointed-set data structure
    and Kruskal's algorithm.
*/
#include <iostream>
#define MAXN 100001
// MAXN is the number of nodes

using namespace std;

// quantity[MAXN] can be another param from the exercise description
int parent[MAXN], weight[MAXN], quantity[MAXN];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x]);  // path compression
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (weight[x] < weight[y]) {
        parent[x] = y;
        quantity[y] += quantity[x];
    } else if (weight[y] < weight[x]) {
        parent[y] = x;
        quantity[x] += quantity[y];
    } else {
        parent[y] = x;
        quantity[x] += quantity[y];
        weight[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* code */
    return 0;
}
