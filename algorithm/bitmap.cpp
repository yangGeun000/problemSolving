#include<stdio.h>
#include<math.h>

FILE *in, *out;
int w, h, cnt;
int map[205][205];
void B(int x, int y, int width, int high) {
	if (x > width || y > high)return;
	int i, j, n, m;
	int flag = 0, flag2 = 0;
	for (i = y; i <= high; i++) {
		for (j = x; j <= width; j++) {
			if (flag > 0 && flag2 > 0)break;
			if (map[i][j] == 0)flag++;
			if (map[i][j] == 1)flag2++;
		}
	}//다른거 있는지 체크
	if (flag == 0) {
		if (cnt == 50) {
			fprintf(out, "\n");
			cnt = 0;
		}
		fprintf(out, "1");
		cnt++;
		return;
	}//0밖에 없을떄
	if (flag2 == 0) {
		if (cnt == 50) {
			fprintf(out, "\n");
			cnt = 0;
		}
		fprintf(out, "0");
		cnt++;
		return;
	}//1밖에 없을떄
	if (flag > 0 && flag2 > 0) {
		if (cnt == 50) {
			fprintf(out, "\n");
			cnt = 0;
		}
		fprintf(out, "D");
		cnt++;
		m = (y + high) / 2;
		n = (x + width) / 2;
		B(x, y, n, m);//좌상
		B(n + 1, y, width, m);//우상
		B(x, m + 1, n, high);//좌하
		B(n + 1, m + 1, width, high);//우하
	}
	return;
}
void D(int x, int y, int width, int high) {
	if (x > width || y > high)return;
	int i, j, n, m;
	int flag = 0, flag2 = 0;
	int tmp;
	char c;
	if (cnt == 50) {
		fscanf(in, "%c", &tmp);
		cnt = 0;
	}
	fscanf(in, "%c", &c);
	cnt++;
	if (c == '\n')return;
	if (c == 'D') {
		m = (y + high) / 2;
		n = (x + width) / 2;
		D(x, y, n, m);//좌상
		D(n + 1, y, width, m);//우상
		D(x, m + 1, n, high);//좌하
		D(n + 1, m + 1, width, high);//우하
	}
	else {
		tmp = c - 48;
		for (i = y; i <= high; i++) {
			for (j = x; j <= width; j++) {
				map[i][j] = tmp;
			}
		}
	}
	return;
}

int main() {
	in = fopen("bitmap.inp", "r");
	out = fopen("bitmap.out", "w");
	int i, j;
	char tmp;
	char bit;
	for (;;) {
		fscanf(in, "%c %d %d\n", &bit, &h, &w);
		if (bit == '#')break;
		if (bit == 'B') {
			cnt = 0;
			for (i = 0; i < h; i++) {
				for (j = 0; j < w; j++) {
					if (cnt == 50) {
						fscanf(in, "%c", &tmp);
						cnt = 0;
					}
					fscanf(in, "%c", &tmp);
					cnt++;
					tmp -= 48;
					map[i][j] = tmp;
				}
			}
			fscanf(in, "%c", &tmp);
			fprintf(out, "D ");
			if (h < 100) fprintf(out, " ");
			if (h < 10) fprintf(out, " ");
			fprintf(out, "%d ", h);
			if (w < 100) fprintf(out, " ");
			if (w < 10) fprintf(out, " ");
			fprintf(out, "%d\n", w);
			cnt = 0;
			B(0, 0, w - 1, h - 1);
			fprintf(out, "\n");
		}//B
		if (bit == 'D') {
			fprintf(out, "B ");
			if (h < 100) fprintf(out, " ");
			if (h < 10) fprintf(out, " ");
			fprintf(out, "%d ", h);
			if (w < 100) fprintf(out, " ");
			if (w < 10) fprintf(out, " ");
			fprintf(out, "%d\n", w);
			cnt = 0;
			D(0, 0, w - 1, h - 1);
			cnt = 0;
			for (i = 0; i < h; i++) {
				for (j = 0; j < w; j++) {
					if (cnt == 50) {
						fprintf(out, "\n");
						cnt = 0;
					}
					fprintf(out, "%d", map[i][j]);
					cnt++;
				}
			}
			fprintf(out, "\n");
		}//D
	}

	fclose(in);
	fclose(out);
	return 0;
}