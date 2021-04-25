#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;

bool check(ll b) {
    ll count = 0;
    REP(i, N) {
        if ((b >> i) & 1)
            count++;
        else
            count--;
        if (count < 0)
            return false;
    }
    return count == 0;
}

string parse(ll b) {
    string ret = "";
    REP(i, N) {
        if ((b >> i) & 1)
            ret.push_back('(');
        else
            ret.push_back(')');
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<string> ans;
    REP(bit, pow(2LL, N)) {
        if (check(bit)) {
            ans.push_back(parse(bit));
        }
    }
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}