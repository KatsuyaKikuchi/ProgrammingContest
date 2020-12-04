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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ans = 0;
    while (true) {
        bool exist = false;
        for (ll i = 'z'; i >= 'a'; --i) {
            REP(j, S.length()) {
                if (S[j] != i)
                    continue;

                if ((j > 0 && S[j - 1] == i - 1) || (j < S.length() - 1 && S[j + 1] == i - 1)) {
                    ans++;
                    S.erase(S.begin() + j);
                    exist = true;
                    break;
                }
            }
            if (exist)
                break;
        }
        if (!exist)
            break;
    }

    cout << ans << endl;
    return 0;
}