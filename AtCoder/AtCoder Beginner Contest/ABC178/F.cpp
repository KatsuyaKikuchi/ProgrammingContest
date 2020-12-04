#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];
pll NA[200005];
pll NB[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    memset(NA, 0, sizeof(NA));
    memset(NB, 0, sizeof(NB));
    REP(i, N) {
        cin >> A[i];
        NA[A[i] - 1].first = A[i];
        NA[A[i] - 1].second++;
    }
    REP(i, N) {
        cin >> B[i];
        NA[B[i] - 1].first = B[i];
        NA[B[i] - 1].second++;
    }

    REP(i, 200005) {
        ll mx = std::max(NA[i].second, NB[i].second);
        ll mn = std::min(NA[i].second, NB[i].second);
        if (N - mx < mn) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

#if false
    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
#endif
    vector<pll> v;
    while (true) {
        v.clear();
        REP(i, N) {
            if (A[i] != B[i])
                continue;
            pll p(i, 1);
            if (i > 0 && A[i - 1] == B[i - 1] && B[i] == B[i - 1]) {
                p.first = v.back().first;
                p.second = v.back().second + 1;
                v.pop_back();
            }
            v.push_back(p);
        }

        sort(v.begin(), v.end(), [](pll a, pll b) { return a.second > b.second; });
        if (v.size() <= 1)
            break;
        auto t = v;
        ll index = 1;
        REP(i, v.size()) {
            REP(j, v[i].second) {
                if (t[index].second == 0) {
                    index = (index + 1) % v.size();
                }
                B[v[i].first + j] = A[t[index].first];
                t[index].second--;
                t[index].first++;
            }
        }
    }

    if (v.size() >= 1) {
        ll p = B[v[0].first];
        queue<ll> q;
        REP(i, N) {
            if (A[i] != p && B[i] != p)
                q.push(i);
        }

        if (v[0].second > q.size()) {
            cout << "No" << endl;
            return 0;
        }
        REP(i, v[0].second) {
            ll k = q.front();
            q.pop();
            B[v[0].first + i] = B[k];
            B[k] = A[v[0].first + i];
        }
    }
    REP(i, N) {
        cout << B[i] << " ";
    }
    cout <<
         endl;
    return 0;
}
