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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    REP(i, K) {
        ll a = 0, b = 0, c = 0;
        for (ll j = i; j < N; j += K) {
            if (S[j] == '0')
                a++;
            else if (S[j] == '1')
                b++;
            else
                c++;
        }

        if (a > 0 && b > 0)
            return false;
        char t = '?';
        if (a > 0)
            t = '0';
        else if (b > 0)
            t = '1';
        for (ll j = i; j < N; j += K) {
            S[j] = t;
        }
    }

    {
        ll a = 0, b = 0, c = 0;
        REP(i, K) {
            if (S[i] == '0')
                a++;
            else if (S[i] == '1')
                b++;
            else
                c++;
        }
        if (std::max(a, b) > std::min(a, b) + c)
            return false;
#if false
        FOR(i,N,K)
        {
            if (S[i] == '0')
                a++;
            else if (S[i] == '1')
                b++;
            else
                c++;

            if (S[i-K] == '0')
                a--;
            else if (S[i-K] == '1')
                b--;
            else
                c--;
        }
#endif
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