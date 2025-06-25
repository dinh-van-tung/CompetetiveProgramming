/**
 *    ()_()                                ()_()
 *   ( o.o )  -> *Author: VanTungDinh <-  ( -.- )
 *    > ^ <                                (")(")
 *
 *   Last reviewed and updated: 2025/06/25
 *   Link submit: none
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
#define clz(x) __builtin_clzll((x)) /* count leading zeros */
#define ctz(x) __builtin_ctzll((x)) /* count trailing zeros */
#define ll long long
#define ull unsigned long long
#define ld long double
#define db double
#define pi acos(-1)
#define maxn 1005
#define mod 1000000007

int n, m, ans[maxn], indegree[maxn];
vector<int> graph[maxn], Topo;
queue<int> listSource;

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
            listSource.push(u);
            Topo.push_back(u);
        }
    }

    while (listSource.size()) {
        int u = listSource.front();
        listSource.pop();
        for (auto v : graph[u]) {
            indegree[v] -= 1;
            if (indegree[v] == 0) {
                listSource.push(v);
                Topo.push_back(v);
            }
        }
    }

    if (Topo.size() < n) {
        cout << -1 << '\n';
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
