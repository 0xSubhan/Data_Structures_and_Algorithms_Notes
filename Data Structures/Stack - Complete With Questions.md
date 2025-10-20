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
