#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

ll A[200005];
Vertex V[200005];
ll D[200005];
bool U[200005];
stack<ll> S[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(pll(0, 0));
    U[0] = true;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        D[t.first] = t.second;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i];
            if (U[n])
                continue;
            U[n] = true;
            q.push(pll(n, t.second + 1));
        }
    }

    REP(i, N) {
        S[(i + 1) % 3].push(i + 1);
    }

    vector<ll> odd, even;
    REP(i, N) {
        ll depth = D[i];
        if ((depth % 2) == 0)
            even.push_back(i);
        else
            odd.push_back(i);
    }

    if (even.size() <= S[0].size()) {
        REP(i, even.size()) {
            ll index = even[i];
            A[index] = S[0].top();
            S[0].pop();
        }
        REP(i, odd.size()) {
            ll index = odd[i];
            REP(j, 3) {
                if (S[j].empty())
                    continue;
                A[index] = S[j].top();
                S[j].pop();
                break;
            }
        }
    }
    else if (odd.size() <= S[0].size()) {
        REP(i, odd.size()) {
            ll index = odd[i];
            A[index] = S[0].top();
            S[0].pop();
        }
        REP(i, even.size()) {
            ll index = even[i];
            REP(j, 3) {
                if (S[j].empty())
                    continue;
                A[index] = S[j].top();
                S[j].pop();
                break;
            }
        }
    }
    else {
        if (odd.size() >= S[1].size()) {
            REP(i, odd.size()) {
                ll index = odd[i];
                ll n = 0;
                if (!S[1].empty()) {
                    n = S[1].top();
                    S[1].pop();
                }
                else {
                    n = S[0].top();
                    S[0].pop();
                }
                A[index] = n;
            }
            REP(i, even.size()) {
                ll index = even[i];
                ll n = 0;
                if (!S[2].empty()) {
                    n = S[2].top();
                    S[2].pop();
                }
                else {
                    n = S[0].top();
                    S[0].pop();
                }
                A[index] = n;
            }
        }
        else {
            REP(i, even.size()) {
                ll index = even[i];
                ll n = 0;
                if (!S[1].empty()) {
                    n = S[1].top();
                    S[1].pop();
                }
                else {
                    n = S[0].top();
                    S[0].pop();
                }
                A[index] = n;
            }
            REP(i, odd.size()) {
                ll index = odd[i];
                ll n = 0;
                if (!S[2].empty()) {
                    n = S[2].top();
                    S[2].pop();
                }
                else {
                    n = S[0].top();
                    S[0].pop();
                }
                A[index] = n;
            }
        }
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
