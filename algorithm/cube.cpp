#include <stdio.h>
int dp[201][201][201];
int min(int i, int j) {
	if (i < j)return i;
	else return j;
}
int box(int w, int l, int h) {
	if (dp[w][l][h] != 0)return dp[w][l][h];
	if (w == l && l == h) {
		dp[w][l][h] = 1;
		return 1;
	}
	int i, tmp, tmp2, case1, case2, case3, result;
	case1 = 8000001;
	case2 = 8000001;
	case3 = 8000001;
	if (w > 1) {
		for (i = 1; i <= w / 2; i++) {
			if (dp[i][l][h] != 0)tmp = dp[i][l][h];
			if (dp[i][l][h] == 0) {
				tmp = box(i, l, h);
				dp[i][l][h] = tmp;
			}
			if (dp[w - i][l][h] != 0)tmp2 = dp[w-i][l][h];
			if (dp[w - i][l][h] == 0) {
				tmp2 = box(w - i, l, h);
				dp[w - i][l][h] = tmp2;
			}
			if (case1 > tmp + tmp2)case1 = tmp + tmp2;
		}
	}
	if (l > 1) {
		for (i = 1; i <= l / 2; i++) {
			if (dp[w][i][h] != 0)tmp = dp[w][i][h];
			if (dp[w][i][h] == 0) {
				tmp = box(w, i, h);
				dp[w][i][h] = tmp;
			}
			if (dp[w][l - i][h] != 0)tmp2 = dp[w][l - i][h];
			if (dp[w][l - i][h] == 0) {
				tmp2 = box(w, l - i, h);
				dp[w][l - i][h] = tmp2;
			}
			if (case2 > tmp + tmp2)case2 = tmp + tmp2;
		}
	}
	if (h > 1) {
		for (i = 1; i <= h / 2; i++) {
			if (dp[w][l][i] != 0)tmp = dp[w][l][i];
			if (dp[w][l][i] == 0) {
				tmp = box(w, l, i);
				dp[w][l][i] = tmp;
			}
			if (dp[w][l][h - i] != 0)tmp2 = dp[w][l][h - i];
			if (dp[w][l][h - i] == 0) {
				tmp2 = box(w, l, h - i);
				dp[w][l][h - i] = tmp2;
			}
			if (case3 > tmp + tmp2)case3 = tmp + tmp2;
		}
	}
	result = case1;
	result = min(result, case2);
	result = min(result, case3);
	return result;
}
int main() {
	FILE *in, *out;
	in = fopen("cube.inp", "r");
	out = fopen("cube.out", "w");
	int T, W, L, H;
	fscanf(in, "%d", &T);
	while (T--) {
		fscanf(in, "%d%d%d", &W, &L, &H);
		dp[W][L][H] = box(W, L, H);
		fprintf(out, "%d\n", dp[W][L][H]);
	}
	fclose(in);
	fclose(out);
	return 0;
}