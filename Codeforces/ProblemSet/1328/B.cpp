#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(ll N, ll K) {
    string ret = "";
    ll n = N;
    while (true) {
        ll c = (n - 1) * (n - 2) / 2;
        if (c < K) {
            K -= c;
            ret.push_back('b');
            while (ret.size() < N) {
                if (ret.size() == N - K)
                    ret.push_back('b');
                else
                    ret.push_back('a');
            }
            break;
        }
        ret.push_back('a');
        n--;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, K;
        cin >> N >> K;
        cout << solve(N, K) << endl;
    }
    return 0;
}