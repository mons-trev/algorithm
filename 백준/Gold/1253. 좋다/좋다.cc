#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

// 이분 탐색으로 다시

vector <int> list;

int n;


bool binarysearch(int idx) {
	int tar = list[idx];
	int left = 0;
	int right = n - 1;
	while (left < right) {
		//int mid = (left + right) / 2;
		if (list[left] + list[right] == tar) {
			if (left != idx && right != idx) {
				return true;
			}
			else if (left == idx) {
				left++;
				continue;
			}
			else if(right == idx){
				right--;
				continue;
			}
		}
		else if (list[left] + list[right] > tar) {
			right --;
		}
		else {
			left ++;
		}
	}
	return false;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (binarysearch(i)) {
			ans++;
		}
	}
	cout << ans;
}



/* wrong
4
0 0 0 0
vector<int> list;

bool check[2000][2000];
bool finalcheck[2000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end()); // 오름차순 정렬
	//제일 첫번째, 두번째 인덱스는 불가능
	
	int idx = 2; // 목표 인덱스를 가리키는 인덱스 포인터
	int ans = 0; // 최종 답
	while (idx < n) {
		
		int tar = list[idx];
		queue<pair<int, int>> q;
		q.push({ 0,n-1 });
		check[0][n-1] = true;
		while (!q.empty()) { // 투 포인터 실행
			int l = q.front().first;
			int r = q.front().second;
			int sum = list[l] + list[r];
			q.pop();
			if (sum == tar) { // tar이랑 일치하면 break;
				ans++;
				finalcheck[idx] = true;
				break;
			}
			else if (sum < tar) {
				if (l + 1 < r && l + 1 != idx && !check[l + 1][r]) { // 왼쪽을 하나 올리고
					q.push({ l + 1,r });
					check[l + 1][r] = true;
				}
				if (r + 1 < n && r + 1 != idx && !check[l][r + 1]) { //오른쪽을 하나 올리고.. idx 가 포함되는 지 안되는지 질문 게시판 참고해야됨
					q.push({ l,r + 1 });
					check[l][r + 1] = true;
				}

			}
			else {
				if (l - 1 >= 0 && l - 1 != idx && !check[l - 1][r]) { // 왼쪽을 하나 내리고
					q.push({ l - 1,r });
					check[l - 1][r] = true;
				}
				if (r - 1 > l && r - 1 != idx && !check[l][r - 1]) { //오른쪽을 하나 내리고
					q.push({ l,r - 1 });
					check[l][r - 1] = true;
				}
			}
			memset(check, false, sizeof(check));
			idx++;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (!finalcheck[i]) {
			for (int j = i + 1; j < n; ++j) {
				if (list[j] != list[i]) {
					break;
				}
				if (finalcheck[j]) {
					ans++;
					finalcheck[i] = true;
					break;
				}
			}
		}
	}
	cout << ans;
}
*/