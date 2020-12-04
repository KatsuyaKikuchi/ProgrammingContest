#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 26;

ll D;
ll C[30];
ll S[400][30];
ll T[400];
ll P[400];
set<ll> Last[30];
ll Damage[400][30];

ll calc(ll t, ll d, ll score) {
    score += S[d][t];
    REP(i, MAX) {
        if (t == i)
            continue;
        score -= C[i] * (d - *Last[i].rbegin());
    }
    return score;
}

ll changeCalc(ll d, ll q, ll score) {
    ll old = P[d];
    score += S[d][q] - S[d][old];

    auto oldIt = Last[old].lower_bound(d);
    auto newIt = Last[q].lower_bound(d);

    {
        oldIt--;
        ll p = *oldIt;
        oldIt++;
        oldIt++;
        ll n = D;
        if (oldIt != Last[old].end()) {
            n = *oldIt;
        }
        score += Damage[d - p - 1][old] + Damage[n - d - 1][old];
        score -= Damage[n - p - 1][old];
    }
    {
        ll n = D;
        if (newIt != Last[q].end()) {
            n = *newIt;
        }
        newIt--;
        ll p = *newIt;
        score += Damage[n - p - 1][q];
        score -= Damage[d - p - 1][q] + Damage[n - d - 1][q];
    }

    return score;
}

ll change(ll d, ll q, ll score) {
    score = changeCalc(d, q, score);
    ll old = P[d];
    {
        auto it = Last[old].lower_bound(d);
        Last[old].erase(it);
    }
    {
        Last[q].insert(d);
    }
    P[d] = q;
    return score;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> D;
    REP(i, MAX) {
        cin >> C[i];
    }
    REP(i, D) {
        REP(j, MAX) {
            cin >> S[i][j];
        }
    }
    REP(i, D) {
        cin >> T[i];
        T[i]--;
    }
    ll score = 0;
    REP(i, MAX) {
        Last[i].insert(-1);
    }
    REP(i, D) {
        score = calc(T[i], i, score);
        Last[T[i]].insert(i);
        P[i] = T[i];
    }

    memset(Damage, 0, sizeof(Damage));
    REP(i, MAX) {
        REP(j, D) {
            Damage[j + 1][i] = Damage[j][i] + C[i] * (j + 1);
        }
    }

    ll M;
    cin >> M;
    REP(_, M) {
        ll d, q;
        cin >> d >> q;
        d--;
        q--;
        score = change(d, q, score);
        cout << score << endl;
    }


    return 0;
}