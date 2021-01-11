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
    ll p = pow(2LL, N);
    vector<ll> A(p);
    vector<ll> v(p);
    REP(i, p) {
        cin >> A[i];
        v[i] = i;
    }

    while (v.size() > 2) {
        vector<ll> t;
        for (ll i = 0; i < v.size(); i += 2) {
            if (A[v[i]] > A[v[i + 1]]) {
                t.push_back(v[i]);
            }
            else
                t.push_back(v[i + 1]);
        }
        sort(t.begin(), t.end());
        v = t;
    }
    if (A[v[0]] > A[v[1]]) {
        cout << v[1] + 1 << endl;
    }
    else
        cout << v[0] + 1 << endl;
    return 0;
}