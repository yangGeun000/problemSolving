#include<stdio.h>

int map[20][20];
int k,B,W,cnt;
int black=0, white=0;
void bfs(int x,int y) {
	if (x >= k || y >= k)return;
	if (x < 0 || y < 0)return;
	if (map[y][x] < 0)return;
	if (map[y][x] == 1) {
		B++;
		return;
	}
	if (map[y][x] == 2) {
		W++;
		return;
	}
	if (map[y][x] == 0) {
		map[y][x] = -1;
		cnt++;
		bfs(x, y-1);//상
		bfs(x, y+1);//하
		bfs(x-1, y);//좌
		bfs(x+1, y);//우
	}
	return;
}
int main() {
	FILE *in, *out;
	in = fopen("go.inp", "r");
	out = fopen("go.out", "w");
	int i, j;
	char tmp;
	fscanf(in, "%d", &k);
	fscanf(in, "%c",&tmp);
	for (i=0;i<k;i++) {
		for (j = 0; j < k; j++) {
			fscanf(in, "%c", &tmp);
			if (tmp == '.') {
				map[i][j] = 0;//공백
			}
			if (tmp == 'B') {
				map[i][j] = 1;//검은돌
			}
			if (tmp == 'W') {
				map[i][j] = 2;//흰돌
			}
		}
		fscanf(in, "%c", &tmp);
	}
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			B = 0, W = 0, cnt = 0;
			bfs(j, i);
			if (B == 0 && W > 0) {
				white += cnt;
			}//흰돌집 계산
			if (B > 0 && W == 0) {
				black += cnt;
			}//검은돌집 계산
		}
	}
	fprintf(out, "%d ", black);
	fprintf(out, "%d", white);
	fclose(in);
	fclose(out);
	return 0;
}