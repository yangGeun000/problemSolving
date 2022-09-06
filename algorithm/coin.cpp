#include<stdio.h>
int dp[110][110][110][2];
int coin(int a, int b, int c,int flag) {
	if (a == 0 && b == 0 && c == 0) return 0;
	if (a < 0 || b <0 || c < 0) return 0;
	if (dp[a][b][c][flag] != 0)return dp[a][b][c][flag];
	int tmp[9],i,cnt=0;
	if (flag == 0) {
		if (a == 1 && b == 0 && c == 0) return -1;
		if (a == 0 && b == 1 && c == 0) return -1;
		if (a == 0 && b == 0 && c == 1) return -1;
		tmp[0] = coin(a - 1, b, c, (flag + 1) % 2);
		tmp[1] = coin(a - 2, b, c, (flag + 1) % 2);
		tmp[2] = coin(a - 3, b, c, (flag + 1) % 2);
		tmp[3] = coin(a, b - 1, c, (flag + 1) % 2);
		tmp[4] = coin(a, b - 2, c, (flag + 1) % 2);
		tmp[5] = coin(a, b - 3, c, (flag + 1) % 2);
		tmp[6] = coin(a, b, c - 1, (flag + 1) % 2);
		tmp[7] = coin(a, b, c - 2, (flag + 1) % 2);
		tmp[8] = coin(a, b, c - 3, (flag + 1) % 2);
		for (i = 0; i < 10; i++) {
			if (i == 9)break;
			if (tmp[i] == 1)break;
		}
		if (i == 0) {
			dp[a][b][c][flag]= coin(a - 1, b, c, (flag + 1) % 2);
			return coin(a - 1, b, c, (flag + 1) % 2);
		}
		if (i == 1) {
			dp[a][b][c][flag] = coin(a - 2, b, c, (flag + 1) % 2);
			return coin(a - 2, b, c, (flag + 1) % 2);
		}
		if (i == 2) {
			dp[a][b][c][flag] = coin(a - 3, b, c, (flag + 1) % 2);
			return coin(a - 3, b, c, (flag + 1) % 2);
		}
		if (i == 3) {
			dp[a][b][c][flag] = coin(a , b-1, c, (flag + 1) % 2);
			return coin(a, b - 1, c, (flag + 1) % 2);
		}
		if (i == 4) {
			dp[a][b][c][flag] = coin(a, b - 2, c, (flag + 1) % 2);
			return coin(a, b - 2, c, (flag + 1) % 2);
		}
		if (i == 5) {
			dp[a][b][c][flag] = coin(a, b - 3, c, (flag + 1) % 2);
			return coin(a, b - 3, c, (flag + 1) % 2);
		}
		if (i == 6) {
			dp[a][b][c][flag] = coin(a, b, c-1, (flag + 1) % 2);
			return coin(a, b, c - 1, (flag + 1) % 2);
		}
		if (i == 7) {
			dp[a][b][c][flag] = coin(a, b, c - 2, (flag + 1) % 2);
			return coin(a, b, c - 2, (flag + 1) % 2);
		}
		if (i == 8) {
			dp[a][b][c][flag] = coin(a, b, c - 3, (flag + 1) % 2);
			return coin(a, b, c - 3, (flag + 1) % 2);
		}
		if (i == 9)return -1;
	}
	else {
		if (a == 1 && b == 0 && c == 0) return 1;
		if (a == 0 && b == 1 && c == 0) return 1;
		if (a == 0 && b == 0 && c == 1) return 1;
		tmp[0] = coin(a - 1, b, c, (flag + 1) % 2);
		tmp[1] = coin(a - 2, b, c, (flag + 1) % 2);
		tmp[2] = coin(a - 3, b, c, (flag + 1) % 2);
		tmp[3] = coin(a, b - 1, c, (flag + 1) % 2);
		tmp[4] = coin(a, b - 2, c, (flag + 1) % 2);
		tmp[5] = coin(a, b - 3, c, (flag + 1) % 2);
		tmp[6] = coin(a, b, c - 1, (flag + 1) % 2);
		tmp[7] = coin(a, b, c - 2, (flag + 1) % 2);
		tmp[8] = coin(a, b, c - 3, (flag + 1) % 2);
		for (i = 0; i < 10; i++) {
			if (i == 9)break;
			if (tmp[i] == -1)break;
		}
		if (i == 0) {
			dp[a][b][c][flag] = coin(a - 1, b, c, (flag + 1) % 2);
			return coin(a - 1, b, c, (flag + 1) % 2);
		}
		if (i == 1) {
			dp[a][b][c][flag] = coin(a - 2, b, c, (flag + 1) % 2);
			return coin(a - 2, b, c, (flag + 1) % 2);
		}
		if (i == 2) {
			dp[a][b][c][flag] = coin(a - 3, b, c, (flag + 1) % 2);
			return coin(a - 3, b, c, (flag + 1) % 2);
		}
		if (i == 3) {
			dp[a][b][c][flag] = coin(a, b - 1, c, (flag + 1) % 2);
			return coin(a, b - 1, c, (flag + 1) % 2);
		}
		if (i == 4) {
			dp[a][b][c][flag] = coin(a, b - 2, c, (flag + 1) % 2);
			return coin(a, b - 2, c, (flag + 1) % 2);
		}
		if (i == 5) {
			dp[a][b][c][flag] = coin(a, b - 3, c, (flag + 1) % 2);
			return coin(a, b - 3, c, (flag + 1) % 2);
		}
		if (i == 6) {
			dp[a][b][c][flag] = coin(a, b, c - 1, (flag + 1) % 2);
			return coin(a, b, c - 1, (flag + 1) % 2);
		}
		if (i == 7) {
			dp[a][b][c][flag] = coin(a, b, c - 2, (flag + 1) % 2);
			return coin(a, b, c - 2, (flag + 1) % 2);
		}
		if (i == 8) {
			dp[a][b][c][flag] = coin(a, b, c - 3, (flag + 1) % 2);
			return coin(a, b, c - 3, (flag + 1) % 2);
		}
		if (i == 9)return 1;
	}
}

int main() {
	FILE *in, *out;
	in = fopen("coin.inp", "r");
	out = fopen("coin.out", "w");
	int i, j, k, T, t,cnt;
	int a, b, c,win;
	fscanf(in, "%d", &T);
	while (T) {
		T--;
		fscanf(in, "%d%d%d", &a, &b, &c);
		fprintf(out, "(%d %d %d) : ", a, b, c);
		win=coin(a, b, c,0);
		fprintf(out, "%d\n", win);
	}
	fclose(in);
	fclose(out);
	return 0;
}