#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll R[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    memset(R, 0, sizeof(R));
    vector<pll> ans;

    map<pll, bool> mp;
    stack<pll> s, t;
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] == 0)
            continue;
        if (A[i] == 1) {
            pll n(i, i);
            ans.push_back(n);
            R[n.first]++;
            s.push(n);
            continue;
        }
        if (A[i] == 2) {
            pll x(N, N);
            while (!s.empty()) {
                pll y = s.top();
                s.pop();
                if (mp[y])
                    continue;
                x = y;
                break;
            }
            if (x.first == N && x.second == N) {
                cout << -1 << endl;
                return 0;
            }
            mp[x] = true;
            pll n(x.first, i);
            ans.push_back(n);
            t.push(n);
            continue;
        }

        {
            pll x(N, N);
            while (!t.empty()) {
                pll y = t.top();
                t.pop();
                x = y;
                break;
            }

            if (x.first == N && x.second == N) {
                while (!s.empty()) {
                    pll y = s.top();
                    s.pop();
                    if (mp[y])
                        continue;
                    x = y;
                    break;
                }
            }
            if (x.first == N && x.second == N) {
                cout << -1 << endl;
                return 0;
            }
            mp[x] = true;
            pll n(i, i);
            ans.push_back(n);
            pll m(n.first, x.second);
            t.push(n);
            ans.push_back(m);
        }

    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

#if false
    REP(i, N) {
        REP(j, N) {
            bool e = false;
            REP(k, ans.size()) {
                if (i == ans[k].first && j == ans[k].second)
                    e = true;
            }

            if (e)
                cout << "x ";
            else
                cout << ". ";
        }
        cout << endl;
    }
#endif
    return 0;
}