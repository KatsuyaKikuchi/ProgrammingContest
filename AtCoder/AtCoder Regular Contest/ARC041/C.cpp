#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        ll x;
        char d;
        cin >> x >> d;
        A[i] = pll(x, 0);
        if (d == 'L')
            A[i].second = 1;
    }

    ll ans = 0;
    queue<pll> R;
    {
        ll n = 0;
        REP(i, N) {
            if (A[i].second == 1) {
                if (n > 0) {
                    R.push(pll(A[i - 1].first, n));
                }
                n = 0;
                continue;
            }
            if (n > 0) {
                ans += n * (A[i].first - A[i - 1].first - 1);
            }
            n++;
            if (i == N - 1) {
                ans += n * (M - A[N - 1].first);
            }
        }
    }
    stack<pll> L;
    {
        ll n = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (A[i].second == 0) {
                if (n > 0) {
                    L.push(pll(A[i + 1].first, n));
                }
                n = 0;
                continue;
            }
            if (n > 0) {
                ans += n * (A[i + 1].first - A[i].first - 1);
            }
            n++;
            if (i == 0) {
                ans += n * (A[0].first - 1);
            }
        }
    }

    //cout << R.size() << " " << L.size() << endl;
    while (!R.empty() || !L.empty()) {
        pll r = R.front();
        pll l = L.top();
        R.pop();
        L.pop();
        ans += std::max(r.second, l.second) * (l.first - r.first - 1);
    }

    cout << ans << endl;
    return 0;
}