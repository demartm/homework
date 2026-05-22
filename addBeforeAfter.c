#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x;
	int y;

	struct point* next;
};

//struct point* addToHead(struct point** head,int x,int y) {
//	if (head) {
//		struct point* el = (struct point*)calloc(sizeof(struct point), 1);
//		if (el) {
//			el->x = x;
//			el->y = y;
//
//			el->next = *head;
//			*head = el;
//			return el;
//		}
//		
//	}
//	return NULL;
//
//}

struct point* addAfter(struct point *list,int x,int y, int x_add,int y_add) {
	if (list) {
		struct point* el = (struct point*)malloc(sizeof(struct point));

		if (el) {
			struct point* ptr = NULL;
			for (ptr = list; ptr && !(ptr->x == x && ptr->y == y); ptr = ptr->next);

			if (ptr) {
				el->x = x_add;
				el->y = y_add;
				el->next = ptr->next;
				ptr->next = el;

				return el;
			}
			free(el);

		}

	}
	return NULL;
}

struct point* addBefore(struct point** list, int x, int y, int x_add, int y_add) {
	if (list && *list) {
		struct point* el = (struct point*)malloc(sizeof(struct point));

		if (el) {
			if ((*list)->x == x && (*list)->y == y) {
				el->x = x_add;
				el->y = y_add;
				el->next = *list;
				(*list) = el;
			}
			else {
				struct point* ptr = NULL;
				for (ptr = *list; ptr->next && !(ptr->next->x == x && ptr->next->y == y); ptr = ptr->next);
				if (ptr->next) {

					el->x = x_add;
					el->y = y_add;
					el->next = ptr->next;
					ptr->next = el;

					

				}
				else {
					free(el);
					return NULL;
				}
			}
			return el;
			
		}
	}

	return NULL;
}


int main() {
	struct point* list = NULL;

	struct point* el1 = (struct point*)malloc(sizeof(struct point));
	struct point* el2 = (struct point*)malloc(sizeof(struct point));
	struct point* el3 = (struct point*)malloc(sizeof(struct point));
	struct point* el4 = (struct point*)malloc(sizeof(struct point));

	if (el1 && el2 && el3 && el4) {

		el1->x = 1;
		el1->y = 1;
		el1->next = el2;

		el2->x = 2;
		el2->y = 2;
		el2->next = el3;

		el3->x = 3;
		el3->y = 3;
		el3->next = el4;

		el4->x = 4;
		el4->y = 4;
		el4->next = NULL;

		list = el1;



		struct point* new_el = addAfter(list, 1, 1, 11, 11);
		if (!new_el) {
			printf("error adding");
		}

		new_el = addAfter(list, 4, 4, 11, 11);

		if (!new_el) {
			printf("error adding");
		}

		new_el = addBefore(&list, 3, 3, 44, 44);

		if (!new_el) {
			printf("error adding");
		}

		new_el = addBefore(&list, 1, 1, 22, 22);

		//printf("%d %d\n\n", new_el->x, new_el->y);

		if (!new_el) {
			printf("error adding");
		}

		for (struct point* ptr = list; ptr; ptr = ptr->next) {
			printf("%d %d\n", ptr->x, ptr->y);
		}


		//new_el = addBefore(&list, -1, -1, 0, 0);

		//if (!new_el) {
		//	printf("error adding");
		//}

		struct point* ptr = NULL;
		while (list) {
			ptr = list->next;
			free(list);
			list = ptr;
		}

	}
	else {
		printf("error initializing");
	}
	return 0;
}