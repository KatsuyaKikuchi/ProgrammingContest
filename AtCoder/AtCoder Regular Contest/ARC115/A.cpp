#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool test(string A, string B) {
    ll cnt = 0;
    REP(i, A.length()) {
        if (A[i] != B[i])
            cnt++;
    }
    return cnt % 2 == 0;
}

ll counts(string A) {
    ll ret = 0;
    REP(i, A.length()) {
        if (A[i] == '1')
            ret++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    ll odd = 0, even = 0;
    REP(i, N) {
        ll cnt = counts(S[i]);
        if (cnt % 2 == 0) {
            ans += odd;
            even++;
        }
        else {
            ans += even;
            odd++;
        }
    }
    cout << ans << endl;
    return 0;
}