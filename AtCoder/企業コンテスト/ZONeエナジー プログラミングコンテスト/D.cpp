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
    string S;
    cin >> S;
    ll N = S.length();
    deque<char> q;
    bool last = true;
    REP(i, N) {
        if (S[i] == 'R') {
            last = !last;
        }
        else {
            if (last)
                q.push_back(S[i]);
            else
                q.push_front(S[i]);
        }
    }

    stack<char> stk;
    while (!q.empty()) {
        if (last) {
            stk.push(q.back());
            q.pop_back();
        }
        else {
            stk.push(q.front());
            q.pop_front();
        }
    }

    string ans = "";
    while (!stk.empty()) {
        char c = stk.top();
        stk.pop();
        if (!ans.empty() && ans[ans.size() - 1] == c) {
            ans.pop_back();
        }
        else {
            ans.push_back(c);
        }
    }
    cout << ans << endl;
    return 0;
}