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
# Stack Applications: Reversing Strings and Linked Lists

## Reversing a String Using a Stack

A string, represented as a character array (e.g., "hello" in C-style with a null terminator), can be reversed using a stack. The process involves:

1. **Pushing characters onto the stack**: Traverse the string from left to right, pushing each character onto a stack of characters. For "hello", 'H' is pushed first, then 'E', 'L', 'L', and finally 'O'.
    
2. **Popping characters to overwrite the string**: Once all characters are pushed, start from the beginning of the string (index 0). Pop the topmost character from the stack and place it at the current index. Continue this until the stack is empty. Since stacks operate on a Last-In, First-Out (LIFO) principle, characters are retrieved in reverse order of their insertion.
    

### Code Example (C++)

The implementation in C++ involves creating a character array for the string. The user inputs a string, which is then passed to a `reverse` function along with its length. This `reverse` function utilizes the `std::stack` from the C++ Standard Template Library (STL).

```cpp
// Include stack header
#include <stack>

// Function signature for reverse
void reverse(char* C, int n) {
    std::stack<char> S; // Create a stack of characters

    // Push characters onto stack
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }

    // Pop characters to reverse the string
    for (int i = 0; i < n; i++) {
        C[i] = S.top(); // Get top element
        S.pop();        // Pop top element
    }
}

// Main function would handle user input, call reverse, and print
// Example: char str[50]; printf("Enter a string: "); gets(str);
// reverse(str, strlen(str)); printf("Reversed string: %s\n", str);
```

### Efficiency Analysis

- **Time Complexity**: All stack operations (push, pop, top) take constant time, O(1). Both the pushing and popping loops run `n` times (where `n` is the string length). Since these loops are sequential, the total time complexity is O(n) + O(n) = O(n).
    
- **Space Complexity**: An auxiliary stack is used to store all `n` characters of the string. Therefore, the space complexity is O(n).
    

### Alternative: Efficient String Reversal (Without Extra Space)

A more space-efficient approach for string reversal uses two pointers, `i` (start) and `j` (end). While `i` is less than `j`, swap the characters at `C[i]` and `C[j]`, then increment `i` and decrement `j`. This method has a space complexity of O(1) as it uses a constant amount of extra memory.

## Reversing a Linked List Using a Stack

Unlike arrays, linked list nodes are stored at disjoint memory locations, making direct access or two-pointer swapping difficult. Stacks provide a clear method for reversing linked lists.

### Challenges with Linked Lists

- Direct indexing like arrays is not possible.
    
- Previous reversal methods (iterative and recursive) have been discussed in this series.
    
    - Iterative: O(n) time, O(1) space.
        
    - Recursive: O(n) time, O(n) space (due to implicit call stack).
        

### Explicit Stack Method for Linked List Reversal

This method uses an explicit stack of pointers to nodes (or node references):

1. **Pushing node addresses onto the stack**: Traverse the linked list from the head. For each node, push its address (or a pointer to it) onto the stack. If nodes are at addresses 100, 150, 250, 300, these addresses would be pushed in that order.
    
2. **Rebuilding links by popping**: Once all node addresses are on the stack, the head of the linked list is set to the address of the node at the top of the stack (which was the last node in the original list). Then, in a loop:
    
    - Take the address from the top of the stack.
        
    - Set the `next` pointer of the current node (initially the new head) to this popped address.
        
    - Move to the newly linked node.
        
    - Pop the stack.
        
3. **Terminating the list**: After the loop, the `next` pointer of the last node (which was the first node in the original list) is set to `null`.
    

### Code Logic (Conceptual C++)

Assuming `head` is a global `Node*` and `Node` has a `data` and `next` field:

```cpp
// Assuming Node structure and global Node* head

void reverseLinkedListWithStack() {
    if (head == nullptr) return; // Handle empty list

    std::stack<Node*> S; // Stack to store node pointers
    Node* temp = head;

    // Push all node pointers onto the stack
    while (temp != nullptr) {
        S.push(temp);
        temp = temp->next;
    }

    // Reconstruct the linked list
    head = S.top(); // New head is the last node pushed
    S.pop();
    temp = head;

    while (!S.empty()) {
        temp->next = S.top(); // Link current node to the next one in reverse order
        S.pop();
        temp = temp->next; // Move to the newly linked node
    }
    temp->next = nullptr; // The last node (original first) now points to null
}
```

### Efficiency Analysis

- **Time Complexity**: Traversing the list to push nodes is O(n). Traversing the stack to rebuild links is also O(n). Total time complexity is O(n).
    
- **Space Complexity**: The stack stores `n` node pointers. Thus, the space complexity is O(n).
    

## Conclusion

While a stack might not be the most space-efficient for string reversal, it simplifies the logic significantly for problems like linked list reversal and printing elements in reverse order. Understanding both explicit and implicit stack usage (as seen in recursion) is crucial for efficient programming.

## My Code 

```cpp
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
            return -1;
        }
        
        return top->data;
    } 
    // Return Head Node:
    Node*& getHead()
    {
        return top;
    }
    //
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
// Reverse String using stack:
void Reverse_string(char* str,int n)
{
    stack<char> stk;

    for (size_t i = 0; i < n; i++)
    {
        stk.push(str[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        str[i] = stk.top();
        stk.pop();
    }    
}
void getName(char* str)
{
    cout << "Enter Name: " ; cin >> str;
}
// Reversing Linked List using stack:
void Reverse_list_UsingStack(Node*& head)
{
    if(head == nullptr) return;
    stack<Node*> coll;
    Node* temp = head;

    while (temp != nullptr)
    {
        coll.push(temp);
        temp = temp->link;
    }
    temp = coll.top(); head = temp;
    coll.pop();
    while (!coll.empty())
    {
        temp->link = coll.top();
        coll.pop();
        temp = temp->link;
    }
    temp->link = nullptr;
    
}
int main()
{
    // Reversing C style string using stack:
    char str[51];
    getName(str);
    Reverse_string(str,strlen(str));

    for (size_t i = 0; i < strlen(str); i++)
    {
        cout << str[i];{}
    }
    
    // Reversing Linked list using stack:
    cout << "\nCurrent List: "; printList_linked(s2); // current List
    Reverse_list_UsingStack(s2.getHead());
    printList_linked(s2);
    

    cout << '\n';
    return 0;

}
```

```cpp
// Reversing a doubly linked list using a stack:
    struct NodeD
    {
        int data;
        NodeD* prev;
        NodeD* next;

        NodeD(int val)
            : data {val}
            , prev {nullptr}
            , next {nullptr}
        {
        }        
    };

void Reverse_listDoubly(NodeD*& head)
{
    if(head == nullptr) return;
    stack<NodeD*> s;
    NodeD* temp = head;
    
    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->next; 
    }
    // Setting last node as head:
    head = s.top();
    s.pop();
    temp = head;
    // Handling case for other nodes:
    while (!s.empty())
    {
        temp->next = s.top();
        s.top()->prev = temp;
        temp = temp->next;
        s.pop();
    }
    temp->next = nullptr;    
}
```

---
# Solving the Balanced Parentheses Problem with a Stack

## Problem Description

This lesson discusses a common programming interview question: checking for balanced parentheses in an expression. The expression is a string comprising constants, variables, operators, and various types of parentheses, including curly braces `{}` and square brackets `[]`.

### Properties of Balanced Parentheses

1. **Correct Nesting:** A closing parenthesis must correspond to a previously opened parenthesis of the same type.
    
2. **Order of Closure:** A parenthesis can only close if all parentheses opened _after_ it have already been closed. Essentially, "anything that is opened last should be closed first" within its nested scope.
    
3. **Last Unclosed Principle:** As the expression is scanned from left to right, any closer must correspond to the _last unclosed_ opening parenthesis.
    

## Solution Approach Using a Stack

To solve this problem, we can use a stack data structure, which enforces a "last-in, first-out" (LIFO) behavior. This aligns perfectly with the "last unclosed first closed" principle of balanced parentheses.

### Algorithm Steps:

1. **Initialize an empty stack:** This stack will keep track of all opened but not yet closed parentheses.
    
2. **Scan the expression from left to right:** Process each character in the string.
    
    - **If an opening symbol is encountered** (e.g., `(`, `{`, `[`):
        
        - Push it onto the stack.
            
    - **If a closing symbol is encountered** (e.g., `)`, `}`, `]`):
        
        - **Check for an empty stack:** If the stack is empty, it means there's no corresponding opening parenthesis for the current closing symbol. The expression is unbalanced, so return `false`.
            
        - **Check the top of the stack:** Compare the current closing symbol with the top element of the stack. If they form a matching pair (e.g., `)` matches `(`, `}` matches `{`, `]` matches `[`):
            
            - Pop the top element from the stack (as it has found its counterpart).
                
        - **If no match:** If the top of the stack does not match the closing symbol (e.g., a `)` tries to close a `{` or `[`), the expression is unbalanced. Return `false`.
            
3. **After scanning the entire expression:**
    
    - **Check if the stack is empty:** If the stack is empty, it means every opening parenthesis found its corresponding closing counterpart, and the expression is balanced. Return `true`.
        
    - **If the stack is not empty:** It means there are unclosed opening parentheses, and the expression is unbalanced. Return `false`.
        

## Pseudocode Example

```pseudocode
function checkBalancedParenthesis(expression):
  // Store the number of characters in the string
  num_chars = length(expression)

  // Create an empty stack of characters
  stack = new Stack()

  // Scan the expression from left to right
  for i from 0 to num_chars - 1:
    char = expression[i]

    // If it's an opening symbol
    if char is '(', '{', or '[':
      stack.push(char)
    // If it's a closing symbol
    else if char is ')', '}', or ']':
      // Scenario 1: Stack is empty (no opening counterpart)
      if stack.isEmpty():
        return false

      // Scenario 2: Top of stack doesn't pair with closing symbol
      top_char = stack.top()
      if (char == ')' and top_char != '(') or \
         (char == '}' and top_char != '{') or \
         (char == ']' and top_char != '['):
        return false

      // Scenario 3: Match found, pop from stack
      else:
        stack.pop()

  // After scanning, check if the stack is empty
  if stack.isEmpty():
    return true // All parentheses balanced
  else:
    return false // Unbalanced parentheses
```

## Example Walkthroughs

### Example 1: `)` (Unbalanced - Closing without opening)

1. Scan `)`. Stack is empty.
    
2. Encounter `)`. Stack is empty, so `return false`.
    

### Example 2: `[{)]` (Unbalanced - Mismatched pair)

1. Scan `[`. Push `[` onto stack. Stack: `[`
    
2. Scan `{`. Push `{` onto stack. Stack: `[`, `{`
    
3. Scan `(`. Push `(` onto stack. Stack: `[`, `{`, `(`
    
4. Scan `]`. Top of stack is `(`. `]` does not pair with `(`. `return false`.
    

### Example 3: `({()})` (Balanced)

1. Scan `(`. Push `(`. Stack: `(`
    
2. Scan `{`. Push `{`. Stack: `(`, `{`
    
3. Scan `(`. Push `(`. Stack: `(`, `{`, `(`
    
4. Scan `)`. Top of stack is `(`. They pair. Pop `(`. Stack: `(`, `{`
    
5. Scan `)`. Top of stack is `{`. They don't pair. Oh, wait, in the audio, this example was `({()})`. Let's re-evaluate.
    
    - Scan `(`. Push `(`. Stack: `(`
        
    - Scan `{`. Push `{`. Stack: `(`, `{`
        
    - Scan `(`. Push `(`. Stack: `(`, `{`, `(`
        
    - Scan `)`. Top of stack is `(`. Pairs. Pop `(`. Stack: `(`, `{`
        
    - Scan `}`. Top of stack is `{`. Pairs. Pop `{`. Stack: `(`
        
    - Scan `)`. Top of stack is `(`. Pairs. Pop `(`. Stack: `[]` (empty)
        
6. End of expression. Stack is empty. `return true`.

### My code (Implementation)

```cpp
// Solving the Balanced Parentheses Problem with a Stack:
bool pseudocodecheckBalancedParenthesis(string& expr)
{
    stack<char> s;
    
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[')
        {
            s.push(expr[i]);
        }
        else if(expr[i] == '}' || expr[i] == ']' || expr[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }

            // Checking for corresponding:
            if (expr[i] == ')' && s.top() == '(' || expr[i] == '}' && s.top() == '{' || expr[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else
                return false; // meaning it is unbalanced!
            
        }
    }
    return s.empty();    
}
int main()
{
    // pseudocodecheckBalancedParenthesis Implementation:
    string expr = "{[()]}";

    if (pseudocodecheckBalancedParenthesis(expr))
    {
        cout << "\nExpression is balanced!" << endl;
    }
    else
        cout << "\nExpression is not balanced!" << endl;
    

    cout << '\n';
    return 0;

}
```

---
# Infix , prefix and postfix

## Introduction to Expression Evaluation

This lesson introduces the important computer science topic of evaluating arithmetic and logical expressions, focusing on how expressions are written and processed. Expressions typically consist of constants, variables, operators, and parentheses, arranged according to specific grammatical rules.

## Infix Notation

Most commonly, expressions are written in _infix notation_, where an operator is placed between two operands. An operand can be a constant, a variable, or even another expression. For example, in "2 + 3", 2 and 3 are operands and '+' is the operator. Similarly, in "(P + Q) * (R + S)", both (P+Q) and (R+S) are operands for the multiplication operator.

Throughout this lesson, the focus will be on _binary operators_, which require exactly two operands.

### Rules for Evaluating Infix Expressions

Evaluating infix expressions, especially those with multiple operators and no parentheses, requires specific rules to resolve ambiguity. Consider the expression "4 + 6 * 2":

- If addition is performed first, the result is (4 + 6) * 2 = 20.
    
- If multiplication is performed first, the result is 4 + (6 * 2) = 16.
    

To resolve such ambiguities, _operator precedence rules_ are followed, similar to those in high school mathematics (PEMDAS/BODMAS):

1. **Parentheses/Brackets**: Highest precedence.
    
2. **Exponents**: Applied from right to left (right-associative).
    
    - Example: `2^3^2` is `2^(3^2)` = `2^9` = `512`.
        
3. **Multiplication and Division**: Applied from left to right (left-associative).
    
4. **Addition and Subtraction**: Applied from left to right (left-associative).
    

_Operator associativity_ determines the order of operations for operators with equal precedence (e.g., left-to-right for multiplication/division and addition/subtraction, right-to-left for exponents).

Parentheses are crucial in infix notation because they explicitly dictate the order of operations, overriding default precedence and associativity, and improving readability.

## Limitations of Infix Notation

Despite its common use and human readability, infix notation can be challenging for machines to parse and evaluate unambiguously without complex rules like operator precedence and associativity. This complexity led to the development of alternative notations.

## Prefix Notation (Polish Notation)

Proposed by a Polish logician in 1924, _prefix notation_ (or Polish notation) places the operator _before_ its operands. This notation is parenthesis-free and eliminates ambiguity related to operator precedence and associativity.

- Infix: `2 + 3` -> Prefix: `+ 2 3`
    
- Infix: `P - Q` -> Prefix: `- P Q`
    
- Infix: `A + B * C` -> Prefix: `+ A * B C`
    

In prefix notation, an operand can be a constant, a variable, or another prefix expression. The key advantage is that each operand is unambiguously associated with only one operator, simplifying parsing.

## Postfix Notation (Reverse Polish Notation)

_Postfix notation_ (or Reverse Polish Notation), developed in the 1950s by computer scientists, places the operator _after_ its operands. This syntax is highly favored for machine computation due to its straightforward parsing and evaluation, requiring minimal time and memory.

- Infix: `2 + 3` -> Postfix: `2 3 +` (operands can be separated by spaces or delimiters)
    
- Infix: `P - Q` -> Postfix: `P Q -`
    
- Infix: `A + B * C` -> Postfix: `A B C * +`
    

Similar to prefix notation, postfix expressions are parenthesis-free and avoid the ambiguities of infix notation. Operands can be constants, variables, or other postfix expressions.

## Manual Conversion from Infix to Prefix/Postfix

To convert an infix expression to prefix or postfix manually, one must follow the order of operations (precedence and associativity) as if evaluating the expression, converting the innermost or highest-precedence operations first. Temporary parentheses can be used to visualize the order of conversion.

**Example: Infix** `A + B * C` **to Prefix**

1. Prioritize `B * C`: `A + (* B C)`
    
2. Prioritize `A + (...)`: `+ A (* B C)` -> Result: `+ A * B C`
    

**Example: Infix** `A + B * C` **to Postfix**

1. Prioritize `B * C`: `A + (B C *)`
    
2. Prioritize `A + (...)`: `A (B C *) +` -> Result: `A B C * +`
    

While parentheses enhance human readability in infix expressions, they are unnecessary for prefix and postfix notations, making them more memory-efficient for machines.

## Conclusion

Infix, prefix, and postfix notations offer different ways to represent expressions. While infix is common for human interaction, prefix and postfix notations are more efficient and unambiguous for computational evaluation, especially with the use of stack data structures. The next lesson will cover the evaluation of prefix and postfix notations.

## why prefix or postfix notation is used instead of infix in cs

### 🧩 1. The Problem with Infix Notation

In **infix notation**, the operator is written **between** operands — like in normal math:

```css
A + B * C
```

But here, **ambiguity arises** — should you do addition first or multiplication first?  
Humans rely on **operator precedence** and **parentheses** to understand the order:

```css
A + (B * C)
```

Computers, however, do **not naturally understand precedence** or parentheses without extra logic.  
So, parsing infix expressions requires:

- Handling **operator precedence** (`*` > `+`)
    
- Handling **associativity** (`a - b - c` means `(a - b) - c`)
    
- Handling **parentheses**
    

This makes **compilers and interpreters** more complex.

### ⚙️ 2. Why Prefix and Postfix Are Better

In **prefix** (Polish) and **postfix** (Reverse Polish) notation,  
the order of operations is **encoded directly by the position of operators**,  
so **no parentheses or precedence rules** are needed.

#### Example

Expression:

```css
A + B * C
```

|Form|Notation|Evaluation Order|
|---|---|---|
|Infix|`A + B * C`|ambiguous (need rules)|
|Prefix|`+ A * B C`|do `* B C` first, then `+ A`|
|Postfix|`A B C * +`|do `B C *` first, then `A +`|

Thus, **prefix/postfix** eliminates ambiguity entirely.

### 💡 3. Advantages for Computers

✅ **No need for parentheses** — structure is implicit  
✅ **Easier parsing** — can be processed with simple stacks  
✅ **Efficient evaluation** — especially for interpreters and compilers

For example, postfix (Reverse Polish Notation) can be evaluated using a **stack**:

1. Read tokens left to right.
    
2. Push operands on stack.
    
3. When operator appears, pop operands, apply operation, and push result back.

### 🔢 4. Example of Postfix Evaluation

Infix:

```css
(3 + 4) * 5
```

Postfix:

```css
3 4 + 5 *
```

Evaluation using stack:

|Step|Stack|Action|
|---|---|---|
|Read 3|[3]|push 3|
|Read 4|[3, 4]|push 4|
|Read +|[7]|pop 3, 4 → 3+4=7|
|Read 5|[7, 5]|push 5|
|Read *|[35]|pop 7, 5 → 7*5=35|

Result = **35**

### 🧠 5. In Practice

- **Compilers** internally convert infix expressions into **postfix** or **prefix** form before evaluation or code generation.
    
- **Stack-based architectures** (like the Java Virtual Machine) use postfix-style evaluation.
    
- **Expression trees** in compilers or interpreters also naturally align with prefix/postfix traversal.

### 🏁 Summary

|Aspect|Infix|Prefix/Postfix|
|---|---|---|
|Human readability|High|Low|
|Computer readability|Complex|Easy|
|Needs parentheses|Yes|No|
|Parsing difficulty|High|Low|
|Evaluation mechanism|Requires precedence rules|Simple stack-based|

---
# Evaluating Prefix and Postfix Expressions

## Introduction to Prefix and Postfix Evaluation

This lesson focuses on evaluating prefix and postfix expressions. While both evaluation algorithms are similar, postfix evaluation is discussed first due to its easier understanding and implementation. The lesson then proceeds to explain prefix evaluation. The main tool for these evaluations is a stack.

## Postfix Expression Evaluation

### Manual Evaluation of Postfix Expressions

To manually evaluate a postfix expression, scan it from left to right. Identify the first occurrence of an `operand, operand, operator` pattern. Apply the operator to the two preceding operands and reduce the expression. Repeat this process until all operators are resolved, and the expression is reduced to a single value.

### Programmatic Evaluation of Postfix Expressions using a Stack

When evaluating postfix expressions programmatically (e.g., from a string where operands and operators are space-separated), a stack data structure is highly efficient. The process involves a single pass through the expression:

1. **Scan from left to right:** Process each token (operand or operator).
    
2. **If a token is an operand:** Push it onto the stack.
    
3. **If a token is an operator:**
    
    - Pop the top two elements from the stack. The first popped element is the second operand (`OP2`), and the second popped element is the first operand (`OP1`).
        
    - Perform the operation (e.g., `OP1 operator OP2`).
        
    - Push the result back onto the stack.
        
4. **Final Result:** After scanning the entire expression, the single remaining element on the stack is the final result.
    

This method leverages the Last-In, First-Out (LIFO) nature of a stack, which naturally handles the order of operations in postfix notation.

## Prefix Expression Evaluation

### Manual Evaluation of Prefix Expressions

Similar to postfix, prefix expressions can be evaluated manually. The key difference is scanning the expression from right to left.

### Programmatic Evaluation of Prefix Expressions using a Stack

Evaluating prefix expressions programmatically also uses a stack, but with a reversed scanning direction and operand order:

1. **Scan from right to left:** Process each token.
    
2. **If a token is an operand:** Push it onto the stack.
    
3. **If a token is an operator:**
    
    - Pop the top two elements from the stack. This time, the first popped element is the first operand (`OP1`), and the second popped element is the second operand (`OP2`). This order is crucial, especially for non-commutative operations like subtraction or division.
        
    - Perform the operation (e.g., `OP1 operator OP2`).
        
    - Push the result back onto the stack.
        
4. **Final Result:** The single element remaining on the stack after processing is the final answer.

>Computers find **infix notation hard to evaluate** directly because they need to keep track of **operator precedence** (like `*` before `+`) and **parentheses**.

**Prefix and Postfix** eliminate these ambiguities —  
no parentheses are needed, and order of operations is **completely determined by position**.

## 💡 Evaluating Postfix Expressions

Now suppose:

```cpp
A=2, B=3, C=5, D=4, E=9
```

Then postfix becomes:

```cpp
2 3 * 5 4 * + 9 -
```

### Algorithm (Step-by-step manual method)

1. **Scan from left → right**
    
2. When you see an **operand (number)** → **push it** onto a stack.
    
3. When you see an **operator** → **pop two operands**, perform the operation, then **push the result** back.

### Example Walkthrough

|Step|Symbol|Action|Stack (top at right)|
|---|---|---|---|
|1|`2`|Operand → push|`[2]`|
|2|`3`|Operand → push|`[2, 3]`|
|3|`*`|Pop 3,2 → 2×3=6 → push 6|`[6]`|
|4|`5`|Operand → push|`[6, 5]`|
|5|`4`|Operand → push|`[6, 5, 4]`|
|6|`*`|Pop 4,5 → 5×4=20 → push 20|`[6, 20]`|
|7|`+`|Pop 20,6 → 6+20=26 → push 26|`[26]`|
|8|`9`|Operand → push|`[26, 9]`|
|9|`-`|Pop 9,26 → 26−9=17 → push 17|`[17]`|

✅ **Final Answer:** `17`

### 🧠 Why the Stack Works

- The **stack** stores the most recent operands.
    
- When an operator appears, it’s always applied to the **two most recent operands**.
    
- That’s why the **Last In, First Out (LIFO)** behavior fits perfectly.

## 🧰 Pseudocode for Postfix Evaluation

```cpp
function evaluatePostfix(expression):
    create empty stack S

    for each token in expression:
        if token is operand:
            S.push(token)
        else if token is operator:
            op2 = S.pop()
            op1 = S.pop()
            result = applyOperator(op1, op2, token)
            S.push(result)

    return S.top()  // final answer
```

### My Code

```cpp
// Using stack to evaulate postfix expression:
int evaluatePostfix(const string& expr)
{
    stack<int> s;

    for(char ch : expr)
    {
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            int tempConverter = ch - '0';
            s.push(tempConverter);
        }
        else
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top(); 
            s.pop();

            int result = 0;
            switch (ch)
            {
            case '+':
                s.push(result = operand1+operand2);
                break;
            case '-':
                s.push(result = operand1-operand2);
                break;
            case '*':
                s.push(result = operand1*operand2);
                break;
            case '/':
                s.push(result = operand1/operand2);
                break;            
            }
        }
        
    } 
    return s.top();
} 
// Using stack to evaulate prefix expression:
int evaluatePrefix(const string& expr)
{
    stack<int> s;

    for(int i = static_cast<int>(expr.length()-1); i >= 0; i--)
    {
        char ch = expr[i]; 
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            int tempConverter = ch - '0';
            s.push(tempConverter);
        }
        else
        {
            int operand1 = s.top(); 
            s.pop();
            int operand2 = s.top();
            s.pop();

            int result = 0;
            switch (ch)
            {
            case '+':
                s.push(result = operand1+operand2);
                break;
            case '-':
                s.push(result = operand1-operand2);
                break;
            case '*':
                s.push(result = operand1*operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    cerr << "Error: division by zero in prefix expression\n";
                    return 0;
                }            
                s.push(result = operand1/operand2);
                break;            
            }
        }
        
    } 
    return s.top();
} 
```

---
# Infix to Postfix


## 🧩 What Is Infix, Postfix, and Why Convert?

- **Infix notation:** Operators are written _between_ operands — e.g.,  
    `A + B * C`
    
- **Postfix notation (Reverse Polish Notation):** Operators come _after_ operands — e.g.,  
    `A B C * +`
    

Computers find **postfix** much easier to evaluate because **no parentheses** or **operator precedence rules** are needed at runtime.  
The evaluation can be done **strictly left to right** using a stack.

## ⚙️ Manual Conversion Intuition

Let’s understand this using the example:

```cpp
A + (B * C)
```

1. The inner expression `(B * C)` becomes → `B C *`
    
2. Replace the inner expression back: `A + (B C *)`
    
3. Now place `+` after its operands: `A B C * +`
    

✅ **Result:** `A B C * +`

This is what you’d do manually using your knowledge of **operator precedence** (`*` before `+`) and **associativity** (left to right for most operators).

But this becomes tedious when dealing with expressions like:  
`A + B * (C ^ D - E) ^ (F + G * H) - I`

That’s why we need a **systematic algorithm**.

## ⚡ Efficient Algorithm: One Left-to-Right Pass

The algorithm scans the infix expression **once**, using a **stack** to handle operators.

### Key Observation:

- **Operands** keep their order (e.g., `A`, `B`, `C` stay `A`, `B`, `C`).
    
- Only **operators** move around depending on their precedence and parentheses.
    

So we can safely append operands directly to the output (postfix) as we read them.

## 🧱 Using a Stack: Why and How

The **stack** temporarily holds operators (and parentheses).

Let’s break down how tokens (characters) are processed:

### 1️⃣ If token is an **operand** (`A`, `B`, `C`):

➡️ Directly add it to the postfix string.  
Because operands’ order never changes.

Example:

```cpp
Input: A
Postfix: A
```

### 2️⃣ If token is an **operator** (`+`, `-`, `*`, `/`, `^`):

You **cannot** append it directly yet — because you might still see its **right operand** later.

Instead:

- Compare its **precedence** with the **top of the stack**.
    
- Use the rules below.
    

#### Operator Precedence:

|Operator|Precedence|Associativity|
|---|---|---|
|`^` (power)|highest|right-to-left|
|`*`, `/`|medium|left-to-right|
|`+`, `-`|lowest|left-to-right|

#### Rules:

- If stack top has **higher or equal precedence** (and same associativity), pop it and append it to the postfix.
    
- Then push the current operator.
    

This ensures that operators are placed in postfix order based on their execution priority.

### 3️⃣ **Parentheses Handling**

Parentheses change the natural precedence of operators, so special handling is needed.

#### (a) If token is `(`:

Push it onto the stack.  
It marks a **boundary** — operators before this should not interfere with operators inside.

#### (b) If token is `)`:

Pop operators and append to postfix **until** an opening parenthesis `(` is found.  
Then pop and discard that `(`.

This ensures that subexpressions inside parentheses are processed as one independent group.

## 🧮 Example: `A + B * C - D`

Let’s go step by step:

|Token|Action|Stack|Postfix|
|---|---|---|---|
|`A`|Operand → append|—|`A`|
|`+`|Stack empty → push `+`|`+`|`A`|
|`B`|Operand → append|`+`|`A B`|
|`*`|`*` has **higher** precedence than `+` → push `*`|`+, *`|`A B`|
|`C`|Operand → append|`+, *`|`A B C`|
|`-`|`-` has **lower** precedence than `*`, so pop `*` → postfix: `A B C *`  <br>Then `-` has **equal** precedence as `+`, pop `+` → postfix: `A B C * +`  <br>Push `-`|`-`|`A B C * +`|
|`D`|Operand → append|`-`|`A B C * + D`|

Now end of expression:  
Pop remaining operators → `A B C * + D -`

✅ **Final Postfix:** `A B C * + D -`

## 🧠 Algorithm Behavior Summary

This algorithm effectively:

- **Preserves operand order**
    
- **Reorders operators** using the stack
    
- **Respects parentheses and precedence**

## 🧰 Full Algorithm (Pseudocode)

```cpp
function infixToPostfix(expression):
    stack S
    string result = ""

    for each char in expression:
        if isOperand(char):
            result += char

        else if char == '(':
            S.push(char)

        else if char == ')':
            while S.top() != '(':
                result += S.top()
                S.pop()
            S.pop()  # remove '('

        else if isOperator(char):
            while S not empty and S.top() != '(' and hasHigherPrecedence(S.top(), char):
                result += S.top()
                S.pop()
            S.push(char)

    # After scanning all characters
    while S not empty:
        result += S.top()
        S.pop()

    return result
```

### Helper Functions:

- `isOperand(ch)` → checks if ch is A-Z, a-z, 0-9
    
- `isOperator(ch)` → checks if ch is `+`, `-`, `*`, `/`, `^`
    
- `hasHigherPrecedence(op1, op2)` → compares their precedence
    
- Associativity rules:
    
    - Left-to-right: pop when equal or higher precedence (`+ - * /`)
        
    - Right-to-left: pop only when higher precedence (`^`)

## 🧾 Example Walkthrough with Parentheses

Expression:

```
(A + B) * C
```

|Token|Action|Stack|Postfix|
|---|---|---|---|
|`(`|push|`(`||
|`A`|operand → append|`(`|`A`|
|`+`|push|`( +`|`A`|
|`B`|operand → append|`( +`|`A B`|
|`)`|pop until `(` → append `+`|(removed)|`A B +`|
|`*`|push|`*`|`A B +`|
|`C`|operand → append|`*`|`A B + C`|

Now pop remaining operators → `*`

✅ **Final Postfix:** `A B + C *`

## 🧩 Summary Table

|Infix|Postfix|Explanation|
|---|---|---|
|`A + B`|`A B +`|Simple addition|
|`A + B * C`|`A B C * +`|`*` has higher precedence|
|`(A + B) * C`|`A B + C *`|Parentheses first|
|`A + (B * C - D)`|`A B C * D - +`|Inner evaluated first|
## 🧠 Why It’s Efficient

- Only **one scan** over the infix expression.
    
- Stack ensures **O(n)** time complexity.
    
- No recursive parsing or re-evaluation required.

## 💭 The Core Problem

In infix expressions (like `A + B * C`),  
the **order of execution** depends on **operator precedence** and **associativity**.

- Precedence: `*` executes before `+`
    
- Associativity: If two operators have the same precedence, we execute **left-to-right** (for `+`, `-`, `*`, `/`)  
    or **right-to-left** (for `^`).
    

But in postfix, the **order of operators in the expression directly defines** the order of execution.  
So, we must ensure operators appear in postfix **in the same order they would be executed** in infix.

## ⚙️ What the Stack Represents

When we convert infix → postfix, the **stack** temporarily holds operators we haven’t placed yet.

The **stack top** always holds the **most recent unprocessed operator**.  
Before pushing a new operator, we must check if any operator **already waiting on the stack** should go **before** the new one in postfix order.

That’s why we compare **precedence** and **associativity**.

## 🔍 Let’s Understand with an Example

### Example 1: `A + B * C`

|Step|Token|Stack|Postfix|Explanation|
|---|---|---|---|---|
|1|`A`|—|`A`|Operand → append|
|2|`+`|`+`|`A`|Stack empty → push `+`|
|3|`B`|`+`|`A B`|Operand → append|
|4|`*`|`+, *`|`A B`|Check: `*` (current) has **higher precedence** than `+` (top), so keep `+` — push `*`|
|5|`C`|`+, *`|`A B C`|Operand → append|

End of expression → pop all →  
`A B C * +`

✅ Correct postfix.

**Logic:**  
We did _not_ pop `+` because `*` should execute before `+`.  
`*` had **higher precedence**, so we allowed it to go on top.

### Example 2: `A * B + C`

|Step|Token|Stack|Postfix|Explanation|
|---|---|---|---|---|
|1|`A`|—|`A`|Operand|
|2|`*`|`*`|`A`|Push `*`|
|3|`B`|`*`|`A B`|Operand|
|4|`+`|`*` → (pop) → push `+`|`A B *`|When `+` comes, stack top `*` has **higher precedence**, so we **pop it first** before pushing `+`|
|5|`C`|`+`|`A B * C`|Operand|
|6|end|—|`A B * C +`|Pop remaining|

✅ Correct postfix.

**Logic:**  
When `+` arrived, `*` was waiting in stack.  
Since `*` must execute **before** `+`, it should appear **first** in postfix.  
So we pop it and append it before pushing `+`.

This is what that rule enforces:

> “If stack top has higher (or equal, for left-associative) precedence → pop it.”

## ⚖️ Equal Precedence Case (Associativity)

Now let’s see why “**equal precedence and same associativity**” matters.

### Example 3: `A - B + C`

Both `-` and `+` have **equal precedence** and **left-to-right** associativity.

|Step|Token|Stack|Postfix|Explanation|
|---|---|---|---|---|
|1|`A`|—|`A`|Operand|
|2|`-`|`-`|`A`|Push `-`|
|3|`B`|`-`|`A B`|Operand|
|4|`+`|`-` → pop → push `+`|`A B -`|Since `+` and `-` have equal precedence **and left associativity**, we pop the earlier one before pushing the new one|
|5|`C`|`+`|`A B - C`|Operand|
|end|—|—|`A B - C +`|Pop remaining|

✅ Correct postfix.

**Why pop?**  
Because in infix, when two same-precedence operators appear,  
the one **on the left executes first** (left-associative).  
Popping the earlier operator ensures it appears first in postfix.

### Example 4: Right-Associative Operator `^`

Expression:  
`A ^ B ^ C`

Both `^` have **equal precedence**, but **right-to-left** associativity.

|Step|Token|Stack|Postfix|
|---|---|---|---|
|`A`|—|`A`||
|`^`|`^`|`A`||
|`B`|`^`|`A B`||
|`^`|(do **not** pop first `^`) push new `^`|`A B`||
|`C`|`^, ^`|`A B C`||

Then pop → `A B C ^ ^`

✅ Correct postfix.

**Logic:**  
For right-associative operators, we **don’t pop** when precedence is equal,  
because the operator on the **right** executes **first**.  
We only pop when the stack top has _higher_ precedence, not equal.

That’s why the rule says:

> “If stack top has higher or equal precedence **and same associativity**, pop it.”

## 🧠 In Summary

| Case                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | Stack Top  | Current Operator | Action                        | Reason |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------- | ----------------------------- | ------ |
| Higher precedence                                                                                                                                                                                                                                                                                                                                                                                                                                                                       | `*` vs `+` | pop              | `*` must execute before `+`   |        |
| Equal precedence (left-associative)                                                                                                                                                                                                                                                                                                                                                                                                                                                     | `+` vs `-` | pop              | left one executes first       |        |
| Equal precedence (right-associative)                                                                                                                                                                                                                                                                                                                                                                                                                                                    | `^` vs `^` | do **not** pop   | right one executes first      |        |
| ### 🧩 So the Logic Is:<br><br>When we see a new operator:<br><br>1. If there’s an operator already waiting on the stack that must execute **before** the current one (based on precedence or associativity),  <br>    → **pop it first** (append to postfix).<br>    <br>2. Then push the current operator.<br>    <br><br>That simple rule ensures the **final postfix expression represents the correct order of execution** for all possible operator combinations.Lower precedence | `+` vs `*` | don’t pop        | current has higher precedence |        |

## My Implmentation Code

```cpp
// Infix to postfix conversion algorithm:
bool isOperand(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' )
        return true;
    else 
        return false;    
} 
bool isOperator(char ch)
{
    if (ch != '+' &&ch != '-' &&ch != '*' &&ch != '/'&&ch != '^')
    {
        return false;
    }
    else
        return true;
}
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // for non-operators
}

bool hasHigherPrecedence(char top, char current)
{
    // Handle right-associativity of '^'
    if (top == '^' && current == '^')
        return false;

    return precedence(top) >= precedence(current);
}
string infixToPostfix(string& expr)
{
    string result = "";
    stack<char> s; 

    for(char ch : expr)
    {
        if (isOperand(ch))
            result += ch;
        else if(ch == '(')
            s.push(ch);
        else if(ch == ')')
        {
            while (s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }    
        else if(isOperator(ch))
        {
            while(!s.empty() && s.top() != '(' && hasHigherPrecedence(s.top(),ch))
            {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop(); 
    }
    return result;
} 
```


---
