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

    deque<ll> q;
    ll N;
    cin >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        q.push_back(a);
    }

    ll ans = 0;
    while (q.size() > 1) {
        ll f = q.front();
        ll b = q.back();
        // cout << f << " " << b << endl;
        q.pop_front();
        q.pop_back();
        ll ff = f * 2 + q.front() + 1;
        ll bb = b * 2 + q.back() + 1;
        // cout << "r:" << ff << " " << bb << endl;
        ans += std::min(ff, bb);
        if (ff > bb) {
            ll bbb = b + 1 + q.back();
            q.pop_back();
            bbb += q.back() + 1;
            q.pop_back();
            q.push_back(bbb);
            q.push_front(f);
        }
        else {
            ll fff = f + 1 + q.front();
            q.pop_front();
            fff += q.front() + 1;
            q.pop_front();
            q.push_front(fff);
            q.push_back(b);
        }
    }
    cout << ans << endl;
    return 0;
}