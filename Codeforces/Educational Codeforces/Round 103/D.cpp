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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> ans(N + 1, 1);
    {
        ll odd = 0, even = 0;
        REP(i, N) {
            if (S[i] == 'L') {
                if (i % 2 == 0) {
                    even++;
                    odd = 0;
                }
                else {
                    odd++;
                    even = 0;
                }
            }
            else {
                if (i % 2 == 1) {
                    even++;
                    odd = 0;
                }
                else {
                    odd++;
                    even = 0;
                }
            }
            if (i % 2 == 0)
                ans[i + 1] += even;
            else
                ans[i + 1] += odd;
        }
    }
    {
        ll odd = 0, even = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (i % 2 == (N - 1) % 2) {
                if (S[i] == 'R') {
                    even++;
                    odd = 0;
                }
                else {
                    even = 0;
                    odd++;
                }
            }
            else {
                if (S[i] == 'L') {
                    even++;
                    odd = 0;
                }
                else {
                    even = 0;
                    odd++;
                }
            }
            if (i % 2 == (N - 1) % 2)
                ans[i] += even;
            else
                ans[i] += odd;
        }
    }
    REP(i, N + 1) {
        cout << ans[i] << " ";
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