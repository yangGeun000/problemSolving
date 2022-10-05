#include <stdio.h>
int tank[1001][1001], hl[1001][1001], lr[1001][1001];
int T, N, M, H;
int n,m;//보고 있는 좌표
int drain(int tankwater, int hole) {
	int back = tank[n][m];
	if (hole < 0) return tankwater;//구멍이 없음
	if (n < 0 || n == N || m < 0 || m == M) back = 0;//외각처리
	if (tankwater > hole) {
		if (back < hole)return hole;//구멍만큼 빠짐
		else {
			if (back > tankwater) return tankwater;//수압때문 작은거 리턴
			return back;
		}
	}
	else return tankwater; //구멍보다 물이 밑에 있음
}
int main() {
	FILE *in, *out;
	in = fopen("watertank.inp", "r");
	out = fopen("watertank.out", "w");
	int i, j, k, sum;
	fscanf(in, "%d", &T);
	while (T--) {
		sum = 0;
		fscanf(in, "%d%d%d", &N, &M, &H);
		for (i = 0; i < N + 1; i++) {
			for (j = 0; j < M; j++) {
				fscanf(in, "%d", &hl[i][j]);//가로
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M + 1; j++) {
				fscanf(in, "%d", &lr[i][j]);//세로
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				tank[i][j] = H;
			}
		}//물 채우기
		k = 20;
		while (k--) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < M; j++) {
						n = i - 1, m = j;
						tank[i][j] = drain(tank[i][j], hl[i][j]);//상
						n = i + 1, m = j;
						tank[i][j] = drain(tank[i][j], hl[i + 1][j]);//하
						n = i, m = j-1;
						tank[i][j] = drain(tank[i][j], lr[i][j]);//좌
						n = i, m = j+1;
						tank[i][j] = drain(tank[i][j], lr[i][j + 1]);//우
					}
				}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				sum += tank[i][j];
			}
		}//총 물량
		fprintf(out, "%d\n", sum);
	}
	fclose(in);
	fclose(out);
	return 0;
}