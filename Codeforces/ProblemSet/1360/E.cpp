#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll x[2] = {1, 0};
ll y[2] = {0, 1};

bool solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    REP(h, N) {
        REP(w, N) {
            if (S[h][w] == '0')
                continue;
            bool e = false;
            REP(i, 2) {
                ll nx = h + x[i], ny = w + y[i];
                if (nx >= N || ny >= N || S[nx][ny] == '1')
                    e = true;
            }
            if (!e)
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}