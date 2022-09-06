#include<stdio.h>
#include<string.h>

int main() {
	FILE *inp, *out;
	inp = fopen("palindrome.inp", "r");
	out = fopen("palindrome.out", "w");
	int T, i, j, k, tmp, length;
	int count, count2, n, m, x, y;
	char string[1000];
	fscanf(inp, "%d", &T);

	for (k = 0; k < T; k++) {
		count = 0;
		count2 = 0;
		for (i = 0; i < 1000; i++) {
			string[i] = NULL;
		}
		fscanf(inp, "%s", string);
		i = 0;
		j = strlen(string) - 1;
		for (;;) {
			if (count > 2)break;
			if (i >= j)break;
			if (string[i] == string[j]) {
				i++; j--;
				continue;
			}
			if (string[i] != string[j]) {
				if (string[i] == string[j - 1] && string[i + 1] == string[j]) {
					i++; count++;
					continue;
				}
				x = i; y = j;
				n = 0; m = 0;
				for (;;) {
					y--;; n++;
					if (x >= y)break;
					if (string[x] == string[y]) {
						break;
					}
				}
				x = i; y = j;
				for (;;) {
					x++;; m++;
					if (x >= y)break;
					if (string[x] == string[y]) {
						break;
					}
				}
				if (n <= m) {
					j--; count++;
				}
				if (n > m) {
					i++; count++;
				}
			}
		}
		if (count > 2) {
			fprintf(out, "-1\n");
			continue;
		}
		fprintf(out, "%d\n", count);
	}
	fclose(inp);
	fclose(out);
	return 0;
}