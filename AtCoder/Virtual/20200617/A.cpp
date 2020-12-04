#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[305];
ll A[305][305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    REP(i, H) {
        cin >> S[i];
    }

    REP(w, W) {
        ll cnt = 0;
        REP(h, H) {
            if (S[h][w] == '#')
                cnt++;
        }
        if (cnt == 0) {
            if (w > 0) {
                REP(h, H) {
                    A[h][w] = A[h][w - 1];
                }
            }
            continue;
        }
        REP(h, H) {
            A[h][w] = K;
            if (S[h][w] == '#') {
                if (--cnt > 0)
                    K--;
            }
        }
        K--;
        REP(h, H) {
            for (ll j = w - 1; j >= 0; --j) {
                if (A[h][j] == 0)
                    A[h][j] = A[h][j + 1];
                else
                    break;
            }
        }
    }

    REP(h, H) {
        REP(w, W) {
            cout << A[h][w] << " ";
        }
        cout << endl;
    }
    return 0;
}