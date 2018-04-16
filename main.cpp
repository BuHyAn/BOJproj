#include <cstdio>
int max_v(int a, int b) { return a > b ? a : b; }
int N, M, board[8][8], cctv_p[8][2], ctv_c, dir_cnt[] = { 4,2,4,4,1 };


int rec(int p) {
	if (p == ctv_c) {

	}
	
}
int main() {
	freopen("input.txt", "r", stdin);
	/*
	char A[1001], B[1001];
	scanf("%s%s", A, B);
	*/
	int i, j;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
		scanf("%d", &board[i][j]);
		if (board[i][j] && board[i][j] != 6) {
			cctv_p[ctv_c][0] = i, cctv_p[ctv_c][1] = j;
			ctv_c++;
		}
	}
	printf("%d", N*M - rec(0));

	return 0;
}