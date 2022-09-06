#include <stdio.h>
int dp[8][1000001][2][8];
int dp2[11][8][1000001];
int victory(int x,int y,int z, int flag, int g) {
	if (dp[y][z][flag][g] != 0)return dp[y][z][flag][g];
	int i;
	if (flag == 0) {
		if (z < 0)return 1;
		if (z == 0) return -1;
		if ((z%x) == 0) return 1;
		for (i = 1; i <= y; i++) {
			if (g == i)continue;
			dp[y][z - i][(flag + 1) % 2][i] = victory(x,y,z - i, (flag + 1) % 2, i);
			if (dp[y][z - i][(flag + 1) % 2][i] == 1) {
				return dp[y][z - i][(flag + 1) % 2][i];
			}
		}
		return -1;
	}
	else {
		if (z < 0)return -1;
		if (z == 0) return 1;
		if ((z%x) == 0) return -1;
		for (i = 1; i <= y; i++) {
			if (g == i)continue;
			dp[y][z - i][(flag + 1) % 2][i] = victory(x,y,z - i, (flag + 1) % 2, i);
			if (dp[y][z - i][(flag + 1) % 2][i] == -1) {
				return dp[y][z - i][(flag + 1) % 2][i];
			}
		}
		return 1;
	}
}
int max(int x,int y,int z) {
	for (int i = 1; i <= y; i++) {
		if (victory(x,y,z - i, 1, i) == 1)return z-i;
	}
	return -1;
}
int main() {
	FILE *in, *out;
	in = fopen("coinmove.inp", "r");
	out = fopen("coinmove.out", "w");
	int T,P, K,S;
	int i, j, k, h;
	fscanf(in, "%d", &T);
	while (T--) {
		fscanf(in, "%d%d%d", &P, &K, &S);
		for (i = 5; i <= S; i++) {
			dp2[P][K][i]=max(P, K, i);
		}
		fprintf(out, "%d\n", dp2[P][K][S]);
		for (i = 0; i <= S; i++) {
			for (j = 0; j <= 1; j++) {
				for (k = 1; k <= 7; k++) {
					dp[K][i][j][k] = 0;
				}
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}