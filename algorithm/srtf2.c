#include<stdio.h>
typedef struct process {
	int number, arrival, burst;
}process;
int i, j, index, tmp;
int sequence, time, timeup;
process p1[100], p2, p3[100];
void sorting(int index);
void sorting3(int index);
int main() {
	FILE *inp, *out;
	inp = fopen("srtf.inp", "r");
	out = fopen("srtf.out", "w");
	char bsp;
	fscanf(inp, "%d%c", &sequence, &bsp);
	for (i = 0; i < sequence; i++) {
		fscanf(inp, "%d%c%d%c%d", &p1[i].number, &bsp, &p1[i].arrival, &bsp, &p1[i].burst);
	}
	for (i = 0; i < sequence; i++) {
		timeup += p1[i].burst;
	}
	
	sorting(0);
	for (i = 0; i < timeup; i++) {
		sorting3(i);
	}
	for (i = 0; i < sequence; i++) {
		printf("%d %d %d\n", p1[i].number, p1[i].arrival, p1[i].burst);
	}
	time = 0, tmp = 0;
	for (i = 0; i < sequence; i++) {
		if (time < p1[i].arrival)time = p1[i].arrival;
		tmp = time - p1[i].arrival + tmp;
		time += p1[i].burst;
	}
	printf("%d", tmp);
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
	return;
}


void sorting3(int index) {
	p1[0].burst -= 1;
		if (index == p1[i].arrival) {
	for (i = 0; i < sequence; i++) {
			for (i = 0; i < sequence; i++) {
				for (j = 0; j < sequence - 1; j++) {

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
		}
	}
	return;
}