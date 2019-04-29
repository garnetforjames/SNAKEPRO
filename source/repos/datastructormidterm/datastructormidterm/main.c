#include<stdio.h>
#include<stdlib.h>


typedef struct node {

	struct node * next;
	struct node * before;
	char data;


}Node;



Node *header;
Node* tailer;

Node* getNode() {
	Node*temp;
	temp = (Node*)malloc(sizeof(Node));
	return temp;
}

void initList() {
	header = getNode();
	tailer = getNode();
	header->next = tailer;
	tailer->before = header;
	return;
}
void traverseList() {
	Node* p = header->next;

	while (p != NULL) {
		printf("%c", p->data);
		p = p->next;

	}
	printf("\n");
	return;
}

Node*get_entry(int n) {
	int i;
	Node*temp = header;
	for (i = 0; i < n; i++) {
		temp = temp->next;
		if (temp == tailer) {
			printf("invalid position\n");
			temp = NULL;
			return temp;
		}
	}
	return temp;
}

Node* insertAfter(int position, char info) {

	Node*q = getNode();
	Node *p = get_entry(position);
	if (p == NULL) {
	return p;
	}
	q->data = info;
	q->before=p;
	q->next = p->next;
	p->next->before = q;
	p->next = q;
	return q;

}

char Remove(int position) {
	char c;
	Node* p = get_entry(position);
	if (p == NULL)
		return '\0';
	c = p->data;
	p->before->next = p->next;
	p->next->before = p->before;
	free(p);
	return c;
}

int main() {



	char input;
	int num, i;
	int position;
	Node*temp;
	initList();
	scanf("%d", &num);

	for (i = 0; i < num; i++) 
	{
		
		scanf(" %c", &input);
		
		if (input == 'A') 
		{
			scanf("%d %c", &position, &input);
			insertAfter(position - 1, input);
		}
		else if (input == 'D') 
		{
			scanf("%d", &position);
			Remove(position);
		}
		else if (input == 'G') 
		{
			scanf("%d", &position);
			temp = get_entry(position);
			if (temp != NULL)
				printf("%c\n", temp->data);
		}
		else if (input == 'P') 
		{
			
			traverseList();

		}
		else
		{
			
			break; 
		}

	}
	return 0;
}