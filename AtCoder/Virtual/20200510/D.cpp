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
vector<string> ans;

void dfs(string s, char nxt) {
    if (s.length() == N) {
        ans.push_back(s);
        return;
    }
    for (char c = 'a'; c <= nxt; ++c) {
        s.push_back(c);
        dfs(s, c == nxt ? nxt + 1 : nxt);
        s.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    ans.clear();
    dfs("", 'a');

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}