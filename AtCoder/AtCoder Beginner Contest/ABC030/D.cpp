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

int main() {
    ll N, a;
    cin >> N >> a;
    a--;
    string K;
    cin >> K;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    memset(B, -1, sizeof(B));
    ll n = 0;
    while (B[a] == -1) {
        B[a] = n++;
        a = A[a];
    }

    //! aから始まってn-B[a]回でループ
    ll s = a;
    ll l = n - B[a];

    ll m = 0;
    if (K.length() <= 6) {
        //! そのまま確認
        ll M = 0;
        REP(i, K.length()) {
            M *= 10;
            M += K[i] - '0';
        }
        if (M < B[s]) {
            REP(i, N) {
                if (B[i] == M) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
        M -= B[s];
        m = M % (l);
    }
    else {
        ll n = K.length();
        ll t = 0;
        ll x = B[s];
        REP(i, n) {
            ll c = K[n - 1 - i] - '0';
            c -= t;
            t = 0;
            ll y = x % 10;
            x /= 10;
            if (c < y) {
                c += 10;
                t = 1;
            }
            c -= y;
            K[n - 1 - i] = c + '0';
        }

        ll d = 0;
        REP(i, n) {
            d = (d * 10 + K[i] - '0') % l;
        }
        m = d;
    }

    ll ans = s;
    REP(i, m) {
        ans = A[ans];
    }
    cout << ans + 1 << endl;
    return 0;
}