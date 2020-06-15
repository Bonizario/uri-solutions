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
    if (x == parent[x]) return x;
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

/* Python 3 implementation <3
G = [0]*10000
S = [0]*10000

def Find(a):
    if G[a] == a:
        return a
    G[a] = Find(G[a])
    return G[a]

def Union(a, b):
    A = Find(a)
    B = Find(b)
    if A == B:
        return

    if (skills[a][0]>5 or skills[b][0]>5
        or skills[A][1] or skills[B][1]):
        skills[A][1] = True
        skills[B][1] = True

    if S[A] < S[B]:
        G[A] = B
        S[B] += S[A]
    else:
        G[B] = A
        S[A] += S[B]
*/

// 2657 - Sensate (URI Judge Online)
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dict;

int G[10000], S[10000];
pair<int,int> skills[10000];

int Find(int a) {
    if (G[a] == a) return a;
    return G[a] = Find(G[a]);
}

void Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return;
    if (skills[a].first>5 || skills[b].first>5 ||
        skills[A].second == true || skills[B].second == true) {
        skills[A].second = true, skills[B].second = true;
    }

    if (S[A] < S[B]) {
        G[A] = B;
        S[B] += S[A];
    } else {
        G[B] = A;
        S[A] += S[B];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n, m, q, skill;
    string name;
    cin >> n >> m >> q;

    for (i = 0; i < n; i++) {
        cin >> name >> skill;
        dict[name] = i;
        G[i] = i;
        S[i] = 1;
        skills[i] = make_pair(skill, false);
    }

    //cout << "\n\n\n";
    //for (auto &it : dict)
        //cout << it.first << " " << it.second << "\n";
    //cout << "\n\n\n";

    string p1, p2;
    for (i = 0; i < m; i++) {
        cin >> p1 >> p2;
        Union(dict[p1], dict[p2]);
    }

    int id, idParent;
    bool status;
    for (i = 0; i < q; i++) {
        cin >> name;
        id = dict[name];
        idParent = Find(id);

        //cout << "id: "<<id<<" parent: "<<idParent<<"\n";

        if (S[idParent]<2 || skills[id].first>=5)
            status = true;
        else if (!skills[idParent].second && !skills[id].second)
            status = true;
        else
            status = false;
        cout << (status ? "S\n" : "N\n");
    }

    return 0;
}
