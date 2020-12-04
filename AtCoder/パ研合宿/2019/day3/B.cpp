#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2] = {"black", "white"};
ll C[2] = {0, 0};

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, 2) {
            if (S[j] == s) {
                C[j]++;
                break;
            }
        }
    }

    if (C[0] > C[1])
        cout << S[0];
    else
        cout << S[1];
    cout << endl;
    return 0;
}