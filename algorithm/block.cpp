#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct block {
	int X;
	int Y;
	int P;
	int Q;
}block;
block b[10000];
int N;
int max(int x, int y) {
	if (x > y)return x;
	return y;
}
bool comp1(const block& x, const block&y) {
	if (x.Y == y.Y)return  x.X < y.X;
	return x.Y < y.Y;
}
bool comp2(const block& x, const block&y) {
	if (x.X == y.X)return  x.Y < y.Y;
	return x.X < y.X;
}
int down() {
	int i, j, tmp, flag, index, cnt = 0;
	for (i = 0; i < N; i++) {
		if (b[i].Y == 0)continue;
		index = -1;
		flag = 0;
		for (j = i; j >= 0; j--) {
			if (i == j)continue;
			if (b[i].X<b[j].P&&b[i].P>b[j].X) {
				if (b[i].Y == b[j].Q) {
					flag = 2;
					break;
				}
				flag = 1;
				if (index == -1) {
					index = j;
					continue;
				}
				if (b[index].Q < b[j].Q)index = j;
			}
		}
		if (flag == 2)continue;
		if (flag == 1) {
			tmp = b[i].Y - b[index].Q;
			b[i].Q -= tmp;
			b[i].Y -= tmp;
			cnt++;
			continue;
		}
		b[i].Q -= b[i].Y;
		b[i].Y = 0;
		cnt++;
	}
	return cnt;
}
int left() {
	int i, j, tmp, flag, index, cnt = 0;
	for (i = 0; i < N; i++) {
		if (b[i].X == 0)continue;
		index = -1;
		flag = 0;
		for (j = i; j >= 0; j--) {
			if (i == j)continue;
			if (b[i].Y<b[j].Q&&b[i].Q>b[j].Y) {
				if (b[i].X == b[j].P) {
					flag = 2;
					break;
				}
				flag = 1;
				if (index == -1) {
					index = j;
					continue;
				}
				if (b[index].P < b[j].P)index = j;
			}
		}
		if (flag == 2)continue;
		if (flag == 1) {
			tmp = b[i].X - b[index].P;
			b[i].P -= tmp;
			b[i].X -= tmp;
			cnt++;
			continue;
		}
		b[i].P -= b[i].X;
		b[i].X = 0;
		cnt++;
	}
	return cnt;
}
int main() {
	FILE *in, *out;
	in = fopen("block.inp", "r");
	out = fopen("block.out", "w");
	int T;
	int i, weight, high;
	fscanf(in, "%d", &T);
	while (T--) {
		weight = 0, high = 0;
		fscanf(in, "%d", &N);
		for (i = 0; i < N; i++) {
			fscanf(in, "%d%d%d%d", &b[i].X, &b[i].Y, &b[i].P, &b[i].Q);
		}
		while (1) {
			sort(b, b + N, comp1);
			if (down() == 0)break;
			sort(b, b + N, comp2);
			if (left() == 0)break;
		}
		for (i = 0; i < N; i++) {
			weight = max(weight, b[i].P);
			high = max(high, b[i].Q);
		}
		fprintf(out, "%d %d\n", weight, high);
	}
	fclose(in);
	fclose(out);
	return 0;
}