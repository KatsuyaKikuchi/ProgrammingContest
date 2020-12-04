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
ll A[200005];

bool check(ll m) {
    stack<pll> stack;
    stack.push(pll(1, 1));
    REP(i, N - 1) {
        if (A[i] < A[i + 1])
            continue;
        if (m <= 1)
            return false;
        while (stack.size() > 0 && stack.top().first > A[i + 1])
            stack.pop();
        if (stack.top().first == A[i + 1])
            stack.top().second++;
        else
            stack.push(pll(A[i + 1], 2));

        while (stack.top().second > m) {
            ll nxt = stack.top().first - 1;
            stack.pop();
            if (stack.empty() || nxt <= 0)
                return false;
            if (stack.top().first == nxt)
                stack.top().second++;
            else
                stack.push(pll(nxt, 2));
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ok = INF, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;

    return 0;
}