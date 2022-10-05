#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int coef;//계수
	int expo;//지수
	struct Node* link;
}Node;
typedef struct Head {
	struct Node* head;
}Head;

Head* createLinkedList() {
	Head* H = (Head*)malloc(sizeof(Head));//헤드 메모리 할당
	H->head = NULL;//헤드 초기화
	return H;
}

void insertNode(Head* H, int coef, int expo) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* p;
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;//다음주소 초기화

	if (H->head == NULL) {//첫 노드가 없을때
		H->head = newNode;
		return;
	}
	else {//첫 노드가 있을때
		p = H->head;
		for (;;) {
			if (p->link == NULL) break;
			p = p->link;
		}
	}
	p->link = newNode;
	return;
}// 새 노드삽입 연산

void removeNode(Head* H, int del) {
	Node* p;
	Node* n;
	if (H->head == NULL) return;
	if (H->head->link == NULL) {
		if (H->head->expo == del) {
			free(H->head);
			H->head = NULL;
			return;
		}
		return;
	}
	else {
		p = H->head;
		if (p->expo == del) {
			n = p->link;
			free(p);
			H->head = n;
			return;
		}
		p = H->head->link;
		n = H->head;
		for (; p; p = p->link) {
			if (p->expo == del) {
				n->link = p->link;
				free(p);
				return;
			}
			n = n->link;
		}
		return;
	}
}//삭제 연산

int main() {
	FILE *inp, *out;
	inp = fopen("hw2.inp", "rt");
	out = fopen("hw2.out", "wt");
	Head *A, *B, *C, *D;
	int i, coef, expo, del, tmp, tmp2;
	char bsp;

	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();
	D = createLinkedList();
	for (;;) {
		fscanf(inp, "%d%c%d%c", &coef, &bsp, &expo, &bsp);
		insertNode(A, coef, expo);
		if (bsp != ' ')break;
	}//처음 리스트 입력값 
	for (;;) {
		fscanf(inp, "%d%c%d%c", &coef, &bsp, &expo, &bsp);
		insertNode(B, coef, expo);
		if (bsp != ' ')break;
	}//두번째 리스트 입력값
	fscanf(inp, "%d", &del);//삭제 지수값
	removeNode(A, del);//삭제
	removeNode(B, del);//삭제
	Node* a = A->head;
	Node* b = B->head;
	for (; a; a = a->link) {
		for (; b; b = b->link) {
			coef = a->coef * b->coef;
			expo = a->expo + b->expo;
			insertNode(C, coef, expo);
		}
		b = B->head;
	}//다항식 단순곱계산
	Node* c = C->head;
	if (C->head != NULL) {
		for (i = c->expo; i >= 0; i--) {
			tmp = 0; tmp2 = 0;
			for (; c; c = c->link) {
				if (i == c->expo) {
					tmp += c->coef;
					tmp2 =i;
				}
			}
			if (tmp != 0)insertNode(D, tmp, tmp2);
			c = C->head;
		}//곱계산 정리연산
		Node* k;
		k = D->head;
		for (; k; k = k->link) {
			fprintf(out, "%d %d ", k->coef, k->expo);
		}
		fprintf(out, "\n*");
	}
	if (C->head == NULL) {
		fprintf(out, "*");
	}
	return 0;
}
