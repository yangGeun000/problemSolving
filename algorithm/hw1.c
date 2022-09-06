#include<stdio.h>
#include<math.h>

int main() {
	FILE *in, *out;
	in = fopen("hw1.inp", "rt");
	out = fopen("hw1.out", "wt");
	
	int i=0,number=0,odd[50],even[50],tank[50],tmp=0,cnt=0,cnt2=0;
	double sum=0,ave=0,ave2=0,mean=0,var=0,var2=0; 
	char bsp;

	fscanf(in, "%d%c", &number, &bsp);
	for (i=0;i<number;i++) {
		fscanf(in, "%d%c", &tank[i], &bsp);
	}
	for (i = 0; i < number; i++) {
		tmp = tank[i] % 2;
		if (tmp == 0) { 
			even[cnt] = tank[i];
			cnt += 1;
		}
		if (tmp != 0) {
			odd[cnt2] = tank[i];
			cnt2 += 1;
		}
	}
	for (i = 0; i < cnt; i++) {
		sum += even[i];
	}
	ave = sum; ave = ave / cnt;
	mean = ave * ave;
	tmp = 0;
	for (i = 0; i < cnt; i++) {
		tmp += even[i] * even[i];
	}
	var = tmp; var = var / cnt;
	var = var - mean;
	var = sqrt(var); tmp = var * 10; var = tmp; var = var / 10;
	tmp = ave * 10; ave = tmp; ave = ave / 10;
	
	sum =0;
	for (i = 0; i < cnt2; i++) {
		sum += odd[i];
	}
	ave2 = sum; ave2=ave2 / cnt2;
	mean = ave2 * ave2;
	tmp = 0;
	for (i = 0; i < cnt2; i++) {
		tmp += odd[i] * odd[i];
	}
	var2 = tmp; var2= var2/ cnt2;
	var2 = var2 - mean;
	var2 = sqrt(var2); tmp = var2 * 10; var2 = tmp; var2 = var2 / 10;
	tmp = ave2 * 10; ave2 = tmp; ave2 = ave2 / 10;

	if (cnt == 0) {
		ave = 0; var = 0;
	}
	if (cnt2 == 0) {
		ave2 = 0; var2 = 0;
	}
	fprintf(out,"odd %d %.1f %.1f\n", cnt2, ave2, var2);
	fprintf(out,"even %d %.1f %.1f\n", cnt, ave, var);
	fprintf(out,"*");

	fclose(in);
	fclose(out);
	return 0;
}