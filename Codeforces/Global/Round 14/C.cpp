#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, M, X;
    cin >> N >> M >> X;
    vector<pll> H(N);
    REP(i, N) {
        cin >> H[i].first;
        H[i].second = i;
    }
    sort(H.begin(), H.end(), [](pll a, pll b) { return a.first < b.first; });
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    vector<ll> ans(N);
    REP(i, M) {
        q.push(pll(H[i].first, i));
        ans[H[i].second] = i;
    }

    FOR(i, N, M) {
        pll t = q.top();
        q.pop();
        ans[H[i].second] = t.second;
        t.first += H[i].first;
        q.push(t);
        //cout << t.first << " ";
    }
//    cout << endl;

    cout << "YES" << endl;
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
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