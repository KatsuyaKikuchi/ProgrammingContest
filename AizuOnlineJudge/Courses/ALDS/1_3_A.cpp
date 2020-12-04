#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

typedef ll ll;
#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    stack<int> S;
    char s[100];
    while (scanf("%s", s) != -1) {
        if (s[0] == '+')
        {
            int a = S.top(); S.pop();
            int b = S.top(); S.pop();
            S.push(a + b);
        }
        else if (s[0] == '-')
        {
            int a = S.top(); S.pop();
            int b = S.top(); S.pop();
            S.push(b - a);
        }
        else if (s[0] == '*')
        {
            int a = S.top(); S.pop();
            int b = S.top(); S.pop();
            S.push(a * b);
        }
        else
        {
            int x = atoi(s);
            S.push(x);
        }
    }

    cout << S.top() << endl;
    return 0;
}