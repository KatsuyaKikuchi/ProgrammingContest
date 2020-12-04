#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(ll N, ll A, ll B) {
    string ret = "";
    REP(i, B) {
        ret.push_back((char) ('a' + i));
    }
    while (ret.size() < A) {
        ret.push_back(ret[0]);
    }

    while (ret.size() < N) {
        ret.push_back(ret[ret.size() - A]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, A, B;
        cin >> N >> A >> B;
        cout << solve(N, A, B) << endl;
    }
    return 0;
}