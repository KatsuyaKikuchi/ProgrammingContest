#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string parse(ll n) {
    string ret = "";
    REP(_, 4) {
        ll t = n % 10;
        n /= 10;
        ret.push_back('0' + t);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool check(ll n, string &s) {
    string t = parse(n);
   // vector<ll> ok, ng;
    vector<ll> count(10, 0);

    REP(i, t.size()) {
        ll val = t[i] - '0';
        count[val]++;
    }
    REP(i, 10) {
        if (s[i] == 'o' && count[i] == 0)
            return false;
        if (s[i] == 'x' && count[i] > 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();

    ll ans = 0;
    REP(n, 10000) {
        if (check(n, S))
            ans++;
    }
    cout << ans << endl;
    return 0;
}