#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<queue<ll>> C(30);
    REP(i, N) {
        ll c = S[i] - 'a';
        C[c].push(i);
    }
    string ans = "";
    ll index = -1;
    while (ans.size() < K) {
        char c = 'z';
        REP(i, C.size()) {
            while (!C[i].empty() && C[i].front() <= index) {
                C[i].pop();
            }
            if (C[i].empty())
                continue;
            ll idx = C[i].front();
            if (K - (ans.size() + 1) <= N - 1 - idx) {
                index = idx;
                c = 'a' + i;
                break;
            }
        }
        ans.push_back(c);
    }
    cout << ans << endl;
    return 0;
}