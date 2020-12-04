#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    ll N;
    cin >> N;
    memset(A, 0, sizeof(A));
    REP(i, N) {
        ll a;
        cin >> a;
        A[a - 1]++;
    }

    pll p(-1, -1);
    REP(i, N) {
        if (A[i] == 0)
            p.first = i + 1;
        else if (A[i] == 2)
            p.second = i + 1;
    }

    if (p.first == -1)
        cout << "Correct" << endl;
    else
        cout << p.second << " " << p.first << endl;
    return 0;
}