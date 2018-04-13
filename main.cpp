#include <cstdio>
#include <cstring>
char* n1[] = { "one","two","three","four","five","six","seven","eight","nine","ten" };
char* n1119[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen"};
char* nelse[] = { "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" }, ans[100];

int p(int cnt) {
	memset(ans, 0, sizeof ans);
	int ret = 0;
	if (cnt / 100) {
		ret += p(cnt / 100);
		cnt %= 100;
		strcat(ans, "hundred");
		ret += 7;
		//printf("hundred");
	}
	if (cnt > 10) {
		if (cnt / 10 == 1) {
			strcat(ans, n1119[cnt - 11]);
			//printf("%s", n1119[cnt - 11]);
			ret += strlen(n1119[cnt - 11]);
			cnt = 0;
		}
		else {
			strcat(ans, nelse[cnt / 10 - 2]);
			//printf("%s", nelse[cnt / 10 - 2]);
			ret += strlen(nelse[cnt / 10 - 2]);
			cnt %= 10;
		}
	}
	if (cnt) {
		strcat(ans, n1[cnt - 1]);
		//printf("%s", n1[cnt - 1]);
		ret += strlen(n1[cnt - 1]);
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	char S[20][51];
	int N,i,cnt,tot;
	scanf("%d", &N);
	tot = 0;
	for(i=0;i<N;i++) {
		scanf("%s", S[i]);
		if (strcmp(S[i], "$")) tot += strlen(S[i]);
	}
	cnt = tot;
	for (i = 0; i<N; i++) {
		if (strcmp(S[i], "$")) printf("%s ", S[i]);
		else {
			tot = !tot ? 1 : tot;
			while (tot <= 1000) {
				if (cnt + p(tot) == tot) {
					printf("%s ", ans);
					break;
				}
				tot++;
			}
		}
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct _d { int ry, rx, by, bx; };
int main() {
	freopen("input.txt", "r", stdin);
	char board[10][11];
	int H, W, i, j, sry, srx, sby, sbx, dp[10][10][10][10], dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
	_d u;
	memset(dp, 0x7F, sizeof dp);
	scanf("%d%d\n", &H, &W);
	for (i = 0; i < H; i++) {
		scanf("%s", board[i]);
		for (j = 0; j < W; j++) {
			if (board[i][j] == 'R') sry = i, srx = j;
			else if (board[i][j] == 'B') sby = i, sbx = j;
		}
	}
	dp[sry][srx][sby][sbx] = 0;
	queue<_d> q;
	q.push(_d{ sry,srx,sby,sbx });
	while (!q.empty()) {
		u = q.front(), q.pop();
		for (i = 0; i < 4; i++) {
			int rty=u.ry, rtx=u.rx, bty=u.by, btx=u.bx;
		}
	}
	return 0;
}
*/