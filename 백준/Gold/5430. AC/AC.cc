#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int arr[100000];
int main() {
	int t;
	cin >> t;
	while (t--) {
		bool flag = true; //정방향이면 true, 한번 reverse를 한거면 false
		string s; cin >> s;
		int n; cin >> n;
		int f, e; // front, end
		f = 0, e = n - 1; //시작과 끝 투 포인터 이용
		if (e < 0) {
			e = 0;
		}
		string in; cin >> in;
		in.erase(0,1);
		in.erase(in.size() - 1, 1);

		stringstream sstream(in);
		string word;

		int i = 0;
		while (getline(sstream, word, ','))
		{
			arr[i]=stoi(word);
			i++;
		}
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (c == 'R') {//reverse
				int tmp = f;
				f = e;
				e = tmp;
				flag = !flag;//한번씩 바꾸기
			}
			else {//D라면
				if (flag) { //정방향이면
					f++; //front 가 end 앞이므로 하나 뒤로 보내기
				}
				else {
					f--;
				}
			}
		}
		//cout << flag << f << e << endl;
		if (flag) { // 정방향이면
			if (f > e+1 || (f>e && n==0)) {
				cout << "error" << "\n";
			}
			else if (f > e) {
				cout << "[]" << '\n';
			}
			else {
				cout << "[";
				if (!(f == e && n == 0)) {
					for (int i = f; i <= e; ++i) {
						cout << arr[i];
						if (i != e) {
							cout << ",";
						}
					}
				}
				cout << "]\n";
			}
		}
		else { // 정방향이면
			if (f +1 < e || (f < e && n == 0)) {
				cout << "error" << "\n";
			}
			else if (e > f && n!=0) {
				cout << "[]" << '\n';
			}
			else {
				cout << "[";
				if (!(f == e && n == 0)) {
					for (int i = f; i >= e; --i) {
						cout << arr[i];
						if (i != e) {
							cout << ",";
						}
					}
				}
				cout << "]\n";
			}
		}
	}
}