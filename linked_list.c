#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define NULL 0*/

struct list_element {
	char item[40];
	struct list_element *next;
};

typedef struct list_element node;

int menu(void);
void create(node *pt);
node *insert(node *pt);
node *remove_it(node *pt);
void display(node *pt);

int
main() {

	node *start;
	int choice;

	do {
		choice = menu();
		switch (choice) {
			case 1:
				start = (node *) malloc(sizeof(node));
				create(start);
				printf("\n");
				display(start);
				continue;
			case 2:
				start = insert(start);
				printf("\n");
				display(start);
				continue;
			case 3:
				start = remove_it(start);
				printf("\n");
				display(start);
				continue;
			case 4:
				display(start);
				continue;
			default: /* End computation */
				printf("End of computation\n");
		}
	} while (choice != 5);
}

int menu(void) {

	int choice;

	do {
		printf("\n MAIN MENU:\n");
		printf("\t1 - CREATE linked list\n");	
		printf("\t2 - ADD a component\n");	
		printf("\t3 - DELETE a component\n");	
		printf("\t4 - DISPLAY\n");	
		printf("\t5 - END\n");	
		printf("\tEnter your choice: 1, 2, 3, 4, or 5\n");	
		scanf("%d", &choice);
		if (choice < 1 || choice > 5)
			printf("Try again, dumbass\n");
	} while (choice < 1 || choice > 5 );
	printf("\n");
	return(choice);

}

/*create a linked list */
void create(node *record) { 
	/* argument points to the current node */

	printf("Data item (type \'END\' when finished): ");
	scanf(" %[^\n]", record->item);
	if ( strcmp(record->item,"END") == 0)
		record->next = NULL;
	else {
		/* allocate space for next node */
		record->next = (node *) malloc(sizeof(node));
		/* create the next node */
		create(record->next);
	}
	return;
}

void display(node *record) {
	/*display the linked list */

	/* argument points to the current node */
	if (record->next != NULL) {
		printf("%s\n", record->item);
		display(record->next);
	}
}

node *insert(node *first) {
	/* add one component to linked list,
		return a pointer to beginning of modified list */
	
	node *locate(node*, char[]); /* function declaration */
	node *newrecord;
	node *tag;
	char newitem[40];
	char target[40];
	
	printf("New data item: \n");
	scanf(" %[^\n]", newitem);
	printf("Place before (type \'END\' if last): \n");
	scanf(" %[^\n]", target);
	
	if ( strcmp(first->item, target) == 0 ) {
		/* new node is first in list */

		/* allocate space for new node */
		newrecord = (node *) malloc(sizeof(node));
		
		/* assign the new data item to newrecord->item */
		strcpy( newrecord->item, newitem);
		
		/* assign the current pointer to newrecord->next */
		newrecord->next = first;

		/* new pointer becomes beginning of list */
		first = newrecord;
	}
	else {
		/* insert new node after existing node */
		
		/* locate the node PRECEDING the target node */
		tag = locate( first, target );

		if ( tag == NULL )
			printf("Match not found -- try again\n");
		else {
			/* allocate space for new node */
			newrecord = (node *) malloc(sizeof(node));
			
			/* assign the new data item to newrecord->item */
			strcpy( newrecord->item, newitem);
			
			/* assign the next pointer to newrecord->next */
			newrecord->next = tag->next;

			/* assign the new pointer to tag->next */
			tag->next = newrecord;
		}
	}
	return(first);
}

node *locate(node *record, char target[]) { /* locate a node */
	/* return a pointer to the node BEFORE the target node;
		the first arg points to the current node;
		the second argument is the target string */
	
	if( strcmp( record->next->item, target) == 0 ) /* found a match */
		return(record);
	else
		if (record->next->next == NULL)
			return(NULL); /* end of last */
		else
			locate(record->next, target);
}

node *remove_it(node *first) {
	/* remove one component from the linked list; return pointer 
		to beginning of modified list */
	/* argument points to first node */

	node *locate(node*, char[]); /* function declaration, AGAIN */
	node *tag;
	node *temp;
	char target[40];

	printf("Data item to be deleted:\n");
	scanf(" %[^\n]", target);

	if( strcmp(first->item, target) == 0 ) {
		/* delete first node */
		
		/* mark the node following the target node */
		temp = first->next;

		/* free space for the target node */
		free(first);

		/* adjust the pointer to the first node */
		first = temp;
	}

	else {
		/* delete a data item other than the first */
		
		/* locate the node PRECEDING the target node */
		tag = locate(first, target);

		if( tag == NULL ) 
			printf("No match found -- try again\n");
		else {
			/* mark the node following the target node */
			temp = tag->next->next;
			
			/* delete the fucker */
			free(tag->next);

			/* adjust the link to the next node */
			tag->next = temp;
		}
	}
	return(first);
}
						
		

	
