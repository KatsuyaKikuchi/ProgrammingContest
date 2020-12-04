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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B;
    REP(i, N) {
        cin >> A[i];
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    if (B.size() > K) {
        cout << -1 << endl;
        return;
    }
    ll index = 0;
    while (B.size() < K) {
        B.push_back(B[index++]);
    }
    vector<ll> v;
    REP(i, N) {
        REP(j, B.size()) {
            v.push_back(B[j]);
        }
    }
    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
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