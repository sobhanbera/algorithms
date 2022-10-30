#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

typedef struct list {
    node *tree;
    struct list *next;
} list;

node *createNode(char character, int frequency)
{
    node *newNode = malloc(sizeof(node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

list *createList(node *tree)
{
    list *newList = malloc(sizeof(list));
    newList->tree = tree;
    newList->next = NULL;
    return newList;
}

void insertList(list **head, node *tree)
{
    list *newList = createList(tree);
    if (*head == NULL) {
        *head = newList;
    } else {
        list *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newList;
    }
}

void insertSortedList(list **head, node *tree)
{
    list *newList = createList(tree);
    if (*head == NULL) {
        *head = newList;
    } else {
        list *current = *head;
        if (current->tree->frequency > newList->tree->frequency) {
            newList->next = current;
            *head = newList;
        } else {
            while (current->next != NULL && current->next->tree->frequency < newList->tree->frequency) {
                current = current->next;
            }
            newList->next = current->next;
            current->next = newList;
        }
    }
}

void printList(list *head)
{
    list *current = head;
    while (current != NULL) {
        printf("%c %d ", current->tree->character, current->tree->frequency);
        current = current->next;
    }
    printf("\n");
}

void printTree(node *tree)
{
    if (tree != NULL) {
        printf("%c %d ", tree->character, tree->frequency);
        printTree(tree->left);
        printTree(tree->right);
    }
}

void printCodes(node *tree, int *arr, int top)
{
    if (tree->left) {
        arr[top] = 0;
        printCodes(tree->left, arr, top + 1);
    }
    if (tree->right) {
        arr[top] = 1;
        printCodes(tree->right, arr, top + 1);
    }
    if (tree->left == NULL && tree->right == NULL) {
        printf("%c: ", tree->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffmanCoding(char *str)
{
    int n = strlen(str);
    int *arr = malloc(sizeof(int) * n);
    int i = 0;
    int j = 0;
    int k = 0;
    int top = 0;
    int frequency[256] = {0};
    list *head = NULL;
    node *left = NULL;
    node *right = NULL;
    node *topNode = NULL;
    for (i = 0; i < n; i++) {
        frequency[str[i]]++;
    }
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            insertSortedList(&head, createNode(i, frequency[i]));
        }
    }
    while (head->next != NULL) {
        left = head->tree;
        right = head->next->tree;
        topNode = createNode('$', left->frequency + right->frequency);
        topNode->left = left;
        topNode->right = right;
        head = head->next->next;
        insertSortedList(&head, topNode);
    }
    printCodes(head->tree, arr, top);
}

int main()
{
    char str[] = "Hi I am Max from GitHub and this is an example for huffman encoding";
    huffmanCoding(str);
    return 0;
}
