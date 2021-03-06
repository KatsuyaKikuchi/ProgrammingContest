#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A;
    REP(i, N) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    ll M;
    cin >> M;
    REP(i, M) {
        ll b;
        cin >> b;
        A.push_back(b);
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    REP(i, A.size()) {
        cout << A[i] << endl;
    }
    return 0;
}