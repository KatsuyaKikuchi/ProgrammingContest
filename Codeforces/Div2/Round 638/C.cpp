#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll M[30];

string solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    memset(M, 0, sizeof(M));
    REP(i, N) {
        M[S[i] - 'a']++;
    }
    string ret = "";
    if (K == 1) {
        REP(i, 27) {
            REP(_, M[i]) {
                ret.push_back((char) (i + 'a'));
            }
        }
        return ret;
    }

    REP(i, 27) {
        if (M[i] == 0)
            continue;
        if (M[i] >= K) {
            ret.push_back((char) (i + 'a'));
            M[i] -= K;
            break;
        }

        REP(j, 27) {
            K -= M[j];
            if (K <= 0) {
                ret.push_back((char) (j + 'a'));
                break;
            }
        }
        return ret;
    }

    REP(i, 27) {
        if (M[i] == 0)
            continue;

        if (M[i] == N - K) {
            char c = 'a' + i;
            REP(_, ((M[i] + K - 1) / K)) {
                ret.push_back(c);
            }
            break;
        }

        REP(j, 27) {
            REP(_, M[j]) {
                ret.push_back((char) (j + 'a'));
            }
        }
        break;
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