#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }

    while (true) {
        bool update = false;
        for (ll i = N - 2; i >= 0; --i) {
            ll s = H[i] + H[i + 1];
            H[i] = s / 2;
            H[i + 1] = H[i] + s % 2;
        }
        if (!update)
            break;
    }

#if false
    while (true) {
        bool update = false;
        for (ll i = N - 1; i >= 1; --i) {
            if (H[i] >= H[i - 1] + 2) {
                H[i]--;
                H[i - 1]++;
                update = true;
            }
        }
        if (!update)
            break;
    }
#endif

    REP(i, N) {
        cout << H[i] << " ";
    }
    cout << endl;

    return 0;
}