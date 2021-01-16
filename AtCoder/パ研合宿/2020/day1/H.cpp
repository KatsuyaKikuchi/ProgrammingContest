#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll A, B, C;
    cin >> A >> B >> C;

    // A>>i==0&&B>>i==1をチェック
    REP(i, 65) {
        ll a = ((A >> i) & 1);
        ll b = ((B >> i) & 1);
        if (a == 0 && b == 1)
            return false;
    }
    // A>>i==0&&C>>i==1チェック
    REP(i, 65) {
        ll a = ((A >> i) & 1);
        ll c = ((C >> i) & 1);
        if (a == 0 && c == 1)
            return false;
    }
    // (B>>i==1&&C>>i==1)&&(B>>j==1&&C>>j==0)をチェック
    ll t = -1;
    REP(i, 65) {
        ll b = ((B >> i) & 1);
        ll c = ((C >> i) & 1);
        if (b == 1) {
            if (t < 0)
                t = c;
            else if (t != c)
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}