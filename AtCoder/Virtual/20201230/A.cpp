#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
ll N;

ll dfs(vector<ll> v) {
    if (v.size() == N) {
        bool b = false;
        REP(i, N) {
            if (v[i] % 2 == 0)
                b = true;
        }
        if (b)
            return 1;
        return 0;
    }
    ll ret = 0;
    ll index = v.size();
    {
        v.push_back(A[index] - 1);
        ret += dfs(v);
        v.pop_back();
    }
    {
        v.push_back(A[index]);
        ret += dfs(v);
        v.pop_back();
    }
    {
        v.push_back(A[index] + 1);
        ret += dfs(v);
        v.pop_back();
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> v;
    ll ans = dfs(v);
    cout << ans << endl;
    return 0;
}