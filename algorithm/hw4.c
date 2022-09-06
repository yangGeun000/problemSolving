#include<stdio.h>
#include<stdlib.h>

FILE *in, *out;
int heap[1000], size = 0;

void insertheap(int input) {
	int i, tmp;
	size++;
	i = size;
	heap[size] = input;
	for (;;) {
		if (i == 1)break;
		if (heap[i] <= heap[i / 2])break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
		i /= 2;
	}
}//최대힙 입력

void removeheap() {
	int i, tmp;
	fprintf(out, "%d ", heap[1]);
	heap[1] = heap[size];
	heap[size] = NULL;
	size--;
	if (heap[1] == NULL)return;
	i = 1;
	for (;;) {
		//if (heap[i] > heap[i*2] && heap[i] > heap[i*2+1])break;
		if (heap[i * 2] == NULL&&heap[i*2+1]==NULL)return;
		if (heap[i * 2] > heap[i * 2 + 1]) {
			if (heap[i] > heap[i * 2])return;
			tmp = heap[i];
			heap[i] = heap[i * 2];
			heap[i * 2] = tmp;
			i = i * 2;
		}
		if (heap[i * 2] < heap[i * 2 + 1]) {
			if (heap[i] > heap[i * 2 + 1])return;
			tmp = heap[i];
			heap[i] = heap[i * 2 + 1];
			heap[i * 2 + 1] = tmp;
			i = i * 2 + 1;
		}
		//if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])break;
	}
}//최대힙 출력

void mid(int num) {
	if (heap[num] != NULL) {
		mid(num * 2);
		fprintf(out, "%d ", heap[num]);
		mid(num * 2 + 1);
	}
}//중위순회

typedef struct Node {
	int date;
	struct Node* Llink;
	struct Node* Rlink;
}Node;

typedef struct Head {
	struct Node* head;
}Head;

Head* createLinkedList() {
	Head* H = (Head*)malloc(sizeof(Head));//헤드 메모리 할당
	H->head = NULL;//헤드 초기화
	return H;
}

void insertNode(Head* H, int input) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* p;
	newNode->date = input;
	newNode->Llink = NULL;//왼쪽주소초기화
	newNode->Rlink = NULL;//오른쪽주소초기화

	if (H->head == NULL) {//첫 노드가 없을때
		H->head = newNode;
		return;
	}
	else {//첫 노드가 있을때
		p = H->head;
		for (;;) {
			if (p->date > input) {
				if (p->Llink == NULL) {
					p->Llink = newNode;
					return;
				}
				p = p->Llink;
			}
			else {
				if (p->Rlink == NULL) {
					p->Rlink = newNode;
					return;
				}
				p = p->Rlink;
			}
		}
	}
}// 새 노드삽입 연산

void treemid(Node* p) {
	if (p->Llink != NULL) {
		treemid(p->Llink);
	}
	fprintf(out, "%d ", p->date);
	if (p->Rlink != NULL) {
		treemid(p->Rlink);
	}
}// 이진트리 중회순위출력

void removeNode(Head* H, int input) {
	Node *n, *m, *p, *q, *r, *s;
	int flag, a, b;
	n = H->head;
	if (n == NULL)return;
	for (;;) {
		if (H->head->date == input) {
			flag = 2;
			break;
		}
		if (n->date == input)break;
		if (n->date > input) {
			m = n;
			n = n->Llink;
			flag = 0;
			if (n == NULL)return;
		}
		if(n->date<input) {
			m = n;
			n = n->Rlink;
			flag = 1;
			if (n == NULL)return;
		}
	}//삭제할려는 노드찾기
	if (n->Llink == NULL && n->Rlink == NULL) {
		if (flag == 0) {
			m->Llink = NULL;
			free(n);
		}
		if (flag == 1) {
			m->Rlink = NULL;
			free(n);
		}
		if (flag == 2) {
			H->head == NULL;
			free(n);
		}
		return;
	}//자식이 없을때
	if (n->Llink != NULL && n->Rlink != NULL) {
		p = n->Llink; q = n;
		for (;;) {
			if (p->Rlink == NULL) {
				a = n->date - p->date;
				break;
			}
			q = p;
			p = p->Rlink;
		}
		r = n->Rlink; s = n;
		for (;;) {
			if (r->Llink == NULL) {
				b = r->date - n->date;
				break;
			}
			s = r;
			r = r->Llink;
		}
		/*if (n->Llink->Rlink == NULL || n->Rlink->Llink == NULL) {//자식이 둘이
			if (flag == 0) {
				if (a <= b) {
					m->Llink = p; p->Rlink = n->Rlink;
					free(n);
				}
				if (a > b) {
					m->Llink = r; r->Llink = n->Llink;
					free(n);
				}
				return;
			}
			if (flag == 1) {
				if (a <= b) {
					m->Rlink = p; p->Rlink = n->Rlink;
					free(n);
				}
				if (a > b) {
					m->Rlink = r; r->Llink = n->Llink;
					free(n);
				}
				return;
			}
			if (flag == 2) {
				if (a <= b) {
					H->head = p; p->Rlink = n->Rlink;
					free(n);
				}
				if (a > b) {
					H->head = r; r->Llink = n->Llink;
					free(n);
				}
				return;
			}
		}*/
		if (flag == 0) {
			if (a <= b) {
				if (n->Llink == p) {
					m->Llink = p; p->Rlink = n->Rlink;
					free(n);
				}
				else {
					q->Rlink = p->Llink;
					m->Llink = p; p->Llink = n->Llink; p->Rlink = n->Rlink;
					free(n);
				}
			}
			if (a > b) {
				if (n->Rlink == r) {
					m->Llink = r; r->Llink = n->Llink;
					free(n);
				}
				else {
					s->Llink = r->Rlink;
					m->Llink = r; r->Llink = n->Llink; r->Rlink = n->Rlink;
					free(n);
				}
			}
			return;
		}
		if (flag == 1) {
			if (a <= b) {
				if (n->Llink == p) {
					m->Rlink = p; p->Rlink = n->Rlink;
					free(n);
				}
				else {
					q->Rlink = p->Llink;
					m->Rlink = p; p->Llink = n->Llink; p->Rlink = n->Rlink;
					free(n);
				}
			}
			if (a > b) {
				if (n->Rlink == r) {
					m->Rlink = r; r->Llink = n->Llink;
					free(n);
				}
				else {
					s->Llink = r->Rlink;
					m->Rlink = r; r->Llink = n->Llink; r->Rlink = n->Rlink;
					free(n);
				}
			}
			return;
		}
		if (flag == 2) {
			if (a <= b) {
				if (n->Llink == p) {
					H->head = p; p->Rlink = n->Rlink;
					free(n);
				}
				else {
					q->Rlink = p->Llink;
					H->head = p; p->Llink = n->Llink; p->Rlink = n->Rlink;
					free(n);
				}
			}
			if (a > b) {
				if (n->Rlink == r) {
					H->head = r; r->Llink = n->Llink;
					free(n);
				}
				else {
					s->Llink = r->Rlink;
					H->head = r; r->Llink = n->Llink; r->Rlink = n->Rlink;
					free(n);
				}
			}
			return;
		}
	}//자식이 둘다 있을때
	if (n->Llink != NULL) {
		if (flag == 0) {
			m->Llink = n->Llink;
			free(n);
		}
		if (flag == 1) {
			m->Rlink = n->Llink;
			free(n);
		}
		if (flag == 2) {
			H->head = n->Llink;
			free(n);
		}
		return;
	}//왼쪽 자식만 있을 때
	if (n->Rlink != NULL) {
		if (flag == 0) {
			m->Llink = n->Rlink;
			free(n);
		}
		if (flag == 1) {
			m->Rlink = n->Rlink;
			free(n);
		}
		if (flag == 2) {
			H->head = n->Rlink;
			free(n);
		}
		return;
	}//오른쪽 자식만 있을 때
}//삭제 연산


int main() {
	in = fopen("hw4.inp", "rt");
	out = fopen("hw4.out", "wt");
	int i, input;
	char c;
	Head *H;
	H = createLinkedList();
	for (;;) {
		fscanf(in, "%d%c", &input, &c);
		insertheap(input);//힙 입력
		insertNode(H, input);//이진트리 입력
		if (c == '\n')break;
	}
	mid(1);//최대힙 중위순회 출력
	fprintf(out, "\n");
	for (;;) {
		if (heap[1] == NULL)break;
		removeheap();
	}//최대힙 출력
	//힙 종료
	fprintf(out, "\n");
	treemid(H->head);//이진트리 중위순회 출력
	fprintf(out, "\n");
	for (;;) {
		fscanf(in, "%d%c", &input, &c);
		removeNode(H, input);
		if (c == '\n')break;
	}
	treemid(H->head);//삭제 후 이진트리 중위순회 출력
	fprintf(out, "\n*");
	return 0;
}