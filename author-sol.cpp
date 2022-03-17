#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	if(n % 2 == 0) { // the answer does not exist is n is even
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	bool win[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) { // initialize all to false
			win[i][j] = false;
		}
	}
	for(int i = 0; i < n; i++) {
		// start from (i + 1) because it cannot win against itself
		// (n - 1) / 2 = equal amount of matches per player
		for(int j = i + 1; j < i + 1 + (n - 1) / 2; j++) {
			win[i][j%n] = true; // modulo trick to distribute 3 wins in the next 3 indices
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << (win[i][j] ? '1' : '0'); // output
		}
		cout << "\n";
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}

