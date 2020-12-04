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
    ll Q, L;
    cin >> Q >> L;
    stack<pll> S;
    ll size = 0;
    REP(i, Q) {
        string s;
        cin >> s;
        if (s == "Push") {
            ll N, M;
            cin >> N >> M;
            S.push(pll(N, M));
            size += N;
        }
        else if (s == "Pop") {
            ll N;
            cin >> N;
            size -= N;
            while (N > 0) {
                if (S.empty()) {
                    cout << "EMPTY" << endl;
                    return 0;
                }
                pll& t = S.top();
                ll m = std::min(N, t.first);
                N -= m;
                t.first -= m;
                if (t.first <= 0)
                    S.pop();
            }
        }
        else if (s == "Top") {
            if (S.empty()) {
                cout << "EMPTY" << endl;
                return 0;
            }
            pll t = S.top();
            cout << t.second << endl;
        }
        else if (s == "Size") {
            cout << size << endl;
        }

        if (size > L) {
            cout << "FULL" << endl;
            return 0;
        }
    }
    cout << "SAFE" << endl;
    return 0;
}