#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[505][505];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    memset(T, 0, sizeof(T));
    REP(i, N) {
        for (ll j = 1; i + j <= N; j++) {

            T[i][j] += T[i][j - 1];
            if (j % 2 != 0)
                continue;
            bool exist = true;
            REP(k, j / 2) {
                if (S[i + k] != S[i + j / 2 + k])
                    exist = false;
            }
            if (exist)
                T[i][j]++;
        }
    }

    ll ans = 0;
    FOR(i, N, 1) {
        //! S_2の始まりを決める
        for (ll j = 1; j < N; ++j) {
            //! 少なくとも3文字以上残っていないとダメ
            if (N - (2 * j + i) < 3)
                break;
            bool exist = true;
            REP(k, j) {
                if (S[i + k] != S[N - j + k])
                    exist = false;
            }
            if (!exist)
                continue;

            ans += T[i + j][N - (2 * j + i) - 1];
        }
    }
    cout << ans << endl;
    return 0;
}