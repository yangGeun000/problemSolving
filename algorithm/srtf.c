#include <stdio.h>
typedef struct process {
	int number, arrival, burst;
} process;

typedef struct _Queue {
	int number, arrival, burst, wait;
} Que;
process p1[100];
Que Queue[100];
int main() {
	FILE *in, *out;
	int rear = 0;
	int N, i, k;
	int num, arr, use;
	int min, minV;
	int Next, Now, end = 1, skip = 1;
	int waitTime, maxTime = 0;

	in = fopen("srtf.inp", "r");
	out = fopen("srtf.out", "w");

	fscanf(in, "%d\n", &N);
	for (i = 0; i < N; i++) {
		fscanf(in, "%d %d %d\n", &num, &arr, &use);

		for (k = i; k >= 0; k--) {
			if (k == 0) {
				p1[0].number = num;
				p1[0].arrival = arr;
				p1[0].burst = use;
				break;
			}
			else if (arr == p1[k - 1].arrival) {
				if (use < p1[k - 1].burst) { 
					p1[k].number = p1[k - 1].number;
					p1[k].arrival = p1[k - 1].arrival;
					p1[k].burst = p1[k - 1].burst;
				}
				else if ((use == p1[k - 1].burst) && (num < p1[k - 1].number)) {
					p1[k].number = p1[k - 1].number;
					p1[k].arrival = p1[k - 1].arrival;
					p1[k].burst = p1[k - 1].burst;
				}
				else {
					p1[k].number = num;
					p1[k].arrival = arr;
					p1[k].burst = use;
					break;
				}
			}
			else if (arr < p1[k - 1].arrival) { 
				p1[k].number = p1[k - 1].number;
				p1[k].arrival = p1[k - 1].arrival;
				p1[k].burst = p1[k - 1].burst;
			}
			else {
				p1[k].number = num;
				p1[k].arrival = arr;
				p1[k].burst = use;
				break;
			}
		}
	}


	Now = p1[0].arrival;
	Next = 0;
	while (1) {
		if (end&&skip) {
			for (i = Next; i < N; i++) { 
				if (p1[i].arrival == Now) {
					Queue[rear].wait = 0;
					Queue[rear].number = p1[i].number;
					Queue[rear].arrival = p1[i].arrival;
					Queue[rear++].burst = p1[i].burst;
				}
				else {
					break;
				}
			}
			if (i == N) { 
				end = 0;
			}
			else {
				Next = i;
				waitTime = p1[Next].arrival - Now; 
				Now = p1[Next].arrival;
			}
		}
		skip = 1;
		if (!end && rear == 0) break;

		minV = 0;
		min = Queue[0].burst;
		for (i = 1; i < rear; i++) { 
			if (min > Queue[i].burst) { 
				min = Queue[i].burst;
				minV = i;
			}
			else if (min == Queue[i].burst) {
				if (Queue[minV].arrival > Queue[i].arrival) {
					min = Queue[i].burst;
					minV = i;
				}
				else if (Queue[minV].arrival == Queue[i].arrival) {
					if (Queue[minV].number > Queue[i].number) { 
						min = Queue[i].burst;
						minV = i;
					}
				}
			}
		}
		if (!end) {
			waitTime = Queue[minV].burst;
		}

		
		if (Queue[minV].burst > waitTime) { 
			Queue[minV].burst -= waitTime;
			for (i = 0; i < rear; i++) {
				if (i != minV) {
					Queue[i].wait += waitTime;
				}
			}
		}
		else if (Queue[minV].burst == waitTime) { 
			maxTime += Queue[minV].wait; 

			for (i = 0; i < rear; i++) {
				if (i != minV)
					Queue[i].wait += waitTime;
			}

			for (i = minV; i < rear - 1; i++) {
				Queue[i].number = Queue[i + 1].number;
				Queue[i].arrival = Queue[i + 1].arrival;
				Queue[i].burst= Queue[i + 1].burst;
				Queue[i].wait = Queue[i + 1].wait;
			}
			rear--;
		}
		else {
			maxTime += Queue[minV].wait; 

			waitTime -= Queue[minV].burst;
			for (i = 0; i < rear; i++) {
				if (i != minV)
					Queue[i].wait += Queue[minV].burst;
			}

			for (i = minV; i < rear - 1; i++) {
				Queue[i].number = Queue[i + 1].number;
				Queue[i].arrival = Queue[i + 1].arrival;
				Queue[i].burst = Queue[i + 1].burst;
				Queue[i].wait = Queue[i + 1].wait;
			}
			rear--;

			if (rear == 0) {
				skip = 1;
			}
			else {
				skip = 0;
			}
		}
	}

	fprintf(out, "%d\n", maxTime);

	fclose(in);
	fclose(out);

	return 0;
}