#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<bool> A(N, false), B(N, false);
    REP(i, N) {
        ll m;
        cin >> m;
        vector<ll> v(m);
        REP(j, m) {
            cin >> v[j];
            v[j]--;
        }
        REP(j, m) {
            if (!B[v[j]]) {
                A[i] = B[v[j]] = true;
                break;
            }
        }
    }
    REP(i, N) {
        if (A[i])
            continue;

        REP(j, N) {
            if (B[j])
                continue;

            cout << "IMPROVE" << endl;
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
    }

    cout << "OPTIMAL" << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}