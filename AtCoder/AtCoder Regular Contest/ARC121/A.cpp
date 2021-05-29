#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll g;
    ll index;
};
vector<Data> D;
vector<Data> A;

pll getPair(ll a, ll b) {
    return pll(std::min(a, b), std::max(a, b));
}

ll length(pll p) {
    pll g0 = D[p.first].g;
    pll g1 = D[p.second].g;
    return std::max(abs(g0.first - g1.first), abs(g0.second - g1.second));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    A.resize(N);
    D.resize(N);
    REP(i, N) {
        cin >> A[i].g.first >> A[i].g.second;
        A[i].index = i;
        D[i].g.first = A[i].g.first;
        D[i].g.second = A[i].g.second;
        D[i].index = i;
    }
    vector<pll> p;
    sort(A.begin(), A.end(), [](Data a, Data b) { return a.g.first < b.g.first; });
    std::set<pll> st;
    REP(i, N) {
        ll a0 = A[0].index;
        ll a1 = A[1].index;
        ll b0 = A[N - 1].index;
        ll b1 = A[N - 2].index;
        ll index = A[i].index;
        p.push_back(pll(index, a0));
        p.push_back(pll(index, a1));
        p.push_back(pll(index, b0));
        p.push_back(pll(index, b1));
    }
    sort(A.begin(), A.end(), [](Data a, Data b) { return a.g.second < b.g.second; });
    REP(i, N) {
        ll a0 = A[0].index;
        ll a1 = A[1].index;
        ll b0 = A[N - 1].index;
        ll b1 = A[N - 2].index;
        ll index = A[i].index;
        p.push_back(pll(index, a0));
        p.push_back(pll(index, a1));
        p.push_back(pll(index, b0));
        p.push_back(pll(index, b1));
    }

    vector<ll> ans;
    REP(i, p.size()) {
        pll t = getPair(p[i].first, p[i].second);
        auto it = st.find(t);
        if (it == st.end()) {
            st.insert(t);
            ans.push_back(length(t));
        }
    }

    sort(ans.begin(), ans.end(), [](ll a, ll b) { return a > b; });
#if false
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
#endif
    cout << ans[1] << endl;

    return 0;
}