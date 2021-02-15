#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll ans[10];

void solve(ll a, ll b) {
    if (a >= 350)
        ans[0]++;
    else if (a >= 300)
        ans[1]++;
    else if (a >= 250)
        ans[2]++;

    if (b >= 250)
        ans[3]++;

    if (a >= 0 && b < 0)
        ans[4]++;
    if (a < 0)
        ans[5]++;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(ans, 0, sizeof(ans));
    REP(i, N) {
        double a, b;
        cin >> a >> b;
        ll A = round(a * 10LL);
        ll B = round(b * 10LL);
        solve(A, B);
    }

    REP(i, 6) {
        cout << ans[i];
        if (i < 5)
            cout << " ";
    }
    cout << endl;
    return 0;
}