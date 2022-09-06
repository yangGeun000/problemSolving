#include <stdio.h>
#include <string.h>
char high[5001], low[5001];
int dp[5001][5001], S[5001][27], E[5001][27];
char mid[10001];
int length1, length2;
int min(int i, int j) {
	if (i < j)return i;
	else return j;
}
int minclear(int x,int y,int flag) {
	int i, j,result=0;
	if (flag == 0) {
		for (int j = 1; j < 27; j++) {
			if (high[x] == 64 + j) {
				E[y][j]=x;
				break;
			}
		}
		for (int j = 1; j < 27; j++) {
			result += E[y][j] - S[x][j];
		}
		return result;
	}
	else {
		for (int j = 1; j < 27; j++) {
			if (low[y] == 64 + j) {
				E[y][j]=y;
				break;
			}
		}
		for (int j = 1; j < 27; j++) {
			result += E[y][j] - S[x][j];
		}
		return result;
	}
}
int minlength(int x, int y) {
	int length = x + y;
	int result = 0;
	int start[27] = { 0 };
	int end[27] = { 0 };
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j < 27; j++) {
			if (mid[i] == 64 + j) {
				if (start[j] == 0)start[j] = i;
				end[j] = i; 
			}
		}
	}
	for (int j = 1; j < 27; j++) {
		result += end[j] - start[j];
	}
	if (dp[x][y] != 0 && dp[x][y] > result) {
		dp[x][y] = result;
		for (int j = 1; j < 27; j++) {
			S[x][j] = start[j];
			E[y][j] = end[j];
		}
	}
	return result;
}
int clear(int x, int y, int flag) {
	int X = x, Y = y;
	int tmp = 10000000, tmp2 = 10000000;
	if (flag == 0) {
		mid[X + Y] = high[X-1];
		X--;
	}
	if (flag == 1) {
		mid[X + Y] = low[Y-1];
		Y--;
	}
	if (X >0) {
		tmp = clear(X, Y, 0);
	}
	if (Y >0) {
		tmp2 = clear(X, Y, 1);
	}
	if (X == 0 && Y == 0) {
		return minlength(length1, length2);
	} 
	tmp = min(tmp, tmp2);
	return tmp;
}
int main() {
	FILE *in, *out;
	in = fopen("color.inp", "r");
	out = fopen("color.out", "w");
	int T, number,number2, i, j, n, m;
	fscanf(in, "%d", &T);
	while (T--) {
		fscanf(in, "%s", high);
		fscanf(in, "%s", low);
		length1 = strlen(high);
		length2 = strlen(low);
		for (i = 1; i <= length1; i++) {
			dp[1][i] = clear(1, i, 2);
		}
		for (i = 1; i <= length2; i++) {
			dp[i][1] = clear(i, 1, 2);
		}
		for (i = 2; i <= length1; i++) {
			for (j = 2; j <= length2; j++) {
				n=minclear(i-1,j, 0);
				m=minclear(i,j-1, 1);
				dp[i][j] = min(n, m);
			}
		} 
		fprintf(out, "%d\n", dp[length1][length2]);
	}
	fclose(in);
	fclose(out);
	return 0;
}