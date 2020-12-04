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
    getline(cin, S);
    REP(i, S.length()) {
        if (S[i] == ' ')
            cout << " ";
        else if (S[i] == 'A')
            cout << "A";
        else if (S[i] == 'L')
            cout << "<";
        else if (S[i] == 'R')
            cout << ">";
    }
    cout << endl;
    return 0;
}