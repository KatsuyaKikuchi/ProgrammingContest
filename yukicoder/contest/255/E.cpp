#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Matrix {
    Matrix(int r, int c, long long int id = 0)
            : mR(r), mC(c) {
        init(id);
    }

    void init(long long int id) {
        mMat.resize(mR, vector<long long int>(mC, id));
    }

    void print() {
        REP(i, mR) {
            REP(j, mC) {
                cout << mMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] + obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] - obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-() {
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = -this->mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator*(const Matrix &obj) {
        assert(this->mC == obj.mR);
        Matrix ret(this->mR, obj.mC);
        for (int r = 0; r < ret.mR; ++r) {
            for (int c = 0; c < ret.mC; ++c) {
                for (int i = 0; i < this->mC; ++i) {
                    ret.mMat[r][c] += this->mMat[r][i] * obj.mMat[i][c] % MOD;
                    ret.mMat[r][c] %= MOD;
                }
            }
        }
        return ret;
    }

    Matrix &operator=(const Matrix &obj) {
        this->mR = obj.mR;
        this->mC = obj.mC;
        init(0);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                this->mMat[r][c] = obj.mMat[r][c];
            }
        }
        return *this;
    }

    vector<long long int> &operator[](int r) {
        assert(r < mR);
        return mMat[r];
    }

    int mR;
    int mC;
    vector<vector<long long int>> mMat;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;
    N--;

    Matrix mat(3, 3);
    mat[0][0] = mat[1][1] = mat[2][2] = 1;
    mat[0][1] = mat[1][2] = mat[2][0] = MOD - 1;

    Matrix ans(3, 3);
    ans[0][0] = ans[1][1] = ans[2][2] = 1;
    while (N > 0) {
        if (N & 1) {
            ans = ans * mat;
        }
        N /= 2;
        mat = mat * mat;
    }
    // ans.print();

    Matrix vec(3, 1);
    vec[0][0] = A;
    vec[1][0] = B;
    vec[2][0] = C;

    Matrix m = ans * vec;
    cout << m[0][0] << " " << m[1][0] << " " << m[2][0] << endl;
    return 0;
}