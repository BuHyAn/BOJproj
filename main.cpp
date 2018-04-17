#include <cstdio>

bool getstat(int g, int clk) {
	return (g & (1 << clk)) > 0;
}
int rot(int c, int d) {
	if (d == 1) {
		c <<= 1;
		c |= getstat(c, 8);
		c &= ~(1 << 8);
	}
	else {
		c |= (getstat(c, 0) << 8);
		c >>= 1;
	}
	return c;
}
int rev(int d) { return d == 1 ? -1 : 1; }
int main() {
	freopen("input.txt", "r", stdin);
	char S[1001];
	int T,i,j=0,K,idx,d,ans=0, *gear,*dt;
	scanf("%d\n", &T);
	gear = new int[T] {}, dt = new int[T];
	for (i = 0; i < T; i++) {
		scanf("%s", S);
		for (j=0; S[j]; j++) {
			gear[i] <<= 1;
			gear[i] |= (S[j] - '0');
		}
	}
	for (i = 0; i < T; i++) {
		for (j = 7; j >= 0; j--) printf("%d", getstat(gear[i], j));
		printf("\n");
	}
	printf("\n");
	printf("\n");

	scanf("%d", &K);
	while (K--) {
		scanf("%d%d", &idx, &d);
		idx--;
		i = idx - 1, dt[idx] = d;
		while (0 <= idx) {
			if (getstat(gear[idx], 2) != getstat(gear[idx + 1], 6)) dt[idx] = rev(dt[idx + 1]);
			else dt[idx] = dt[idx + 1];
			idx--;
		}
		i = idx + 1;
		while (idx < T) {
			if (getstat(gear[idx], 6) != getstat(gear[idx - 1], 2)) dt[idx] = rev(dt[idx - 1]);
			else dt[idx] = dt[idx - 1];
			idx++;
		}
		for (i = 0; i < T; i++) gear[i] = rot(gear[i], dt[i]);
		for (i = 0; i < T; i++) {
			for (j = 7; j >= 0; j--) printf("%d", getstat(gear[i], j));
			printf("\n");
		}
		printf("\n");
	}
	

	for (i = 0; i < T; i++) ans += getstat(gear[i], 0);
	printf("%d", ans);
	return 0;
}