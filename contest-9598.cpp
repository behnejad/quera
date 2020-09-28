#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;
const int N = 2e5 + 1;
const int C = 26;
int n, x[N], y[N], p[2][C][N], s[2][C][N], t[C + 1][N];

int convert(int c, int i) {
	return c == x[i] ? y[i] : c;
}

void pre() {
	for (int i = 0; i <= C; i++) {
		t[i][0] = 1;
		for (int j = 1; j < N; j++)
			t[i][j] = 1LL * t[i][j - 1] * i % Mod;
	}
	
	for (int t = 0; t < 2; t++)
		for (int c = 0; c < C; c++)
			p[t][c][0] = s[t][c][n + 1] = c;
	for (int t = 0; t < 2; t++) {
		for (int i = 1; i <= n; i++)
			for (int c = 0; c < C; c++)
				p[t][c][i] = convert(p[t][c][i - 1], i);
		for (int i = n; i > 0; i--)
			for (int c = 0; c < C; c++)
				s[t][c][i] = s[t][convert(c, i)][i + 1];
		for (int i = 1; i <= n; i++)
			swap(x[i], y[i]);
		reverse(x + 1, x + n + 1);
		reverse(y + 1, y + n + 1);
	}
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char a, b;
		cin >> a >> b;
		x[i] = a - 'a';
		y[i] = b - 'a';
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
	input();
	pre();
	int q;
	cin >> q;
	while (q--) {
		int len, l, r;;
		cin >> len >> l >> r;
		int cnt = 0;
		for (int c = 0; c < C; c++) {
			int x = s[0][p[0][c][l - 1]][r + 1];
			int y = s[1][p[1][x][n - r]][n - l + 2];
			cnt += y == c;
		}
		cout << t[cnt][len] << endl;
	}
}