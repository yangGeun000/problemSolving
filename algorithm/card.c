#include<stdio.h>
int n[1000];
int dp[1000][1000];
int chose(int x, int y, int z) {
	if (z == 1)return 0;
	int i, j, k, flag = 0;
	int tmp[3], max;
	i = x, j = y;
	if (i < 0)i = 0;
	if (dp[i][j] != 0)return dp[i][j];
	if (i == j) {
		if (j <= 2)flag = 1;
		tmp[0] = n[j] + chose(j - 4, i - 2, flag);
		return tmp[0];
	}
	k = j - i + 1;
	if (j <= 2)flag = 1;
	tmp[0] = n[j] + chose(j - 4, i - 1, flag);
	if (k == 2) {
		flag = 0;
		if (j <= 3)flag = 1;
		tmp[1] = n[j - 1] + chose(j - 5, i - 2, flag);
	}
	if (k == 3) {
		flag = 0;
		if (j <= 3)flag = 1;
		tmp[1] = n[j - 1] + chose(j - 5, i - 1, flag);
		flag = 0;
		if (j <= 4)flag = 1;
		tmp[2] = n[j - 2] + chose(j - 6, i - 2, flag);
	}
	max = tmp[0];
	while (k) {
		k--;
		if (max <= tmp[k]) {
			max = tmp[k];
		}
	}
	dp[i][j] = max;
	return max;
}
int main() {
	FILE *in, *out;
	in = fopen("card.inp", "r");
	out = fopen("card.out", "w");
	int T, t, i, j, max;
	fscanf(in, "%d", &T);
	while (T) {
		T--;
		fscanf(in, "%d", &t);
		for (i = 0; i < t; i++) {
			fscanf(in, "%d", &n[i]);
		}
		max = chose(t - 1, t - 1, 0);
		//max += n[t - 1];
		fprintf(out, "%d\n", max);
		for (i = 0; i <= t - 1; i++) {
			for (j = 0; j <= t - 1; j++) {
				dp[i][j] = 0;
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}