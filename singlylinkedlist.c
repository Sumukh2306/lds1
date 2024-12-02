#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node * link;
};
typedef struct node *NODE;

NODE getnode(){
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL){
		printf("Memory full");
		exit(0);
	}
	return x;
}
NODE insertfront(NODE first,int item){
	NODE temp= getnode();
	temp->info=item;
	temp->link=NULL;
	if (first==NULL)
	{
		return temp;
	}
	temp->link=first;
	return temp;
}

NODE insertrear(NODE first,int item){
	NODE cur;
	NODE temp= getnode();
	temp->info=item;
	temp->link=NULL;

	if (first==NULL)
	{
		return temp;
	}

	cur=first;
	while(cur->link!=NULL){
		cur=cur->link;
	}
	cur->link=temp;
	return first;
}

NODE deletefront(NODE first){
	if (first==NULL){
		printf("Empty");
		return NULL;
	}
	if(first->link==NULL){
		printf("Item deleted is %d",first->info);
		free(first);
		return NULL;
	}
	NODE temp=first;
	temp=temp->link;
	printf("Item deleted is %d",first->info);
	free(first);
	return temp;
}
NODE deleterear(NODE first){
	NODE prev,cur;
	if (first==NULL){
		printf("Empty");
		return NULL;
	}
	if(first->link==NULL){
		printf("Item deleted is %d",first->info);
		free(first);
		return NULL;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL){
		prev=cur;
		cur=cur->link;
	}
	printf("Item deleted is %d\n",cur->info);
	free(cur);
	prev->link=NULL;
	return first;
}
void display(NODE first){
	if (first==NULL){
		printf("Empty");
		return;
	}
	NODE cur=first;
	while(cur!=NULL){
		printf("%d\n",cur->info);
		cur=cur->link;
	}
}
void search(NODE first, int key) {
    if (first == NULL) {
        printf("List is empty. Key not found.\n");
        return;
    }

    NODE cur = first;
    while (cur != NULL) {
        if (cur->info == key) {
            printf("Key found.\n");
            return;
        }
        cur = cur->link;
    }

    printf("Key not found.\n");
}



int main(){
	NODE first= NULL;
	int op,item,key;
	for(;;){
	printf("Menu\n 1:Insert front\n 2:Insert rare\n 3:Delete front\n 4:Delete rear\n 5:Display\n 6:Search\n 7:Exit\n");
	scanf("%d",&op);
	
	switch(op){
	case 1: printf("Enter the item to be inserted:");
			scanf("%d",&item);
			first = insertfront(first,item);
			break;
	case 2: printf("Enter the item to be inserted:");
			scanf("%d",&item);
			first=insertrear(first,item);
			break;
	case 3: first=deletefront(first);
			break;
	case 4: first=deleterear(first);
			break;
	case 5: display(first);
			break;
	case 6:
    	printf("Enter the key to be searched:\n");
    	scanf("%d", &key);
    	search(first, key);
    	break;

	default: exit(0);
	}}

}


insert from anywhere
NODE insertatpos(NODE first, int item, int pos) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (pos <= 1 || first == NULL) { // Insert at the front
        temp->link = first;
        return temp;
    }

    NODE cur = first;
    int count = 1;
    while (cur->link != NULL && count < pos - 1) {
        cur = cur->link;
        count++;
    }
    temp->link = cur->link;
    cur->link = temp;
    return first;
}



delete from anywhere

NODE deleteatpos(NODE first, int pos) {
    if (first == NULL || pos <= 1) { // Delete front
        return deletefront(first);
    }

    NODE prev = NULL, cur = first;
    int count = 1;
    while (cur != NULL && count < pos) {
        prev = cur;
        cur = cur->link;
        count++;
    }
    if (cur == NULL) {
        printf("Invalid position\n");
        return first;
    }
    printf("Item deleted is %d\n", cur->info);
    prev->link = cur->link;
    free(cur);
    return first;
}
