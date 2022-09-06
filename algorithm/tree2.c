#include<stdio.h>
FILE *in, *out;
int pre[10000], ino[10000], post[10000];
int T;

void one(int n, int m) {
	if (n == m) {
		fprintf(out, "%d\n", ino[n]);
		return;
	}
	if (n > m)return;
	int x, y, flag = 0;
	for (x = 0; x < T; x++) {
		for (y = n; y <= m; y++) {
			if (pre[x] == ino[y]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}
	one(n, y - 1);
	one(y + 1, m);
	fprintf(out, "%d\n", ino[y]);
	return;

}

void two(int n, int m) {
	if (n == m) {
		fprintf(out, "%d\n", ino[n]);
		return;
	}
	if (n > m)return;
	int x, y, flag = 0;
	for (x = T - 1; x >= 0; x--) {
		for (y = n; y < m + 1; y++) {
			if (post[x] == ino[y]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}
	fprintf(out, "%d\n", ino[y]);
	two(n, y - 1);
	two(y + 1, m);
	return;
}

int main() {
	in = fopen("tree2.inp", "r");
	out = fopen("tree2.out", "w");
	int k, i, j, cnt;
	int index;
	fscanf(in, "%d", &T);
	cnt = 0;
	for (i = 0; i < 2; i++) {
		fscanf(in, "%d", &k);
		cnt += k;
		index = 0;
		if (k == -1) {
			for (j = 0; j < T; j++) {
				fscanf(in, "%d", &pre[index]);
				index++;
			}
		}
		if (k == 0) {
			for (j = 0; j < T; j++) {
				fscanf(in, "%d", &ino[index]);
				index++;
			}
		}
		if (k == 1) {
			for (j = 0; j < T; j++) {
				fscanf(in, "%d", &post[index]);
				index++;
			}
		}
	}
	if (cnt == -1) {
		one(0, T - 1);
	}
	if (cnt == 1) {
		two(0, T - 1);
	}

	fclose(in);
	fclose(out);

	return 0;
}