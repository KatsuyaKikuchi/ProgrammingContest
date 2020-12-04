#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> A(N + 1);
    REP(i, N) {
        if (S[i] == '0')
            continue;
        ll left = std::max(i - K, 0LL);
        ll right = std::min(N, i + K + 1);
        A[left]++;
        A[right]--;
    }

    ll ret = 0;
    REP(i, N) {
        if (A[i] == 0) {
            ret++;
            ll right = std::min(N, i + K + 1);
            A[right]--;
            A[i]++;
        }
        A[i + 1] += A[i];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}