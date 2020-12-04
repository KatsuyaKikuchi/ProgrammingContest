#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll f = 0, t = 0, o = 0;
    REP(i, N) {
        cin >> A[i];
        ll n = 0;
        while (A[i] % 2 == 0) {
            n++;
            A[i] /= 2;
        }
        if (n >= 2)
            f++;
        else if (n == 1)
            t++;
        else
            o++;
    }

    if (o != 0) {
        if (o - f > 1 || f == 0) {
            cout << "No" << endl;
            return 0;
        }
        if (o - f == 1 && t > 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}