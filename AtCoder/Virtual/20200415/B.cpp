#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        double a, b;
        cin >> a >> b;
        if (a >= 35)
            A[0]++;
        else if (a >= 30)
            A[1]++;
        else if (a >= 25)
            A[2]++;

        if (b >= 25)
            A[3]++;

        if (b < 0 && a >= 0)
            A[4]++;
        if (a < 0)
            A[5]++;
    }

    REP(i, 6) {
        cout << A[i];
        if (i < 5)
            cout << " ";
    }
    cout << endl;
    return 0;
}