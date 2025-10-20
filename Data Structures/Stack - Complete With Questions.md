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
