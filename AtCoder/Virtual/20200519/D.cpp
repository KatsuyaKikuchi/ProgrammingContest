#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
vector<string> S;

void dfs(string s, char c) {
    if (s.length() == N) {
        S.push_back(s);
        return;
    }

    for (char t = 'a'; t < c; ++t) {
        s.push_back(t);
        dfs(s, c);
        s.pop_back();
    }
    s.push_back(c);
    dfs(s, c + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    dfs("", 'a');

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    REP(i, S.size()) {
        cout << S[i] << endl;
    }
    return 0;
}