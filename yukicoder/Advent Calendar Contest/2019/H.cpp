#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

map<ll, vector<pll>> L;
map<ll, vector<pll>> R;
ll A[3];
bool U[200005];

int main() {
    ll N, M;
    cin >> N >> M;

    REP(i, M) {
        ll l, r;
        char c;
        cin >> l >> r >> c;
        l--;
        ll t = 0;
        if (c == 'Y')
            t = 0;
        else if (c == 'K')
            t = 1;
        else
            t = 2;
        L[l].push_back(pll(i, t));
        R[r].push_back(pll(i, t));
    }

    memset(A, 0, sizeof(A));
    memset(U, 0, sizeof(U));
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    REP(i, N) {
        auto rv = R[i];
        REP(j, rv.size()) {
            U[rv[j].first] = false;
        }
        auto lv = L[i];
        REP(j, lv.size()) {
            U[lv[j].first] = true;
            q.push(lv[j]);
        }

        while (!q.empty()) {
            pll t = q.top();
            if (!U[t.first]) {
                q.pop();
                continue;
            }
            A[t.second]++;
            break;
        }
    }

    REP(i, 3) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}