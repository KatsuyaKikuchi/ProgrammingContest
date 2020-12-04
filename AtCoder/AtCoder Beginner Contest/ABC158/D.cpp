#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    ll t, f;
    char c;
};
Query Q[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll q;
    cin >> q;
    REP(i, q) {
        cin >> Q[i].t;
        if (Q[i].t == 2) {
            cin >> Q[i].f >> Q[i].c;
        }
    }

    string pre = "", suf = "";
    ll rev = 0;
    REP(i, q) {
        auto qe = Q[q - 1 - i];
        if (qe.t == 1) {
            rev++;
            continue;
        }

        if (qe.f == 1) {
            if (rev % 2 == 0)
                pre.push_back(qe.c);
            else
                suf.push_back(qe.c);
        }
        else {
            if (rev % 2 == 1)
                pre.push_back(qe.c);
            else
                suf.push_back(qe.c);
        }
    }

    REP(i, pre.length()) {
        cout << pre[i];
    }

    if (rev % 2 == 1)
        reverse(S.begin(), S.end());
    cout << S;

    REP(i, suf.length()) {
        cout << suf[suf.size() - 1 - i];
    }
    cout << endl;

    return 0;
}