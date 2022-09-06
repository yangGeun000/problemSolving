#include <stdio.h>
int tank[1001][1001], hl[1001][1001], lr[1001][1001];
int T, N, M, H;
int n,m;//���� �ִ� ��ǥ
int drain(int tankwater, int hole) {
	int back = tank[n][m];
	if (hole < 0) return tankwater;//������ ����
	if (n < 0 || n == N || m < 0 || m == M) back = 0;//�ܰ�ó��
	if (tankwater > hole) {
		if (back < hole)return hole;//���۸�ŭ ����
		else {
			if (back > tankwater) return tankwater;//���ж��� ������ ����
			return back;
		}
	}
	else return tankwater; //���ۺ��� ���� �ؿ� ����
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
				fscanf(in, "%d", &hl[i][j]);//����
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M + 1; j++) {
				fscanf(in, "%d", &lr[i][j]);//����
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				tank[i][j] = H;
			}
		}//�� ä���
		k = 20;
		while (k--) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < M; j++) {
						n = i - 1, m = j;
						tank[i][j] = drain(tank[i][j], hl[i][j]);//��
						n = i + 1, m = j;
						tank[i][j] = drain(tank[i][j], hl[i + 1][j]);//��
						n = i, m = j-1;
						tank[i][j] = drain(tank[i][j], lr[i][j]);//��
						n = i, m = j+1;
						tank[i][j] = drain(tank[i][j], lr[i][j + 1]);//��
					}
				}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				sum += tank[i][j];
			}
		}//�� ����
		fprintf(out, "%d\n", sum);
	}
	fclose(in);
	fclose(out);
	return 0;
}