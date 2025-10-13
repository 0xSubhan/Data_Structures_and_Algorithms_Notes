
#  **What is an Abstract Data Type (ADT)?**

>An **Abstract Data Type (ADT)** is a **concept** — not a concrete implementation.  
It defines **what** operations can be performed on some data, but **not how** those operations are implemented.

#### 🧠 In simple terms:

Think of ADT as a **blueprint** or **contract** for a data structure.

It says:

> “You can do these operations and expect these results…”

But it doesn’t say:

> “…and here’s how those operations are actually done inside.”

#### ⚙️ Example:

Let’s take the **Stack** as an example of an ADT.

|Operation|Description|
|---|---|
|`push(x)`|Add element `x` on top of the stack|
|`pop()`|Remove and return the top element|
|`peek()`|Return (but don’t remove) the top element|
|`isEmpty()`|Check if the stack has no elements|

The ADT tells us **these are the valid operations**, but not **how** they’re implemented.

#### 🧩 Implementations:

The **implementation** can vary:

- Using an **array**
    
- Using a **linked list**
    

Both satisfy the “Stack ADT” — because both allow push, pop, peek, etc. —  
but the internal working (how data is stored, accessed) is different.

#### 💡 Real-life analogy:

Think of a **TV remote**:

- You know what buttons do — volume up, power off, channel change.
    
- You don’t know (and don’t need to know) how the circuit inside performs it.
    

That’s exactly how **ADT** hides details → it provides **abstraction**.

#### 🧾 Common ADTs:

Here are some widely used abstract data types:
🧩 In short:

ADT = Logical view (what it does)
Data Structure = Physical view (how it’s done)

|ADT|Description|
|---|---|
|**List**|Ordered collection of elements|
|**Stack**|LIFO (Last In First Out) structure|
|**Queue**|FIFO (First In First Out) structure|
|**Deque**|Double-ended queue|
|**Set**|Collection of unique elements|
|**Map (Dictionary)**|Collection of key–value pairs|
#### 🔑 Key Points:

- ADT focuses on **what** operations are performed, not **how**.
    
- It provides **abstraction** and **data encapsulation**.
    
- Actual implementation is called a **data structure**.

#### 🧩 In short:

> **ADT = Logical view (what it does)**  
> **Data Structure = Physical view (how it’s done)**

### List as a abstract data type

A **List ADT** represents an **ordered collection of elements**,  
where each element has a specific **position (index)**,  
and **duplicates are allowed**.

It defines **what operations** can be performed on a list —  
but not **how** those operations are implemented internally.

#### ⚙️ The Concept

When we say **List ADT**, we mean:

> “A collection where you can access elements by position, insert or remove them, and the order matters.”

For example:  
`[10, 20, 30, 40]`  
This is a list with elements in a defined order.

#### 🧱 List ADT — Typical Operations

|Operation|Description|
|---|---|
|`insert(pos, x)`|Insert element `x` at position `pos`|
|`remove(pos)`|Remove the element at position `pos`|
|`get(pos)`|Return the element at position `pos`|
|`set(pos, x)`|Replace element at position `pos` with `x`|
|`size()`|Return the number of elements in the list|
|`isEmpty()`|Check if the list is empty|
|`clear()`|Remove all elements from the list|

These are **logical operations** — they describe **what** can be done.

#### 🧩 Implementations (Data Structures)

The **List ADT** can be implemented in different ways:

|Implementation|Description|Example in C++|
|---|---|---|
|**Array-based list**|Uses a fixed or dynamic array internally|`std::vector`|
|**Linked list**|Uses nodes connected by pointers|`std::list`|
|**Doubly linked list**|Each node has pointers to both next and previous|`std::list` again or custom|

All of these satisfy the **List ADT**,  
but the performance of operations differs depending on the implementation.

#### ✅ In short:

> **List ADT defines what operations are possible on an ordered collection of elements,  
> not how they are performed.**

###  **“Data structure is not just the study of organizing data in a certain manner; it is also the study of how costly or efficient operations of an ADT are.”**

#### 🧩 Step 1: What this means

When we learn **data structures**, we’re not only learning **how** to store data —  
we’re also learning **how well** different storage methods perform when used with an **ADT**.

So, data structures =  
➡️ **organization of data** +  
➡️ **analysis of operation efficiency**.

#### 🧠 Step 2: Connection between ADT and Data Structure

- **Abstract Data Type (ADT)** defines **what** operations exist (the “interface”).  
    Example: For a List ADT — insert, remove, get, size.
    
- **Data Structure** defines **how** those operations are implemented (the “implementation”).
    

Now, different data structures can implement the same ADT **with different efficiencies**.

#### ⚙️ Step 3: Example — List ADT

Suppose we want to implement the **List ADT**.

We have two options:

1. **Array-based list**
    
2. **Linked list**
    

Both can perform operations like insert, remove, and access.  
But the **cost** (time or memory) of these operations differs:

| Operation               | Array-based List | Linked List |
| ----------------------- | ---------------- | ----------- |
| Access element by index | O(1)             | O(n)        |
| Insert at beginning     | O(n)             | O(1)        |
| Insert at end           | O(1) (amortized) | O(1)        |
| Remove middle element   | O(n)             | O(n)        |

So even though both satisfy the same **ADT**,  
their **efficiency (cost)** of performing operations is very different.

#### ⚖️ Step 4: Why this matters

When choosing a data structure, you must consider:

- How **frequently** each operation is performed
    
- Which operations need to be **fast**
    
- The **space** (memory) usage
    

For example:

- If you often need **random access**, use **array** (O(1)).
    
- If you often **insert/delete** at the start, use **linked list** (O(1)).

#### 🧾 Step 5: The takeaway

> Learning data structures means understanding **trade-offs** —  
> how each structure affects the **performance** of ADT operations.

It’s not enough to just know _how_ to store data;  
you must also know _how efficiently_ your structure supports the operations you need.

#### ✅ Summary

|Concept|Meaning|
|---|---|
|**ADT**|Defines _what_ operations exist|
|**Data Structure**|Defines _how_ those operations are implemented|
|**Efficiency Study**|Measures how _costly_ those operations are (in time and space)|
|**Goal**|Choose the best structure for your problem|

---
# Linked List Data Structure

> So before starting lets discus why we need linked list data structure instead of arrays, simply put arrays are fixed and have static size and we cannot extent the array after declaring but arrays are very fast to access since it uses pointer arithmetic and it is contiguous in memory. So we need some dynamic data structure to organize data like arrays and that's where linked list came in!
 
Albert's problem involves storing a list of integers. Instead of requesting a large contiguous block of memory like an array, Albert can request memory for one unit of data at a time. This results in disjoint, non-contiguous blocks of memory.

To link these non-contiguous blocks, each block is designed to store two pieces of information:

1. **Data/Value:** The actual integer being stored.
    
2. **Address of the Next Block:** A pointer to the next element in the list.
    

For example, if the first block stores '6' and the next block (at address 217) stores '5', the first block's address part would store '217'. The last block in the list would have an address of zero or null to indicate the end.

### Node Structure

To implement this, Albert can define a `node` type (e.g., in C/C++ Struct). This `node` would contain:

```cpp
struct Node
{
	int data;
	Node* next;
}
```

- An integer field for the data.
    
- A pointer field (e.g., `node *`) to store the address of the next node.
    

A typical node in memory would, therefore, be 8 bytes (4 bytes for an integer and 4 bytes for a pointer).

### Logical View and Terminology

When these non-contiguous nodes are connected, they form a **linked list data structure**.

- **Head Node:** The first node in the list. The address of the head node is crucial as it provides access to the entire list.
    
- **Null/Zero Address:** In the last node, this signifies the end of the list.
    

### Traversing a Linked List

To access elements, one must start at the head node and follow the links (addresses) from one node to the next. This means accessing an element at a specific position requires traversing all preceding elements.

### Operations on Linked Lists

#### Accessing Elements

- **Time Complexity:** O(N), where N is the size of the list. In the worst case, to access the last element, all N elements must be traversed.
    

#### Insertion

- To insert a node, a new node is created independently.
    
- The links (addresses) of the preceding node and the new node are adjusted to incorporate it into the list.
    
- **Time Complexity:** O(N), because traversing to the insertion point takes O(N).
    
- **Advantage:** Unlike arrays, insertion does not require shifting other elements, making it a simpler operation once the insertion point is found.
    

#### Deletion

- Similar to insertion, deleting a node involves adjusting the links of the surrounding nodes.
    
- **Time Complexity:** O(N) due to the need to traverse to the node to be deleted.
    

### Advantages of Linked Lists

- **Dynamic Size:** Linked lists can grow or shrink as needed, without needing to pre-allocate a fixed size (unlike arrays).
    
- **Efficient Memory Usage:** Memory is allocated only when a node is created, and unused memory is not reserved. While some extra memory is used for storing addresses, it allows for flexible memory allocation.

---
# Arrays vs Linked List : A Comparative Analysis

>One data structure may be really good for one kind of requirement while another data structure can be really good for another kind of requirement.

## Accessing Elements

Accessing an element in an array takes constant time, regardless of its size. This is because arrays are stored as a contiguous block of memory. The address of any element can be calculated directly using its base address and index (e.g., `base_address + index * size_of_element`). In Big O notation, this is represented as O(1).

Conversely, a linked list does not store data in a contiguous memory block. Each element, called a node, contains the data and a pointer to the next node. To access an element, you must traverse the list from the head node. On average, accessing an element in a linked list takes time proportional to the number of elements (N), so its time complexity is O(N).

## Memory Requirement

Arrays require a fixed size to be known before creation, as they occupy a single contiguous memory block. Typically, a larger array is allocated than immediately needed, leaving vacant space for future additions. For example, an array of seven integers might only store three initially, with four unused positions.

Linked lists do not require pre-allocation of a fixed size. Memory is allocated for one node at a time as needed, meaning no reserved empty space. However, linked lists use extra memory for pointer variables within each node. For example, if an integer takes 4 bytes and a pointer variable also takes 4 bytes, each node would require 8 bytes. The memory efficiency of linked lists improves if the data stored within each node is large.

Another memory consideration is the potential difficulty of allocating a very large contiguous block of memory for an array. This is a scenario where linked lists offer an advantage. Also, if an array fills up, a new larger array must be created, and all elements copied, which incurs additional cost not present with linked lists.

## Inserting Elements

Insertion cost varies depending on the position:

- **Beginning of the list:**
    
    - **Arrays:** Inserting at the beginning requires shifting all existing elements one position, making the time complexity O(N), where N is the size of the list.
        
    - **Linked lists:** Inserting at the beginning involves creating a new node and adjusting the head pointer and the new node's link. This is a constant time operation, O(1).
        
- **End of the list:**
    
    - **Arrays (dynamic array scenario):** If there is available space, adding an element at the end is a constant time operation. If the array is full, a new larger array must be created and elements copied, which can be O(N).
        
    - **Linked lists:** To insert at the end, the list must be traversed to find the last node, making the time complexity O(N).
        
- **Middle of the list:**
    
    - **Arrays:** Inserting in the middle requires shifting approximately N/2 elements on average, resulting in an O(N) time complexity.
        
    - **Linked lists:** Inserting in the middle requires traversing to the insertion point, which on average takes O(N) time. After reaching the position, adjusting pointers is O(1).
        

Deletion of elements follows similar time complexities for these three scenarios.

## Ease of Use and Implementation

Arrays are generally much easier to use and implement. Linked list implementations, particularly in languages like C or C++, are more prone to errors such as segmentation faults and memory leaks, requiring careful handling.

This comparison highlights that the choice between an array and a linked list depends on the specific requirements of the application, such as the frequency of access, insertion/deletion operations, and memory constraints.

## 🧠 What “constant time” means

When we say an operation takes **constant time (O(1))**, it means that the **time it takes to perform that operation does _not depend_ on the size of the data structure (like array length)**.

No matter whether your array has **10 elements or 10 million**, the time to access a single element (e.g. `arr[500]`) stays roughly **the same**.


---
# Linked List Implementation in C++

A working knowledge of pointers and dynamic memory allocation in C/C++ is a prerequisite.

## Linked List Structure and Nodes

In a linked list, data is stored in non-contiguous memory blocks, each referred to as a "node." Each node typically has two parts: one to store the actual data and another to store the address (or a "link") of the next node. The memory addresses allocated to these nodes are random, not necessarily sequential or adjacent, which necessitates the use of links to maintain order.

The identity of the linked list is maintained by the address of its first node, often called the "head node." A pointer variable, typically named `A` in this context, stores this address and serves as the primary reference for the entire list.

## Implementing Nodes in C/C++

In C, a node can be defined using a `struct`. For example, a linked list of integers would have a `struct node` with an `int data` field and a `struct node* next` field (or `link`). In C++, the syntax is slightly cleaner, allowing for `node* next`. This `next` field is a pointer to another node, effectively linking them.

## Initializing an Empty Linked List

To start, a pointer to the head node (e.g., `node* A`) is declared. When the list is empty, this pointer should not point to a valid memory location, so it's initialized to `NULL` (or `0`), signifying an invalid address. This `A = NULL` statement indicates an empty list.

## Inserting the First Node

To insert a node, memory must first be allocated. In C, `malloc` is used to dynamically allocate a memory block equal to the size of a node. `malloc` returns a `void` pointer to the allocated memory, which needs to be type-cast and stored in a `node*` variable (e.g., `temp`).

Once memory is allocated, the node's fields need to be populated:

- The `data` field is assigned the desired value (e.g., `temp->data = 2`). The arrow operator (`->`) is a convenient shorthand for dereferencing the pointer and accessing a member (e.g., `(*temp).data`).
    
- The `link` (or `next`) field of this first node is set to `NULL` because it's currently the only node and thus the last one.
    
- Finally, the head pointer `A` is updated to store the address of this new node (`A = temp`), making it the first node of the list.
    

In C++, the `new` operator (`node* temp = new node;`) is generally preferred over `malloc` for cleaner syntax and better type safety.

## Inserting Nodes at the End of a Non-Empty List

When inserting a new node at the end of an existing list (e.g., to create a list with values 2, 4, 6 from an initial node containing 2):

1. **Create a new node:** Allocate memory and populate the data (e.g., `4`) and set its link to `NULL` using the same `malloc`/`new` and assignment methods as for the first node.
    
2. **Traverse to the last node:** A temporary pointer (e.g., `temp1`) is initialized to the head of the list (`temp1 = A`). A `while` loop (`while (temp1->link != NULL)`) is used to move `temp1` through the list (`temp1 = temp1->link`) until it reaches the last node (where `temp1->link` is `NULL`). It's crucial not to modify the head pointer `A` during this traversal.
    
3. **Link the new node:** Once `temp1` points to the last node of the original list, its `link` field is updated to point to the newly created node (e.g., `temp1->link = temp`). This establishes the connection.
    

This process is repeated for each subsequent node to be inserted at the end.

---
# Linked List : Inserting a node at beginning  

## ⚙️ Step 1: Defining a Node in C++

In C, we use `struct node`, but in C++, we can define it as a **class** or a **struct** (both work; `struct` members are public by default).

```cpp
struct Node {
    int data;     // Data field
    Node* next;   // Pointer to the next node

    // Constructor to easily create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
```

Here:

- `Node* next` holds the address of the next node.
    
- `nullptr` is used instead of `NULL` (C++ standard).
    
- A constructor makes initialization cleaner.

## ⚙️ Step 2: Declaring the Head Node

We need a pointer to the first node — commonly called `head`.

If we declare it **globally**:

```cpp
Node* head = nullptr;
```

This means initially the linked list is **empty** (no nodes).

## ⚙️ Step 3: Inserting at the Beginning

### Goal

We want to **insert a new node** such that it becomes the **first node**, and the existing list is linked after it.

### Logic

1. **Create a new node** using `new`:

```cpp
Node* temp = new Node(x);
```

2. **Point it to the old head**:

```cpp
temp->next = head;
```

3. **Update head** to the new node:

```cpp
head = temp;
```

That’s it. These three steps handle **both cases**:

- If `head == nullptr` (empty list), `temp->next` will just be `nullptr`.
    
- If `head` already points to a list, `temp` will become the new first node.
    

✅ **C++ Implementation:**

```cpp
void insertAtBeginning(int x) {
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}
```

## ⚙️ Step 4: Printing the Linked List

To print, we **traverse** from `head` to the end (`nullptr`):

```cpp
void printList() {
    Node* temp = head;  // Use a temporary pointer
    std::cout << "List: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
```

- Using a separate variable ensures we don’t modify `head`.
    
- Each iteration prints one node’s `data`.

## ⚙️ Step 5: Main Function Logic

We can now use these functions in `main()`:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* head = nullptr; // global head pointer

void insertAtBeginning(int x) {
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}

void printList() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int n, x;
    cout << "How many numbers? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter number: ";
        cin >> x;
        insertAtBeginning(x);
        printList();
    }
}
```

## ⚙️ Step 6: Alternative (Local Head Variable)

### Option 2 — Pass by reference

```cpp
void insertAtBeginning(Node*& head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}
```

Usage in `main()`:

```cpp
insertAtBeginning(head, x);
```

This way, the `head` pointer in `main` is modified directly.

## 🧩 Summary Table

|Concept|Description|C++ Example|
|---|---|---|
|Node definition|Contains `data` and `next` pointer|`struct Node { int data; Node* next; };`|
|Create node|Allocate dynamically|`Node* temp = new Node(x);`|
|Insert at beginning|`temp->next = head; head = temp;`|Works for both empty/non-empty lists|
|Traverse & print|Use temporary pointer|`while(temp != nullptr)`|
|Global head|Simple for small programs|`Node* head = nullptr;`|
|Local head|More flexible|Pass by reference or return new head|

---
# Linked List in C/C++ - Insert a node at nth position

## 🧩 **Goal of the Lesson**

We’re learning how to **insert a node at any position (Nth position)** in a singly linked list — not just at the start or end.

This is the next logical step after learning:

- Insert at beginning
    
- Insert at end
    

Now you’re learning **insert at Nth position**, which generalizes both.

## 🧠 **Conceptual Idea**

Think of a linked list like a **chain of boxes**, each box (node) having:

- `data` — the value inside it
    
- `next` — a pointer (address) to the next box
    

We want to **add a new box at position N** (e.g., 3rd position).  
To do this, we need to:

1. Create the new box.
    
2. Find the box **before** that position (the (N−1)th box). // because that will contain the address of the next box!
    
3. Connect the links properly so the chain isn’t broken.

## 🧱 **Detailed Logic Behind the Four Steps**

### 1️⃣ Create a New Node

We create a node dynamically (from heap memory) because we don’t know at compile time how many nodes we’ll need.

```cpp
Node* temp1 = new Node();
temp1->data = val;
temp1->next = nullptr;
```

This allocates a new memory block for the node.  
Now, `temp1` points to that new block.

### 2️⃣ Move to the (N−1)th Node

Let’s say you want to insert at the **3rd position**.

That means you need to find the **2nd node** because:

- The 2nd node currently points to the 3rd node.
    
- After insertion, the 2nd node should point to your new node.
    

We can move to the (N−1)th node using a loop:

```cpp
Node* temp2 = head;
for (int i = 1; i < n - 1; i++)
{
    temp2 = temp2->next;
}
```

After this loop:

- `temp2` points to the node **before** the insertion point.

### 3️⃣ Link the New Node to the Rest of the List

We don’t want to lose connection with the remaining nodes.

So we first connect the **new node** to the next node:

```cpp
temp1->next = temp2->next;
```

Now, your new node points to the node that was originally after `(N-1)`.

### 4️⃣ Link the Previous Node to the New Node

Finally, update the `(N−1)`th node’s link to point to the new node:

```cpp
temp2->next = temp1;
```

This completes the insertion — all nodes are connected in proper order again.

## ⚙️ **Special Case: Inserting at Beginning (N = 1)**

If position = 1:

- You don’t need to find any previous node (because there’s none).
    
- You simply make your new node point to the current head, and then make the new node the head.

```cpp
if (n == 1)
{
    temp1->next = head;
    head = temp1;
    return;
}
```

## 🧮 **Visualization Example**

Let’s simulate inserting step by step:

### Initially:

```cpp
head → [2 | *] → [3 | *] → nullptr
```

### Insert 8 at position 3:

1. Create node `[8 | *]`
    
2. Go to (N−1)th = 2nd node (`[3]` is currently 2nd node)
    
3. Set new node’s next = 2nd node’s next
    
4. Update 2nd node’s next to new node
    

Result:

```cpp
head → [2 | *] → [3 | *] → [8 | *] → nullptr

```

If we insert at position 1 instead:

```cpp
[8 | *] → [2 | *] → [3 | *]
head points to new node
```

---
# Linked List in C/C++ - Deleting a node at nth position

## 🧩 1. What Does “Deleting a Node” Really Mean?

Deleting a node from a **singly linked list** means:

1. **Disconnecting** that node from the list (fixing links).
    
2. **Freeing** its memory from the heap to avoid leaks.
    

In simple words — we remove the node’s connection so the list “skips” it, and then release the memory used by it.

## ⚙️ 2. How Memory and Links Work

Before deletion, each node contains:

```cpp
[data | next]
```

where `next` stores the **address** of the next node.

Example:

```cpp
head → [10 | *] → [20 | *] → [30 | *] → nullptr
```

Addresses might look like:

```cpp
100: [10 | 200]
200: [20 | 300]
300: [30 | nullptr]
```

If we want to **delete the 2nd node (address 200)**:

- We must make the 1st node (100) point directly to 300.
    
- Then free the memory of node 200.
    

So the new list becomes:

```cpp
head → [10 | 300] → [30 | nullptr]
```

The node `[20 | *]` (200) is detached and then deleted.

## 🧱 3. Step-by-Step Logic

### 🧠 Case 1 — Deleting the First Node (Head Node)

If we’re deleting position `N = 1`, the first node is special because it’s pointed to by `head`.

Steps:

1. Let `temp1 = head` → temporary pointer to the node to delete.
    
2. Move `head` to the **second** node:

```cpp
head = temp1->next;
```

3. Delete the first node:

```cpp
delete temp1;
```

Now the list starts from the new head.

### 🧠 Case 2 — Deleting the Nth Node (Middle or End)

Steps:

1. Create a pointer `temp1 = head`.
    
2. Traverse `(N-2)` times to reach the **(N−1)th node** (the node before the one we’ll delete):

```cpp
for (int i = 0; i < N - 2; ++i)
    temp1 = temp1->next;
```

- Now, `temp1` points to the (N−1)th node.

3.  Create another pointer `temp2 = temp1->next;`  
    → this is the node we want to delete (Nth node).

4. Fix the links:

```cpp
temp1->next = temp2->next;
```

- This **bypasses** the Nth node and links directly to (N+1)th.

5. Delete the Nth node from memory:

```cpp
delete temp2;
```

## 🧩 4. Visual Example — Deleting 3rd Node

Initial list:

```cpp
head → [10 | *] → [20 | *] → [30 | *] → [40 | nullptr]
```

Addresses:

```cpp
100: [10 | 200]
200: [20 | 300]
300: [30 | 400]
400: [40 | nullptr]
```

Let’s delete the **3rd node (30)**.

### Step 1️⃣ — Traverse to (N−1)th node

After loop,  
`temp1` → node at 200 (value 20).

### Step 2️⃣ — Point temp2 to Nth node

`temp2 = temp1->next` → node 300 (value 30).

### Step 3️⃣ — Fix link

```cpp
temp1->next = temp2->next;
```

So node 200 (value 20) now points to 400 (value 40).

### Step 4️⃣ — Free memory

```cpp
delete temp2;
```

Now the list becomes:

```cpp
head → [10 | *] → [20 | *] → [40 | nullptr]
```

Memory for node 300 (value 30) is released.

## 🧠 5. Why Freeing Memory Matters

When we use `new` in C++, the memory for that node comes from the **heap**.  
If we simply disconnect it but **don’t delete it**, that memory stays allocated → causing a **memory leak**.

So always call:

```cpp
delete temp2;
```

after removing its links.

## 🧰 6. C++ Implementation Example

Here’s a simple program outline:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
}

void print() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int n) {
    if (head == nullptr) return; // empty list

    // Case 1: deleting first node
    if (n == 1) {
        Node* temp1 = head;
        head = head->next;
        delete temp1;
        return;
    }

    // Case 2: deleting Nth node
    Node* temp1 = head;
    for (int i = 0; i < n - 2; ++i)
        temp1 = temp1->next;

    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

int main() {
    insert(5);
    insert(6);
    insert(4);
    insert(2);
    print();          // List: 2 4 6 5

    int n;
    cout << "Enter position to delete: ";
    cin >> n;

    deleteNode(n);
    print();          // Updated list
}
```

## 🔍 7. Key Points to Remember

|Concept|Explanation|
|---|---|
|`head`|Points to the first node of the list|
|Deleting first node|Update `head` directly|
|Deleting middle/end node|Traverse to (N−1)th node|
|Fix links|`(N−1)->next = (N+1)`|
|Free memory|`delete temp2;`|
|Memory type|Nodes are dynamically allocated (heap)|
|Invalid positions|Should be handled in production code, but skipped here for simplicity|

## 🧩 8. Analogy (Chain Cut)

Think of your linked list as a **chain** of rings:

```cpp
A — B — C — D
```

To delete `C`:

1. Grab `B` (previous ring).
    
2. Connect `B` directly to `D`.
    
3. Throw away `C`.
    

That’s exactly what:

```cpp
temp1->next = temp2->next;
delete temp2;
```

does in code.

---
# Reverse a linked list - Iterative method

