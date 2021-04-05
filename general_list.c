#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define EVEN 0
#define ODD 1

typedef struct single_node SNode;
typedef struct doubly_node DNode;

void show_ll(SNode* head) ;
char show_instruction();
SNode* insert_front_sll( SNode *head, int data );
SNode* sort_insertion_sll( SNode *head );
int warning_null_sll(SNode* s);
SNode* reverse_sll(SNode* head);
SNode* remove_front_sll( SNode* head );
int size_sll(SNode* head);
int* convert_list_to_arr(SNode* head);
void show_arr(int* arr);
SNode* delete_sll( SNode *head, int val ) ;
int search_data(SNode *head, int val);


struct single_node {
    int data;
    SNode* next;
} ;

struct doubly_node {
    int data;
    DNode* prev;
    DNode* next;
} ;

int warning_null_sll(SNode* s) {
    if( s == NULL ) {
        printf("you haven't structure yet.\n");
        return true;
    }
    return false;
}

// this return copy of pointer. 
SNode* insert_front_sll( SNode *head, int data ) {
    // create new node that been head
    if ( head == NULL )
    {
        head = (SNode*) malloc( sizeof(SNode) );
        head->data = data; head->next = NULL;
    } else {
        SNode* nn = (SNode*) malloc( sizeof(SNode) );
        nn->data = data;
        nn->next = head;
        head = nn;
    }
    return head;
}

SNode* insert_back_sll( SNode *head, int data ) {
    SNode *ptr = head;
    if (ptr == NULL)
    {    
        SNode *tmp = (SNode*) malloc(sizeof(SNode));
        tmp->data = data;
        tmp->next = NULL;
        return tmp;
    }
    
    while ( ptr->next != NULL )
    {
        ptr = ptr->next;
    }

    SNode *tmp = (SNode*) malloc(sizeof(SNode));
    tmp->data = data;
    tmp->next = NULL;
    ptr->next = tmp;

    return head;
}

void show_ll( SNode* head ) {
    
    if(warning_null_sll(head)) return;
    
    SNode *itr = head;
    printf("your linked list is : ");

    while ( itr != NULL )
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

SNode* reverse_sll(SNode* head) {

    if(warning_null_sll(head)) return NULL;

    SNode* tmp = head ;

    if (tmp->next != NULL)
    {
        head = head->next;
        tmp->next = NULL;
        
        // everything insert front tmp
        while (head != NULL)
        {
            SNode *o_head = head->next;
            head->next = tmp;
            tmp = head;
            head = o_head;
        }
        
    }

    return tmp;
}

SNode* remove_front_sll( SNode* head ) {

    if(warning_null_sll(head)) return NULL;

    SNode *temp = head->next;

    free(head);

    return temp;
}

SNode* sort_insertion_sll( SNode *head ) {

    if(warning_null_sll(head)) return NULL;

    // this hold back
    SNode* s_list = NULL;

    while ( head != NULL )
    {
        if ( s_list == NULL )
        {
            s_list = head;
            head = head->next;
            s_list->next = NULL;
        } else {
            
            SNode* s_head = s_list;

            // insert head
            if ( s_head->data > head->data )
            {
                SNode* tmp = head;
                head = head->next;                
                tmp->next = s_list;
                s_list = tmp;
            } else {
                while ( s_head->next != NULL && s_head->next->data < head->data )
                {   
                    s_head = s_head->next;
                }
                SNode *s_head_next = s_head->next;
                SNode *head_next = head->next;
                
                s_head->next = head;
                head->next = s_head_next;
                head->next = NULL;

                head = head_next;
            }
        }
    }
    return s_list;

}

int size_sll(SNode* head) {
    SNode* tmp = head;
    int count = 0;
    while ( tmp != NULL  )
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

int* convert_list_to_arr(SNode* head) {
    
    int i = 1;
    int sz = size_sll(head);
    int* arr = (int*) malloc( sizeof(int) * sz );
    arr[0] = sz;

    SNode* tmp = head;
    
    while ( tmp != NULL  )
    {
        arr[i++] = tmp->data;
        tmp = tmp->next;
    }
    
    return arr;
}
void show_arr(int* arr) {
    int i;
    for ( i = 1; i < arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

SNode* delete_sll( SNode *head, int val ) {
    
    if ( head->data == val )
    {
        SNode *tmp = head;
        head = head->next;
        free(tmp);
        return head; 
    } 
    SNode *tmp = head, *removed;
    while ( tmp->next->data != val )
    {
        tmp = tmp->next;
    }

    // erase node
    removed = tmp->next;
    tmp->next = tmp->next->next;
    free(removed);

    return head;
}

SNode *even_order( SNode *head ) {
    
    SNode *temp = head;
    while ( temp != NULL && temp->next != NULL )
    {
        if ( (temp->next->data % 2) == EVEN )
        {
            SNode *n_h = temp->next; // new head
            temp->next = temp->next->next;
            n_h->next = head;
            head = n_h; 
        }
        
        temp = temp->next;
    }
    
    return head;
}

SNode *odd_order( SNode *head ) {
    
    SNode *temp = head;
    while (  temp != NULL && temp->next != NULL )
    {
        if ( (temp->next->data % 2) == ODD )
        {
            SNode *n_h = temp->next; // new head
            temp->next = temp->next->next;
            n_h->next = head;
            head = n_h; 
        }
        
        temp = temp->next;
    }
    
    return head;
}

int search_data(SNode *head, int val) {
    while (head->data != val && head != NULL)
    {
        head=head->next;
    }
    if (head)
    {
        printf("it is founded.");
        return true;
    }
    printf("no such element.");
    return false;
}

char show_instruction() {
    char select;

    printf("what is your instruction ?\n");
    printf(
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
    );

    scanf(" %c", &select);
    return select;
}

int main() {

    int dataType;

    printf("Welcome to linked list API\n");
    printf("Select your linked list type\n");
    
    printf(
        "0: finish program\n"
        "1: single link list\n"
        "2: doubly link list\n"
        "3: circular link list\n"
        "4: neighborhood matrix\n"
        "5: single linked list via array(deprecated)\n"
    );
    
    scanf("%d", &dataType);

    if (dataType == 0 && dataType > 6)
    {
        return 0;
    }
    else if( dataType == 1 ) {
        
        SNode *head = NULL;
        
        char inst = '1' ;

        while( inst != '0' ) {
            inst = show_instruction();    
            int ele;
            if( inst == '1' ) {
                show_ll(head);
            } else if( inst == '2' ) {

                printf("what is element that you insert head: \n");
                scanf("%d", &ele);

                head = insert_front_sll(head, ele);

            } else if( inst == '3' ) {

                printf("what is element that you insert back: \n");
                scanf("%d", &ele);

                head = insert_back_sll(head, ele);
            } else if( inst == '4' ) {

                printf("your list is sorting...\n");
                head = sort_insertion_sll(head);

            } else if( inst == '5' ) {

                printf("reversing linked list ...\n");
                head = reverse_sll(head);

            } else if( inst == '6' ) {
                printf("converting array...\n");
                int* arr = convert_list_to_arr(head);
                printf("your array converted \n");
                show_arr(arr);
            } else if ( inst == '7' ) {
                printf("what is element that you delete \n");
                scanf("%d", &ele);
                head = delete_sll(head, ele);
            } else if ( inst == '8' ) {
                printf("inserting even numbers to starting position of linked list...\n");
                head = even_order(head);
            } else if ( inst == '9' ) {
                printf("inserting odd numers to starting positon of linked list ...\n");
                head = odd_order(head);
            } else if ( inst == 'A') {
                printf("what is element that you search \n");
                scanf("%d", &ele);
                search_data(head, ele);
            }
        }
        free(head);
        return 0;
    }
    else if( dataType == 2 ) {
        DNode* head = (DNode*) malloc( sizeof(DNode) );
        head->prev = NULL; head->next = NULL;
    }


    
    return 0;
}