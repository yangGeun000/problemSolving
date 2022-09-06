#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int coef;//���
	int expo;//����
	struct Node* link;
}Node;
typedef struct Head {
	struct Node* head;
}Head;

Head* createLinkedList() {
	Head* H = (Head*)malloc(sizeof(Head));//��� �޸� �Ҵ�
	H->head = NULL;//��� �ʱ�ȭ
	return H;
}

void insertNode(Head* H, int coef, int expo) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* p;
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;//�����ּ� �ʱ�ȭ

	if (H->head == NULL) {//ù ��尡 ������
		H->head = newNode;
		return;
	}
	else {//ù ��尡 ������
		p = H->head;
		for (;;) {
			if (p->link == NULL) break;
			p = p->link;
		}
	}
	p->link = newNode;
	return;
}// �� ������ ����

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
}//���� ����

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
	}//ó�� ����Ʈ �Է°� 
	for (;;) {
		fscanf(inp, "%d%c%d%c", &coef, &bsp, &expo, &bsp);
		insertNode(B, coef, expo);
		if (bsp != ' ')break;
	}//�ι�° ����Ʈ �Է°�
	fscanf(inp, "%d", &del);//���� ������
	removeNode(A, del);//����
	removeNode(B, del);//����
	Node* a = A->head;
	Node* b = B->head;
	for (; a; a = a->link) {
		for (; b; b = b->link) {
			coef = a->coef * b->coef;
			expo = a->expo + b->expo;
			insertNode(C, coef, expo);
		}
		b = B->head;
	}//���׽� �ܼ������
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
		}//����� ��������
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
