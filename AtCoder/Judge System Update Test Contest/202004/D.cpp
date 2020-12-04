#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];
ll S[100005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, Q) {
        cin >> S[i];
    }
    B[0] = A[0];
    REP(i, N - 1) {
        B[i + 1] = gcd(B[i], A[i + 1]);
    }

    REP(i, Q) {
        ll q = S[i];

        ll ok = N, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (gcd(B[mid], q) == 1)
                ok = mid;
            else
                ng = mid;
        }

        if (ok == N)
            cout << gcd(B[N - 1], q) << endl;
        else
            cout << ok + 1 << endl;
    }
    return 0;
}