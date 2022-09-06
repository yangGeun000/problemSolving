#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *inp, *out;
	inp = fopen("banker.inp", "rt");
	out = fopen("banker.out", "wt");
	int n, m, cnt = 0, cnt2 = 0, flag = 0, tmp = 0, rmax[50], max[50][50], need[50][50], ravailable[50], available[50][50], re[50], queue[50][50];
	int a, b, d, cnt3 = 0, finish[50];
	int i, j, k, flag2;
	char c[7], tmp2, cntN;
	fscanf(inp, "%d%d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m + 1; j++) {
			queue[i][j] = 0;
		}
	}//대기장소 초기화
	for (i = 0; i < m; i++) {
		fscanf(inp, "%d", &rmax[i]);
	}//자원 최대량 입력
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(inp, "%d", &max[i][j]);
		}
	}//max값 입력
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(inp, "%d", &available[i][j]);
		}
	}//available값 입력
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			need[i][j] = max[i][j] - available[i][j];
		}
	}//need값 입력
	for (i = 0; i < m; i++) {
		ravailable[i] = 0;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ravailable[i] += available[j][i];
		}
		ravailable[i] = rmax[i] - ravailable[i];
	}//남은 자원량 입력

	fscanf(inp, "%c", &tmp2); fscanf(inp, "%c", &tmp2); fscanf(inp, "%c", &tmp2);
	for (;;) {
		tmp = 0;
		flag = 0;
		for (i = 0; i < 7; i++) {
			fscanf(inp, "%c", &c[i]);
		}
		for (i = 0; i < m + 1; i++) {
			fscanf(inp, "%d", &re[i]);
		}
		if (c[0] == 'q')break;//quit
		if (c[2] == 'q') {
			for (i = 0; i < m; i++) {
				if (re[i + 1] > need[re[0]][i]) {
					tmp = 1;
				}
			}
			if (tmp == 1) {
				for (i = 0; i < m; i++) {
					fprintf(out, "%d ", ravailable[i]);
				}
				fscanf(inp, "%c", &tmp2);
				fprintf(out, "\n");
				continue;
			}
			for (i = 0; i < m; i++) {
				if (re[i + 1] > ravailable[i]) {
					tmp = 1;
				}
			}
			if (tmp == 1) {
				for (i = 0; i < m + 1; i++) {
					queue[cnt][i] = re[i];
				}
				cnt += 1;
				for (i = 0; i < m; i++) {
					fprintf(out, "%d ", ravailable[i]);
				}
				fscanf(inp, "%c", &tmp2);
				fprintf(out, "\n");
				continue;
			}
			//safe

			for (a = 0; a < m; a++) {
				available[re[0]][a] += re[a + 1];
				need[re[0]][a] -= re[a + 1];
				ravailable[a] -= re[a + 1];
				finish[a] = 0;
			}

			for (a = 0; a < n; a++) {
				cnt3 = 0;
				if (finish[a] == 0) {
					for (b = 0; b < m; b++) {
						if (need[a][b] <= ravailable[b]) {
							cnt3 += 1;

						}
						if (cnt3 == m) {
							finish[a] = 1;
							cnt3 = 0;
						}
					}
				}
				if (finish[a] == 1) break;
			}

			for (a = 0; a < n; a++) {
				if (finish[a] == 1) {
					flag += 1;
				}
			}//safecheck

			if (flag == 0) {
				for (a = 0; a < m; a++) {
					available[re[0]][a] -= re[a + 1];
					need[re[0]][a] += re[a + 1];
					ravailable[a] += re[a + 1];
				}
				for (i = 0; i < m + 1; i++) {
					queue[cnt][i] = re[i];
				}
				cnt += 1;
				for (i = 0; i < m; i++) {
					fprintf(out, "%d ", ravailable[i]);
				}
				fscanf(inp, "%c", &tmp2);
				fprintf(out, "\n");

				continue;
			}

		}//request
		if (c[2] == 'l') {
			for (i = 0; i < m; i++) {
				available[re[0]][i] -= re[i + 1];
				need[re[0]][i] += re[i + 1];
				ravailable[i] += re[i + 1];
			}//릴리즈 값 할당

			for (j = 0; j < cnt; j++) {
				cnt = 0;
				for (i = 0; i < m; i++) {
					if (ravailable[i] >= queue[j][i + 1]) cnt++;
				}
				if (cnt == m) {
					flag = 0;
					for (i = 0; i < m; i++) { // 일단 할당
						available[queue[j][0]][i] += queue[j][i + 1];
						need[queue[j][0]][i] -= queue[j][i + 1];
						ravailable[i] -= queue[j][i + 1];
						if (need[queue[j][0]][i] < 0) {
							flag = 1;
						}
					}
					if (flag != 1) {

						// unSafe 인지 판단하기
						cntN = 0;
						for (i = 0; i < n; i++) {
							cnt = 0;
							for (k = 0; k < m; k++) {
								if (ravailable[k] >= need[i][k]) cnt++;
							}
							if (cnt == m) cntN++;
						}
					}

					if (cntN == 0 || flag == 1) {
						for (k = 0; k < m; k++) {
							available[queue[i][0]][k] -= queue[i][k + 1];
							ravailable[k] += queue[i][k + 1];
							need[queue[i][0]][k] += queue[i][k + 1];
						}
					}
					else {
						for (k = 0; k < m + 1; k++) {
							queue[i][k] = 0;
						}
					}
				}
			}
		}//release
		for (i = 0; i < m; i++) {
			fprintf(out, "%d ", ravailable[i]);
		}
		fscanf(inp, "%c", &tmp2);
		fprintf(out, "\n");
	}

	return 0;
}
