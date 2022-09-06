#include<stdio.h>
#include<string.h>
char S[100000];
int V[100000];
void K(int i) {
	if (i >= strlen(S))return;
	if (S[i] == 'L') {
		V[i] = (V[i - 1] + 1) % 4;
		return;
	}
	if (S[i] == 'R') {
		V[i] = (V[i - 1] + 3) % 4;
		return;
	}
	return;
}
int main() {
	FILE *in, *out;
	in = fopen("pandora.inp", "r");
	out = fopen("pandora.out", "w");
	int T, i, j, k, cnt;
	int	flag, flag2;
	fscanf(in, "%d", &T);
	for (k = 0; k < T; k++) {
		fscanf(in, "%s", S);
		cnt = 2, flag = 0, flag2 = 0;
		for (i = 0; i < strlen(S); i++) {
			if (flag == 1 && flag2 == 1)break;
			if (i == 0) {
				if (S[0] == 'L') {
					V[0] = 1;
				}
				if (S[0] == 'R') {
					V[0] = 3;
				}
			}
			if (i > 0) {
				K(i);
			}
			K(i + 1);
			K(i + 2);
			if (V[i] == 1) {
				j = i + 1;
				if (j >= strlen(S))j -= strlen(S);
				if (V[j] == 0) {
					if (V[j + 1] == 3) {
						flag = 1;
					}
				}
			}
			if (V[i] == 3) {
				j = i + 1;
				if (j >= strlen(S))j -= strlen(S);
				if (V[j] == 2) {
					if (V[j + 1] == 1) {
						flag = 1;
					}
				}
			}
			//////////////////////////////
			if (V[i] == 2) {
				j = i + 1;
				if (j >= strlen(S))j -= strlen(S);
				if (V[j] == 1) {
					if (V[j + 1] == 0) {
						flag2 = 1;
					}
				}
			}
			if (V[i] == 0) {
				j = i + 1;
				if (j >= strlen(S))j -= strlen(S);
				if (V[j] == 3) {
					if (V[j + 1] == 2) {
						flag2 = 1;
					}
				}
			}
		}
		if (V[strlen(S) - 2] == 1 && V[0] == 3)flag = 1;
		if (flag == 1)cnt--;
		if (flag2 == 1)cnt--;
		fprintf(out, "%d\n", cnt);
	}
	fclose(in);
	fclose(out);
	return 0;
}