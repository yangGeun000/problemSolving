#include<stdio.h>
#include<string.h>

char string[12];

int main() {
	FILE *in, *out;
	in = fopen("cube.inp", "r");
	out = fopen("cube.out", "w");

	int i, j;
	int r = 0, g = 0, b = 0;

	for (;;) {
		r = 0, g = 0, b = 0;
		fscanf(in, "%s", string);
		for (i = 0; i < 12; i++) {
			if (string[i] == 'r')r++;
			if (string[i] == 'g')g++;
			if (string[i] == 'b')b++;
		}
		if (r == 12 || g == 12 || b == 12) {
			fprintf(out, "TRUE\n");
			break;
		}
		if (r % 2 != 0 || g % 2 != 0 || b % 2 != 0) {
			fprintf(out, "FALSE\n");
			continue;
		}
		if (string[1] == string[7] && string[2] == string[8] && string[3] == string[9] && string[4] == string[10] && string[5] == string[11] && string[0] == string[6]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[0] && string[1] == string[9] && string[2] == string[7] && string[3] == string[10] && string[4] == string[8] && string[5] == string[11]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[0] && string[1] == string[10] && string[2] == string[9] && string[3] == string[8] && string[4] == string[7] && string[5] == string[11]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[0] && string[1] == string[8] && string[2] == string[10] && string[3] == string[7] && string[4] == string[9] && string[5] == string[11]) {
			fprintf(out, "TRUE\n");
			continue;
		}//첫줄
		if (string[0] == string[11] && string[1] == string[7] && string[2] == string[9] && string[3] == string[8] && string[4] == string[10] && string[5] == string[6]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[11] && string[1] == string[9] && string[2] == string[10] && string[3] == string[7] && string[4] == string[8] && string[5] == string[6]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[11] && string[1] == string[10] && string[2] == string[8] && string[3] == string[9] && string[4] == string[7] && string[5] == string[6]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[11] && string[1] == string[8] && string[2] == string[7] && string[3] == string[10] && string[4] == string[9] && string[5] == string[6]) {
			fprintf(out, "TRUE\n");
			continue;
		}//두줄
		if (string[0] == string[10] && string[1] == string[6] && string[2] == string[8] && string[3] == string[9] && string[4] == string[11] && string[5] == string[7]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[8] && string[1] == string[6] && string[2] == string[7] && string[3] == string[10] && string[4] == string[11] && string[5] == string[9]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[7] && string[1] == string[6] && string[2] == string[9] && string[3] == string[8] && string[4] == string[11] && string[5] == string[10]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[9] && string[1] == string[6] && string[2] == string[10] && string[3] == string[7] && string[4] == string[11] && string[5] == string[8]) {
			fprintf(out, "TRUE\n");
			continue;
		}//세줄
		if (string[0] == string[7] && string[1] == string[11] && string[2] == string[8] && string[3] == string[9] && string[4] == string[6] && string[5] == string[10]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[9] && string[1] == string[11] && string[2] == string[7] && string[3] == string[10] && string[4] == string[6] && string[5] == string[8]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[10] && string[1] == string[11] && string[2] == string[9] && string[3] == string[8] && string[4] == string[6] && string[5] == string[7]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[8] && string[1] == string[11] && string[2] == string[10] && string[3] == string[7] && string[4] == string[6] && string[5] == string[9]) {
			fprintf(out, "TRUE\n");
			continue;
		}//네줄
		if (string[0] == string[9] && string[1] == string[7] && string[2] == string[6] && string[3] == string[11] && string[4] == string[10] && string[5] == string[8]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[10] && string[1] == string[9] && string[2] == string[6] && string[3] == string[11] && string[4] == string[8] && string[5] == string[7]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[8] && string[1] == string[10] && string[2] == string[6] && string[3] == string[11] && string[4] == string[7] && string[5] == string[9]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[7] && string[1] == string[8] && string[2] == string[6] && string[3] == string[11] && string[4] == string[9] && string[5] == string[10]) {
			fprintf(out, "TRUE\n");
			continue;
		}//다섯줄
		if (string[0] == string[8] && string[1] == string[7] && string[2] == string[11] && string[3] == string[6] && string[4] == string[10] && string[5] == string[9]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[7] && string[1] == string[9] && string[2] == string[11] && string[3] == string[6] && string[4] == string[8] && string[5] == string[10]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[9] && string[1] == string[10] && string[2] == string[11] && string[3] == string[6] && string[4] == string[7] && string[5] == string[8]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		if (string[0] == string[10] && string[1] == string[8] && string[2] == string[11] && string[3] == string[6] && string[4] == string[9] && string[5] == string[7]) {
			fprintf(out, "TRUE\n");
			continue;
		}
		fprintf(out, "FALSE\n");
	}//여섯줄

	fclose(in);
	fclose(out);
	return 0;
}