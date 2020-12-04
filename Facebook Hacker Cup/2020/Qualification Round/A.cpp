#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool A[55][55];

void solve(std::ofstream &ws) {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    REP(i, N) {
        REP(j, N) {
            A[i][j] = false;
        }
    }

    REP(s, N) {
        A[s][s] = true;
        FOR(i, N, s + 1) {
            if (S[i] == 'N' || T[i - 1] == 'N')
                break;
            A[s][i] = true;
        }

        for (ll i = s - 1; i >= 0; --i) {
            if (S[i] == 'N' || T[i + 1] == 'N')
                break;
            A[s][i] = true;
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (A[i][j])
                ws << "Y";
            else
                ws << "N";
        }
        ws << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string filename = "A_ans.txt";
    std::ofstream ws;
    ws.open(filename, std::ios::out);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ws << "Case #" << i + 1 << ":" << endl;
        solve(ws);
    }
    return 0;
}