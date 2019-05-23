#include<iostream>
using namespace std;
int counted = 2;
int uncounted = 1;
int nozirung = 0;
int t, m, n, x, y, arr[50][50];
int zirung(int X, int Y) {
	if (X >= m || Y >= n || X < 0 || Y < 0)return false;
	else if (arr[X][Y] != uncounted)return false;
	else {
		arr[X][Y] = counted;
		return 1 + zirung(X, Y + 1) + zirung(X + 1, Y) + zirung(X - 1, Y) + zirung(X, Y - 1);
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				cin >> x >> y; arr[x][y] = 1;
			}
		
	}

}