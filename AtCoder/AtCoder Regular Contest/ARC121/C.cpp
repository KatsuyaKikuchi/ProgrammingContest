#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve(vector<ll> &A) {
    ll N = A.size();
    vector<ll> ans;
    REP(i, N * N) {
        bool sorted = true;
        REP(j, N - 1) {
            if (A[j] > A[j + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted)
            break;
        bool update = false;
        REP(j, N) {
            if (i % 2 != j % 2)
                continue;
            if (j + 1 >= N)
                break;
            if (A[j] > A[j + 1]) {
                update = true;
                swap(A[j], A[j + 1]);
                ans.push_back(j);
                break;
            }
        }
        if (!update) {
            for (ll j = N - 2; j >= 0; --j) {
                if (j % 2 == i % 2) {
                    swap(A[j], A[j + 1]);
                    ans.push_back(j);
                    break;
                }
            }
        }
#if false
        REP(j, N) {
            cout << A[j] << " ";
        }
        cout << endl;
#endif
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    {
        bool sorted = true;
        REP(j, N - 1) {

            if (A[j] > A[j + 1]) {
                sorted = false;
                break;
            }
        }
        return sorted;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
#if true
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        if (!solve(A)) {
            assert(false);
        }
    }
#else
    vector<ll> A;
    ll N = 8;
    REP(i, N) {
        A.push_back(i + 1);
    }
    do {
        vector<ll> v;
        REP(i, N) {
            v.push_back(A[i]);
        }
        if (!solve(v)) {
            assert(false);
        }
    } while (next_permutation(A.begin(), A.end()));
#endif
    return 0;
}