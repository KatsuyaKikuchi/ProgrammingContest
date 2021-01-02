#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(N, false));
    REP(i, N) {
        A[i][i] = true;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = true;
        A[b][a] = true;
    }
    ll p = pow(2LL, N);


    vector<vector<ll>> bits(N);
    FOR(bit, p, 1) {
        vector<ll> v;
        REP(i, N) {
            if ((bit >> i) & 1)
                v.push_back(i);
        }
        bool e = true;
        REP(i, v.size()) {
            REP(j, v.size()) {
                if (!A[v[i]][v[j]]) {
                    e = false;
                    break;
                }
            }
            if (!e)
                break;
        }

        if (e) {
            bits[0].push_back(bit);
            if (bit == p - 1) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    FOR(i, N, 1) {
        REP(j, bits[i - 1].size()) {
            REP(k, bits[0].size()) {
                ll a = bits[i - 1][j];
                ll b = bits[0][k];
                if ((a & b) > 0)
                    continue;
                bits[i].push_back(a | b);
                ll x = (a | b);
                if (x == p - 1) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
        sort(bits[i].begin(), bits[i].end());
        bits[i].erase(unique(bits[i].begin(), bits[i].end()), bits[i].end());
    }

    return 0;
}