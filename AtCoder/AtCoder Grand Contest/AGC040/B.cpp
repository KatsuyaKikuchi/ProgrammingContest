#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

ll count(pll range) {
    return std::max(range.second - range.first + 1, 0LL);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    ll ans = 0;
    REP(i, N) {
        ans = std::max(ans, count(A[i]));
    }
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });
    pll left = A[0];
    pll right(0, INF);
    vector<pll> v;
    FOR(i, N, 1) {
        if (A[0].second < A[i].first) {
            right.first = std::max(right.first, A[i].first);
            right.second = std::min(right.second, A[i].second);
        }
        else {
            v.push_back(A[i]);
        }
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.first > b.first; });
    if (right.second == INF) {
        ll idx = 0;
        REP(i, v.size()) {
            if (count(v[idx]) < count(v[i]))
                idx = i;
        }
        pll tmp = left;
        REP(i, v.size()) {
            if (idx == i)
                continue;
            tmp.first = std::max(tmp.first, v[i].first);
            tmp.second = std::min(tmp.second, v[i].second);
        }
        ans = std::max(ans, count(tmp) + count(v[idx]));
    }
    REP(i, v.size()) {
        pll tmp(std::max(left.first, v[i].first), std::min(left.second, v[i].second));
        if (right.second != INF)
            ans = std::max(ans, count(tmp) + count(right));
        right.first = std::max(right.first, v[i].first);
        right.second = std::min(right.second, v[i].second);
    }
    ans = std::max(ans, count(left) + count(right));
    cout << ans << endl;
    return 0;
}