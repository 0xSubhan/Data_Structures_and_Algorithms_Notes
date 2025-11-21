# Introduction to Queues

Queues are a fundamental data structure for storing and organizing data in computers, characterized by a "First-In, First-Out" (FIFO) principle. This means the first element added to the queue is the first one to be removed. This contrasts with stacks, which follow a "Last-In, First-Out" (LIFO) principle.

Unlike stacks, where both insertion and removal occur from the same end (the "top"), queues require insertion at one end (the "rear" or "tail") and removal from the other end (the "front" or "head").

## Queue as an Abstract Data Type (ADT)

When defining a queue as an Abstract Data Type (ADT), we focus solely on its features and available operations, without delving into implementation specifics. The logical view of a queue, as an ADT, defines the following:

- **Insertion (Enqueue):** Elements are added to the rear/tail of the queue.
    
- **Deletion (Dequeue):** Elements are removed from the front/head of the queue.
    

## Core Operations of a Queue ADT

- **Enqueue (or Push):** Inserts an element at the rear or tail end of the queue. For a queue of integers, this operation might have a `void` return type.
    
- **Dequeue (or Pop):** Removes an element from the front or head of the queue. Typically, this operation also returns the removed element. For a queue of integers, it would return an `integer`.
    
- **Front (or Peek):** Returns the element at the front of the queue without removing it. This operation should not modify the queue.
    
- **IsEmpty:** Checks if the queue is empty. Returns `true` if the queue contains no elements, `false` otherwise.
    
- **IsFull (optional):** If the queue has a limited size, this operation checks if the queue is full. Returns `true` if the queue is at its maximum capacity, `false` otherwise.
    

All these operations should ideally have a time complexity of O(1) (constant time), meaning the time taken for these operations does not depend on the number of elements in the queue.

## Logical Representation

Logically, a queue can be visualized as a container open from both sides. Elements are inserted from one side (rear) and removed from the other (front). This is different from a stack, which is open from only one side.

### Example Simulation of Queue Operations:

1. **Initial State:** An empty queue.
    
2. **Enqueue(2):** The queue now contains [2]. Both front and rear point to 2.
    
3. **Enqueue(5):** The queue now contains [2, 5]. 5 is inserted at the rear.
    
4. **Enqueue(7):** The queue now contains [2, 5, 7]. 7 is inserted at the rear.
    
5. **Dequeue():** 2 is removed from the front. The queue now contains [5, 7].
    
6. **Front():** Returns 5 (the current front element) without removing it.
    
7. **IsEmpty():** Returns `false`.
    

## Use Cases of Queues

Queues are commonly used in scenarios involving shared resources that can only handle one request at a time. Requests are queued up, and the first request received is the first one served.

- **Printer Queues:** Print jobs are added to a queue, and the printer processes them one by one in the order they were received.
    
- **CPU Scheduling:** Processes requiring CPU time are placed in a queue, and the CPU handles them sequentially.
    
- **Traffic Simulation:** Queues can simulate waiting lines in various real-world scenarios.
    

## Queue Implementations

There are two popular ways to implement a queue:

### 1. Array-Based Implementation

An array can be used to store queue elements. A segment of the array, defined by `front` and `rear` indices, represents the queue. Elements are added by incrementing `rear` and removed by incrementing `front`.

**Challenges with a simple array implementation:**

- **Wasted Space:** When elements are dequeued, the space at the beginning of the array becomes unused and cannot be easily reclaimed for new insertions, leading to inefficient memory usage if not handled.
    

**Pseudocode for Array-Based Queue:**

- **Initialization:** `front = -1`, `rear = -1` (for an empty queue).
    
- `IsEmpty()`**:** Returns `true` if `front == -1` and `rear == -1`.
    
- `Enqueue(X)`**:**
    
    - Check if queue is full. (For a simple array, this might mean `rear == MAX_INDEX`).
        
    - If empty, set `front = 0`, `rear = 0`.
        
    - Else, increment `rear`.
        
    - Store `X` at `A[rear]`. ...
        
- `Dequeue()`**:**
    
    - Check if queue is empty.
        
    - If `front == rear` (single element), set `front = -1`, `rear = -1` to mark as empty.
        
    - Else, increment `front`.
        
- `Front()`**:** Returns `A[front]` (after checking if empty).
    

### 2. Circular Array Implementation

To overcome the wasted space issue in a simple array, a circular array concept can be used. In a circular array, after reaching the last index, the next position wraps around to the beginning of the array (index 0). This is achieved using the modulo operator.

- **Next position calculation:** `(current_position + 1) % N`, where `N` is the array size.
    
- **Previous position calculation:** `(current_position + N - 1) % N` (to ensure a positive result).
    

**Modified Pseudocode for Circular Array-Based Queue:**

- `IsEmpty()`**:** Remains the same (`front == -1` and `rear == -1`).
    
- `IsFull()`**:** Returns `true` if `(rear + 1) % N == front`.
    
- `Enqueue(X)`**:**
    
    - If `IsFull()`, exit.
        
    - If `IsEmpty()`, set `front = 0`, `rear = 0`.
        
    - Else, `rear = (rear + 1) % N`.
        
    - Store `X` at `A[rear]`.
        
- `Dequeue()`**:**
    
    - If `IsEmpty()`, exit.
        
    - If `front == rear` (single element), set `front = -1`, `rear = -1`.
        
    - Else, `front = (front + 1) % N`.
        
- `Front()`**:** Returns `A[front]` (after checking if empty).
    

All operations in the circular array implementation also maintain a constant time complexity (O(1)).

### Meaning Of:

```cpp
return ((rear + 1) % N) == front;
```

This line checks whether the **queue is full**.

 In a circular queue (classic implementation), the queue is full when:

👉 **The next position after `rear` is the same as `front`**

Because this means:

- `front` has stopped moving forward (queue is full)
    
- `rear` has reached the position just behind `front`
    
- There is NO empty space left to insert anything

### 🔍 **Reason for using `front = (front + 1) % N;`**

When you remove (dequeue) an element from a circular queue, you move `front` **to the next element**.

But the queue is circular.  
So after the last index (`N-1`), the next index is not `N` — it's **0**.

**Modulo makes this wrap-around possible.**

---
# Linked List Implementation

## Limitations of Array-Based Queue Implementation

When implementing a queue with arrays, even with a circular array, there are limitations:

- **Fixed Size**: Arrays have a fixed size, meaning the queue can become full.
    
- **Handling Full Arrays**: If the array is full, options include:
    
    - Denying further insertions (queue is full).
        
    - Creating a new, larger array and copying all elements, which is a costly O(N) operation.
        
- **Wasted Memory**: A large array allocated for potential maximum capacity might have significant unused memory if the queue size is typically small.
    

## Advantages of Linked List Implementation

Using linked lists to implement queues avoids the problems associated with fixed-size arrays:

- **Dynamic Size**: Linked lists can grow or shrink dynamically, eliminating the need to resize or handle full conditions.
    
- **Memory Efficiency**: Memory is allocated only as needed for each node, reducing wasted space.
    

## Linked List Basics

A linked list is a collection of nodes, where each node contains two fields:

- **Data**: Stores the actual value.
    
- **Next**: Stores the address (or reference) to the next node in the sequence.
    

Nodes are stored at non-contiguous memory locations. The linked list is identified by the address of its head node, often stored in a pointer variable named `head`.

## Achieving O(1) Operations with Linked Lists

To ensure both enqueue and dequeue operations take constant time, we need to manage pointers efficiently. If we insert at one end and remove from the other, one operation typically becomes O(N) in a standard singly linked list because traversing to the tail takes linear time.

To overcome this, we use two pointer variables:

- `front`: Always stores the address of the front node (for dequeue).
    
- `rear`: Always stores the address of the rear node (for enqueue).
    

### Enqueue Operation (Insertion at Rear)

1. Create a new node with the data to be enqueued.
    
2. If the queue is empty (both `front` and `rear` are null), set both `front` and `rear` to point to the new node.
    
3. Otherwise, set the `next` pointer of the current `rear` node to point to the new node.
    
4. Update the `rear` pointer to point to the new node.
    

This process avoids traversal and ensures O(1) time complexity.

### Dequeue Operation (Removal from Front)

1. Check if the queue is empty. If so, print an error and return.
    
2. Store the address of the current `front` node in a temporary pointer.
    
3. If `front` and `rear` are pointing to the same node (only one element in the queue), set both `front` and `rear` to null.
    
4. Otherwise, update `front` to point to the `next` node in the sequence (`front = front->next`).
    
5. Free the memory of the node previously at the front using the temporary pointer.
    

This also ensures O(1) time complexity because we directly manipulate the `front` pointer and then free the memory.

## C Code Structure

```cpp
// Linked List Implementation of Queues:
class Queue_Link
{
private:
    struct Node
    {
        int val;
        Node* next;

        Node(int value)
        {
            val = value;
            next = nullptr;
        }
    };
    Node* front = nullptr;
    Node* rear = nullptr;
public:
    void Enqueue(int val)
    {
        Node* newNode = new Node(val);
        if (front == nullptr && rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode; 
    }
    void Dequeue()
    {
        Node* temp = front;
        if (front == nullptr)
        {
            // Empty!
            cout << "Empty Queue!\n";
            return;
        }
        if (front == rear)
        {
            delete temp;
            front = rear = nullptr;
            return;
        }
        front = front->next;
        delete temp;
    }
    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        return false;
    }
    int Front()
    {
        if (front == nullptr)
        {
            cout << "Empty!\n";
            return -1;
        }
        return front->val;
    }

}; 
```

---
