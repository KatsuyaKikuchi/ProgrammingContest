#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<pll> A;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    A.resize(2 * N);
    REP(i, 2 * N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first< b.first; });
    vector<ll> idx0, idx1;
    REP(i, N) {
        idx0.push_back(A[i].second);
        idx1.push_back(A[i + N].second);
    }
    sort(idx0.begin(), idx0.end());
    sort(idx1.begin(), idx1.end());
    vector<char> ans(2 * N);
    REP(i, N) {
        ll a = idx0[i];
        ll b = idx1[i];
        ans[min(a, b)] = '(';
        ans[max(a, b)] = ')';
    }
    REP(i, ans.size()) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}