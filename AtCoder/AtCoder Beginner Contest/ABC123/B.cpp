#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> v;

void dfs(vector<ll> t) {
    if (t.size() == 5) {
        v.push_back(t);
        return;
    }
    REP(i, 5) {
        bool exist = false;
        REP(j, t.size()) {
            if (t[j] == i)
                exist = true;
        }
        if (exist)
            continue;
        t.push_back(i);
        dfs(t);
        t.pop_back();
    }
}

ll A[10];

int main() {
    REP(i, 5) {
        cin >> A[i];
    }

    ll min = INF;
    vector<ll> vv;
    dfs(vv);
    REP(i, v.size()) {
        ll t = 0;
        REP(j, 4) {
            t += A[v[i][j]];
            t += (10 - (t % 10)) % 10;
        }
        t += A[v[i][4]];
        min = std::min(min, t);
    }
    cout << min << endl;
    return 0;
}