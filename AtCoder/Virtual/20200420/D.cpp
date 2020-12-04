#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string A[105];
ll C[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    memset(C, 0, sizeof(C));
    REP(i, H) {
        cin >> A[i];
    }
    REP(i, H) {
        REP(j, W) {
            C[A[i][j] - 'a']++;
        }
    }

    bool success = true;
    REP(h, (H + 1) / 2) {
        REP(w, (W + 1) / 2) {
            ll s = 1;
            if (H - h - 1 != h)
                s *= 2;
            if (W - w - 1 != w)
                s *= 2;

            ll index = -1;
            REP(n, 27) {
                if (C[n] < s)
                    continue;

                if (index < 0 || C[index] > C[n])
                    index = n;
            }

            if (index < 0)
                success = false;
            C[index] -= s;
        }
    }

    if (success)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}