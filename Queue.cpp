#include "Queue.h"
#include <stdexcept>
#include <iostream>

// Constructor
Queue::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;
}

// Destructor
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Inserts a new element at the rear of the queue.
void Queue::enqueue(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        frontNode = newNode;
        rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

// Removes the front element of the queue and returns it.
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    Node* temp = frontNode;
    int data = frontNode->data;
    frontNode = frontNode->next;
    delete temp;
    count--;
    return data;
}

// Returns the front element present in the queue without removing it.
int Queue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return frontNode->data;
}

// Checks if the queue is empty
bool Queue::isEmpty() const {
    return count == 0;
}

// Returns the total number of elements present in the queue.
int Queue::size() const {
    return count;
}

int main() {
    Queue myQueue;

    // Check if the queue is empty before enqueueing
    if (myQueue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(45);
    myQueue.enqueue(100);

    // Check if the queue is empty after enqueueing
    if (myQueue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Get the front element without removing it
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Dequeue elements
    int element1 = myQueue.dequeue();
    int element2 = myQueue.dequeue();

    // Get the front element after dequeuing
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Print dequeued elements
    std::cout << "Dequeued elements: " << element1 << " and " << element2 << std::endl;

    // Get the total number of elements in the queue
    std::cout << "Number of elements in the queue: " << myQueue.size() << std::endl;

    return 0;
}
