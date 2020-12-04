#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string X = "atcoder";

ll swap(string &s, char c, int index) {
    FOR(i, s.length(), index) {
        if (s[i] != c)
            continue;
        ll ret = i - index;
        for (ll j = i; j > index; --j) {
            swap(s[j], s[j - 1]);
        }
        return ret;
    }
    return -1;
}

ll solve() {
    string S;
    cin >> S;
    ll N = S.length();
    vector<queue<ll>> Q(30);
    REP(i, N) {
        char c = S[i];
        Q[c - 'a'].push(i);
    }
    ll ret = INF;
    if (X.size() >= S.size()) {
        ll sum = 0;
        REP(i, S.size()) {
            FOR(j, N, i) {
                if (S[j] > X[i]) {
                    ret = std::min(ret, sum + j - i);
                    break;
                }
            }
            ll t = swap(S, X[i], i);
            if (t < 0)
                break;
            sum += t;
        }
    }
    else {
        ll sum = 0;
        REP(i, X.size()) {
            FOR(j, N, i) {
                if (S[j] > X[i]) {
                    ret = std::min(ret, sum + j - i);
                    break;
                }
            }
            ll t = swap(S, X[i], i);
            if (t < 0)
                break;
            sum += t;
            if (i == X.size() - 1)
                ret = std::min(ret, sum);
        }
    }

    if (ret == INF)
        ret = -1;
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