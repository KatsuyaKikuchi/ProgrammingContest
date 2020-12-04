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
bool T[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(T, 0, sizeof(T));
    ll index = 0;
    REP(i, N) {
        if (A[i] == index + 1) {
            T[index] = true;
            index++;
        }
    }

    if (index == 0)
        cout << -1 << endl;
    else
        cout << N - index << endl;
    return 0;
}