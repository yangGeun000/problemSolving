#include<stdio.h>
typedef struct process {
	int number, arrival, burst;
}process;
int i, j, index, tmp;
int sequence, time;
process p1[100], p2;
void sorting(int index);
void sorting2(int index);
int main() {
	FILE *inp, *out;
	inp = fopen("sjf.inp", "r");
	out = fopen("sjf.out", "w");
	char bsp;
	time = 0;
	fscanf(inp, "%d%c", &sequence, &bsp);
	for (i = 0; i < sequence; i++) {
		fscanf(inp, "%d%c%d%c%d", &p1[i].number, &bsp, &p1[i].arrival, &bsp, &p1[i].burst);
	}
	sorting(0);
	for (i = 1; i < sequence; i++) {
		sorting2(i);
	}
	printf("%d\n", time);
	time = 0, tmp = 0;
	for (i = 0; i < sequence; i++) {
		if (time < p1[i].arrival)time = p1[i].arrival;
		tmp = time - p1[i].arrival + tmp;
		time += p1[i].burst;
	}
	fprintf(out,"%d", tmp);
	fclose(inp);
	fclose(out);

	return 0;
}

void sorting(int index) {
	for (i = index; i < sequence; i++) {
		for (j = index; j < sequence - 1; j++) {
			if (p1[j].arrival > p1[j + 1].arrival) {
				p2 = p1[j];
				p1[j] = p1[j + 1];
				p1[j + 1] = p2;
			}
			else if (p1[j].arrival == p1[j + 1].arrival) {
				if (p1[j].burst > p1[j + 1].burst) {
					p2 = p1[j];
					p1[j] = p1[j + 1];
					p1[j + 1] = p2;
				}
				else if (p1[j].burst == p1[j + 1].burst) {
					if (p1[j].number > p1[j + 1].number) {
						p2 = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = p2;
					}
				}
			}
		}
	}
	time += p1[index].burst;
	return;
}

void sorting2(int index) {
	if (time < p1[index].arrival)time = p1[index].arrival;
	for (i = index; i < sequence; i++) {
		for (j = index; j < sequence - 1; j++) {
			if (p1[j].arrival > time || p1[j + 1].arrival > time) continue;
			if (p1[j].burst > p1[j + 1].burst) {
				p2 = p1[j];
				p1[j] = p1[j + 1];
				p1[j + 1] = p2;
			}
			else if (p1[j].burst == p1[j + 1].burst) {
				if (p1[j].arrival > p1[j + 1].arrival) {
					p2 = p1[j];
					p1[j] = p1[j + 1];
					p1[j + 1] = p2;
				}
				else if (p1[j].arrival == p1[j + 1].arrival) {
					if (p1[j].number > p1[j + 1].number) {
						p2 = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = p2;
					}
				}
			}
		}
	}
	i = index;
	time += p1[index].burst;
	return;
}