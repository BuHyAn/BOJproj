#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
	freopen("input.txt", "r", stdin);
	char N[81];
	int	T;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%s", N);
		if (std::next_permutation(N, N + strlen(N))) printf("%s\n", N);
		else printf("BIGGEST\n");
	}
	return 0;
}