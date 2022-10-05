#include<stdio.h>

int number[50];

int main() {
	FILE *in, *out;
	in = fopen("ladder.inp", "r");
	out = fopen("ladder.out", "w");
	int T, i, j, k;
	int x, y, time, cnt = 0, tmp,index,flag;
	int xmap[100000], ymap[1000000], xmap2[100000], ymap2[100000];
	fscanf(in, "%d", &T);
	for (i = 0;; i++) {
		fscanf(in, "%d%d%d%d", &xmap[i], &ymap[i], &xmap2[i], &ymap2[i]);
		if (xmap[i] == 0 && ymap[i] == 0 && xmap2[i == 0] && ymap[i] == 0)break;
		cnt++;
	}
	for (k = 0; k < T; k++) {
		x = k, y = 10000, time = 0,tmp = 0;
		for (;;) {
			flag = 0,tmp=0;
			for (i = 0; i < cnt; i++) {
				if (x == xmap[i]) {
					if (y > ymap[i]) {
						if (tmp <= ymap[i]) {
							tmp = ymap[i];
							index = i;
							flag = 1;
						}
					}
				}
				if (x == xmap2[i]) {
					if (y > ymap2[i]) {
						if (tmp <= ymap2[i]) {
							tmp = ymap2[i];
							index = i;
							flag = 2;
						}
					}
				}
			}
			if (flag == 0) {
				time += y;
				number[x] = k;
				break;
			}
			time += (y - tmp);
			if (flag == 1) {
				x = xmap2[index], y = ymap2[index],tmp=ymap2[index];
			}
			if (flag == 2) {
				x = xmap[index], y = ymap[index],tmp=ymap[index];
			}
		}
	}
	for (i=0;i<T;i++) {
		fprintf(out, "%d ", number[i]);
	}
	fclose(in);
	fclose(out);
	return 0;
}