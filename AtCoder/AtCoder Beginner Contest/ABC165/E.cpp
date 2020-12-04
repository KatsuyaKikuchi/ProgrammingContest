#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> ans;
    if (N % 2 == 1) {
        REP(i, M) {
            ans.push_back(pll(i + 1, N - 1 - i));
        }
    }
    else {
        ll es = 1, os = N;
        for (ll m = M; m > 0; --m) {
            if (m % 2 == 0) {
                ans.push_back(pll(es, es + m));
                es++;
            }
            else {
                ans.push_back(pll(os, os - m));
                os--;
            }
        }
    }

    REP(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}