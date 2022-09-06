#include<stdio.h>

int main() {
	FILE *in, *out;
	in = fopen("bowling.inp", "r");
	out = fopen("bowling.out", "w");
	int T = 0, n[50][10], score = 0, tmp = 0, tmp2 = 0;
	int i, j, k;
	char c;
	fscanf(in, "%d", &T);

	for (k = 0; k < T; k++) {
		score = 0;
		for (i = 0; i < 15; i++) {
			for (j = 0; j < 5; j++) {
				n[i][j] = -1;
			}
		}
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 2; j++) {
				fscanf(in, "%d", &tmp);
				n[i][j] = tmp;
				score += tmp;
				tmp2 = n[9][0] + n[9][1];
				if (i == 9 && tmp2 >= 10) {
					fscanf(in, "%d", &tmp);
					n[9][2] = tmp;
					score += tmp;
				}
				if (n[i][0] == 10 && i < 9)break;
			}
		}

		for (i = 0; i < 9; i++) {
			if (n[i][0] == 10) {
				score += n[i + 1][0];
				if (n[i + 1][1] == -1) {
					score += n[i + 2][0];
					continue;
				}
				score += n[i + 1][1];
				continue;
			}

			if (n[i][0] + n[i][1] == 10) {
				score += n[i + 1][0];
			}
		}
		fprintf(out, "%d", score);
		if (k != T - 1) { fprintf(out, "\n"); }
	}

	fclose(in);
	fclose(out);

	return 0;
}