#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N + 5, 0);
    REP(i, N) {
        cin >> A[i];
        B[A[i]]++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    REP(i, N + 1) {
        if (B[i] > 0)
            continue;
        q.push(i);
    }

    vector<ll> ans;

    while (!q.empty()) {
        ll n = q.top();
        if (n == N)
            break;
        q.pop();

        if (--B[A[n]] == 0) {
            q.push(A[n]);
        }
        ans.push_back(n + 1);
        B[n]++;
        A[n] = n;
    }

    REP(i, N) {
        if (A[i] == i)
            continue;
        FOR(j, N, i + 1) {
            if (A[j] != i)
                continue;

            ans.push_back(j + 1);
            ll n = q.top();
            q.pop();
            if (--B[A[j]] == 0) {
                q.push(A[j]);
            }
            B[n]++;
            A[j] = n;
        }
        ll n = q.top();
        q.pop();
        if (--B[A[i]] == 0) {
            q.push(A[i]);
        }
        A[i] = n;
        B[n]++;
        ans.push_back(i + 1);

#if false
        REP(j, N) {
            cout << A[j] << " ";
        }
        cout << endl;
        cout << "-------" << endl;
#endif

        bool e = true;
        REP(j, N - 1) {
            if (A[j] > A[j + 1]) {
                e = false;
                break;
            }
        }
        if (e)
            break;
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}