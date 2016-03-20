#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pll> vp;
typedef vector<ll> vll;

const int SIZE = 30;
const int H = SIZE, W = SIZE;
int a[H][W];
vp ans;
vp one;
vp t_one;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

void init() {
    one.clear();
    t_one.clear();
}

void updateOne() {
    if (t_one.size() > one.size()) {
        one.resize(t_one.size());
        rep(i, t_one.size()) {
            one[i] = t_one[i];
        }
    }
}

void dfs(int x, int y) {
    // cout << x << " " << y << endl;
    t_one.emplace_back(P(x, y));

    bool end = true;
    rep(k, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!inside(nx, ny)) continue;
        if (a[nx][ny] == 0) continue;
        if (a[nx][ny] == a[x][y] - 1) {
            // t_one.emplace_back(P(nx, ny));
            dfs(nx, ny);
            t_one.pop_back();
            end = false;
        }
    }

    if (end) updateOne();
}

void updateAns() {
    rep(i, one.size()) {
        ans.emplace_back(one[i]);
    }
}

void updateBoard() {
    rep(i, one.size()) {
        int x = one[i].first, y = one[i].second;
        a[x][y]--;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }

    rep(x, H) {
        rep(y, W) {
            while (a[x][y] > 0) {
                // cout << x << " " << y << endl;
                init();
                dfs(x, y);  // この手でつぶすライン(one)を決める
                updateAns();
                updateBoard();
            }
            // rep(i, H) {
            //     rep(j, W) {
            //         cout << a[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }

    rep(i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}
