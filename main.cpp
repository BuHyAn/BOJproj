#include <cstdio>
int abs_v(int a) { return a < 0 ? -a : a; }
int min_v(int a, int b) { return a < b ? a : b; }
int N, board[20][20],S;

int rec(int p, int s) {
	if (p == N) return abs_v(S - 2*s);
	
	return min_v()
}
int main() {
	freopen("input.txt", "r", stdin);
	/*
	char A[1001], B[1001];
	scanf("%s%s", A, B);
	*/
	int i, j, S=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d", &board[i][j]), S += board[i][j];
	
	return 0;
}