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
const ll MAX_NUM = 1500;

ll D;
ll C[30];
ll S[400][30];
ll T[400];
vector<ll> Past;
vector<set<ll>> Last;
ll Damage[400][30];


struct TestCase {
    TestCase() {
        std::random_device rnd;
        mMt = std::mt19937(rnd());
    }

    int get(int low, int height) {
        if (low > height)
            swap(low, height);
        int d = height - low;
        if (d == 0)
            return low;
        std::uniform_int_distribution<> rand(0, d);
        return low + rand(mMt);
    }

    std::mt19937 mMt;
};

ll calc(ll t, ll d, ll score) {
    score += S[d][t];
    REP(i, MAX) {
        if (t == i)
            continue;
        score -= C[i] * (d - *Last[i].rbegin());
    }
    return score;
}

ll changeCalc(ll d, ll q, ll score, const vector<set<ll>> &last, const vector<ll> &past) {
    ll old = past[d];
    score += S[d][q] - S[d][old];

    auto oldIt = last[old].lower_bound(d);
    auto newIt = last[q].lower_bound(d);

    {
        oldIt--;
        ll p = *oldIt;
        oldIt++;
        oldIt++;
        ll n = D;
        if (oldIt != last[old].end()) {
            n = *oldIt;
        }
        score += Damage[d - p - 1][old] + Damage[n - d - 1][old];
        score -= Damage[n - p - 1][old];
    }
    {
        ll n = D;
        if (newIt != last[q].end()) {
            n = *newIt;
        }
        newIt--;
        ll p = *newIt;
        score += Damage[n - p - 1][q];
        score -= Damage[d - p - 1][q] + Damage[n - d - 1][q];
    }

    return score;
}

ll change(ll d, ll q, ll score, vector<set<ll>> &last, vector<ll> &past) {
    score = changeCalc(d, q, score, last, past);
    ll old = past[d];
    {
        auto it = last[old].lower_bound(d);
        last[old].erase(it);
    }
    {
        last[q].insert(d);
    }
    past[d] = q;
    return score;
}

ll randomChange(ll d, ll q, ll score, ll num, vector<pll> &changeVec) {
    vector<set<ll>> CopyLast(MAX);
    REP(i, MAX) {
        auto it = Last[i].begin();
        while (it != Last[i].end()) {
            CopyLast[i].insert(*it);
            it++;
        }
    }
    changeVec.clear();

    TestCase randGen = TestCase();
    vector<ll> past(D);
    REP(i, D) {
        past[i] = Past[i];
    }

    score = change(d, q, score, CopyLast, past);
    changeVec.push_back(pll(d, q));
    if (d == D - 1)
        return score;
    REP(_, num) {
        ll dt = randGen.get(d + 1, D - 1);
        ll qt = randGen.get(0, MAX - 1);
        ll s = changeCalc(dt, qt, score, CopyLast, past);
        if (s > score) {
            score = change(dt, qt, score, CopyLast, past);
            changeVec.push_back(pll(dt, qt));
        }
    }
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
        T[i] = 0;
    }
    ll score = 0;
    Last.resize(MAX);
    REP(i, MAX) {
        Last[i].clear();
        Last[i].insert(-1);
    }
    Past.resize(D);
    REP(i, D) {
        score = calc(T[i], i, score);
        Last[T[i]].insert(i);
        Past[i] = T[i];
    }

    memset(Damage, 0, sizeof(Damage));
    REP(i, MAX) {
        REP(j, D) {
            Damage[j + 1][i] = Damage[j][i] + C[i] * (j + 1);
        }
    }

    REP(i, D) {
        //! i+1日目以降をワンダムに変形させ、最も解がよくなるものを選ぶ

#if false
        pll mx = pll(score, T[i]);
        REP(j, MAX) {
            ll s = changeCalc(i, j, score);
            if (s > mx.first)
                mx = pll(s, j);
        }
        score = change(i, mx.second, score);
        T[i] = mx.second;
#else
        vector<pll> C;
        pll mx = pll(score, T[i]);
        REP(j, MAX) {
            vector<pll> changeVec;
            ll s = randomChange(i, j, score, MAX_NUM, changeVec);
            if (s > mx.first) {
                C.swap(changeVec);
                mx = pll(s, j);
            }
        }
        REP(i, C.size()) {
            pll t = C[i];
            score = change(t.first, t.second, score, Last, Past);
            T[t.first] = t.second;
        }
        //score = change(i, mx.second, score, Last, Past);
        //T[i] = mx.second;
#endif
    }

    REP(i, D) {
        cout << T[i] + 1 << endl;
    }

    return 0;
}