#include <cstdio>
<<<<<<< HEAD
#include <queue>
int main() {
	freopen("input.txt", "r", stdin);
	std::priority_queue<int> q;
	int D,N;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &D);
		q.push(-D);
	}
	while (!q.empty()) printf("%d\n", -q.top()), q.pop();
=======
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
	
>>>>>>> 90cc53539249f5c79b5bb1f9159b8de7671dd6ea
	return 0;
}