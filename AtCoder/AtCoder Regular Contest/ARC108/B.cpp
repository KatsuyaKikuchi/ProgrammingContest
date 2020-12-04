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
    stack<char> s;
    REP(i, N) {
        if (S[i] != 'x') {
            s.push(S[i]);
        }
        else {
            if (s.size() >= 2) {
                char a = s.top();
                s.pop();
                char b = s.top();
                s.pop();
                if (a == 'o' && b == 'f') {
                    continue;
                }
                else {
                    s.push(b);
                    s.push(a);
                    s.push(S[i]);
                }
            }
            else {
                s.push(S[i]);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}