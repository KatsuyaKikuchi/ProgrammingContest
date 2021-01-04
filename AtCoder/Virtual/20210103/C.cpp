#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll y[8] = {1, 0, -1, 0, -1, 1, -1, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    ll H = 100, W = 100;
    vector<string> S(H);
    REP(i, H) {
        string s = "";
        ll w = W / 2;
        REP(i, w) {
            s.push_back('.');
        }
        while (s.size() < W) {
            s.push_back('#');
        }
        S[i] = s;
    }
    A--;
    B--;
    REP(i, H) {
        REP(j, W) {
            bool e = true;
            REP(k, 8) {
                ll nx = x[k] + i, ny = y[k] + j;
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                    e = false;
                    break;
                }
                if (S[i][j] != S[nx][ny])
                    e = false;
            }
            if (!e)
                continue;
            if (S[i][j] == '.' && B > 0) {
                S[i][j] = '#';
                B--;
            }
            else if (S[i][j] == '#' && A > 0) {
                S[i][j] = '.';
                A--;
            }
        }
    }
    cout << H << " " << W << endl;
    REP(i, H) {
        cout << S[i] << endl;
    }
    return 0;
}