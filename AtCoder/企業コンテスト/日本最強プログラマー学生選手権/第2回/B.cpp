#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10005];
ll B[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    std::map<ll, ll> mp;
    REP(i, N) {
        cin >> A[i];
        mp[A[i]]++;
    }
    REP(i, M) {
        cin >> B[i];
        mp[B[i]]++;
    }
    vector<ll> v;
    REP(i, N) {
        if (mp[A[i]] == 1)
            v.push_back(A[i]);
    }
    REP(i, M) {
        if (mp[B[i]] == 1)
            v.push_back(B[i]);
    }

    sort(v.begin(), v.end());

    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}