#include <cstdio>
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
	return 0;
}