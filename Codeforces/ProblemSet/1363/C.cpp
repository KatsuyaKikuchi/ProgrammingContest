#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a]++;
        A[b]++;
    }

    if (A[X - 1] <= 1)
        return "Ayush";

    if ((N - 1) % 2 == 0)
        return "Ashish";
    return "Ayush";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}