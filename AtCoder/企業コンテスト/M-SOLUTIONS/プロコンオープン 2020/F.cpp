#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<pll> U, D, L, R;
    REP(i, N) {
        pll g;
        cin >> g.first >> g.second;
        char x;
        cin >> x;
        if (x == 'U')
            U.push_back(g);
        else if (x == 'D')
            D.push_back(g);
        else if (x == 'L')
            L.push_back(g);
        else if (x == 'R')
            R.push_back(g);
    }

    ll ans = INF;
    {
        std::map<ll, set<ll>> M;
        REP(i, L.size()) {
            M[L[i].second].insert(L[i].first);
        }

        REP(i, R.size()) {
            auto it = M[R[i].second].lower_bound(R[i].first);
            if (it == M[R[i].second].end())
                continue;
            ll d = (*it) - R[i].first;
            ans = std::min(ans, d * 5LL);
        }
    }
    {
        //! U&D
        std::map<ll, set<ll>> M;
        REP(i, D.size()) {
            M[D[i].first].insert(D[i].second);
        }

        REP(i, U.size()) {
            auto it = M[U[i].first].lower_bound(U[i].second);
            if (it == M[U[i].first].end())
                continue;
            ll d = (*it) - U[i].second;
            ans = std::min(ans, d * 5LL);
        }
    }
    {
        //!L&D
        std::map<ll, std::set<ll>> M;
        REP(i, L.size()) {
            ll y = L[i].second + L[i].first;
            M[y].insert(L[i].first);
        }

        REP(i, D.size()) {
            ll y = D[i].second + D[i].first;
            auto it = M[y].lower_bound(D[i].first);
            if (it == M[y].end())
                continue;
            ll d = (*it) - D[i].first;
            ans = std::min(ans, d * 10LL);
        }
    }
    {
        //!L&U
        std::map<ll, std::set<ll>> M;
        REP(i, L.size()) {
            ll y = L[i].second - L[i].first;
            M[y].insert(L[i].first);
        }

        REP(i, U.size()) {
            ll y = U[i].second - U[i].first;
            auto it = M[y].lower_bound(U[i].first);
            if (it == M[y].end())
                continue;
            ll d = (*it) - U[i].first;
            ans = std::min(ans, d * 10LL);
        }
    }
    {
        //! R&D
        std::map<ll, std::set<ll>> M;
        REP(i, D.size()) {
            ll y = D[i].second - D[i].first;
            M[y].insert(D[i].first);
        }

        REP(i, R.size()) {
            ll y = R[i].second - R[i].first;
            auto it = M[y].lower_bound(R[i].first);
            if (it == M[y].end())
                continue;
            ll d = (*it) - R[i].first;
            ans = std::min(ans, d * 10LL);
        }
    }
    {
        //! R&U
        std::map<ll, std::set<ll>> M;
        REP(i, U.size()) {
            ll y = U[i].second + U[i].first;
            M[y].insert(U[i].first);
        }

        REP(i, R.size()) {
            ll y = R[i].second + R[i].first;
            auto it = M[y].lower_bound(R[i].first);
            if (it == M[y].end())
                continue;
            ll d = (*it) - R[i].first;
            ans = std::min(ans, d * 10LL);
        }
    }

    if (ans == INF)
        cout << "SAFE" << endl;
    else
        cout << ans << endl;
    return 0;
}