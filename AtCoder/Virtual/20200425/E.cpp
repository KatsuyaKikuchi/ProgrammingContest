#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;

    ll H = 100, W = 100;
    REP(i, H) {
        S[i] = "";
        REP(j, W) {
            if (j < W / 2)
                S[i].push_back('#');
            else
                S[i].push_back('.');
        }
    }
    A--;
    B--;

    REP(i, H) {
        if (i % 2 == 0)
            continue;

        REP(j, W / 2) {
            if (j % 2 == 1)
                continue;
            if (A == 0)
                break;

            A--;
            S[i][j] = '.';
        }

        FOR(j, W, W / 2) {
            if (j % 2 == 0)
                continue;
            if (B == 0)
                break;

            B--;
            S[i][j] = '#';
        }
    }
    cout << H << " " << W << endl;
    REP(i, H) {
        cout << S[i] << endl;
    }
    return 0;
}