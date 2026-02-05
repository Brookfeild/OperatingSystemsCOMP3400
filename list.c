#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @param head The head of the linked list
 * Returns the head of the linked list
 */
struct ll_node *ll_head(struct ll_node *head) {
    if(head != NULL) {
        return head;
    } else {
        return NULL;
    }
}

/**
 * @param head The head of the linked list
 * Returns the tail of the linked list
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ll_node *node = head;
    while(node->next != NULL) {
        node = node->next;
    }
    return node;
}

/**
 * @param head The head of the linked list
 * Returns the number of elements in the linked list
 */
int ll_size(struct ll_node *head) {
    int i = 0;
    while(head != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

/**
 * @param head The head of the linked list
 * @param value The value to find in the linked list
 * The function searches through the list, and returns the node when 
 * the number is found. If not found, return NULL.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *ptr = head;
    while(ptr!=NULL){
        if(ptr->data == value){
            return ptr;
        }
        ptr=ptr->next;
    }
    return NULL;
}

/**
 * @param head The head of the linked list
 * Returns an array containing the elements of the linked list
 */
int *ll_toarray(struct ll_node *head) {
    if(head == NULL) {
        return NULL;
    }
    struct ll_node *node = head;
    int size = ll_size(head);
    int *array = malloc(sizeof(int) * size);
    for(int i = 0; node != NULL; i++) {
        array[i] = node->data;
        node = node->next;
    }
    return array;
}

/**
 * @param data The data for the new node
 * Creates a new linked list node
 */
struct ll_node *ll_create(int data) {
    struct ll_node *s = malloc(sizeof (struct ll_node));
    s->data = data;
    s->next=NULL;
    return s;
}

/**
 * @param head The head of the linked list
 * Destroys the linked list
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *ptr = head;
    while(ptr!=NULL) {
        head=head->next;
        free(ptr);
        ptr=head;
    }
    head=NULL;
}

/**
 * @param head The head of the linked list
 * @param data The data to append to the linked list
 * Adds a node to the linked list
 */
void ll_append(struct ll_node *head, int data) {
    if(head == NULL) {
        return;
    }

    struct ll_node *ptr = head;
    struct ll_node *tail=NULL;
    tail=head;

    while(ptr!=NULL){
        if( ptr->next == NULL) {
            tail = ptr;

            struct ll_node *s = (struct ll_node*) malloc(sizeof (struct ll_node));
            s->data = data;
            s->next=NULL;

            tail->next = s;
            tail = s;

            return;

        }
        ptr=ptr->next;

    }
}

/**
 * @param data An array of integers
 * @param len The length of the array
 * Returns the head of a linked list created from the array
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if(len <= 0) {
        return NULL;
    }

    struct ll_node *head = ll_create(data[0]);
    struct ll_node *current = head;

    for(int i = 1; i < len; i++) {
        current->next = ll_create(data[i]);
        current = current->next;
    }

    return head;
}

/**
 * @param head The head of the linked list
 * @param value The value to remove from the linked list
 * Removes a node from the linked list
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    struct ll_node *ptr = head;
    struct ll_node *prev = NULL;

    if(ptr != NULL && ptr->data == value) {
        struct ll_node *newHead = ptr->next;
        free(ptr);
        return newHead;
    }

    while(ptr != NULL && ptr->data != value) {
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        return head;
    }

    prev->next = ptr->next;
    free(ptr);

    return head;
}

/**
 * @param head The head of the linked list
 * Prints the linked list
 */
void printList(struct ll_node *head){
    if( head == NULL){
        printf("LIST IS EMPTY\n");
        return;
    }
    while( head !=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}

void test_head() {
    printf("test_head: ");

    int arr[] = {1,2,3};
    struct ll_node *list = ll_fromarray(arr, 3);

    if (ll_head(list)->data == 1) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_tail() {
    printf("test_tail: ");

    int arr[] = {4,5,6};
    struct ll_node *list = ll_fromarray(arr, 3);

    struct ll_node *t = ll_tail(list);

    if (t && t->data == 6 && t->next == NULL) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_size() {
    printf("test_size: ");

    int arr[] = {10,20,30,40};
    struct ll_node *list = ll_fromarray(arr, 4);

    if (ll_size(list) == 4) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_find() {
    printf("test_find: ");

    int arr[] = {1,2,3};
    struct ll_node *list = ll_fromarray(arr, 3);

    struct ll_node *n = ll_find(list, 2);
    struct ll_node *missing = ll_find(list, 33);

    if (n != NULL && n->data == 2 && missing == NULL) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_toarray() {
    printf("test_toarray: ");

    int arr[] = {3,6,9};
    struct ll_node *list = ll_fromarray(arr, 3);

    int *out = ll_toarray(list);

    if (out && out[0] == 3 && out[1] == 6 && out[2] == 9) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    free(out);
    ll_destroy(list);
}

void test_create() {
    printf("test_create: ");

    struct ll_node *n = ll_create(42);

    if (n && n->data == 42 && n->next == NULL) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    free(n);
}

void test_destroy() {
    printf("test_destroy: ");

    int arr[] = {1,2,3};
    struct ll_node *list = ll_fromarray(arr, 3);

    ll_destroy(list);
    list = NULL;

    if (list == NULL) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

void test_append() {
    printf("test_append: ");

    struct ll_node *list = ll_create(1);
    ll_append(list, 2);
    ll_append(list, 3);

    if (ll_size(list) == 3 && ll_tail(list)->data == 3) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_fromarray() {
    printf("test_fromarray: ");

    int arr[] = {5,10,15};

    struct ll_node *list = ll_fromarray(arr, 3);

    if (list && list->data == 5 && list->next->data == 10 && ll_tail(list)->data == 15) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_remove() {
    printf("test_remove: ");

    int arr[] = {1,2,3,4};
    struct ll_node *list = ll_fromarray(arr, 4);

    list = ll_remove(list, 3);
    list = ll_remove(list, 1);
    list = ll_remove(list, 99);

    if (ll_size(list) == 2 && ll_find(list, 3) == NULL && list->data == 2) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    ll_destroy(list);
}

void test_printList() {
    printf("test_printList (visual check):\n");

    int arr[] = {7,8,9};
    struct ll_node *list = ll_fromarray(arr, 3);

    printf("Expected: 7 8 9\nActual:   ");
    printList(list);

    ll_destroy(list);
}

int main() {
    static struct ll_node* list = NULL;

    list = ll_create(9);
    ll_append(list, 8);
    ll_append(list, 12);

    struct ll_node *n = ll_find(list, 8);
    if( n != NULL)
        printf("%d\n", n->data); 
    printList(list);

    ll_destroy(list);
    list=NULL;
    n = ll_find(list, 8);
    if( n != NULL)
        printf("%d\n", n->data);
    printList(list);

    test_head();
    test_tail();
    test_size();
    test_find();
    test_toarray();
    test_create();
    test_destroy();
    test_append();
    test_fromarray();
    test_remove();
    test_printList();

    return 0;
}