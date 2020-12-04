#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string T0[3] = {"aa.",
                "..b",
                "..b"};
string T1[4] = {"aabc",
                "ddbc",
                "bcaa",
                "bcdd"};
string T2[5] = {"aabba",
                "bcc.a",
                "b..cb",
                "a..cb",
                "abbaa"};
string T3[6] = {"aabc..",
                "ddbc..",
                "..aabc",
                "..ddbc",
                "ab..aa",
                "ab..bb"};
string T4[7] = {"aabbcc.",
                "dd.dd.a",
                "..d..da",
                "..d..db",
                "dd.dd.b",
                "..d..dc",
                "..d..dc"};

int main() {
    ll N;
    cin >> N;
    if (N == 2) {
        cout << -1 << endl;
        return 0;
    }

    if (N == 3) {
        REP(i, N) {
            cout << T0[i] << endl;
        }
        return 0;
    }

    REP(i, N) {
        if (N - 4 * i > 7)
            continue;

        REP(j, i) {
            REP(t, 4) {
                REP(k, N) {
                    if (j * 4 <= k && (j + 1) * 4 > k)
                        cout << T1[t][k - j * 4];
                    else
                        cout << '.';
                }
                cout << endl;
            }
        }

        ll n = N - 4 * i;
        REP(t, n) {
            REP(j, N) {
                if (i * 4 <= j) {
                    if (n == 4)
                        cout << T1[t][j - i * 4];
                    else if (n == 5)
                        cout << T2[t][j - i * 4];
                    else if (n == 6)
                        cout << T3[t][j - i * 4];
                    else
                        cout << T4[t][j - i * 4];
                }
                else
                    cout << '.';
            }
            cout << endl;
        }
        break;
    }
    return 0;
}