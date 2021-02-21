#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first;
        A[i].first--;
        A[i].second = i;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    vector<ll> ans;
    vector<bool> used(N, false);
    queue<pll> before, after;
    REP(i, N) {
        before.push(pll(A[i].second, A[i].second));
        after.push(pll(A[i].second, N - A[i].second - 1));
    }

    REP(i, N) {
        while (ans.size() < A[i].first) {
            while (!before.empty() && before.front().second <= 0) {
                before.pop();
            }
            while (!after.empty() && after.front().second <= 0) {
                after.pop();
            }

            if (!before.empty()) {
                auto &t = before.front();
                if (used[t.first]) {
                    cout << "No" << endl;
                    return 0;
                }
                ans.push_back(t.first + 1);
                t.second--;
                continue;
            }

            if (!after.empty()) {
                auto &t = after.front();
                if (!used[t.first]) {
                    cout << "No" << endl;
                    return 0;
                }
                ans.push_back(t.first + 1);
                t.second--;
                continue;
            }
            cout << "No" << endl;
            return 0;
        }
        ans.push_back(A[i].second + 1);
        used[A[i].second] = true;
    }
    while (!before.empty() && before.front().second <= 0) {
        before.pop();
    }
    if (!before.empty()) {
        cout << "No" << endl;
        return 0;
    }
    while (!after.empty()) {
        pll t = after.front();
        after.pop();
        REP(_, t.second) {
            ans.push_back(t.first + 1);
        }
    }
    cout << "Yes" << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}