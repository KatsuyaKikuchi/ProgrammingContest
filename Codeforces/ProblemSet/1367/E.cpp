#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll C[30];

ll solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    REP(i, S.length()) {
        C[S[i] - 'a']++;
    }
    for (ll i = N; i >= 1; --i) {
        if (K % i == 0)
            return i;
        ll k = i / gcd(i, K % i);
        ll sum = 0;

        REP(j, 30) {
            sum += C[j] / k;
        }

        if (i / k <= sum)
            return i;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}