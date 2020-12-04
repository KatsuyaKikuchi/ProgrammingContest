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
ll P[10];
ll Q[10];
vector<vector<ll>> T;

void dfs(vector<ll> v) {
    if (v.size() == N) {
        T.push_back(v);
        return;
    }

    REP(i, N) {
        bool exist = false;
        REP(j, v.size()) {
            if (v[j] == i + 1)
                exist = true;
        }
        if (exist)
            continue;
        v.push_back(i + 1);
        dfs(v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> P[i];
    }
    REP(i, N) {
        cin >> Q[i];
    }

    vector<ll> v;
    dfs(v);

    ll a, b;
    REP(i, T.size()) {
        bool p = true;
        REP(j, N) {
            if (T[i][j] != P[j])
                p = false;
        }
        if (p)
            a = i;
        bool q = true;
        REP(j, N) {
            if (T[i][j] != Q[j])
                q = false;
        }
        if (q)
            b = i;
    }

    cout << abs(a - b) << endl;

    return 0;
}