#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(string &S) {
    string s = "", t = "";
    bool u = false;
    REP(i, S.length()) {
        if (S[i] == '2') {
            if (u) {
                s.push_back('0');
                t.push_back('2');
            }
            else {
                s.push_back('1');
                t.push_back('1');
            }
            continue;
        }
        else if (S[i] == '0') {
            s.push_back('0');
            t.push_back('0');
            continue;
        }

        if (u) {
            s.push_back('0');
            t.push_back('1');
        }
        else {
            s.push_back('1');
            t.push_back('0');
        }
        u = true;
    }

    cout << s << endl;
    cout << t << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        string S;
        cin >> S;
        solve(S);
    }
    return 0;
}