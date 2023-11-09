#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Inserts a new element at the rear of the queue.
    void enqueue(int data);

    // Removes the front element of the queue and returns it.
    int dequeue();

    // Returns the front element present in the queue without removing it.
    int front() const;

    // Checks if the queue is empty
    bool isEmpty() const;

    // Returns the total number of elements present in the queue.
    int size() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;
};

#endif
