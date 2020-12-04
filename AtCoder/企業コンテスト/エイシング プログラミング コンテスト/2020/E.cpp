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
    ll K;
    ll L;
    ll R;
};

ll solve() {
    ll N;
    cin >> N;
    vector<Data> F, S, A;
    REP(i, N) {
        Data d;
        cin >> d.K >> d.L >> d.R;
        if (d.L == d.R)
            A.push_back(d);
        else if (d.L < d.R)
            S.push_back(d);
        else
            F.push_back(d);
    }
    sort(F.begin(), F.end(), [](Data a, Data b) {
        if (a.K == b.K)
            return abs(a.L - a.R) > abs(b.L - b.R);
        return a.K > b.K;
    });
    sort(S.begin(), S.end(), [](Data a, Data b) {
        if (a.K == b.K)
            return abs(a.L - a.R) > abs(b.L - b.R);
        return a.K < b.K;
    });
    ll ret = 0;
    REP(i, A.size()) {
        ret += A[i].L;
    }
    {
        priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) {
            return abs(a.L - a.R) < abs(b.L - b.R);
        });

        ll index = F.size();
        ll fi = 0;
        while (index > 0) {
            while (fi < F.size() && F[fi].K >= index) {
                q.push(F[fi++]);
            }
            index--;
            if (q.empty())
                continue;
            ret += q.top().L;
            q.pop();
        }

        while (!q.empty()) {
            ret += q.top().R;
            q.pop();
        }
    }
    {
        priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) {
            return abs(a.L - a.R) < abs(b.L - b.R);
        });

        ll index = F.size() + A.size() + 1;
        ll si = 0;
        while (index <= N) {
            while (si < S.size() && S[si].K < index) {
                q.push(S[si++]);
            }
            index++;
            if (q.empty())
                continue;
            ret += q.top().R;
            q.pop();
        }

        while (si < S.size()) {
            ret += S[si++].L;
        }
        while (!q.empty()) {
            ret += q.top().L;
            q.pop();
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}