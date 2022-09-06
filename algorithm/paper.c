#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct data {
	int x;
	int y;
	int w;
	int h;
	int area;
	int number;
}data;
int com(const void *a, const void *b)
{
	int A = *(int *)a;
	int B = *(int *)b;
	if (A < B)return -1;
	if (A > B)return 1;
	return 0;
}
int map[4000][4000];
int them[5000];

int main() {
	FILE *in, *out;
	in = fopen("paper.inp", "r");
	out = fopen("paper.out", "w");
	data p[2000];
	int T, i, j, k, n, m, index, index2;
	int tmp, tmp2, tmp3, cnt, resurt = 0, resurt2 = 0, resurt3 = 0;
	fscanf(in, "%d", &T);
	for (k = 0; k < T; k++) {
		fscanf(in, "%d%d%d%d", &p[k].x, &p[k].y, &p[k].w, &p[k].h);
		p[k].w += p[k].x;
		p[k].h += p[k].y;
		p[k].number = k;
	}
	for (k = 0; k < T; k++) {
		them[k] = p[k].x;
	}
	index = 0;
	for (k = T; k < 2 * T; k++) {
		them[k] = p[index].w;
		index++;
	}
	qsort(them, 2 * T, sizeof(int), com);
	index = 0;
	for (k = 0; k < 2 * T; k++) {
		for (i = 0; i < T; i++) {
			if (them[k] == p[i].x) {
				p[i].x = index;
			}
			if (them[k] == p[i].w) {
				p[i].w = index;
			}
		}
		if (them[k] != them[k + 1])index++;
	}
	//
	for (k = 0; k < T; k++) {
		them[k] = p[k].y;
	}
	index = 0;
	for (k = T; k < 2 * T; k++) {
		them[k] = p[index].h;
		index++;
	}
	qsort(them, 2 * T, sizeof(int), com);
	index = 0;
	for (k = 0; k < 2 * T; k++) {
		for (i = 0; i < T; i++) {
			if (them[k] == p[i].y) {
				p[i].y = index;
			}
			if (them[k] == p[i].h) {
				p[i].h = index;
			}
		}
		if (them[k] != them[k + 1])index++;
	}
	//
	for (k = 0; k < T; k++) {
		tmp = p[k].w - p[k].x;
		tmp2 = p[k].h - p[k].y;
		p[k].area = tmp*tmp2;
	}
	for (k = 0; k < T; k++) {
		for (n = p[k].y; n < p[k].h; n++) {
			for (m = p[k].x; m < p[k].w; m++) {
				map[n][m] = p[k].number+1;
			}
		}
	}
	for (k = 0; k < T; k++) {
		cnt = 0;
		tmp = k;
		for (n = p[k].y; n < p[k].h; n++) {
			for (m = p[k].x; m < p[k].w; m++) {
				if (map[n][m] == p[k].number+1) {
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			resurt++;
			continue;
		}
		if (cnt == p[tmp].area) {
			resurt3++;
			continue;
		}
		if (cnt < p[tmp].area) {
			resurt2++;
			continue;
		}
	}
	fprintf(out, "%d %d %d", resurt, resurt2, resurt3);
	fclose(in);
	fclose(out);
	return 0;
}