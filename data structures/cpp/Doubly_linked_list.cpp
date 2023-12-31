#include <iostream>
using namespace std;
struct node *tail = NULL;
//creating node for doubly linked list
class node
{
public:
    int data;
    struct node *prev;
    struct node *next;
    node(int d1, node* p = nullptr, node* n = nullptr) : 
        data(d1),
        prev(p),
        next(n) {}
};
//functionto create ll
struct node *create_dll(struct node *head)
{
    int input;
    cin >> input;
    struct node *newnode = new struct node(input);
    if (head == nullptr) {
        return newnode;
    } else {
        node *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        newnode->prev = p;
        p->next = newnode;
        return head;
    }
}
//function to insert  node at head
struct node *insert_at_beg_in_dll(struct node *head)
{
    int input_data;
    cin >> input_data;

    // Creating a new node with input data using the constructor
    node *newnode = new node(input_data);

    if (head == nullptr) {
        return newnode;
    } else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return head;
}
//function to to insert element at end
struct node *insert_at_end_in_dll(struct node *head)
{
    struct node *newnode = new struct node;
    newnode->next = NULL;
    newnode->prev = NULL;
    cin >> newnode->data;
    tail = newnode;
    if (head == NULL)
    {
        return newnode;
    }
    else
    {
        struct node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
        newnode->prev = p;
        return head;
    }
}
//display in forward direction
void display_forward_dll(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
//display in reverse order
void display_backward_dll()
{
    struct node *end = tail;
    while (end != NULL)
    {
        cout << end->data << " ";
        end = end->prev;
    }
}
//main function
int main()
{
    struct node *head = NULL;
    int t = 1, n;
    int w;
    while (t)
    {
        cout << "\nSelect choice\n1)create dll\n2)insert at beg\n3)insert at end\n4)display forward\n5)display  reverse\nEnter: ";
        cin >> w;
        switch (w)
        {
        case 1:
            cout << "\nEnter number of data elemenets in the dll: ";
            cin >> n;
            while (n--)
            {
                head = create_dll(head);
            }
            break;
        case 2:
            head = insert_at_beg_in_dll(head);
            cout << "\n";
            break;
        case 3:
            head = insert_at_end_in_dll(head);
            cout << "\n";
            break;
        case 4:
            cout << "\n";
            display_forward_dll(head);
            cout << "\n";
            break;
        case 5:
            cout << "\n";
            display_backward_dll();
            cout << "\n";
            break;
        default:
            cout << "\nWrong choice!\n";
        }
        cout << "(1/0): ";
        cin >> t;
    }
    return 0;
}
