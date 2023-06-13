#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead, DListNode* here)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == here) {
			printf("%s [O]\n", p->data);
		}
		else {
			printf("%s\n", p->data);
		}
	}
	printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	DListNode* here = head;
	DListNode* next = (DListNode*)malloc(sizeof(DListNode));
	init(next);

	

	while (1) {
		printf("=========메뉴=========\n");
		printf("n) 다음 과일\n");
		printf("p) 이전 과일\n");
		printf("d) 현재 과일 삭제\n");
		printf("i) 현재 과일 다음에 과일 추가\n");
		printf("o) 과일 리스트 출력(현재 선택된 과일에는 마지막에[O] 출력)\n");
		printf("e) 프로그램 종료\n");
		printf("메뉴를 선택하세요: ");
		char s[100];
		char input[100];
		scanf_s("%s", input, sizeof(input));
		if (strlen(input) == 1) {
			char c = input[0];
			switch (c) {
			case 'n':
				if (here->rlink == head) {
					here = head->rlink;
				}
				else {
					here = here->rlink;
				}
				break;
			case 'p':
				if (here->llink == head) {
					here = head->llink;
				}
				else {
					here = here->llink;
				}
				break;
			case 'd':
				if (head->rlink == head) {
					printf("리스트가 비어있습니다.\n");
				}
				else {
					if (here->rlink == head) {
						next = head->rlink;
					}
					else {
						next = here->rlink;
					}
					ddelete(here->llink, here);
					here = next;
				}
				break;
			case 'i':
				printf("추가할 과일을 입력하세요: ");
				scanf_s("%s", s, sizeof(s));
				if (head->rlink == head) {
					dinsert(here, _strdup(s));
					here = here->rlink;
				}
				else
				{
					dinsert(here, _strdup(s));
				}
				break;
			case 'o':
				if (head->llink == head) {
					printf("리스트가 비어있습니다. \n");
				}
				else {
					print_dlist(head, here);
				}
				break;
			case 'e':
				printf("프로그램을 종료합니다,.\n");
				exit(0);
			default:
				printf("다시 선택해주세요.\n");
				while (getchar() != '\n');
			}
		}
		else {
			printf("다시 선택해주세요.\n");
		
		}

	}
	system("pause");
	return 0;
}