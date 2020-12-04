#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    vector<vector<ll>> ans;

    while (true) {
#if false
        REP(i, N) {
            cout << A[i] << " ";
        }
        cout << endl;
        cout << "--------------------" << endl;
#endif

        bool e = true;
        REP(i, N - 1) {
            if (A[i] + 1 == A[i + 1])
                continue;
            e = false;
            break;
        }
        if (e)
            break;
        vector<ll> v;
        if (A[0] != 1) {
            ll idx = 0;
            FOR(i, N, 1) {
                if (A[i] + 1 == A[0]) {
                    idx = i;
                    break;
                }
            }
            ll nums = 1;
            FOR(i, N, 1) {
                if (A[i] == A[i - 1] + 1)
                    nums++;
                else
                    break;
            }
            v.push_back(nums);
            v.push_back(idx + 1 - nums);
            if (idx != N - 1)
                v.push_back(N - 1 - idx);
        }
        else if (A[N - 1] != N) {
            ll idx = 0;
            REP(i, N - 1) {
                if (A[N - 1] + 1 == A[i]) {
                    idx = i;
                    break;
                }
            }
            ll nums = 1;
            for (ll i = N - 2; i >= 0; --i) {
                if (A[i] + 1 == A[i + 1])
                    nums++;
                else
                    break;
            }
            if (idx > 0)
                v.push_back(idx);
            v.push_back(N - idx - nums);
            v.push_back(nums);
        }
        else {
            ll idx = 0;
            REP(i, N - 1) {
                if (A[i] + 1 != A[i + 1]) {
                    idx = i + 1;
                    break;
                }
            }
            v.push_back(idx);
            ll nums = 1;
            FOR(i, N, idx + 1) {
                if (A[i] == A[i - 1] + 1)
                    nums++;
                else
                    break;
            }
            v.push_back(nums);
            ll idx2 = 0;
            REP(i, N) {
                if (A[idx] == A[i] + 1) {
                    idx2 = i;
                    break;
                }
            }
            v.push_back(idx2 - idx + 1 - nums);
            v.push_back(N - 1 - idx2);
        }
        ans.push_back(v);

        vector<vector<ll>> t;
        ll index = 0;
        REP(i, v.size()) {
            vector<ll> tt;
            REP(j, v[i]) {
                tt.push_back(A[index]);
                index++;
            }
            t.push_back(tt);
        }
        index = 0;
        for (ll i = t.size() - 1; i >= 0; --i) {
            REP(j, t[i].size()) {
                A[index++] = t[i][j];
            }
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