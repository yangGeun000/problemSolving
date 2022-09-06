#include <stdio.h>

typedef struct process {
	int number, arrival, burst;
}process;


int main(){
	FILE *inp, *out;
	inp = fopen("fcfs.inp", "r");
	out = fopen("fcfs.out", "w");
	int i,j,k,index,tmp;
	int sequence, time;
	char bsp;
	process p1[100], p2;
	fscanf(inp,"%d%c",&sequence,&bsp);
	for (i=0; i < sequence;i++) {
		fscanf(inp, "%d%c%d%c%d", &p1[i].number, &bsp, &p1[i].arrival, &bsp, &p1[i].burst);
	}
	for (i = 0; i < sequence; i++) {
		for (j = 0; j < sequence-1; j++) {
			if (p1[j].arrival > p1[j + 1].arrival) {
				p2 = p1[j];
				p1[j] = p1[j+1];
				p1[j+1] = p2;
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