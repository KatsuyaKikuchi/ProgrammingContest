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
                    ret.mMat[r][c] += this->mMat[r][i] * obj.mMat[i][c];
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
    ll N, K;
    cin >> N >> K;
    if (N <= K) {
        cout << 1 << endl;
        return 0;
    }

    return 0;
}