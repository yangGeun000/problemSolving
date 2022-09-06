#include<stdio.h>
#include<string.h>

int main() {
	FILE *in, *out;
	in = fopen("tree.inp", "r");
	out = fopen("tree.out", "w");
	int T, k, cnt,n,m;
	int i, j, num, stack[5000];
	char c, tmp[100], string[5000][10];
	fscanf(in, "%d", &T);
	for (k = 0; k < T; k++) {
		cnt = 0;
		for (i = 0; i < 100; i++) {
			tmp[i] = NULL;
		}
		for (i = 0; i < 5000; i++) {
			stack[i] = -1;
			for (j=0;j<10;j++) {
				string[i][j] = NULL;
			}
		}
		for (i=0;;i++) {
			fscanf(in, "%s", tmp);
			if (tmp[0] == '(') {
				cnt++;
			}
			if (tmp[0] == ')') {
				cnt--;
			}
			fprintf(out, "%s ", tmp);
			if (cnt == 0)break;
			for (j=0;j<10;j++) {
				string[i][j] = tmp[j];
				if (tmp[j] == NULL)break;
			}
		}
		fprintf(out, "\nPreorder\n");
		num = 0;
		for (i=0;i<5000;i++) {
			if (string[i][0] == NULL)break;
			if (string[i][0] == '(') {
				fprintf(out, "r%d\n", num);
				num++;
				continue;
			}
			if(string[i][0] == ')')continue;
			else{
				for (j=0;j<10;j++) {
					if (string[i][j] == NULL) {
						break;
					}
					fprintf(out, "%c", string[i][j]);
				}
				fprintf(out,"\n");
			}
		}
		fprintf(out, "Inorder\n");
		num = 0;
		cnt = 0;
		for (i=0;i<5000;i++) {
			if (string[i][0] == NULL) {
				for (;;) {
					if (stack[0] == -1)break;
					cnt--;
					fprintf(out, "r%d\n", stack[cnt]);
					stack[cnt] = -1;
				}
				break;
			}
			if (string[i][0] == '(') {
				stack[cnt] = num;
				cnt++; num++;
				continue;
			}
			if (string[i][0] == ')')continue;
			else {
				for (j = 0; j < 10; j++) {
					if (string[i][j] == NULL)break;
					fprintf(out, "%c", string[i][j]);
				}
				fprintf(out, "\n");
				if (stack[0] == -1)continue;
				if (stack[0] != -1) {
					cnt--;
					fprintf(out, "r%d\n", stack[cnt]);
					stack[cnt] = -1;
				}
			}
		}

	}
	fclose(in);
	fclose(out);

	return 0;
}