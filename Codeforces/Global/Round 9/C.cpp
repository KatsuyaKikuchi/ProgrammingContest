#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N + 5);
    REP(i, N) {
        cin >> A[i];
        B[A[i]] = i;
    }
    ll x = A[0];
    ll index = 1;
    std::set<ll> s;
    FOR(i, N, 1) {
        s.insert(A[i]);
    }
    while (index < N) {
        if (x < A[index]) {
            s.erase(A[index]);
            index++;
            continue;
        }

        auto it = s.lower_bound(x);
        if (it == s.end()) {
            return false;
        }
        ll nxt = *it;
        while (index < N) {
            s.erase(A[index]);
            if (A[index] == nxt) {
                x = nxt;
                break;
            }
            index++;
        }
        index++;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}