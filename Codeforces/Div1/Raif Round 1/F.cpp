#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S;
ll N;

ll test() {
    ll ret = 0;
    REP(i, N) {
        FOR(j, N, i) {
            ll s = 0;
            ll len = 0;
            FOR(k, j + 1, i) {
                if (S[k] == '0')
                    len = -1;
                len++;
                s = std::max(len, s);
            }
            ret += s;
        }
    }
    return ret;
}


int T[500005];
ll A[500005];
int I[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    //REP(_, pow(2LL, N))
    {

#if false
        S.clear();
        REP(j, N) {
            ll p = ((_ >> j) & 1);
            S.push_back('0' + p);
        }
#else
        cin >> S;
#endif
        //   cout << test() << endl;
        memset(T, 0, sizeof(T));
        ll len = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (S[i] == '0')
                len = -1;
            len++;
            T[i] = len;
        }
#if false
        REP(i, N) {
            cout << T[i] << " ";
        }
        cout << endl;
#endif

        REP(i, N + 1) {
            I[i] = -1;
        }

        ll ans = 0;
        memset(A, 0, sizeof(A));
        len = 0;
        vector<pll> v;
        REP(i, N) {
            if (S[i] == '0') {
                if (len > 0) {
                    I[0] = i;
                }
                len = -1;

                REP(i, v.size()) {
                    pll t = v[i];
                    I[t.first] = t.second;
                }
                v.clear();
            }
            len++;

            if (S[i] == '1') {
                ll sum = i - I[len];
                A[i] += sum;
                v.push_back(pll(T[i], i));
            }
           // cout << A[i] << " ";
            ans += A[i];
            A[i + 1] += A[i];
        }
       // cout << endl;
        cout << ans << endl;

#if false
        ll tst = test();
        if (ans != tst) {
            cout << ans << " " << tst << endl;
            cout << S << endl;
            break;
        }
#endif
    }
    return 0;
}