#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> v;
    ll n = 1;
    FOR(i, N, 1) {
        if (S[i - 1] == S[i]) {
            n++;
            continue;
        }
        v.push_back(n);
        n = 1;
    }
    v.push_back(n);

    ll size = v.size();
    ll ret = 0;
    ll index = 0;
    REP(i, size) {
        while (index < v.size() && v[index] <= 1) {
            index++;
        }
        ret++;
        if (index < v.size()) {
            v[index]--;
        }
        else {
            size--;
        }
        while (index <= i) {
            index++;
        }
    }

    return ret;
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