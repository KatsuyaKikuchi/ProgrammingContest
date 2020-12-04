#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll check(string &s, string &t, ll index = -1) {
    ll ret = 0;
    ll n = s.length();
    REP(i, n) {
        if (i == index)
            continue;
        if (s[i] != t[i])
            ret++;
    }
    return ret;
}

string solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    string ret = S[0];
    {
        bool e = true;
        REP(i, N) {
            if (check(ret, S[i]) > 1)
                e = false;
        }
        if (e)
            return ret;
    }

    REP(i, M) {
        ll p = i;
        ret = S[0];
        bool e = true;
        REP(j, N) {
            ll num = check(ret, S[j], p);
            if (num > 1)
                e = false;
            else if (num == 1 && p >= 0) {
                ret[i] = S[j][i];
                p = -1;
            }
        }
        if (e)
            return ret;
    }

    return "-1";
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