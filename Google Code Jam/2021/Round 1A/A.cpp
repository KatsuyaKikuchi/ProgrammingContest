#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string next(const string &base, const string &nxt) {
    ll N = base.size();
    ll M = nxt.size();
    if (N < M)
        return nxt;

    string ret = nxt;
    REP(i, M) {
        if (base[i] == nxt[i])
            continue;
        while (ret.size() < N) {
            ret.push_back('0');
        }
        if (base[i] > nxt[i]) {
            ret.push_back('0');
        }
        return ret;
    }

    string suffix = "";
    ll value = 1;
    for (ll i = N - 1; i >= M; --i) {
        ll t = base[i] - '0' + value;
        value = t / 10;
        suffix.push_back('0' + (t % 10));
    }
    if (value > 0)
        suffix.push_back('0');
    reverse(suffix.begin(), suffix.end());
    return ret + suffix;
}

ll solve() {
    ll N;
    cin >> N;
    vector<string> v(N);
    REP(i, N) {
        cin >> v[i];
    }

    ll ret = 0;
    string value = v[0];
    FOR(i, N, 1) {
        value = next(value, v[i]);
        ret += value.size() - v[i].size();
        //cout << value << endl;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}