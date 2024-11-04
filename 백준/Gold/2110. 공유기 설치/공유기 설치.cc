#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;
vector<int> h;
vector<bool> check;

bool pos(int mid) {
	int ch = h[0];
	int a = 1;
	bool ret = false;
	for (int i = 1; i < h.size(); ++i) {
		if (h[i] - ch >= mid) {
			ch = h[i];
			a++;
		}
		if (a >= c) {
			ret = true;
			break;
		}
	}
	return ret;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	sort(h.begin(), h.end());

	int maxdst = h[h.size()-1] - h[0]; // 양 끝거리

	// 그리디 접근
	// 1. 1번에는 무조건 설치하는게 맞나 -> 1 아니고 다른데 세운다고 가정했을 떄, 1번에 두는 경우보다 이득이 없음
	// 첫번째 무조건 두고 시작

	// 이분 탐색
	// 거리를 기준으로 이분탐색을 한다.
	// 1부터 하나씩 늘려가면서 최대 거리로 잡고 가능한지 파악하면 TLE 에러 발생
	// 이분탐색 실행

	int low = 1;//가장 짧은 거리
	int high = maxdst; //가장 먼 거리
	int result = 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (pos(mid)) {
			low = mid + 1;
			result = max(result, mid);
		}
		else {
			 high = mid-1;
		}
	}

	cout << result;

}