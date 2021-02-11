#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;
//typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

long long solve() {
    long long A, B;
    cin >> A >> B;
    ll s = A * B;
    ll ok = 0, ng = s;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll x = (mid + 1) / 2;
        ll n = x * (mid - x + 1);
        if (n < s)
            ok = mid;
        else
            ng = mid;
    }
    long long ret = ok;
    if (std::min(A, B) <= ret) {
        long long x = std::max((ret + 1) / 2, std::min(A, B));
        long long n = (x + 1) * std::max(1LL, ret - x + 1LL);
        if (n >= s)
            ret--;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(_, Q) {
        cout << std::max(0LL, solve()) << endl;
    }
    return 0;
}