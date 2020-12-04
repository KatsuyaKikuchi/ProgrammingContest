#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll H[100005];

bool check(ll N) {
    H[0]--;
    REP(i, N - 1) {
        if (H[i + 1] < H[i])
            return false;
        H[i + 1] = std::max(H[i + 1] - 1, H[i]);
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    if (check(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}