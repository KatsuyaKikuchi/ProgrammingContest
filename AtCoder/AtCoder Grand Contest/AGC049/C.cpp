#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll A[200005];
ll B[200005];
ll S[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll sum = 0;
    REP(i, N) {
        cin >> B[i];
        sum += B[i];
    }
    ll ans = sum;
    memset(S, 0, sizeof(S));
    ll left = INF;
    for (ll i = N - 1; i >= 0; --i) {
        S[i] = S[i + 1];
        if (A[i] > B[i]) {
            left = min(left, A[i] - B[i]);
            continue;
        }
        //! 放置しておくとロボット0を破壊してしまう。
        //! 回避する手段としては、
        //! 1 : ボールの数字を書き換え、0が破壊されないようにする
        //! 2 : 他のロボットで破壊するよう仕向ける
        //! の2パターンある
        {
            //! このロボットが1までのロボットを破壊するデストロイヤーとなる
            ll diff = B[i] - A[i] + 1; //! ロボットA[i]のボールを書き換えなければいけない個数
            //! ロボットA[i+k]でロボット0を破壊してしまうようなロボットの処理
            ans = std::min(ans, diff + std::max(0LL, S[i] - diff));
        }
        {
            //! パターン2、このロボットを破壊する
            if (left <= A[i]) {
                //! 勝手に破壊される
            }
            else {
                {
                    //! これ以前のロボットを全て破壊している時
                    //! またはA[i]<=B[i]のロボットがいない時
                    S[i]++;
                }
                {
                    //! これ以前にデストロイヤーがいる時
                    //! 何もする必要なし
                }
            }
        }
    }
    ans = std::min(ans, S[0]);
    cout << ans << endl;
    return 0;
}