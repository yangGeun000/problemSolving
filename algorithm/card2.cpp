#include<stdio.h>
int n[1000];
int dp[1000][1000];
int chose(int start, int end,int flag) {
	if (dp[start][end] != 0)return dp[start][end];
	if (start == end&&flag==0)return n[start];
	if (start == end && flag == 1)return 0;
	int tmp,tmp2;
	if (flag == 0) {
		tmp = n[start]+chose(start + 1, end, 1);
		tmp2 = chose(start, end - 1, 1)+n[end];
		if (tmp >= tmp2) {
			dp[start][end] = tmp;
			return tmp;
		}
		if (tmp < tmp2) {
			dp[start][end] = tmp2;
			return tmp2;
		}
	}
	if (flag == 1) {
		tmp = chose(start + 1, end, 0);
		tmp2 = chose(start, end - 1, 0);
		if (tmp >= tmp2) {
			return tmp2;
		}
		if (tmp < tmp2) {
			return tmp;
		}
	}
}
int main() {
	FILE *in, *out;
	in =fopen("card2.inp","r");
	out = fopen("card2.out", "w");
	int i,j,T,t;
	int max;
	fscanf(in, "%d", &T);
	while (T) {
		T--,max=0;
		fscanf(in, "%d", &t);
		for(i=0;i<t;i++){
			fscanf(in, "%d", &n[i]);
		}
		max=chose(0, t-1,0);
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