#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> S(N);
    REP(i, N) {
        cin >> S[i];
        if (S[i] == 0)
            S[i] = -1;
    }
    sort(S.begin(), S.end());
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll n;
        cin >> n;
        ll ok = INF, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            ll index = lower_bound(S.begin(), S.end(), mid) - S.begin();
            if (N - index <= n)
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << endl;
    }
    return 0;
}