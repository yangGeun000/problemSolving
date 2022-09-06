#include <stdio.h>
#include <algorithm>
typedef struct light {
	int L;
	int R;
}light;
light n[100000];
int N;
int min(int x, int y) {
	if (x < y)return x;
	return y;
}
bool comp(const light& x, const light& y) {
	if (x.L == y.L)return  x.R > y.R;
	return x.L < y.L;
}
int count(int x,int y,int cnt) {
	if (x > y) return cnt;
	int i,tmp=100001,number=0,tank=100001,tank2;
	for (i = 0; i < N; i++) {
		if (x>=n[i].L&&y<=n[i].R) {
			return cnt + 1;
		}
		if (x<n[i].R&&x>=n[i].L) {
			tank2 = y - n[i].R;
			if (tank >= tank2) {
				number = i;
				tank = tank2;
			}
		}
		if (y<=n[i].R&&y>n[i].L) {
			tank2 = n[i].L - x;
			if (tank >= tank2) {
				number = i;
				tank = tank2;
			}
		}
	}
	i = number;
	if (x < n[i].R&&x >= n[i].L) {
		tmp = count(n[i].R, y, cnt + 1);
	}
	if (y <= n[i].R&&y > n[i].L) {
		tmp = count(x, n[i].L, cnt + 1);
	}
	return tmp;
}
int main() {
	FILE *in, *out;
	in = fopen("light.inp", "r");
	out = fopen("light.out", "w");
	int K,L,R;
	int i, result;
	fscanf(in,"%d", &N); 
	for (i = 0; i < N; i++) {
		fscanf(in, "%d%d", &n[i].L, &n[i].R);
	}
	std::sort(n, n + N, comp);
	fscanf(in, "%d", &K);
	while (K--) {
		fscanf(in, "%d%d", &L, &R);
		result=count(L, R, 0);
		if (result == 100001)result = -1;
		fprintf(out, "%d\n", result);
	}
	fclose(in);
	fclose(out);
	return 0;
}