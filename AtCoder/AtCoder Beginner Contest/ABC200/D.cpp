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
    ll N;
    cin >> N;
    vector<ll> tmp(N);
    REP(i, N) {
        cin >> tmp[i];
    }
    vector<ll> A;
    REP(i, std::min(N, 8LL)) {
        A.push_back(tmp[i]);
    }

    vector<vector<ll>> V(200);
    FOR(bit, pow(2LL, A.size()), 1) {
        vector<ll> v;
        ll s = 0;
        REP(i, A.size()) {
            if ((bit >> i) & 1) {
                s += A[i];
                s %= 200;
                v.push_back(i + 1);
            }
        }
        if (V[s].size() > 0) {
            cout << "Yes" << endl;
            cout << V[s].size();
            REP(i, V[s].size()) {
                cout << " " << V[s][i];
            }
            cout << endl;
            cout << v.size();
            REP(i, v.size()) {
                cout << " " << v[i];
            }
            cout << endl;
            return 0;
        }
        V[s] = v;
    }
    cout << "No" << endl;

    return 0;
}