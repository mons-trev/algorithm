#include<iostream>
#include<map>

using namespace std;

int pal[26];
char name[50];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		pal[s[i] - 'A']++;
	}

	int left = 0;
	int right = n - 1;
	
	for (int i = 0; i < n/2; ++i) {
		bool flag = false;
		for (int j = 0; j < 26; ++j) {
			if (pal[j] >= 2) {
				name[i] = name[n - 1 - i] = j + 'A';
				pal[j] -= 2;
				flag = true;
				break;
			}
		}
		if(!flag) {
		cout << "I'm Sorry Hansoo";
		return 0;
		}
	}

	if (n % 2 != 0) {
		for (int i = 0; i < 26; ++i) {
			if (pal[i] != 0) {
				name[n / 2] = i + 'A';
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << name[i];
	}

}