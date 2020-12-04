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

    ll A = 0, B = 0;
    cin >> A >> B;

    ll C = B - A;
    if (C < 0 || C % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans;

    ans.push_back(A);
    ans.push_back(C / 2);
    if ((ans[0] & (C / 2)) == 0)
        ans[0] |= (C / 2);
    else
        ans.push_back(C / 2);

    for (auto it = ans.begin(); it != ans.end();) {
        if (*it == 0) {
            ans.erase(it);
            continue;
        }
        it++;
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}