#include<stdio.h>
FILE *in, *out;

typedef struct process {
	int request, number, index;
}process;
int head = 0, time = 0, retime = 1, tmp = 0, tmp2 = 0, end, cnt = 0, flag = 0;
process disk[100], Q[100];

void value(int n, int m) {
	if (n > m) {
		tmp = n - m;
	}
	if (n < m) {
		tmp = m - n;
	}
	if (n == m)tmp = 0;
	return;
}

void value2(int n, int m) {
	if (n > m) {
		tmp2 = n - m;
	}
	if (n < m) {
		tmp2 = m - n;
	}
	if (n == m)tmp2 = 0;
	return;
}

void FCFS(int s) {
	int i, result;
	for (;;) {
		for (i = 0;; i++) {//대기큐에 넣기
			if (disk[i].request == -1) {
				end = i - 1;
				break;
			}
			if (time >= disk[i].request&&disk[i].index == 0) {
				Q[cnt].index = 1;  disk[i].index = 1;
				Q[cnt].request = disk[i].request;
				Q[cnt].number = disk[i].number;
				cnt++;
			}
		}
		for (i = 0; i < 100; i++) {
			if (Q[i].index == 1)break;//대기큐에 있을때
			if (i == end + 1)break;
		}
		if (i == end + 1)break;;//대기큐에 없을때
		Q[i].index = 0;
		value(head, Q[i].number);
		result = tmp + s;
		head = Q[i].number;
		time += result;
	}
	return;
}

void SSTF(int s) {
	int i, k, result, n = 0;
	for (;;) {
		for (i = 0;; i++) {//대기큐에 넣기
			if (disk[i].request == -1) {
				end = i - 1;
				break;
			}
			if (time >= disk[i].request&&disk[i].index == 0) {
				Q[cnt].index = 1;  disk[i].index = 1;
				Q[cnt].request = disk[i].request;
				Q[cnt].number = disk[i].number;
				cnt++;
			}
		}
		for (i = 0;; i++) {
			if (Q[i].index == 1) {
				n = 1;
				value(head, Q[i].number);
				k = i;
				break;
			}
			if (i == end)break;
		}
		for (i = 0; i < 100; i++) {
			if (Q[i].index == 1) {
				if (i >= 1) {
					value2(head, Q[i].number);
					if (tmp > tmp2) {
						tmp = tmp2;
						k = i;
					}
				}
			};//대기큐에 있을때
			if (i == end)break;
		}
		if (n == 0)break;;//대기큐에 없을때
		Q[k].index = 0;
		value(head, Q[k].number);
		result = tmp + s;
		head = Q[k].number;
		time += result;
		n = 0;
	}
	return;
}

void LOOK(int s) {
	int i, k, result, n = 0,m=0;
	for (;;) {
		for (i = 0;; i++) {//대기큐에 넣기
			if (disk[i].request == -1) {
				end = i - 1;
				break;
			}
			if (time >= disk[i].request&&disk[i].index == 0) {
				Q[cnt].index = 1;  disk[i].index = 1;
				Q[cnt].request = disk[i].request;
				Q[cnt].number = disk[i].number;
				cnt++;
			}
		}
		if (flag == 0) {
			for (i = 0; i < 100; i++) {
				if (Q[i].index == 1 && head <= Q[i].number) {
					n = 1;
					value(head, Q[i].number);
					k = i;
					break;
				}
				if (i == end) {
					flag = 1;
					m++;
					break;
				}
			}
			if (n == 0&&m==2)break;;//대기큐에 없을때
			if (flag == 1)continue;
			for (i = 0; i < 100; i++) {
				if (Q[i].index == 1 && head <= Q[i].number) {
					if (i >= 1) {
						value2(head, Q[i].number);
						if (tmp > tmp2) {
							tmp = tmp2;
							k = i;
						}
					}
				};//대기큐에 있을때
				if (i == end)break;
			}
		}
		if (flag == 1) {
			for (i = 0; i < 100; i++) {
				if (Q[i].index == 1 && head >= Q[i].number) {
					n = 1;
					value(head, Q[i].number);
					k = i;
					break;
				}
				if (i == end) {
					flag = 0;
					m++;
					break;
				}
			}
			if (n == 0&&m==2)break;;//대기큐에 없을때
			if (flag == 0)continue;
			for (i = 0; i < 100; i++) {
				if (Q[i].index == 1 && head >= Q[i].number) {
					if (i >= 1) {
						value2(head, Q[i].number);
						if (tmp > tmp2) {
							tmp = tmp2;
							k = i;
						}
					}
				};//대기큐에 있을때
				if (i == end)break;
			}
		}
		if (n == 0)break;;//대기큐에 없을때
		Q[k].index = 0;
		value(head, Q[k].number);
		result = tmp + s;
		head = Q[k].number;
		time += result;
		n = 0;
		m = 0;
	}
	return;
}

int main() {
	in = fopen("disk.inp", "rt");
	out = fopen("disk.out", "wt");
	int i, s;
	char c, name[5];
	fscanf(in, "%s%d", name, &s);
	for (i = 0; i < 100; i++) {
		fscanf(in, "%d%d", &disk[i].request, &disk[i].number);
		if (disk[i].request == -1)break;
	}
	for (;; time++) {
		if (name[0] == 'F') {
			FCFS(s);
		}
		if (name[0] == 'S') {
			SSTF(s);
		}
		if (name[0] == 'L') {
			LOOK(s);
		}
		if (Q[end].request == disk[end].request && Q[end].index == 0)break;
	}
	fprintf(out, "%d %d", time, head);
	return 0;
}