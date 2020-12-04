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

Vertex V[100005];
bool A[100005], B[100005];
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[b].node.push_back(a);
    }
    string S;
    cin >> S;
    S.push_back('\"');

    ll group = 0;
    vector<bool> v;
    REP(i, S.length()) {
        if (group > 0) {
            if (S[i] == 'w')
                v.push_back(true);
            else
                v.push_back(false);
            while (i < S.length() && S[i] != '\"')
                i++;
            continue;
        }

        if (S[i] < '0' || '9' < S[i])
            continue;
        while (i < S.length() && S[i] >= '0' && '9' >= S[i]) {
            group = group * 10 + S[i] - '0';
            i++;
        }
        i--;
    }

#if false
    cout << group << endl;
    REP(i, v.size()) {
        if (v[i])
            cout << "x";
        else
            cout << "o";
    }
    cout << endl;
#endif

    group--;
    memset(A, 0, sizeof(A));

    A[group] = true;
    REP(i, v.size()) {
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        ll num = 0;
        REP(j, N) {
            if (!A[j])
                continue;
            num++;
            for (auto &n:V[j].node) {
                B[n] = true;
                C[n]++;
            }
        }

        if (!v[i]) {
            REP(i, N) {
                if (num == C[i])
                    B[i] = false;
                else
                    B[i] = true;
            }
        }
        swap(A, B);
    }

    ll ans = 0;
    REP(i, N) {
        if (A[i])
            ans++;
    }
    cout << ans << endl;

    return 0;
}