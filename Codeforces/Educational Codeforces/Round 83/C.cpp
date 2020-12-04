#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e16;

ll S[60];

string solve(vector<ll> &A, ll K) {
    ll N = A.size();
    ll p = 1;
    ll max = 0;
    REP(i, N) {
        max = std::max(max, A[i]);
    }
    REP(_, 60) {
        S[_] = p;
        if (p > max)
            break;
        p *= K;
    }
    vector<ll> v;
    REP(i, N) {
        ll n = A[i];
        ll index = 0;
        while (n >= S[index])
            index++;
        while (index >= 0) {
            if (n >= S[index]) {
                n -= S[index];
                v.push_back(index);
            }
            index--;
        }
        if (n > 0)
            return "NO";
    }

    sort(v.begin(), v.end());
    REP(i, v.size()) {
        if (i + 1 >= v.size())
            break;
        if (v[i] == v[i + 1])
            return "NO";
    }
    return "YES";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        memset(S, 0, sizeof(S));
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A, K) << endl;
    }
    return 0;
}