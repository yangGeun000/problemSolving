#include<stdio.h>
long long int cash[21][21][21];
long long int pole(int n, int l, int r) {
	long long int mix, tmp, tmp2, tmp3;
	if (n == 0 || l == 0 || r == 0)return 0;
	if (n == 1 && l == 1 && r == 1)return 1;
	if (l == 1 && r == 1)return 0;
	if (cash[n - 1][l - 1][r] == -1) {
		cash[n - 1][l - 1][r] = pole(n - 1, l - 1, r);
		tmp = cash[n - 1][l - 1][r];
	}
	if (cash[n - 1][l - 1][r] != -1) {
		tmp = cash[n - 1][l - 1][r];
	}
	if (n < 3) {
		tmp2 = 0;
	}
	if(n>=3){
		if (cash[n - 1][l][r] == -1) {
			cash[n - 1][l][r] = pole(n - 1, l, r);
			tmp2 = cash[n - 1][l][r];
			tmp2 *= (n - 2);
		}
		if (cash[n - 1][l][r] != -1) {
			tmp2 = cash[n - 1][l][r];
			tmp2 *= (n - 2);
		}
	}
	if (cash[n - 1][l][r-1] == -1) {
		cash[n - 1][l][r-1] = pole(n - 1, l, r-1);
		tmp3 = cash[n - 1][l][r - 1];
	}
	if (cash[n - 1][l][r-1] != -1) {
		tmp3 = cash[n - 1][l][r-1];
	}
	mix = tmp + tmp2 + tmp3;
	return mix;
}

int main() {
	FILE *in, *out;
	in = fopen("pole.inp", "r");
	out = fopen("pole.out", "w");
	int T, i, j,k, n, l, r;
	long long int mix;
	for(i=0;i<21;i++){
		for (j = 0; j < 21; j++) {
			for (k = 0; k < 21; k++) {
				cash[i][j][k] = -1;
			}
		}
	}
	fscanf(in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(in, "%d%d%d", &n, &l, &r);
		mix = pole(n, l, r);
		fprintf(out, "%lld\n", mix);
	}
	fclose(in);
	fclose(out);
	return 0;
}