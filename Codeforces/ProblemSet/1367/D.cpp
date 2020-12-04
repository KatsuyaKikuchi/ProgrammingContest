#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    string S;
    cin >> S;
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> C(26, 0);
    REP(i, S.length()) {
        C[S[i] - 'a']++;
    }

    string ret(N, 'a');
    while (true) {
        vector<ll> v;
        REP(i, N) {
            if (A[i] == 0)
                v.push_back(i);
        }
        if (v.size() == 0)
            break;
        REP(i, N) {
            if (A[i] < 0)
                continue;
            REP(j, v.size()) {
                A[i] -= abs(i - v[j]);
            }
        }

        for (ll i = 25; i >= 0; --i) {
            if (C[i] < v.size()) {
                C[i] = 0;
                continue;
            }
            REP(j, v.size()) {
                A[v[j]] = -1;
                ret[v[j]] += i;
            }
            C[i] = 0;
            break;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}