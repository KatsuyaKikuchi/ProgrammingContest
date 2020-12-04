#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve(vector<ll> &A) {
    ll N = A.size();
    map<ll, bool> M;

    vector<ll> B(N);
    vector<ll> v;
    REP(i, N) {
        REP(j, 11) {
            if (A[i] % P[j] == 0) {
                B[i] = j;
                v.push_back(j);
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() << endl;
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), B[i]) - v.begin();
        cout << index + 1;
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        solve(A);
    }
    return 0;
}