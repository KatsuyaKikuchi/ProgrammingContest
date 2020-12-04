#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pair<string, string> A[20005];

int main() {
    ll N;
    cin >> N;
    std::map<string, ll> m;
    vector<string> v;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        if (m[A[i].second] == 0) {
            m[A[i].second] = v.size() + 1;
            v.push_back(A[i].second);
        }
    }

    vector<bool> u(v.size(), false);
    REP(i, N) {
        if (m[A[i].first] == 0)
            continue;
        ll index = m[A[i].first];
        u[index - 1] = true;
    }

    REP(i, v.size()) {
        if (u[i])
            continue;
        cout << v[i] << endl;
    }
    return 0;
}