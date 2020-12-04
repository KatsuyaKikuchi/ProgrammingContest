#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll t;
    ll low;
    ll heigh;
};

string solve(vector<Data> &v, ll init) {
    ll t = 0;
    ll low = init, height = init;
    REP(i, v.size()) {
        ll diff = v[i].t - t;

        ll lowmin = low - diff;
        ll heightmax = height + diff;
        if (lowmin > v[i].heigh || heightmax < v[i].low)
            return "NO";
        low = std::max(v[i].low, lowmin);
        height = std::min(v[i].heigh, heightmax);
        t += diff;
    }
    return "YES";
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, M;
        cin >> N >> M;
        vector<Data> v(N);
        REP(i, N) {
            cin >> v[i].t >> v[i].low >> v[i].heigh;
        }
        cout << solve(v, M) << endl;
    }
    return 0;
}