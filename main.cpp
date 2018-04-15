#include <cstdio>
#include <cstring>
int main() {
	freopen("input.txt", "r", stdin);
	//< protocol > "://" < host > [ ":" < port > ] [ "/" < path > ]
	char S[100],p[100],h[100],pn[100];
	int T, i, pos, SL,j,tc;
	bool used;
	scanf("%d\n", &T);
	for(tc=1;tc<=T;tc++) {
		for (i = 0; i < 100; i++) S[i] = p[i] = h[i] = pn[i] = 0;
		scanf("%s", S);
		used = 0;
		SL = strlen(S);
		for (i = 0; S[i+2]; i++)
			if (S[i] == ':' && S[i + 1] == '/' && S[i + 2] == '/') {
				used = 1;
				break;
			}
		if (used) {
			for (j = 0; j < i; j++) p[j] = S[j];
			i += 3;
		}
		else i = 0;
		pos = 0;
		while (S[i] && S[i] != '/' && S[i] != ':')
			h[pos++] = S[i++];
		pos = 0;
		if (S[i] == ':') {
			i++;
			while (S[i] && S[i] != '/')
				pn[pos++] = S[i++];
		}
		i++;
		printf("URL #%d\n", tc);
		printf("Protocol = %s\nHost     = %s\nPort     = %s\nPath     = %s\n\n", p[0] ? p : "<default>", h[0] ? h : "<default>", pn[0] ? pn : "<default>", S[i] ? &S[i] : "<default>");
	}
	return 0;
}