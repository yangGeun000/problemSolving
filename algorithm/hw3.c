#include<stdio.h>
#include<stdlib.h>

FILE *in, *out;
char tmp;

typedef struct Node {
	char date;
	struct Node* link;
}Node;

typedef struct Head {
	struct Node* head;
}Head;

typedef struct Stack {
	Node* top;
}Stack;

Head* createLinkedList() {
	Head* H = (Head*)malloc(sizeof(Head));//헤드 메모리 할당
	H->head = NULL;//헤드 초기화
	return H;
}

Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));//스택 메모리 할당
	S->top = NULL;//스택 초기화
	return S;
}

void push(Head* H, Stack* S, char date) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* p;
	newNode->date = date;
	newNode->link = NULL;//다음주소 초기화

	if (H->head == NULL) {//첫 노드가 없을때
		H->head = newNode;
		S->top = newNode;
		return;
	}
	else {//첫 노드가 있을때
		p = H->head;
		for (;; p = p->link) {
			if (p->link == NULL) break;
			//p = p->link;
		}
	}
	p->link = newNode;
	S->top = newNode;
	return;
}// 스택 push 연산

void pop(Head* H, Stack* S) {
	Node* p;
	Node* n;
	if (S->top == NULL) return;//스택에 데이터가 없을 때
	if (H->head->link == NULL) {
		tmp = S->top->date;
		if (tmp != '(') {
			fprintf(out, "%c", tmp);
		}
		free(S->top);
		H->head = NULL;
		S->top = NULL;
		return;
	}// 스택에 데이터가 하나 있을 때
	else {
		p = H->head->link;
		n = H->head;
		for (; p; p = p->link) {
			if (p->link == NULL) {
				tmp = S->top->date;
				if (tmp != '(') {
					fprintf(out, "%c", tmp);
				}
				S->top = n;
				n->link = NULL;
				free(p);
				return;
			}
			n = n->link;
		}
		return;
	}
}//스택 pop 연산

int main() {
	in = fopen("hw3.inp", "rt");
	out = fopen("hw3.out", "wt");
	int i, cnt = 0, flag = 0;
	char c, test;
	Head *H; Stack *S;
	H = createLinkedList();//헤드 초기화
	S = createStack();//스택 초기화

	for (;;) {
		if (flag == 2)break;//두번 돌면 빠져나옴
		fscanf(in, "%c", &c);
		if (c == '\n') {
			for (;;) {
				if (cnt == 0)break;
				pop(H, S);
				cnt--;
			}
			flag++;
			fprintf(out, "\n");
			continue;
		}
		if (c == '(') {
			push(H, S, c);
			continue;
		}
		if (c == ')') {
			for (;;) {
				pop(H, S);
				if (tmp == '(')break;
			}
			continue;
		}
		if (c == '+' || c == '-') {
			for (;;) {
				if (cnt == 0)break;
				if (S->top == NULL)break;
				if (S->top->date == '(')break;
				pop(H, S);
				cnt--;
			}
			push(H, S, c);
			cnt++;
			continue;
		}
		if (c == '*' || c == '/') {
			if (S->top == NULL) {
				push(H, S, c);
				cnt++;
				continue;
			}
			if (S->top->date == '*'||S->top->date=='/') {
				pop(H, S);
				cnt--;
				push(H, S, c);
			}
			else {
				push(H, S, c);
			}
			cnt++;
			continue;
			
		}
		fprintf(out, "%c", c);
	}
	fprintf(out, "*");
	return 0;
}