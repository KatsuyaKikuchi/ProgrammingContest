#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 10000;

struct Data {
    string Q;
    string R;
};

void solve() {
    ll N;
    cin >> N;
    vector<char> v;
    vector<Data> d;
    REP(i, MAX) {
        string Q;
        string R;
        cin >> Q >> R;
        d.push_back(Data{Q, R});
        REP(j, R.size()) {
            v.push_back(R[j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<vector<bool>> U(10, vector<bool>(10, true));
    vector<pll> C(10);
    REP(i, 10) {
        C[i] = pll(i, 0);
    }
    REP(i, d.size()) {
        char c = d[i].R[0];
        ll index = lower_bound(v.begin(), v.end(), c) - v.begin();
        U[index][0] = false;
        if (d[i].Q == "-1") {
            C[index].second++;
        }
        else {
            if (d[i].Q.length() != d[i].R.length())
                continue;
            ll n = d[i].Q[0] - '0';
            for (ll j = n + 1; j <= 9; ++j) {
                U[index][j] = false;
            }
        }
    }

    string S = "ZZZZZZZZZZ";
    if (d[0].Q == "-1") {
        sort(C.begin(), C.end(), [](pll a, pll b) { return a.second > b.second; });
        REP(i, 10) {
            REP(j, 10) {
                U[i][j] = false;
            }
        }
        REP(i, 10) {
            ll n = C[i].first;
            FOR(j, 10, i + 1) {
                U[n][j] = true;
            }
        }
        U[C[9].first][0] = true;
    }
    REP(i, 10) {
        if (U[i][0]) {
            S[0] = v[i];
            REP(j, 10) {
                U[i][j] = false;
            }
            break;
        }
    }
    for (ll n = 9; n > 0; --n) {
        REP(i, 10) {
            if (!U[i][n])
                continue;
            REP(j, 10) {
                U[i][j] = false;
            }
            S[n] = v[i];
            break;
        }
    }
    cout << S << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}