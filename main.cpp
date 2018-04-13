#include <cstdio>
#include <cstring>
int min_v(int a, int b) { return a < b ? a : b; }
int max_v(int a, int b) { return a > b ? a : b; }
int N, M,c[100],m[100],dp[100][10001];
int rec(int p, int tc) {
	if (p == N) return 0;
	int& ret = dp[p][tc];
	if (ret != -1) return ret;
	ret = 0;
	if (tc >= c[p]) ret = rec(p + 1, tc - c[p]) + m[p];
	return (ret = max_v(ret, rec(p + 1, tc)));
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	memset(dp, -1, sizeof dp);
	int i;
	for (i = 0; i < N; i++) scanf("%d", &m[i]);
	for (i = 0; i < N; i++) scanf("%d", &c[i]);
	for (i = 0;; i++)
		if (rec(0, i) >= M) return ~printf("%d", i);
	return 0;
}