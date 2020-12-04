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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    string T = "";
    ll d = 0;
    REP(i, N) {
        if (S[i] == '(')
            d++;
        else
            d--;

        if (d < 0) {
            T.push_back('(');
            d++;
        }
    }

    cout << T << S;
    while (d > 0) {
        d--;
        cout << ')';
    }
    cout << endl;
    return 0;
}