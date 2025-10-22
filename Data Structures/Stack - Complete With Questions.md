# Introduction to Stack Data Structure

This lesson introduces the stack data structure, a method for storing and organizing data in computers. Unlike arrays and linked lists, which were previously discussed, this lesson focuses on stacks as an Abstract Data Type (ADT). When discussing a data structure as an ADT, the emphasis is solely on its features or available operations, not its implementation details. It defines the data structure as a mathematical or logical model.

### Stack as an Abstract Data Type (ADT)

A stack is a list or collection with a fundamental restriction: insertion and deletion can only be performed from one end, referred to as the "top of the stack." This unique characteristic makes a stack a "Last-In, First-Out" (LIFO) collection, meaning the most recently added item is the first to be removed. This principle is not very different from how objects are organized in the real world.

### Real-world Examples of Stacks

- **Stack of dinner plates**: You always take a plate from the top and put a new one on top.
    
- **Tower of Hanoi puzzle**: Discs are moved between pegs, but a larger disc cannot be placed on a smaller one, illustrating the top-only access.
    
- **Pack of tennis balls**: Typically, you remove and insert balls from one opening, resembling stack behavior.

### Core Operations of Stack ADT

The primary operations available with a stack ADT are:

- **Push**: Inserts an item onto the top of the stack.
    
- **Pop**: Removes the most recent item from the top of the stack.
    

Other common operations include:

- **Top**: Returns the element at the top of the stack without removing it.
    
- **IsEmpty**: Checks if the stack is empty (returns true if empty, false otherwise).
    

All these operations (Push, Pop, Top, IsEmpty) can typically be performed in constant time, meaning their time complexity is O(1). The LIFO principle is central: an element pushed last is popped first.

### Logical Representation of a Stack

Logically, a stack can be visualized as a three-sided container open from one side. An empty stack is represented as such a container with no elements. When elements are pushed, they are added to the top. When elements are popped, they are removed from the top.

### Applications of Stacks

Stacks are used in various important computing scenarios:

- **Function call execution**: In programming, stacks manage function calls, including those involved in recursion (a chain of function calls to the same function).
    
- **Undo operation in editors**: Implementing undo functionality in text or image editors often relies on a stack to store previous states.
    
- **Algorithm implementation**: Stacks are crucial for algorithms, such as verifying balanced parentheses in source code. Compilers use stacks to ensure every opening parenthesis or brace has a corresponding closing one in the correct position. If they are not balanced, an error is thrown.
    

Future lessons will delve into the implementation of stacks.

---
# Stack Data Structure Implementation As An Array

## Stack as an Abstract Data Type

As an Abstract Data Type (ADT), a stack is defined as a mathematical or logical model focusing only on its features and operations, not its implementation. Key operations include insertion (push) and deletion (pop), which must be performed one element at a time from a single end, known as the "top of the stack."

## Implementation Methods

Stacks can be implemented using two popular methods:

- **Arrays**
    
- **Linked Lists**
    

### Array-Based Implementation

To implement a stack using an array, an array of a fixed size (e.g., 10 integers) is created. A `top` variable is used to store the index of the top element of the stack. For an empty stack, `top` is initialized to -1.

#### Push Operation

When a `push` operation is called (e.g., `push(X)`):

1. The `top` variable is incremented.
    
2. The new element `X` is placed at the `top` index.
    

This operation takes constant time (O(1)).

#### Pop Operation

When a `pop` operation is called:

1. The `top` variable is decremented.
    

This operation also takes constant time (O(1)). Elements are not explicitly removed or reset; they are simply considered out of the stack's scope.

#### Overflow Handling

A limitation of array-based implementation is the possibility of an overflow if the stack exceeds the array's capacity. Two strategies for handling this are:

1. **Error Handling**: The `push` function can check if the array is full and return an error if an overflow occurs. This means the push operation will fail.
    
2. **Dynamic Array**: Upon overflow, a new, larger array (ideally twice the size) is created. The contents of the old array are copied to the new array. The old array can then be deleted. While a normal push is O(1), a push during an overflow becomes O(N) due to the copying process. However, the average time complexity for N pushes remains O(1).
    

#### Other Operations

- **Top Operation**: Returns the element at the `top` of the stack. This is typically done by returning the element at the `top` index.
    
- **IsEmpty Operation**: Checks if the stack is empty by verifying if `top` is equal to -1. Returns true if empty, false otherwise.
    

Some implementations combine `pop` and `top`, where `pop` not only removes an element but also returns its value.

## Basic C Implementation Example

A basic array-based stack implementation in C involves:

- Declaring a global array (`A`) with a `MAX_SIZE` (e.g., 101) and a global `top` variable initialized to -1.
    
- `push` **function**: Increments `top` (using pre-increment `++top`) and then assigns the value. It includes overflow checks, printing an error message if `top` reaches `MAX_SIZE - 1`.
    
- `pop` **function**: Decrements `top`. It includes underflow checks, printing an error if `top` is -1.
    
- `top` **function**: Returns the element at `A[top]`.
    
- A `print` function (for testing) to display stack elements after each operation, although this is not a standard stack operation.
    

This basic implementation is not ideal as it doesn't create an explicit `stack` data type. Object-oriented languages or C structures can be used for more robust implementations.

### Code

```cpp
#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class STACK
{
private:
    static const int MAX = 101;
    int stack[MAX];
    int top {-1};
    
public:
    void push(int val)
    {
        if (top == MAX-1)
        {
            cout << "Overflow!" << endl;
            return;
        }
        top++;
        stack[top] = val;
    }    
    void pop()
    {
        if (top == -1)
        {
            cout << "Pop : Already Empty" << endl; 
            return;
        }
        
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        
        return stack[top];
    }
    int Top_index()
    {
        return top;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    const int* Stack() const
    {
        return stack;
    } 
};
void printStack(STACK& stack)
{
    if (stack.Top_index() == -1)
    {
        cout << endl;
        return;
    }
    
    for(size_t i = 0; i <= stack.Top_index(); i++)
    {
        cout << stack.Stack()[i] << " ";
    }
    cout << endl;
}

int main() {
        
    STACK s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    printStack(s1);

    s1.pop();

    printStack(s1);

    cout << "TOP: " << s1.Top() << endl;

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    printStack(s1);

    if (s1.isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }
    else    
        cout << "Not Empty!" << endl;
    


    cout << '\n';
    return 0;
}
```

---
# Linked List Implementation of Stack

### Time Complexity for Insertion and Deletion

For a stack, push and pop operations must have a constant time complexity (O(1)).

- **Inserting/Deleting at the end of a linked list (tail):** This operation has a time complexity of O(N) because it requires traversing the entire list to reach the last or second-to-last node. This is not suitable for stack operations.
    
- **Inserting/Deleting at the beginning of a linked list (head):** This operation has a constant time complexity of O(1). This makes it ideal for implementing stack operations.

### Stack Implementation using Linked List

To implement a stack using a linked list, we consistently perform insertions and deletions at the beginning of the list. The head of the linked list effectively becomes the "top" of the stack.

### Node Structure

In C, a node can be defined as a structure with two fields:

- An integer to store the data.
    
- A pointer to another node, storing the address of the next node.
    

### Top Variable

A pointer to a node, named `top`, is used to indicate the top of the stack. Initially, `top` is set to `NULL`, indicating an empty stack.

### Push Operation

1. **Create a new node:** Allocate memory for a new node using `malloc`.
    
2. **Set data:** Store the value to be pushed into the data field of the new node.
    
3. **Link to existing top:** Set the `next` pointer of the new node to point to the current `top`.
    
4. **Update top:** Set `top` to point to the newly created node. This effectively inserts the new node at the beginning of the list.
    

### Pop Operation

1. **Check for empty stack:** If `top` is `NULL`, the stack is empty, and an error should be handled.
    
2. **Create a temporary pointer:** A temporary pointer (`temp`) is created and made to point to the current `top` node.
    
3. **Update top:** `top` is updated to point to the next node in the list (the node that was previously second in the list).
    
4. **Free memory:** The memory allocated to the node pointed to by `temp` (the original top node) is freed.
    

### Advantages of Linked List Implementation

One significant advantage of a linked list-based stack over an array-based implementation is that it does not suffer from overflow issues, as long as the machine has available memory. It allocates memory dynamically as needed, making push and pop operations more efficient in terms of memory usage.

```cpp
// Link List Implementation of stack:
    struct Node
    {
        int data;
        Node* link;

        Node(int val)
            : data {val}
            , link {nullptr}
        {
        }
    };
class STACK_LINK
{
private:

    Node* top {nullptr}; // alternative of head 
public:
    void push(int val)
    {
        Node* newNode = {new Node(val)};
        if (top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode->link = top;
        top = newNode;
    }
    void pop()
    {
        if (top == nullptr)
        {
            return;
        }
        Node* temp = top;
        top = top->link;
        delete temp;
    }
    int Top() const
    {
        if (top == nullptr)
        {
            cout << "Linked List Is Empty So There is no top!" << endl;
            return;
        }
        
        return top->data;
    } 
    bool isEmpty()
    {
       return top == nullptr;
    }
    Node* getList()
    {
        return top;
    }
};
void printList_linked(STACK_LINK& s)
{
    Node* temp = s.getList();
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->link; 
    }
    cout << endl;
}

int main()
{
    // Linked list implementation of stack testing:
    cout << "linked list implementation using stack: " << '\n';
    STACK_LINK s2;
    s2.push(5);
    s2.push(4);
    s2.push(3);
    s2.push(2);
    s2.push(1);

    printList_linked(s2);

    s2.pop();
    printList_linked(s2);
    cout << "Top: " <<  s2.Top() << endl;



    cout << '\n';
    return 0;
	
}
```

---
