#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

/*

        "0: finish program. \n"
        "1: show linked list. \n"
        "2: insert head of linkedlist\n"
        "3: insert back of linkedlist\n"
        "4: sort linked list\n"
        "5: reverse linked list\n"
        "6: convert linked list to array(deprecated)\n"
        "7: delete data from linked list\n"
        "8: parse even and odd numbers (even number first order)\n"
        "9: parse even and odd numbers (odd number first order)\n"
        "A: search data in linked list\n"
*/
typedef struct Node Node;
typedef struct DList D_List;

D_List* create_dl();
void insert_front_dl( D_List* list, int val );
void insert_back_dl( D_List* list, int val );
void show_dl( D_List* list );

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct DList {
    int sz;
    Node* head;
    Node* tail;
};

D_List* create_dl() {
    D_List* list = (D_List*) malloc( sizeof(D_List) );
    list->sz = 0;
    list->head = NULL; list->tail = NULL;
    return list;
}

void insert_front_dl( D_List* list, int val ) {
    if (list->sz == 0)
    {
        list->head = list->tail = (Node*) malloc (sizeof(Node));
        list->tail->value = list->head->value = val;
        list->head->next = NULL; list->head->prev = NULL;
    } else {
        list->head->prev = (Node*) malloc (sizeof(Node));
        list->head->prev->prev = NULL; list->head->prev->next = list->head;
        list->head = list->head->prev; list->head->value = val;
    }
    list->sz++;
}

void show_dl( D_List* list ) {

    Node* head = list->head;

    if ( list->sz == 0 )
    {
        printf("no element in list.\n");
        return;
    }

    while ( head != NULL )
    {
        printf("%d ", head->value);
        head = head->next;
    }

}

void insert_back_dl( D_List* list, int val ) {
    Node* tail = list->tail; 
    tail->next = (Node*) malloc (sizeof(Node));
    tail->next->prev = tail; tail->next->value = val;
    list->tail = tail->next; list->tail->next = NULL;
}

void delete_ele_dl(D_List* list, int val) {
    if( list->sz == 0 ) {
        printf("there is no element.\n");
        return;
    } else if ( list->head->value == val ) {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    } else if ( list->tail->value == val ) {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next=NULL;
    } else {
        Node* hd = list->head;
        while ( hd != NULL && hd->value != val )
        {
            hd = hd->next;
        }
        if ( hd == NULL )
        {
            printf("there is no such element.\n");
            return;
        } else {
            hd->prev->next = hd->next;
            hd->next->prev = hd->prev;
            free(hd);
        }
        
    }
    list->sz--;
}


int main() {

    D_List* list = create_dl();
    while (true)
    {
        int sel, ele;
        printf(" selection : 0 show, 1 insertf , 2 insertb, 3 delete :  \n");
        scanf("%d", &sel);
        if ( sel == 0 )
        {
            show_dl(list);
        } else if ( sel == 1 ) {
            scanf("%d", &ele);
            insert_front_dl(list, ele);
        } else if ( sel == 2 ) {
            scanf("%d", &ele);
            insert_back_dl(list, ele);
        } else if ( sel == 3 ) {
            printf("element index that you remove : \n");
            scanf("%d", &ele);
            delete_ele_dl(list, ele);
        }
        
    }
    

    int ele = 5;
    insert_front_dl(list, ele);
    insert_back_dl(list, ele);


    return 0;
}