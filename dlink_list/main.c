#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* element;
typedef struct DListNode {	// ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
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

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// ��� removed�� �����Ѵ�.
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
		printf("=========�޴�=========\n");
		printf("n) ���� ����\n");
		printf("p) ���� ����\n");
		printf("d) ���� ���� ����\n");
		printf("i) ���� ���� ������ ���� �߰�\n");
		printf("o) ���� ����Ʈ ���(���� ���õ� ���Ͽ��� ��������[O] ���)\n");
		printf("e) ���α׷� ����\n");
		printf("�޴��� �����ϼ���: ");
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
					printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
				printf("�߰��� ������ �Է��ϼ���: ");
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
					printf("����Ʈ�� ����ֽ��ϴ�. \n");
				}
				else {
					print_dlist(head, here);
				}
				break;
			case 'e':
				printf("���α׷��� �����մϴ�,.\n");
				exit(0);
			default:
				printf("�ٽ� �������ּ���.\n");
				while (getchar() != '\n');
			}
		}
		else {
			printf("�ٽ� �������ּ���.\n");
		
		}

	}
	system("pause");
	return 0;
}