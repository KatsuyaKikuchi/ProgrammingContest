#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll getIndex(const vector<ll> &V, ll value) {
    ll ok = 0, ng = V.size();
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (V[mid] <= value)
            ok = mid;
        else
            ng = mid;
    }
    if (ok == 0 && value < V[0])
        return -1;
    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> R, G, B;
    REP(i, 2 * N) {
        ll a;
        char c;
        cin >> a >> c;
        switch (c) {
            case 'R':
                R.push_back(a);
                break;
            case 'G':
                G.push_back(a);
                break;
            case 'B':
                B.push_back(a);
                break;
        }
    }
    sort(R.begin(), R.end());
    sort(G.begin(), G.end());
    sort(B.begin(), B.end());

    if (R.size() % 2 == 0 && G.size() % 2 == 0 && B.size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> X, Y, Z;
    if (R.size() % 2 == 1 && B.size() % 2 == 1) {
        swap(X, R);
        swap(Y, B);
        swap(Z, G);
    }
    else if (R.size() % 2 == 1 && G.size() % 2 == 1) {
        swap(X, R);
        swap(Y, G);
        swap(Z, B);
    }
    else {
        swap(X, G);
        swap(Y, B);
        swap(Z, R);
    }
    ll ans = INF;
    REP(i, X.size()) {
        ll idx = getIndex(Y, X[i]);
        if (idx >= 0)
            ans = std::min(ans, abs(X[i] - Y[idx]));
        if (idx + 1 < Y.size())
            ans = std::min(ans, abs(X[i] - Y[idx + 1]));
    }

    ll Xmin = INF, Ymin = INF;
    if (Z.size() >= 2) {
        REP(i, Z.size()) {
            ll xmin = INF, ymin = INF;
            {
                ll idx = getIndex(X, Z[i]);
                if (idx >= 0)
                    xmin = std::min(xmin, abs(Z[i] - X[idx]));
                if (idx + 1 < X.size())
                    xmin = std::min(xmin, abs(Z[i] - X[idx + 1]));
                ans = std::min(ans, xmin + Ymin);
            }
            {
                ll idx = getIndex(Y, Z[i]);
                if (idx >= 0)
                    ymin = std::min(ymin, abs(Z[i] - Y[idx]));
                if (idx + 1 < Y.size())
                    ymin = std::min(ymin, abs(Z[i] - Y[idx + 1]));
                ans = std::min(ans, ymin + Xmin);
            }
            Xmin = std::min(Xmin, xmin);
            Ymin = std::min(Ymin, ymin);
        }
    }
    cout << ans << endl;

    return 0;
}