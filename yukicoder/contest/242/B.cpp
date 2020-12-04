#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll x[4] = {-2, -1, 1, 2};

bool solve(string &S) {
    ll N = S.length();
    REP(i, N - 2) {
        ll a = 0, b = 0;
        REP(j, 3) {
            if (S[i + j] == 'o')
                a++;
            if (S[i + j] == '-')
                b++;
        }
        if (a + b == 3 && a > 1)
            return true;
    }
    REP(i, N - 3) {
        if (S[i] != '-' || S[i + 3] != '-')
            continue;
        if (S[i + 1] == 'o' && S[i + 2] == 'o')
            return true;
        if (S[i + 1] == 'o' && S[i + 2] == '-')
            return true;
        if (S[i + 1] == '-' && S[i + 2] == 'o')
            return true;
    }
    ll d = 0;
    bool f = false;
    REP(i, N) {
        if (S[i] == 'x') {
            d = 0;
            f = false;
            continue;
        }

        if (S[i] == '-') {
            if (f)
                d++;
            continue;
        }

        f = true;
        if (d % 2 == 1)
            return true;
        d = 0;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        ll N;
        string S;
        cin >> N >> S;
        if (solve(S))
            cout << "O" << endl;
        else
            cout << "X" << endl;
    }
    return 0;
}