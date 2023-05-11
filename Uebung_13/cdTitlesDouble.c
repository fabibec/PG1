#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node{
    struct node *next;
    struct node *before;
    char *string;
} node;


void fillList(node **list_start);
void trimString(char *str);
void insertString(char *tmp_str, node **list_start);
void printList(node *list_start);
void navigateList(node *list_start);
void freeList(node **list_start);

int main (void)
{
    node *head = NULL;
    fillList(&head);
    navigateList(head);
    printList(head);
    freeList(&head);
    return 0;
}

void fillList(node **list_start) {
    char *temp = NULL;
    unsigned int buf_size;

    while (1) {
        getline(&temp,&buf_size,stdin);

        //Clears of \n and spaces from string and returns new length
        trimString(temp);

        // Read String until the user types "end"
        if(strcmp(temp,"end") == 0) break;

        //insert duplicates the String so pointer can be reused
        if(strcmp(temp,"") != 0) {
            insertString(temp, list_start);
        }
    }

    // Free memory allocated by getline
    free(temp);
}

void trimString(char *str) {
    // Find new starting index
    int start = 0;
    while(str[start] == ' ' || str[start] == '\n' || str[start] == '\t') {
        start++;
    }

    // Find new end
    int end = strlen(str) - 1;
    while(str[end] == ' ' || str[end] == '\n' || str[end] == '\t') {
        end--;
    }

    // Trim the front
    int index = 0;
    if(start != 0) {
        while (start <= end) {
            str[index] = str[start];
            start++;
            index++;
        }
    }

    // Set new ending
    str[end - start + 1] = '\0';
}

void insertString(char *tmp_str, node **list_start) {
    // Duplicate String and create new node
    node *new_node = malloc(sizeof(node));
    new_node->before = NULL;
    new_node->next = NULL;
    new_node->string = strdup(tmp_str);

    // Insert at the front
    if (*list_start != NULL) {
        (*list_start)->before = new_node;
    }
    new_node->next = *list_start;
    *list_start = new_node;
}

void printList(node *list_start) {
    if (list_start != NULL) {
        int index = 0;
        node *cursor = list_start;
        while(cursor != NULL) {
            index++;
            printf("At index %d: %s\n", index, cursor->string);
            cursor = cursor->next;
        }
        printf("-----\nThis list contains %d elements\n", index);
    }
}

void navigateList(node *list_start) {
    printf("You are now able to navigate through the list, use f to move forward,\n"
           "b to go backwards and e to exit the navigation menu\n"
           "----------------------------\n");
    char c;
    node *current = list_start;

    // Exit if empty
    if (current == NULL) {
        printf("The provided list is empty.");
    } else {
        do {
            c = getc(stdin);
            fflush(stdin);
            switch (c) {
                case 'f':
                    if (current->next == NULL) {
                        printf("You can't move forward. Try again.\n");
                    } else {
                        printf("Track: %s\n", current->next->string);
                        current = current->next;
                    }
                    break;
                case 'b':
                    if (current->before == NULL) {
                        printf("You can't move backwards. Try again.\n");
                    } else {
                        printf("Track: %s\n", current->before->string);
                        current = current->before;
                    }
                    break;
                case 'e': break;
                default:
                    printf("You used an undefined char. Please try again.");
            }
        } while (c != 'e');
    }
}

void freeList(node **list_start) {
    if(list_start != NULL) {
        node *del = *list_start;
        while (*list_start != NULL) {
            del = *list_start;
            *list_start = (*list_start)->next;

            // Free string in node
            free(&(del->next));

            // Free node itself
            free(del);
        }
    }

}
