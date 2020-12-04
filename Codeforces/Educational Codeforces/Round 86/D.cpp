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
    ll N, K;
    cin >> N >> K;
    multiset<ll> S;
    REP(i, N) {
        ll a;
        cin >> a;
        S.insert(a);
    }
    vector<ll> B(K);
    REP(i, K) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    vector<vector<ll>> ans;
    ans.push_back(vector<ll>());
    REP(i, K) {
        ll k = K - i;
        ll index = ans.size() - 1, ng = -1;
        while (abs(index - ng) > 1) {
            ll mid = (index + ng) / 2;
            if (ans[mid].size() < B[i])
                index = mid;
            else
                ng = mid;
        }
        while (!S.empty()) {
            auto t = S.lower_bound(k);
            if (t == S.end()) {
                break;
            }

            while (ans[index].size() >= B[i]) {
                index++;
                if (ans.size() <= index) {
                    ans.push_back(vector<ll>());
                }
            }

            ans[index].push_back(*t);
            S.erase(t);
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].size();
        REP(j, ans[i].size()) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}