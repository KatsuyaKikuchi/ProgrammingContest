#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> v0, v1, v2;
    ll s0 = 0, s1 = 0, s2 = 0;
    {
        v0.push_back(A[0]);
        REP(i, N - 1) {
            ll a = std::min(A[i + 1], v0[i]);
            v0.push_back(a);
        }
        REP(i, N) {
            s0 += v0[i];
        }
    }
    {
        v1.push_back(A[N - 1]);
        REP(i, N - 1) {
            ll a = std::min(A[N - 2 - i], v1[i]);
            v1.push_back(a);
        }
        reverse(v1.begin(), v1.end());
        REP(i, N) {
            s1 += v1[i];
        }
    }

    {
        REP(i, N) {
            vector<ll> v(N);
            ll s = 0;
            v[i] = A[i];
            for (ll j = i - 1; j >= 0; --j) {
                v[j] = std::min(v[j + 1], A[j]);
            }
            for (ll j = i + 1; j < N; ++j) {
                v[j] = std::min(v[j - 1], A[j]);
            }

            REP(j, N) {
                s += v[j];
            }

            if (s > s2) {
                s2 = s;
                v2.swap(v);
            }
        }
    }

    ll max = std::max({s0, s1, s2});
    if (max == s0) {
        REP(i, N) {
            cout << v0[i];
            if (i < N - 1)
                cout << " ";
        }
        cout << endl;
    }
    else if (max == s1) {
        REP(i, N) {
            cout << v1[i];
            if (i < N - 1)
                cout << " ";
        }
        cout << endl;
    }
    else {
        REP(i, N) {
            cout << v2[i];
            if (i < N - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}