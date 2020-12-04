#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;

void dfs(vector<ll> v) {
    if (v.size() == N) {
        REP(i, N) {
            cout << v[i] + 1;
            if (i < N - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }

    REP(i, N) {
        bool e = false;
        REP(j, v.size()) {
            if (v[j] == i)
                e = true;
        }
        if (e)
            continue;
        v.push_back(i);
        dfs(v);
        v.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs(vector<ll>());
    return 0;
}