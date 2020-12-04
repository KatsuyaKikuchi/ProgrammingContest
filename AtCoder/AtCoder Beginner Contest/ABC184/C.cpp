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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = 3;
    if (A == C && B == D) {
        ans = 0;
    }
    else if (A + B == C + D ||
             A - B == C - D ||
             abs(A - C) + abs(B - D) <= 3) {
        ans = 1;
    }
    else {
        ll a = ((A % 2) + (B % 2)) % 2;
        ll b = ((C % 2) + (D % 2)) % 2;
        if (a == b) {
            ans = 2;
        }
        else {
            if (abs(A - C) + abs(B - D) <= 6) {
                ans = 2;
            }
            else {
                ll c = C - A;
                ll d0 = D - c;
                ll d1 = D + c;
                if (abs(B - d0) <= 3 || abs(B - d1) <= 3) {
                    ans = 2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}