#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char S[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> S[j][i];
        }
    }
    vector<char> v(N, 0);
    REP(i, (N + 1) / 2) {
        vector<bool> L(30, false), R(30, false);
        REP(j, N) {
            L[S[j][i] - 'a'] = true;
            R[S[j][N - 1 - i] - 'a'] = true;
        }

        bool e = false;
        REP(j, 27) {
            if (L[j] && R[j]) {
                v[i] = v[N - 1 - i] = (char) ('a' + j);
                e = true;
                break;
            }
        }
        if (!e) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(i, N) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}