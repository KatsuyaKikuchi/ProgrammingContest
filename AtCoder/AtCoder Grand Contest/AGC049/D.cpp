#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> tst;

void dfs(vector<ll> v, ll N, ll M, ll sum = 0) {
    if (v.size() == N) {
        if (sum != M)
            return;
        FOR(i, N - 1, 1) {
            if (2 * v[i] > v[i - 1] + v[i + 1])
                return;
        }
        tst.push_back(v);
        return;
    }
    REP(i, M + 1) {
        if (i + sum > M)
            break;
        v.push_back(i);
        sum += i;
        dfs(v, N, M, sum);
        sum -= i;
        v.pop_back();
    }
}

void test(ll N, ll M) {
    dfs(vector<ll>(), N, M);
    REP(i, tst.size()) {
        REP(j, tst[i].size()) {
            cout << tst[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    test(N, M);

    return 0;
}