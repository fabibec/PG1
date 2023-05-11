#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Enums */
typedef enum {
    e_book,
    book,
} booktype;
/* Structs  & Unions*/

struct Stadt {
    char* name;
    unsigned int einwohner;
    char typ;
};
struct book {
    int price;
};

struct e_book {
    int price;
};

union item{
    struct book b;
    struct e_book eb;
};

typedef struct list2types{
    struct list2types *next;
    union item i;
    int typeb;
}list2types;

/* Linked list*/
list2types *initNode(int type, int bprice) {
    list2types *new_node = malloc(sizeof(list2types));
    new_node->next = NULL;
    new_node->typeb = type;
    if (type) {
        new_node->i.b.price = bprice;
    } else {
        new_node->i.eb.price = bprice;
    }
    return new_node;
}

void insertFront(list2types **head, int type, int bprice) {
    list2types *new_node = initNode(type, bprice);
    new_node->next = *head;
    *head = new_node;
}

void insertBack(list2types **head, int type, int bprice) {
    list2types *new_node = initNode(type, bprice);
    if (*head == NULL) {
        *head = new_node;
    } else {
        list2types *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

}

void insertAfter(list2types **head, int type, int bprice, int index)
{
    list2types *new_node = initNode(type, bprice);
    list2types *current = *head;
    while(current != NULL  && current->i.b.price != index && current->i.eb.price != index) {
        current = current->next;
    }
    if (current != NULL) {
        new_node->next = current->next;
        current->next = new_node;
    } else {
        insertBack(head, type, bprice);
    }
}

void printList(list2types *head) {
    while(head != NULL) {
        if(head->typeb) {
            printf("This is a paperback book. Price: %d Euro\n",head->i.b.price);
        } else {
            printf("This is an e-book. Price: %d Euro\n",head->i.eb.price);
        }
        head = head->next;
    }
}
/*
void sortList(list2types **head) {
    // Using the bubble sort message
    list2types *i = head;
    list2types  *j =
}
*/
/* Recursion*/

void btof(int arr[], int size) {
    if (size == 1) {
        printf("%d\n", *arr);
    } else {
        btof(arr + 1, size - 1);
        printf("%d\n", *arr);
    }
}

void printReversedNum(int num) {
    if(num == 0){
        NULL;
    } else {
        printReversedNum(num / 10);
        printf("%d\n", num %10);
    }
}

int maxevenel(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        int nextElement = maxevenel(arr + 1, size - 1);
        return (arr[0] > nextElement && arr[0] % 2 == 0) ? arr[0] : nextElement;
    }
}

void spiegeln(int len, double *arr) {
    for (int i = 0; i < len / 2; ++i) {
        if (arr[i] != arr[len-i-1]) {
            double temp = arr[i];
            arr[i] = *(arr + len - i - 1);
            *(arr + len - i - 1) = temp;
        }
    }
}

struct Stadt neueStadt(char *name, int einwohner) {
    struct Stadt neueStadt;
    neueStadt.einwohner = einwohner;
    neueStadt.name = name;
    neueStadt.typ = (einwohner > 5000) ? (einwohner < 100000) ? 'M' : 'G' : 'D';
    return neueStadt;
}

void printCross(int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if(i == j || i+j == length - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int ownStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int main (void) {
    int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr1[4] = {1,2,3, 4};

    int test[][3] = {{1,2,3},{4,5,6}};
    printf("%d\n", **test);
    printf("%d\n", *test[0]);
    printf("%d\n", **test + 1);
    printf("%p\n", test[1]);
    int size = sizeof(test);
    //btof(arr,12);
    //int num = 102453;
    //printReversedNum(num);
    //printf("%d", maxevenel(arr,7));
    /* New linked list with items of different type
    list2types *head = NULL;
    insertAfter(&head,e_book,25,10);
    insertFront(&head,1,10);
    insertFront(&head,0,20);
    insertBack(&head,0,30);
    insertAfter(&head,1,40,100);
    insertAfter(&head, e_book, 50, 20);
    printList(head);*/
    printCross(5);
    printCross(6);
    printf("%d", ownStrLen("Hello"));
}
