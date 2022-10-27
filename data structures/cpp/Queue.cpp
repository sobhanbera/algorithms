#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of a queue
#define SIZE 1000
 
// A class to store a queue
class Queue
{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    Queue(int size = SIZE);     // constructor
    ~Queue();                   // destructor
 
    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}
 
// Utility function to dequeue the front element
int Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    int x = arr[front];
    cout << "Removing " << x << endl;
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Utility function to return the front element of the queue
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int Queue::size() {
    return count;
}
 
// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool Queue::isFull() {
    return (size() == capacity);
}
 
int main()
{
    // create a queue of capacity 5
    Queue q(5);
 
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << "The front element is " << q.peek() << endl;
    q.dequeue();
 
    q.enqueue(4);
 
    cout << "The queue size is " << q.size() << endl;
 
    q.dequeue();
    q.dequeue();
    q.dequeue();
 
    if (q.isEmpty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }
 
    return 0;
}