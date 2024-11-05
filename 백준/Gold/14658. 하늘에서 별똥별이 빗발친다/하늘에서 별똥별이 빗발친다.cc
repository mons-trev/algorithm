#include<iostream>
#include<vector>

using namespace std;

int main() {
    int yy, xx, l, k;
    cin >> xx >> yy >> l >> k;
    vector<pair<int, int>> p;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back({ x,y });
    }

    int ans = 0;

    for (int i = 0; i < k; ++i) {
  
        for (int j = 0; j < k; ++j) {
            int cnt = 0;
            int mox = min(p[i].first, p[j].first);
            int moy = min(p[i].second, p[j].second);


            for (int a = 0; a < k; ++a) {
                int tx = p[a].first;
                int ty = p[a].second;

                if (ty >= moy && tx >= mox) {
                    if (ty <= moy + l && tx <= mox + l) {
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << k-ans;

}