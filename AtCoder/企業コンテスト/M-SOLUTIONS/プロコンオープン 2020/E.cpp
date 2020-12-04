#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll g;
    ll P;
};

ll A[20];
ll N;
Data D[20];

ll calc(vector<ll> &X, vector<ll> &Y) {
    ll ret = 0;
    REP(i, N) {
        ll mn = INF;
        {
            auto x = lower_bound(X.begin(), X.end(), D[i].g.first) - X.begin();
            if (x < X.size()) {
                mn = std::min(mn, abs(X[x] - D[i].g.first));
            }
            x--;
            if (x >= 0) {
                mn = std::min(mn, abs(X[x] - D[i].g.first));
            }
        }
        {
            auto y = lower_bound(Y.begin(), Y.end(), D[i].g.second) - Y.begin();
            if (y < Y.size()) {
                mn = std::min(mn, abs(Y[y] - D[i].g.second));
            }
            y--;
            if (y >= 0) {
                mn = std::min(mn, abs(Y[y] - D[i].g.second));
            }
        }
        ret += (D[i].P * mn);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> D[i].g.first >> D[i].g.second >> D[i].P;
    }

    REP(i, N + 1) {
        A[i] = INF;
    }

    ll p = pow(3LL, N);
    REP(b, p) {
        vector<ll> v;
        vector<ll> X, Y;
        X.push_back(0);
        Y.push_back(0);
        ll bit = b;
        ll n = 0;
        ll m = 0;
        while (bit > 0) {
            ll t = bit % 3;
            if (t > 0) {
                if (t == 1)
                    X.push_back(D[m].g.first);
                else if (t == 2)
                    Y.push_back(D[m].g.second);
                n++;
            }
            bit /= 3;
            m++;
        }

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        A[n] = std::min(A[n], calc(X, Y));
    }

    REP(x, N + 1) {
        cout << A[x] << endl;
    }
    return 0;
}