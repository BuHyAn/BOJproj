#include <cstdio>
int min_v(int a, int b) { return a < b ? a : b; }
int N, M, H, check[12][32];
void set(int b, int a, int v) {
	check[b][a] = v, check[b + 1][a] = -v;
}

int rec(int y, int x, int c) {
	if (y == H + 1) {
		int f = 1, x, i, j;
		for (j = 1; j <= H; j++) {
			for (i = 1; i <= N; i++)
				printf("%c%c", check[i][j] ? '*' : '|', check[i][j] == 1 ? '-' : ' ');
			printf("\n");
		}
		printf("\n");
		for (i = 1; i <= N && f; i++) {
			j = 1, x = i;
			while (j <= H + 1) {
				x += check[x][j];
				j++;
			}
			if (x != i) f = 0;
		}
		return f ? c : 1e9;
	}
	if (x == N) return rec(y + 1, 1, c);
	int ret = rec(y, x + 1, c);
	if (c + 1 <= 3 && !check[x][y]) {
		set(x, y, 1);
		ret = min_v(ret, rec(y, x + 1, c + 1));
		set(x, y, 0);
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int a, b, i, ans = 1e9;
	scanf("%d%d%d", &N, &M, &H);
	while (M--) {
		scanf("%d%d", &a, &b);
		set(b, a, 1);
	}
	ans = rec(1, 1, 0);
	printf("%d", ans > 3 ? -1 : ans);
	return 0;
}