#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K, N, M;
    cin >> K >> N >> M;
    REP(i, K) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + K, greater<pll>());
    ll T = (K + 1) / 2;
    ll S = (N - M) * 100LL;

    {
        ll border = A[T - 1].first;
        vector<ll> v;
        REP(i, K) {
            if (border > A[i].first)
                break;
            if (border + S <= A[i].first) {
                v.push_back(A[i].second + 1);
                continue;
            }
            if (A[T].first + S > A[i].first)
                continue;
            if (A[T].first + S <= A[i].first)
                v.push_back(A[i].second + 1);
        }

        sort(v.begin(), v.end());
        REP(i, v.size()) {
            cout << v[i] << endl;
        }
    }
    cout << "--------" << endl;
    {
        vector<ll> v;
        REP(i, T) {
            v.push_back(A[i].second + 1);
        }
        FOR(i, K, T) {
            if (A[i].first + S >= A[T - 1].first)
                v.push_back(A[i].second + 1);
        }
        sort(v.begin(), v.end());
        REP(i, v.size()) {
            cout << v[i] << endl;
        }
    }

    return 0;
}