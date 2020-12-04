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
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<string> S(N);
    REP(i, N) {
        string s;
        REP(j, M) {
            if (j < A)
                s.push_back('1');
            else
                s.push_back('0');
        }
        S[i] = s;
    }

    REP(j, M) {
        ll c = 0;
        REP(i, N) {
            if (S[i][j] == '1')
                c++;
        }
        REP(i, std::max(0LL, c - B)) {
            S[N - 1 - i][j] = '0';
            if (j + A < M)
                S[N - 1 - i][j + A] = '1';
        }
    }

    REP(i, N) {
        ll c = 0;
        REP(j, M) {
            if (S[i][j] == '1')
                c++;
        }
        if (c != A) {
            cout << "NO" << endl;
            return;
        }
    }
    REP(j, M) {
        ll c = 0;
        REP(i, N) {
            if (S[i][j] == '1')
                c++;
        }
        if (c != B) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    REP(i, N) {
        cout << S[i] << endl;
    }
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