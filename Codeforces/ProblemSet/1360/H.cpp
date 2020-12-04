#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll convert(string s) {
    ll N = s.length();
    ll ret = 0;
    REP(i, N) {
        ret = ret * 2LL + s[i] - '0';
    }
    return ret;
}

string restore(ll n, ll m) {
    string ret = "";
    while (n > 0) {
        ret.push_back((char) ('0' + n % 2));
        n /= 2;
    }

    while (ret.size() < m)
        ret.push_back('0');
    reverse(ret.begin(), ret.end());
    return ret;
}

string solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> v(N);
    REP(i, N) {
        string s;
        cin >> s;
        v[i] = convert(s);
    }
    sort(v.begin(), v.end());
    ll mx = pow(2LL, M) - 1;
    ll ret = (mx - N) / 2;
    REP(i, v.size()) {
        if (v[i] <= ret)
            ret++;
    }

    return restore(ret, M);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << solve() << endl;
    }
    return 0;
}