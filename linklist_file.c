#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Create the structure */
typedef struct node {
	int id;
	char stuId[20];
	char firstName[20];
	char secondName[20];
	char name[20];
	struct node *next;
} Node;

/* Create link list */
Node* createList();
/* The third function implement search second name */
int searchWord(Node*, char[]);
/* Empty the link list */
void deleteList(Node*);
/* print the information of one student */
void pInfo(Node *p);
/* Show all the student information */
void showList(Node *head);
void insert(Node *pHead);
Node *deleteStu(Node *pHead);


int main(void) {
	int opt;
	char str[20];
	Node *pHead;
	pHead = createList();
	while(1)
	{
		printf("1. search id\n");
		printf("2. search stuid\n");
		printf("3. search secondName\n");
		printf("4. show\n");
		printf("5. insert a student\n");
		printf("6. delete first student\n");
		printf("Choose the option:");
		scanf("%d", &opt);
		getchar();
		switch(opt)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			searchWord(pHead, str);
			break;
		case 4:
			showList(pHead);
			break;
		case 5:
			insert(pHead);
			break;
		case 6:
			pHead = deleteStu(pHead);
			break;
		}
		system("pause");
		system("cls");
	}
	deleteList(pHead);
	return 0;
}

Node* createList(){
	char oneline[100],temp[100];
	Node *pNode1, *pNode2, *head = NULL;
	int i=0;
	int j, num=0;
	int flag;
	FILE * f;
	setbuf(stdout, NULL);
	f=fopen("./stuInfo.txt", "r");
	if(f==NULL){
		printf("Open file error!\n");
		return -1;
	}


	while (fscanf(f,"%[^\n]",oneline)!=EOF){
		fgetc(f);
		num=0;
		flag=0;
		
		pNode2 =(Node*)malloc(sizeof(Node));
		pNode2->id = ++i;
		for(j=3;j<13;j++)
			temp[num++]=oneline[j];
		temp[num]='\0';
		strcpy(pNode2->stuId,temp);
		num=0;
		for(j=14;oneline[j];j++)
		{
			temp[num++]=oneline[j];
			if(flag&&!(oneline[j]>='a'&&oneline[j]<='z'||oneline[j]>='A'&&oneline[j]<='Z'))
			{
				num--;
				temp[num]='\0';
				strcpy(pNode2->firstName, temp);
				break;
			}
			if(!(oneline[j]>='a'&&oneline[j]<='z'||oneline[j]>='A'&&oneline[j]<='Z'))
			{
				temp[num]='\0';
				strcpy(pNode2->secondName, temp);
				flag=1;
				num=0;
			}

		}

		if (head == NULL)
			head = pNode2;
		else
			pNode1->next = pNode2;
		pNode1 = pNode2;
	}

	pNode1 -> next = NULL;

	fclose(f);
	return head;
}

int mycmp(char *a,char *b)
{
	int i;
	for(i=0;b[i];i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

int searchWord(Node* head, char str[]){
	Node *p=head;
	int i=0;
	printf("Enter second name: ");
	scanf("%s", str);
	while(p!=NULL)
	{
		i++;
		//printf("%s%s\n",p->secondName, str);
		if(mycmp(p->secondName, str))
			pInfo(p);
		p=p->next;
	}

	return 0;

}

void pInfo(Node *p)
{
	printf("ID:%d\tstuID:%s\tFN:%s\tSN:%s\n", p->id,p->stuId,p->firstName,p->secondName);
	return ;
}

void showList(Node *head){
	Node *pNode1, *pNode2;
	pNode1 = head;
	while (pNode1 != NULL){
		pNode2 = pNode1 -> next;
		pInfo(pNode1);
		pNode1 = pNode2;
	}
	return;
}

void deleteList(Node *head){
	Node *pNode1, *pNode2;
	pNode1 = head;
	while (pNode1 != NULL){
		pNode2 = pNode1 -> next;
		free(pNode1);
		pNode1 = pNode2;
	}
	return;
}

void insert(Node *pHead)
{
	Node *p;
	Node *pNode;
	pNode = pHead;
	while (pNode->next != NULL){
		pNode = pNode->next;
	}
	p = (Node*)malloc(sizeof(Node));
	printf("Enter ID:");
	scanf("%d", &(p->id));
	printf("Enter STUID:");
	scanf("%s", p->stuId);
	printf("Enter first name:");
	scanf("%s", p->firstName);
	printf("Enter second name:");
	scanf("%s", p->secondName);
	
	p->next = NULL;
	pNode->next = p;
	printf("Successful!");
}

Node *deleteStu(Node *pHead)
{
	Node *p;
	p = pHead->next;
	free(pHead);
	printf("Successful!");
	return p;
}