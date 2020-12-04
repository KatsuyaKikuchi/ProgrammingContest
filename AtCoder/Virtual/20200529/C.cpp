#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    bool rev = false;
    string suf = "";
    REP(i, Q) {
        ll T;
        cin >> T;
        if (T == 1) {
            rev = !rev;
            continue;
        }
        ll F;
        cin >> F;
        char C;
        cin >> C;
        if (F == 1) {
            if (rev)
                S.push_back(C);
            else
                suf.push_back(C);
        }
        else {
            if (rev)
                suf.push_back(C);
            else
                S.push_back(C);
        }
    }
    if (rev) {
        reverse(S.begin(), S.end());
        cout << S << suf << endl;
    }
    else {
        reverse(suf.begin(), suf.end());
        cout << suf << S << endl;
    }
    return 0;
}