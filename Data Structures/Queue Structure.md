## Introduction to Queues

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
        
    - Store `X` at `A[rear]`.
        
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


---
