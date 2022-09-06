#include <stdio.h>
typedef struct map {
	int N;
	char C;
	int can[9];
}map;
map M[9][9];
int R[9][9];
int flag;
void check(int n, int m) {//��,��,�׷캸�� �ĺ�üũ
	int i,j;
	for (i = 0; i < 9; i++) {//�ĺ� �ʱ�ȭ
		M[n][m].can[i] = 0;
	}
	for (i = 0; i < 9; i++) {//��
		if (i == n)continue;
		if (M[i][m].N != 0) {
			M[n][m].can[M[i][m].N - 1] = 1;
		}
	}
	for (i = 0; i < 9; i++) {//��
		if (i == m)continue;
		if (M[n][i].N != 0) {
			M[n][m].can[M[n][i].N - 1] = 1;
		}
	}
	for (i = 97; i <= 105; i++) {
		if (M[n][m].C == i) {//�׷�
			for (j = 0; j < 9; j++) {
				if (R[i-97][j] != 0)M[n][m].can[j] = 1;
			}
			return;
		}
	}
}
int putzero(int x, int y) {//�ĺ��ϳ��� �� �ֱ�
	int k, cnt = 0, index;
	for (k = 0; k < 9; k++) {
		if (M[x][y].can[k] == 0) {
			cnt++;
			index = k;
		}
	}
	if (cnt == 1) {
		M[x][y].N = index + 1;
		for (k = 97; k <= 105; k++) {
			if (M[x][y].C == k) { R[k-97][index] = 1; return 1; }
		}
	}
	return 0;
}
void put(int x, int y, int k) {//�� �ֱ�
	int i;
	M[x][y].N = k + 1;
	for (i = 97; i <= 105; i++) {
		if (M[x][y].C == i) { R[i - 97][k] = 1; break; }
	}
}
void disput(int x, int y,int k) {//�� �ٽ� �ʱ�ȭ
	int i;
	M[x][y].N = 0;
	for (i = 97; i <= 105; i++) {
		if (M[x][y].C == i) { R[i - 97][k] = 0; break; }
	}
}
void clear() {//�ʱ�ȭ
	int n, m, k;
	for (n = 0; n < 9; n++) {
		for (m = 0; m < 9; m++) {
			R[n][m] = 0;
			for (k = 0; k < 9; k++) {
				M[n][m].can[k] = 0;
			}
		}
	}
}
void slove(int index) {
	int n, m, k;
	for (n = index; n < 9; n++) {
		for (m = 0; m < 9; m++) {
			if (M[n][m].N == 0) { 
				check(n,m);
				for (k = 0; k < 9; k++) {
					if (M[n][m].can[k]==0) { 
						put(n, m, k);
						slove(n);
						if (flag == 1) return;
						disput(n, m, k);
					}
				}
				return; 
			}
		}
	}
	flag = 1;
	return;
}
int main() {
	FILE *in, *out;
	in = fopen("sudoku.inp", "r");
	out = fopen("sudoku.out", "w");
	int T, cnt = 1,count;
	int n, m, k;
	fscanf(in, "%d", &T);
	while (T--) {
		clear();//�ĺ�,�׷� �ʱ�ȭ
		fprintf(out, "Test Case No: %d\n", cnt++);
		for (n = 0; n < 9; n++) {//�� �Է�
			for (m = 0; m < 9; m++) {   
				fscanf(in, "%d", &M[n][m].N);
			}
		}
		fscanf(in, "%*c%*c");
		for (n = 0; n < 9; n++) {//�׷��Է�
			for (m = 0; m < 9; m++) {
				fscanf(in, "%c%*c", &M[n][m].C);
				if (M[n][m].N != 0) {			   
					for (k = 97; k <= 105; k++) {
						if (M[n][m].C == k) {
							R[k - 97][M[n][m].N - 1] = 1; 
							break;
						}
					}
				}
			}
		}
		fscanf(in, "%*c");
		while (1) {//�ĺ� �ϳ��ΰ� ã�Ƽ� �ֱ�
			count = 0;
			for (n = 0; n < 9; n++) {
				for (m = 0; m < 9; m++) {
					if (M[n][m].N == 0) {
						check(n, m);
						count += putzero(n, m);
					}
				}
			}
			if (count == 0)break;
		}
		flag = 0;
		slove(0);
		for (n = 0; n < 9; n++) {//���
			for (m = 0; m < 9; m++) {
				fprintf(out, "%d ", M[n][m].N);
			}
			fprintf(out, "\n");
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}