#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 1000005;

ll A[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    ll front = MAX / 2, back = MAX / 2 + 1;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll d, x;
            cin >> d >> x;
            if (d == 0)
                A[front--] = x;
            else
                A[back++] = x;
        }
        else if (q == 1) {
            ll p;
            cin >> p;
            cout << A[front + 1 + p] << endl;
        }
        else {
            ll d;
            cin >> d;
            if (d == 0)
                front++;
            else
                back--;
        }
    }
    return 0;
}