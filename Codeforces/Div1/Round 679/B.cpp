#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    bool buy;
    ll n;
};

Data D[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 2 * N) {
        char c;
        cin >> c;
        D[i].buy = (c == '-');
        if (D[i].buy) {
            cin >> D[i].n;
        }
    }

    stack<ll> s;
    vector<ll> ans(N);
    vector<ll> v;
    REP(i, 2 * N) {
        if (!D[i].buy)
            v.push_back(i);
    }
    REP(i, 2 * N) {
        if (!D[i].buy) {
            auto t = lower_bound(v.begin(), v.end(), i) - v.begin();
            s.push(t);
            continue;
        }
        if (s.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        {
            ll t = s.top();
            s.pop();
            ans[t] = D[i].n;
        }
    }

    {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        ll index = 0;
        REP(i, 2 * N) {
            if (D[i].buy) {
                ll t = q.top();
                q.pop();
                if (t != D[i].n) {
                    cout << "NO" << endl;
                    return 0;
                }
                continue;
            }
            q.push(ans[index]);
            index++;
        }
    }

    cout << "YES" << endl;
    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}