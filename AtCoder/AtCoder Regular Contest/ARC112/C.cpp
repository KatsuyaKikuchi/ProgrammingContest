#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    ll p;
    vector<ll> c;
    ll num_edge = 0;
    ll num_vertex = 0;
    ll count = 0;
    ll get = 1;
};

Vertex V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V[0].p = -1;
    REP(i, N - 1) {
        ll p;
        cin >> p;
        p--;
        V[p].c.push_back(i + 1);
        V[i + 1].p = p;
    }

    queue<ll> q;
    REP(i, N) {
        if (V[i].c.size() == 0)
            q.push(i);
    }
    while (!q.empty()) {
        // 頂点tに来たときに、いくつ取れるのか？を調べる
        ll t = q.front();
        q.pop();
        V[t].num_edge = 0;
        V[t].num_vertex = 1;
        vector<ll> odd, even, even_good;
        for (auto &child:V[t].c) {
            V[t].num_edge += V[child].num_edge + 1;
            V[t].num_vertex += V[child].num_vertex;
            ll x = V[child].num_edge * 2LL + V[child].num_vertex;
            if (x % 2 == 0) {
                ll y = V[child].num_vertex - 2LL * V[child].get;
                if (y > 0)
                    even_good.push_back(child);
                else
                    even.push_back(child);
            }
            else
                odd.push_back(child);
        }

        V[t].get = 1;
        //! oddの頂点を相手にとられる数が少ない順に選んでいく選ぶ
        sort(odd.begin(), odd.end(), [](ll a, ll b) {
            ll x = V[a].num_vertex - 2LL * V[a].get;
            ll y = V[b].num_vertex - 2LL * V[b].get;
            return x > y;
        });
        {
            REP(i, even_good.size()) {
                V[t].get += V[even_good[i]].get;
            }
            REP(i, odd.size()) {
                if (i % 2 == 0)
                    V[t].get += V[odd[i]].get;
                else
                    V[t].get += V[odd[i]].num_vertex - V[odd[i]].get;
            }
            if ((odd.size() % 2LL) == 0) {
                REP(i, even.size()) {
                    V[t].get += V[even[i]].get;
                }
            }
            else {
                REP(i, even.size()) {
                    V[t].get += V[even[i]].num_vertex - V[even[i]].get;
                }
            }
        }

        if (V[t].p >= 0) {
            ll p = V[t].p;
            V[p].count++;
            if (V[p].count == V[p].c.size()) {
                q.push(p);
            }
        }
    }
    cout << V[0].get << endl;
#if false
    REP(i, N) {
        cout << V[i].get << " ";
    }
    cout << endl;
    REP(i, N) {
        cout << V[i].num_vertex << " ";
    }
    cout << endl;
#endif
    return 0;
}