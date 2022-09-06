#include<stdio.h>
typedef struct {
	int  PID, number, count, count2;
}proess;

int main() {
	FILE *in, *out;
	in = fopen("page.inp", "rt");
	out = fopen("page.out", "wt");
	proess input[3500], FIFO[3500], LRU[3500], OPT[3500];
	int i, j, k, index, cnt, cnt2, cnt3, flag, fault, m, n, tmp[3500];
	char c;
	for (i = 0; i < 3500; i++) {
		input[i].PID = -1; input[i].number = -1; input[i].count = 0;
		FIFO[i].PID = -1; FIFO[i].number = -1; FIFO[i].count = 0;
		LRU[i].PID = -1; LRU[i].number = -1; LRU[i].count = 0;
		OPT[i].PID = -1; OPT[i].number = -1; OPT[i].count = -1; OPT[i].count2 = 0;
		tmp[i] = -1;
	}
	fscanf(in, "%d", &k);
	for (i = 0;; i++) {
		fscanf(in, "%d%c%d", &input[i].PID, &c, &input[i].number);
		if (input[i].PID == -1) break;
	}//입력값 받기
	index = 0; fault = 0;
	for (i = 0;; i++) {
		cnt = 0; flag = 0;
		if (input[i].PID == -1) break;
		for (j = 0;; j++) {
			if (FIFO[j].PID == -1) break;
			if (input[i].PID == FIFO[j].PID) {
				cnt++;
				if (input[i].number == FIFO[j].number) {
					flag = 1;
				}
			}
		}
		if (cnt == k) {
			if (flag == 0) {
				for (j = 0;; j++) {
					if (input[i].PID == FIFO[j].PID) {
						for (n = 0;; n++) {
							for (m = 0;; m++) {
								if (input[i].PID == FIFO[m].PID) {
									if (FIFO[m].count == n) {
										fault++;
										FIFO[m].number = input[i].number;
										FIFO[m].count = i;
										flag++;
										break;
									}
								}
								if (FIFO[m].PID == -1)break;
							}
							if (flag == 1)break;
						}
					}
					if (flag == 1) {
						flag = 0;
						break;
					}
				}
			}
		}

		if (cnt < k) {
			if (flag == 0) {
				FIFO[index].PID = input[i].PID; FIFO[index].number = input[i].number; FIFO[index].count = i;
				index++; fault++;
			}
		}
	}//FIFO
	fprintf(out, "FIFO: %d\n", fault);
	for (i = 0;; i++) {
		if (FIFO[i].PID == -1) break;
		fprintf(out, "%d %d %d\n", i, FIFO[i].PID, FIFO[i].number);
	}

	index = 0; fault = 0;
	for (i = 0;; i++) {
		cnt = 0; flag = 0;
		if (input[i].PID == -1) break;
		for (j = 0;; j++) {
			if (LRU[j].PID == -1) break;
			if (input[i].PID == LRU[j].PID) {
				cnt++;
				if (input[i].number == LRU[j].number) {
					flag = 1;
					LRU[j].count = i;
				}
			}
		}
		if (cnt == k) {
			if (flag == 0) {
				for (j = 0;; j++) {
					if (input[i].PID == LRU[j].PID) {
						for (n = 0;; n++) {
							for (m = 0;; m++) {
								if (input[i].PID == LRU[m].PID) {
									if (LRU[m].count == n) {
										fault++;
										LRU[m].number = input[i].number;
										LRU[m].count = i;
										flag++;
										break;
									}
								}
								if (LRU[m].PID == -1)break;
							}
							if (flag == 1)break;
						}
					}
					if (flag == 1) {
						flag = 0;
						break;
					}
				}
			}
		}

		if (cnt < k) {
			if (flag == 0) {
				LRU[index].PID = input[i].PID; LRU[index].number = input[i].number; LRU[index].count = i;
				index++; fault++;
			}
		}
	}//LRU
	fprintf(out, "LRU: %d\n", fault);
	for (i = 0;; i++) {
		if (LRU[i].PID == -1) break;
		fprintf(out, "%d %d %d\n", i, LRU[i].PID, LRU[i].number);
	}

	index = 0; fault = 0;
	for (i = 0;; i++) {
		cnt = 0; cnt2 = 0; flag = 0;
		if (input[i].PID == -1) break;
		for (j = 0;; j++) {
			if (OPT[j].PID == -1) break;
			if (input[i].PID == OPT[j].PID) {
				cnt++;
				tmp[cnt2] = j; cnt2++;
				if (input[i].number == OPT[j].number) {
					flag = 1;
				}
			}
		}
		cnt3 = k;
		for (j = i + 1;; j++) {
			if (input[j].PID == -1)break;
			if (cnt3 == 0)break;
			if (input[j].PID == input[i].PID) {
				for (cnt2 = 0; cnt2 < k; cnt2++) {
					if (input[j].PID == OPT[tmp[cnt2]].PID) {
						if (input[j].number == OPT[tmp[cnt2]].number) {
							if (OPT[tmp[cnt2]].count == -1) {
								OPT[tmp[cnt2]].count = cnt3;
								cnt3--;
							}
							
						}
					}
				}
			}
		}

		if (cnt == k) {
			if (flag == 0) {
				if (cnt3>=2) {
					for (j = 0;; j++) {
						if (input[i].PID == OPT[j].PID&&OPT[j].count == -1) {
							for (n = 0;; n++) {
								for (m = 0;; m++) {
									if (input[i].PID == OPT[m].PID&&OPT[m].count==-1) {
										if (OPT[m].count2 == n) {
											fault++;
											OPT[m].number = input[i].number;
											flag++;
											OPT[m].count2 = i;
											break;
										}
									}
									if (OPT[m].PID == -1)break;
								}
								if (flag == 1)break;
							}
						}
						if (flag == 1) {
							flag = 0;
							break;
						}
					}
				}
				else {
					for (j = 0;; j++) {
						if (input[i].PID == OPT[j].PID) {
							for (n = -1;; n++) {
								for (m = 0;; m++) {
									if (input[i].PID == OPT[m].PID) {
										if (OPT[m].count == n) {
											fault++;
											OPT[m].number = input[i].number;
											flag++;
											OPT[m].count2 = i;
											break;
										}
									}
									if (OPT[m].PID == -1)break;
								}
								if (flag == 1)break;
							}
						}
						if (flag == 1) {
							flag = 0;
							break;
						}
					}
				}
			}
		}
		cnt3 = cnt3;
		if (cnt < k) {
			if (flag == 0) {
				OPT[index].PID = input[i].PID; OPT[index].number = input[i].number; OPT[index].count2 = i;
				index++; fault++;
			}
		}
		for (j = 0;; j++) {
			if (OPT[j].PID == -1) break;
			OPT[j].count = -1;
		}
	}//OPT
	fprintf(out, "OPT: %d\n", fault);
	for (i = 0;; i++) {
		if (OPT[i].PID == -1) break;
		fprintf(out, "%d %d %d\n", i, OPT[i].PID, OPT[i].number);
	}
	return 0;
}
