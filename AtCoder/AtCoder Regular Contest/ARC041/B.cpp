#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[505];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> S[i];
    }

    vector<string> T(N);
    REP(i, N) {
        string s = "";
        REP(j, M) {
            ll m = INF;
            REP(n, 4) {
                ll nx = i + x[n], ny = j + y[n];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    m = 0;
                    continue;
                }
                m = std::min(m, (ll) (S[nx][ny] - '0'));
            }
            s.push_back(m + '0');
            REP(n, 4) {
                ll nx = i + x[n], ny = j + y[n];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                S[nx][ny] -= m;
            }
        }
        T[i] = s;
    }

    REP(i, N) {
        cout << T[i] << endl;
    }
    return 0;
}