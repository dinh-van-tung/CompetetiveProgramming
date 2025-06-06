/*
     ()_()                                  ()_()
    ( o.o )  -> *Author: Van Tung Dinh <-  ( -.- )
     > ^ <                                  (")(")
    -> Link submit: https://www.spoj.com/problems/TOPOSORT/
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define ff(i, a, b, j) for (int i = (a), bb = (b), jj = (j); i <= bb; i += jj)
#define rf(i, a, b, j) for (int i = (a), bb = (b), jj = (j); i >= bb; i -= jj)
#define lshift(x, i) ((x) << (i))
#define rshift(x, i) ((x) >> (i))
#define checkbit(x, i) (((x) >> (i)) & 1ll)
#define cnt_bit1(x) __builtin_popcountll((x))
#define clz(x) __builtin_clzll((x)) // count leading zeros
#define ctz(x) __builtin_ctzll((x)) // count trailing zeros
#define ll long long
#define ull unsigned long long
#define ld long double
#define db double
#define pi acos(-1)
#define maxn 10005
#define mod 1000000007

int n, m, indegree[maxn];
vector<int> graph[maxn], Topo, temp;
queue<int> listSource;

vector<int> MergeSort(vector<int> a, vector<int> b) {
    vector<int> res;
    int pa = 0, pb = 0;
    while (pa < a.size() && pb < b.size()) {
        if (a[pa] <= b[pb]) {
            res.push_back(a[pa]);
            pa += 1;
        }
        else if (a[pa] > b[pb]) {
            res.push_back(b[pb]);
            pb += 1;
        }
    }

    ff (i, pa, a.size() - 1, 1) {
        res.push_back(a[i]);
    }

    ff (i, pb, b.size() - 1, 1) {
        res.push_back(b[i]);
    }

    return res;
}

void input() {
    cin >> n >> m;
    ff (i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v] += 1;
    }
    return;
}

void solve() {
    ff (u, 1, n, 1) {
        if (indegree[u] == 0) {
            temp.push_back(u);
        }
    }

    for (auto x : temp) {
        listSource.push(x);
        vector<int> TopoTemp;
        TopoTemp.push_back(x);

        while (listSource.size()) {
            int u = listSource.front();
            sort(graph[u].begin(), graph[u].end());
            listSource.pop();
            for (auto v : graph[u]) {
                indegree[v] -= 1;
                if (indegree[v] == 0) {
                    listSource.push(v);
                    TopoTemp.push_back(v);
                }
            }
        }
        Topo = MergeSort(TopoTemp, Topo);
    }

    if (Topo.size() < n) {
        cout << "Sandro fails." << '\n';
        return;
    }

    for (auto x : Topo) {
        cout << x << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case = 1;
//    cin >> test_case;
    ff (i, 1, test_case, 1) {
        input();
        solve();
    }
    return 0;
}
/*
     ()_()                                  ()_()
    ( o.o )  -> *Author: Van Tung Dinh <-  ( -.- )
     > ^ <                                  (")(")
    -> Link submit: https://www.spoj.com/problems/TOPOSORT/
*/
