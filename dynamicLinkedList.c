#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	char  id;
	char* data;
	unsigned int dataLen;
	
	struct node* next;
	struct node* prev;	
}node_t;

node_t* head;
node_t* tail;

void insert_node(node_t* nodeElement);
void remove_node(void);

void processNode(node_t* nodeElement);
void displayLink(void);


int main(int argc, char *argv[]) {
	
	node_t* newNode = NULL;
	
	head = NULL;
	tail = NULL;
	
	while(1){
		system("cls");
		printf("\n Link: ");
		displayLink();
		printf("\n");
		printf("Enter 1 to insert a new node, 0 to remove a node:");
		char choice;
		scanf(" %c",&choice);
		switch(choice){
			case '1':
				newNode = (node_t*)(malloc(sizeof(node_t)));
				printf("Enter node Id: ");
				scanf(" %c",&newNode->id);
				insert_node(newNode);
				break;
			case '0':
				remove_node();
				break;
		}
	}
	return 0;
}

void insert_node(node_t* nodeElement){
	// check if link/buffer empty
	if(head==NULL && tail==NULL){
		head = nodeElement;
		tail = nodeElement;
		nodeElement->next = NULL; //not nodeElement.next!! (Wrong!)
		nodeElement->prev = NULL;
		return;
	}
	// link is node empty (sorting algo start)
	node_t* currentNode = head;
	while(currentNode!=NULL){
		if(nodeElement->id >= currentNode->id){
			if(currentNode==tail){
				//insert now, new node become the new tail
				currentNode->next = nodeElement;
				nodeElement->prev = currentNode;
				nodeElement->next = NULL;
				tail = nodeElement;
				return;
			}
			if(nodeElement->id < currentNode->next->id){
				nodeElement->next = currentNode->next;
				nodeElement->prev = currentNode;
				currentNode->next = nodeElement;
				nodeElement->next->prev = nodeElement;
				return;
			}
		}
		
		if(nodeElement->id < currentNode->id){
			if(currentNode==head){
				nodeElement->next = currentNode;
				nodeElement->prev = NULL;
				currentNode->prev = nodeElement;
				head = nodeElement;
				return;
			}
			nodeElement->next = currentNode->next;
			nodeElement->prev = currentNode;
			currentNode->next = nodeElement;
			nodeElement->next->prev = nodeElement;
			return;
		}
		currentNode = currentNode->next;
		continue;
	}
}

void remove_node(void){
	if(head==NULL && tail==NULL){
		return;
	}
	node_t* elementToBeRemoved = head;
	head = head->next;
	if(head==NULL)
		tail=NULL;
	elementToBeRemoved->next = NULL;
	processNode(elementToBeRemoved);
}

void processNode(node_t* nodeElement){
	// process the node
	free(nodeElement);
}

void displayLink(void){
	node_t* tmp = head;
	if(tmp==NULL){
		printf("NULL\n");
		return;
	}
	while(tmp!=NULL){
		printf("%c -> ",tmp->id);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
