#include <stdio.h>
#include <stdlib.h>
int X[505],D[505][505],C[505][505];
int compare(const void* first, const void* second) {
	if (*(int*)first > *(int*)second)return 1;
	if (*(int*)first < *(int*)second)return -1;
	else return 0;
}
int min(int i, int j) {
	if (i < j)return i;
	else return j;
}
int c(int i, int j) {
	if (i == j) return 0;
	int n,mid,tmp=0;
	if ((i + j) % 2 == 0) {
		mid = ((i + j) / 2);
	}
	if ((i + j) % 2 == 1) {
		mid = ((i + j) / 2)+1;
	}
	for (n = mid-1; i <= n; n--) {
		tmp += X[mid] - X[n];
	}
	for (n = mid+1; n<=j; n++) {
		tmp += X[n] - X[mid];
	}
	return tmp;
}
int main() {
	FILE *in, *out;
	in = fopen("bin.inp", "r");
	out = fopen("bin.out", "w");
	int T,n,m;
	int i,j,k,tmp;
	fscanf(in, "%d", &T);
	while (T--) {
		fscanf(in, "%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			fscanf(in, "%d", &X[i]);
		}
		if (n == m) { fprintf(out, "0\n"); continue; }
		qsort(X, n + 1, sizeof(int), compare);
		for (i = 1; i <= n; i++) {
			for (j = i; j <= n; j++) {
				C[i][j] = c(i, j);
			}
		}
		for (i = 1; i <= n; i++) {
			D[i][1] = C[1][i];
		}
		for (i = 1; i <= n; i++) {
			for (j = 2; j <= m; j++) {
				if (i == j) {
					D[i][j] = 0;
					continue;
				}
				tmp = D[i - 1][j - 1] + C[i][i];
				for (k = i-1; k >=1 ; k--) {
					tmp=min(tmp, D[k - 1][j - 1] + C[k][i]);
				}
				D[i][j] = tmp;
			}
		}
		fprintf(out, "%d\n", D[n][m]);
	}
	fclose(in);
	fclose(out);
	return 0;
}