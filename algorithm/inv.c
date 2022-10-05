#include<stdio.h> 

int n[1000000], m[1000000]; 
unsigned long long inv;
void merge(int start,int mid, int end) {
	int left = start,right=mid+1, index = start;
	int i, flag;
	unsigned long long cnt = 0;
	for (;;) {
		if (left > mid) {
			flag = 0;
			break;
		}
		if (right > end) {
			flag = 1;
			break;
		}
		if (n[left] > n[right]) {
			m[index] = n[right];
			right++, index++, cnt++;
			continue;
		}
		if (n[left] < n[right]) {
			m[index] = n[left];
			left++, index++;
			inv += cnt;
			continue;
		}
	}
	if (flag == 0) {
		for (i = right; i <= end; i++) {
			m[index] = n[i];
-			index++;
		}
	}
	if (flag == 1) {
		for (i = left; i <= mid; i++) {
			m[index] = n[i];
			index++;
			inv += cnt;
		}
	}
	for (i = start; i <= end; i++) {
		n[i] = m[i];
	}
	return;
}
void msort(int start,int end) {
	if (start == end)return;
	int mid= (start+end)/2;
	if (start<end) {
		msort(start, mid);
		msort(mid + 1, end);
		merge(start,mid,end);
	}
	return;
}

int main() {
	FILE *in, *out;
	in = fopen("inv.inp", "r");
	out = fopen("inv.out", "w");
	int T,i,j,k,cnt;
	fscanf(in, "%d", &T);
	for (k = 0; k < T; k++) {
		inv = 0;//도치수 카운터
		fscanf(in, "%d", &cnt);//cnt 원소개수
		for (i=0;i<cnt;i++) {
			fscanf(in, "%d", &n[i]);
		}
		msort( 0, cnt-1);
		fprintf(out, "%u\n", inv);
	}
	fclose(in);
	fclose(out);
	return 0;
}