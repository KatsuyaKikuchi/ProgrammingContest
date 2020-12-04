#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[2005];
pll B[2005];

struct Data {
    ll dist;
    ll i;
    ll j;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
    }
    sort(B, B + M, [](pll a, pll b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    vector<pll> v;
    ll y = -1;
    REP(i, M) {
        if (y >= B[i].second)
            continue;
        y = B[i].second;
        v.push_back(B[i]);
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.first < b.first; });

    vector<Data> x;
    REP(i, N) {
        REP(j, v.size()) {
            if (v[j].first >= A[i].first)
                x.push_back(Data{v[j].first + 1 - A[i].first, j, i});
        }
    }
    ll ans = 0;
    std::set<pll> st;
    REP(i, N) {
        ll d = A[i].first;
        ll ok = v.size(), ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (v[mid].first >= d)
                ok = mid;
            else
                ng = mid;
        }
        if (ok == v.size()) {
            ans = std::max(ans, 0LL);
        }
        else {
            ans = std::max(ans, std::max(0LL, v[ok].second - A[i].second + 1));
            st.insert(pll(std::max(0LL, v[ok].second - A[i].second + 1), i));
        }
    }
    sort(x.begin(), x.end(), [](Data a, Data b) { return a.dist < b.dist; });

    REP(i, x.size()) {
        ll index = x[i].j;
        ll ok = x[i].i + 1;
        pll t(0LL, index);
        pll p(std::max(0LL, v[ok - 1].second - A[index].second + 1), index);
        st.erase(p);
        if (ok < v.size()) {
            t.first = std::max(0LL, v[ok].second - A[index].second + 1);
        }
        st.insert(t);
        auto it = st.end();
        it--;
        ll m = it->first + x[i].dist;
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}