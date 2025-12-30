# Introduction to trees

>This lesson introduces **tree data structures**, one of the most important and widely used non-linear data structures in computer science. Trees are used in countless applications, from file systems to searching, indexing, compilers, hierarchical data representation, and much more.

## **1. From Linear to Nonlinear Structures**

So far, earlier lessons likely covered **linear data structures**—such as:

- **Arrays**
    
- **Linked Lists**
    
- **Stacks**
    
- **Queues**
    

In these structures, data is arranged **sequentially**, meaning:

- There is a well-defined **start** and **end**.
    
- Each element has a **previous** and **next** element.
    
- Data flows linearly in one main direction.
    

Linear structures are good for specific kinds of problems but become inefficient for representing hierarchies or quickly searching large datasets.

## **2. Why Different Data Structures Exist**

Choosing the right data structure depends on:

### **a) Type of data being stored**

Some data is inherently hierarchical (e.g., family trees, organizational structures).

### **b) Cost of operations**

Different structures provide different costs for:

- Searching
    
- Inserting
    
- Deleting
    

If we need fast search, we might store data in sorted arrays to perform **binary search**, which is very efficient (O(log n)).

### **c) Memory consumption**

Linked lists use extra memory for pointers. Arrays may waste space. Trees may require extra pointer fields.

### **d) Ease of implementation**

Sometimes a simpler structure is used just because it’s easier to code, although this isn’t always ideal.

## **3. Introduction to Trees**

A **tree** is a **nonlinear**, **hierarchical** data structure.  
It is especially useful for representing hierarchical data.

### **Example: Organizational Hierarchy**

The lesson shows a company hierarchy:

- **John** is the CEO → root of the tree.
    
- John has two direct subordinates → Steve and Rama.
    
- Steve has three subordinates → Lee, Bob, Ella.
    
- Rama has two subordinates.
    
- Bob and others also have their own subtrees.
    

This hierarchical structure visually resembles an upside-down tree, with the **root at the top** and branches going downward.

Trees are perfect for representing such naturally hierarchical data.

```markdown
                     John (CEO)
                   /             \
            Steve                   Rama
         /    |     \            /      \
      Lee    Bob    Ella     Karan     Riya
                  /    \
             Tom        Sam
```

## **4. Tree Definition**

A **tree data structure** consists of:

- **Nodes** → entities containing data
    
- **Links/edges** → connections between nodes
    
- A hierarchical parent → child relationship
    

Trees are **not linear**, and they grow in multiple directions.

## **5. Important Tree Terminology**

### **Root**

- The topmost node in the tree.
    
- The only node without a parent.
    

### **Parent**

- A node that directly connects to child nodes.
    

### **Child**

- A node directly connected below a parent.
    

### **Siblings**

- Nodes with the **same parent**.
    

### **Leaf Node**

- A node with **no children**.
    

### **Internal Node**

- Any node that has **at least one child**.
    

### **Grandparent / Grandchild**

- Parent of parent → grandparent.
    
- Child of child → grandchild.
    

### **Ancestor / Descendant**

If you can move from Node A to Node B by following directed links:

- A is an **ancestor** of B.
    
- B is a **descendant** of A.
    

These relationships mimic real-life family trees.

### **Cousins**

Nodes that:

- Have different parents
    
- But share the same grandparent

## **6. Tree Properties**

### **Recursive Structure**

A tree is inherently **recursive**, meaning:

- A tree consists of a **root** and **subtrees**.
    
- Each subtree is itself a complete tree.
    
- This recursive nature helps in:
    
    - Tree traversal algorithms
        
    - Binary search tree operations
        
    - Balanced tree algorithms
        

### **Number of Edges (Links)**

A tree with **n nodes** always has **n - 1 edges** because:

- Every node except the root has exactly one incoming edge.

## **7. Depth and Height**

### **Depth of a Node**

- Number of edges from the **root** to that node.
    
- Root has depth **0**.
    
- Example:
    
    - Depth of node 5 may be 2 (requires 2 edges to reach it).
        

### **Height of a Node**

- Number of edges in the **longest path** from that node to a **leaf**.
    

Examples:

- Leaf nodes have height **0**.
    
- Height of root = height of entire tree.
    

### **Height of a Tree**

- Height of the **root node**.
    
- Measures how tall or deep the tree is.
    

Depth ≠ height.  
They measure different things.

## **8. Types of Trees**

Trees can be categorized based on their properties.

### **Binary Tree**

- Each node can have **at most two children**.
    
- These children are called:
    
    - **Left child**
        
    - **Right child**
        

Because binary trees are simple and uniform, they are the most commonly studied type of tree.

## **9. Implementing Trees in Memory**

### **Node Structure (for Binary Tree)**

Each node typically has:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

- `data` → stores information
    
- `left` → pointer to left subtree
    
- `right` → pointer to right subtree
    

For general trees (where a node can have many children), different structures like arrays of pointers or linked lists are used.

## **10. Applications of Trees in Computer Science**

Trees are extremely useful.

### **a) Storing Hierarchical Data**

Examples:

- File systems (folders inside folders)
    
- Organization charts
    
- Category structures
    

### **b) Fast Searching / Insertion / Deletion**

**Binary Search Trees (BST)** can search for data in O(log n) time if balanced.

### **c) Tries (Prefix Trees)**

Tries are special trees used for:

- Storing dictionaries
    
- Auto-complete
    
- Spell checking
    
- Prefix queries
    

They allow extremely fast lookup of words and string patterns.

# **Final Summary**

This lesson explains:

- Why trees are needed (linear structures are not enough)
    
- How trees represent hierarchical data
    
- Important tree terminology (root, child, leaf, siblings, ancestors…)
    
- Structural properties (recursive nature, number of edges)
    
- Depth and height of nodes
    
- Introduction to binary trees and tree implementation
    
- Major applications of trees (file systems, searching, tries)
    

This foundation prepares you for more advanced topics like:

- Binary Search Trees (BST)
    
- AVL Trees
    
- Heaps
    
- Tries
    
- Tree traversal algorithms (inorder, preorder, postorder)

---
# Binary Tree 

## 1. Recap: Tree Data Structure

In earlier lessons, a **tree** was introduced as a **non-linear hierarchical data structure** consisting of:

- **Nodes** (data elements)
    
- **Edges** (connections between nodes)
    

Trees are used to represent hierarchical relationships such as:

- File systems
    
- Organization charts
    
- Database indexing
    

## 2. Introduction to Binary Tree

A **binary tree** is a special type of tree with the following rule:

> **Each node can have at most two children**

These two children are called:

- **Left child**
    
- **Right child**
    

There is **no restriction** that a node must have two children—it can have:

- 0 children
    
- 1 child
    
- 2 children

## 3. Children in a Binary Tree

- If a node has **no children**, it is called a **leaf node**
    
- If a node has only one child:
    
    - The missing child is stored as **NULL** in memory
        
- If a node has both children:
    
    - Both left and right pointers are non-null
        

### Important Terms

- **Root node** → Topmost node
    
- **Leaf node** → Node with zero children
    
- **Internal node** → Node with at least one child

## 4. Valid Binary Trees

A binary tree can have **any shape**, as long as:

- No node has more than **two children**
    

Examples:

- A tree with **only one node**
    
- A skewed tree (like a linked list)
    
- A full-looking tree
    

All are valid binary trees.

## 5. Types of Binary Trees

### 5.1 Strict (Proper / Full) Binary Tree

A binary tree is called **strict** if:

- Every node has **either 0 or 2 children**
    
- No node has exactly **one child**
    

❌ Not strict → nodes with one child  
✅ Strict → all nodes have 0 or 2 children

### 5.2 Complete Binary Tree

A binary tree is **complete** if:

1. **All levels except the last are completely filled**
    
2. **Last level nodes are filled from left to right**
    

✔ Allowed: Missing nodes on the **right side only**  
❌ Not allowed: Empty space on the left before a node

#### ✅ Example of a Complete Binary Tree

```markdown
        1
      /   \
     2     3
    / \   /
   4   5 6
```

#### Why this tree is **COMPLETE**:

✔ All levels **except the last** are completely filled  
✔ Last level nodes are filled **from left to right**  
✔ Missing node (7) is on the **right side only**

#### A level is **completely filled** when:

> **All possible node positions at that level are occupied**

#### Maximum nodes at level `i`:

`2^i`

| Level | Max nodes | Filled means    |
| ----- | --------- | --------------- |
| 0     | 1         | 1 node present  |
| 1     | 2         | 2 nodes present |
| 2     | 4         | 4 nodes present |
| 3     | 8         | 8 nodes present |

#### What does

#### **“Last level nodes are filled from left to right”**

mean?

It means:

> **On the last (deepest) level of the tree, nodes must appear in order from the left side first, without leaving gaps.**

You are **not allowed** to:

- Skip a left position
    
- Put a node on the right **before** putting one on the left

#### Visual Explanation

##### ✅ Correct (Filled from Left to Right)

```markdown
        1
      /   \
     2     3
    / \   /
   4   5 6
```

🔹 Last level = `{4, 5, 6}`  
🔹 Nodes are placed **left → right**  
🔹 No gaps on the left

✔ This is a **complete binary tree**

##### ❌ Incorrect (Gap on the Left)

```markdown
        1
      /   \
     2     3
    /       \
   4         6
```

❌ Node `5` is missing  
❌ Node `6` appears **after a gap on the left**

🚫 This violates “left to right” rule  
🚫 NOT a complete binary tree

### 5.3 Perfect Binary Tree

A binary tree is **perfect** if:

- **All levels are completely filled**
    
- Every internal node has **two children**
    
- All leaf nodes are at the **same level**
    

➡ A perfect binary tree is **always complete**, but not vice versa.

## 6. Depth, Level, and Height

### Level

- Nodes at the same depth are on the same **level**
    
- Root is at **Level 0**
    

### Depth

- Depth of a node = number of edges from **root to that node**
    

### Height

Height of a tree is:

> **Number of edges in the longest path from root to a leaf**

Special cases:

- Height of **empty tree** = **-1**
    
- Height of tree with **one node** = **0**
    

## 7. Maximum Nodes at Each Level

At level `i`, maximum number of nodes =

`2^i`

|Level|Max Nodes|
|---|---|
|0|1|
|1|2|
|2|4|
|3|8|

This happens because **each node can have two children**.

## 8. Maximum Nodes in a Binary Tree

For a binary tree with height `h`:

`Max Nodes = 2^h+1 - 1`

Example:

- Height = 3
    
- Levels = 4
    
- Max nodes = 2^4 - 1 = 15
    

This is achieved **only in perfect binary trees**.

### 1️⃣ What does **“maximum nodes”** mean?

For a given **height `h`**, many different binary trees are possible.  
Some will have fewer nodes, some more.

👉 **Maximum nodes** means:

> **The greatest number of nodes a binary tree can have for that height.**

This happens when **every possible position is filled**.

###  2️⃣ Recall: Height and Levels

- **Height (h)** = number of edges in the longest path from root to a leaf
    
- **Number of levels** = `h + 1`
    

Example:

```cpp
Height = 3
Levels = 0, 1, 2, 3   → total = 4 levels
```

### 3️⃣ How many nodes can each level have?

In a binary tree:

|Level|Maximum Nodes|
|---|---|
|0|2⁰ = 1|
|1|2¹ = 2|
|2|2² = 4|
|3|2³ = 8|

Because:

> **Each node can have at most 2 children**

### 4️⃣ Add nodes from all levels

To get the **maximum number of nodes**, all levels must be full:

```
Max nodes = 2^0 + 2^1 + 2^2 + ----- + 2^h   
```

This is a **geometric series**, whose sum is:

```
Max Nodes = 2^h+1 - 1
```

### 5️⃣ Example: Height = 3

#### Step 1: Find levels

```
Levels = h + 1 = 3 + 1 = 4
```

#### Step 2: Apply formula

```
Max Nodes = 2^4 - 1 = 16 - 1 = 15 
```

### 6️⃣ Visual Example (Perfect Binary Tree)

```markdown
            ●          ← Level 0 (1)
          /   \
        ●       ●      ← Level 1 (2)
       / \     / \
      ●   ●   ●   ●    ← Level 2 (4)
     / \ / \ / \ / \
    ● ● ● ● ● ● ● ●   ← Level 3 (8)
```

#### Total nodes:

```Markdown
1+2+4+8 = 15
```

✔ All levels are completely filled  
✔ This gives **maximum possible nodes**

### 7️⃣ Why ONLY Perfect Binary Trees achieve this?

A **perfect binary tree**:

- Has **all levels completely filled**
    
- Has **no missing nodes**
    

If **even one node is missing**, total nodes become **less than max**.

#### ❌ Not Perfect → Fewer Nodes

```
        ●
      /   \
     ●     ●
    / \
   ●   ●
```

Height = 2  
Max possible = 7  
Actual nodes = 5 ❌

### 8️⃣ Key Result to Remember 
> **A binary tree with height `h` can have at most `2^(h+1) − 1` nodes, and this maximum is achieved only when the tree is a perfect binary tree.**

### Where does the **−1** come from?

#### Intuition (No Maths)

##### Imagine a perfect binary tree

```
Levels:  0   1   2   3
Nodes:   1 + 2 + 4 + 8 = 15
```

Now look at:

```
2^h+1  = 2^4 = 16
```

But the tree **does NOT have 16 nodes**  
Why?

➡ Because **we started counting from 1, not 0**  
➡ One node is always “extra” in `2^{h+1}`

==look it this way 2 power doesnt start from 0 which would have given us 1 but it starts from 1 so it give us 2 and now one node is extra !

So we subtract **1**:

```
16-1 = 15 
```

#### Another Simple Way to Think About It 🧠

##### Think of filling all slots

A perfect binary tree of height `h` has:

- `h + 1` levels
    
- Each level doubles the nodes
    

If you filled **one extra imaginary level**, you would have:

2h+12^{h+1}2h+1

But that last level **does not exist**, so we remove **1 node**.

### Tiny Memory Trick 💡

> **Binary trees double → totals overshoot by one → subtract 1**

## 9️⃣ Height in Terms of Number of Nodes

### A) Perfect Binary Tree

#### Key property of a perfect binary tree

- All levels are **completely filled**
    
- It has the **maximum number of nodes** for a given height
    

We already know:

```markdown
Max Nodes = 2^h+1 - 1
```

#### Deriving height from number of nodes

Let:

- `n` = number of nodes
    
- `h` = height

```
n = 2^h+1 - 1
```

Add 1 on both sides:

```
n + 1 = 2^h+1
```

Take log base 2:

```
Log2(n+1) = h + 1
```

So:

```
h = log2(n+1) - 1
```

#### Example

```
n = 15
h = log2(16) - 1 = 4 - 1 = 3
```

✔ This matches the tree:

- Levels = 4
    
- Height = 3
    

#### Why this works only for **perfect trees**

Because **every possible node position exists**.  
If even **one node is missing**, this formula is no longer exact.


### B) Complete Binary Tree

In a **complete binary tree**:

- All levels except the last are filled
    
- Last level is filled **from left to right**
    
- Node count is **close to perfect**, but may not be exact
    

So we use:

```
h = floor(log2n)
```

#### Why floor (⌊ ⌋)?

Because:

- Tree may not be fully filled
    
- Height must be an **integer**
    
- We take the **largest integer height possible**

#### Example

```
n = 13
log2(13) = 3.7
h = floor(3.7) = 3
```

✔ Correct height

#### 🔑 Quick Comparison

|Tree Type|Height Formula|
|---|---|
|Perfect|`log₂(n + 1) − 1`|
|Complete|`⌊log₂ n⌋`|

## 🔟 Why Height Matters (Time Complexity)

### Core Idea

> **Most tree operations move from root down to a leaf**

The **longer this path**, the **more time** it takes.

That path length = **height of tree**

### Common Tree Operations

- Searching
    
- Inserting
    
- Deleting
    

⏱ Time complexity depends on **height `h`**

`Time directly propotional to height`

### Best Case (Complete / Balanced Tree)

`O(logn)`

### Worst Case (Skewed Tree – like linked list)

`O(n)`

That’s why we try to **keep trees balanced**.

## 11. Balanced Binary Tree

A binary tree is **balanced** if:

> For every node:  
> **| height(left subtree) − height(right subtree) | ≤ 1**

- Most commonly, `k = 1`
    
- Balanced trees keep height **minimum**
    

Example:

- AVL Trees
    
- Red-Black Trees

```
        10
       /  \
      5    15
     / \   /
    3   7 12
```

### 1️⃣ Rule of a Balanced Binary Tree

A binary tree is **balanced** if **for every node**:

```
|height(left subtree) - height(right subtree)| <= 1
```

📌 Height = number of **edges** in the longest path to a leaf  
📌 Height of **empty tree = −1**

### 2️⃣ Start from the Leaf Nodes (Bottom-Up)

#### Leaf nodes: `3`, `7`, `12`

Each leaf:

```
   ●
```

- Left subtree = empty → height = −1
    
- Right subtree = empty → height = −1
    
- Difference = |−1 − (−1)| = **0** ✔
    

✔ Balanced at leaf nodes

### 3️⃣ Check Node `5`

```
      5
     / \
    3   7
```

- Height of left subtree (3) = **0**
    
- Height of right subtree (7) = **0**
    

Difference:

```
|0-0| = 0<= 1
```

✔ Node `5` is balanced  
Height of node `5` = `max(0, 0) + 1 = 1`

### 4️⃣ Check Node `15`

```
     15
    /
   12
```

Height of left subtree (12) = 0

Height of right subtree (empty) = −1

Difference:

```
|0-(-1)| = 1 <= 1
```

✔ Node `15` is balanced  
Height of node `15` = `max(0, -1) + 1 = 1`

### 5️⃣ Check Root Node `10`

```
        10
       /  \
      5    15
```

- Height of left subtree (rooted at 5) = **1**
    
- Height of right subtree (rooted at 15) = **1**
    

Difference:

```
|1-1| = 0<=1
```

✔ Root is balanced

### 6️⃣ Final Conclusion

|Node|Left Height|Right Height|Diff|Balanced?|
|---|---|---|---|---|
|3|−1|−1|0|✔|
|7|−1|−1|0|✔|
|12|−1|−1|0|✔|
|5|0|0|0|✔|
|15|0|−1|1|✔|
|10|1|1|0|✔|

## 12. Height Calculation Clarification

We **do NOT** count number of nodes in path.  
We count **number of edges**.

|Tree|Height|
|---|---|
|Empty tree|-1|
|Single node|0|
|4 nodes in path|3|
## 13. Storage of Binary Trees in Memory

### 13.1 Linked Representation (Most Common)

Each node stores:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

✔ Flexible
✔ Used for general binary trees

### 13.2 Array Representation (Special Case)

Used mainly for **complete binary trees** (like heaps).

#### Index Rules

For node at index `i`:

- Left child → `2i + 1`
    
- Right child → `2i + 2`
    

Example:

```cpp
Index:  0  1  2  3  4  5  6
Values: 2  4  1  ...
```

✔ Efficient memory usage
✔ No pointers needed
❌ Only works properly for complete trees

## 14. Connection to Heaps & BST

Heaps → Implemented using arrays

Binary Search Trees (BST) → Efficient searching if tree is balanced

Next topic usually:
➡ Binary Search Tree (BST)

## 15. Key Takeaways

- Binary tree allows **max 2 children**
    
- Height determines **performance**
    
- Balanced trees give **log n time**
    
- Perfect tree = max efficiency
    
- Skewed tree = worst performance

---
# Binary Search Tree (BST)

## 1. Problem Statement

We want a **data structure** to store a **modifiable collection of records** such that:

- We can **search** records quickly
    
- We can **insert** new records
    
- We can **delete** records efficiently
    

The collection can be large (millions or billions of records), so performance is critical.

## 2. Using Array or Linked List

### A) Array

#### Search

- We must scan elements one by one
    
- **Worst-case time:**
    
    O(n)O(n)O(n)

#### Insertion

- If space exists → insert at end
    
- **Time:**
    
    O(1)O(1)O(1)

#### Deletion

- Requires shifting elements
    
- **Worst-case time:**
    
    O(n)O(n)O(n)

#### Sorted Array

- Search using **Binary Search**
    
- **Search time:**
    
    O(log⁡n)O(\log n)O(logn)
- **Insertion & Deletion:** still need shifting
    
    O(n)O(n)O(n)

👉 Problem: **Fast search but slow updates**

### B) Linked List

#### Search

- Must traverse node by node
    
- **Time:**
    
    O(n)

#### Insertion

- At head → **O(1)**
    
- At tail → **O(n)**
    

#### Deletion

- First search, then remove
    
- **Time:**
    
    O(n)

👉 Problem: **Fast insertion, slow search**

## 3. Why Binary Search Tree (BST)?

We want:

- Fast **search**
    
- Fast **insertion**
    
- Fast **deletion**
    

➡ **Binary Search Tree (BST)** provides all three in

`O(logn) (average Case)`

## 4. What is a Binary Search Tree?

A **Binary Search Tree** is a **binary tree** with a special property:

### BST Property:

For **every node**:

- All values in the **left subtree** are **less than or equal** to the node
    
- All values in the **right subtree** are **greater** than the node
    
- Both left and right subtrees are also BSTs (recursive property)

### Example of a BST

```markdown
        15
       /  \
     10    20
    / \   /  \
   8  12 17  25
```

✔ Valid BST because:

- Left values < parent
    
- Right values > parent
    

❌ If `12` were replaced with `16`, BST property would break.

## 5. Searching in a BST

### Steps:

1. Start at the **root**
    
2. Compare the value:
    
    - If equal → found
        
    - If smaller → go **left**
        
    - If larger → go **right**
        
3. Repeat until found or tree ends
    

### Why is it fast?

- At each step, **half of the tree is discarded**
    
- Similar to **binary search**
    

### Time Complexity:

- **Balanced BST:**
    
    `O(Logn)`
- **Unbalanced BST (worst case):**
    
    `O(n)`

## 6. Balanced vs Unbalanced BST

### Balanced BST

- Difference between heights of left and right subtree ≤ 1
    
- Search space reduces by half at each step
    
- Best performance

```
Balanced BST:
        15
       /  \
     10    20
```

### Unbalanced BST (Worst Case)

Looks like a linked list:

```
10
  \
   12
     \
      15
        \
         20
```

- Search becomes linear
    
- **Time:** O(n)

## 7. Insertion in BST

### Steps:

1. Start at root
    
2. Compare value
    
3. Move left or right
    
4. Insert at the first empty position
    

### Example:

Insert `19`:

```sql
15 → right → 20 → left → 17 → right → insert 19
```

✔ No shifting needed  
✔ Just pointer adjustments

### Time Complexity:

- **Average:**

`O(logn)`

## 8. Deletion in BST

### Steps:

1. Search the node → O(log n)
    
2. Adjust links (based on case)
    
    - Leaf node
        
    - One child
        
    - Two children
        

### Time Complexity:

- **Average:**

`O(logn)`

## 9. Summary Comparison

| Data Structure | Search       | Insert       | Delete       |
| -------------- | ------------ | ------------ | ------------ |
| Array          | O(n)         | O(1)         | O(n)         |
| Sorted Array   | O(log n)     | O(n)         | O(n)         |
| Linked List    | O(n)         | O(1)         | O(n)         |
| **BST (avg)**  | **O(log n)** | **O(log n)** | **O(log n)** |
## 10. Final Notes

- BST combines benefits of **binary search** and **linked structure**
    
- Performance depends on **tree balance**
    
- Special trees (AVL, Red-Black) are used to **maintain balance**

---
# BST Implementation through linked list

```cpp
#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class BST
{
private:
    struct Node
    {
        int m_data;
        Node* left;
        Node* right;

        Node(int data)
            : m_data{data}
        {
        }
    };
    Node* root {nullptr};
    // ===== Private Recursive Insert =====
    Node* Insert(Node* currentNode, int data)
    {
        if (currentNode == nullptr)
        {
            return new Node(data); 
        }
        else if(data <= currentNode->m_data)
        {
            currentNode->left = Insert(currentNode->left,data);
        }
        else
        {
            currentNode->right = Insert(currentNode->right,data);
        }
        return currentNode;
    }
    // ===== Private Recursive Search =====
    bool Search(Node* currentNode, int key)
    {
        if (currentNode == nullptr)
        {
            return false;
        }

        if(key == currentNode->m_data)
        {
            return true;
        }
        else if(key < currentNode->m_data)
        {
            return Search(currentNode->left,key);
        }
        else
            return Search(currentNode->right,key);
        
    }
public:
    // Insert Function:
    void Insert(int data)
    {
        root = Insert(root,data);
  
    }
    //
    bool Search(int key)
    {
        return Search(root,key);
    }

};
int main() {
    
    return 0;
}
```

## **Binary Search Tree (BST) Using Class in C++ — Notes**

## 1️⃣ Overview

A **Binary Search Tree (BST)** is a binary tree where each node satisfies:

- All nodes in the **left subtree** have values **less than or equal** to the node’s value.
    
- All nodes in the **right subtree** have values **greater** than the node’s value.
    

BSTs allow **fast insertion, search, and deletion** with average time complexity `O(log n)` for balanced trees.

## 2️⃣ BST Class Structure

```cpp
class BST
{
private:
    struct Node { ... };
    Node* root{nullptr};

    Node* Insert(Node* currentNode, int data);
    bool Search(Node* currentNode, int key);

public:
    void Insert(int data);
    bool Search(int key);
};
```

- **`Node`**: Represents a tree node.
    
- **`root`**: Pointer to the root node of the BST. Initially `nullptr` (empty tree).
    
- **Private functions**: Recursive helpers for insert and search.
    
- **Public functions**: User interface — called directly on the tree.

## 3️⃣ Node Structure

```cpp
struct Node
{
    int m_data;   // Value stored in node
    Node* left;   // Pointer to left child
    Node* right;  // Pointer to right child

    Node(int data)
        : m_data{data}, left{nullptr}, right{nullptr} {}
};
```

Key points:

Each node stores data and pointers to left/right children.

Constructor initializes m_data and sets left/right to nullptr.

## 4️⃣ Private Recursive Insert Function

```cpp
Node* Insert(Node* currentNode, int data)
{
    if (currentNode == nullptr)
        return new Node(data);

    if (data <= currentNode->m_data)
        currentNode->left = Insert(currentNode->left, data);
    else
        currentNode->right = Insert(currentNode->right, data);

    return currentNode;
}
```

**Explanation:**

1. **Base Case**: If the current spot is `nullptr`, create a new node.
    
2. **Recursive Case**:
    
    - If `data <= currentNode->m_data`, go **left**.
        
    - Else, go **right**.
        
3. Always **return the current node**, so parent pointers are updated correctly.
    

**Why return `currentNode`?**

- Recursive insert may create a new subtree; returning the node ensures the parent points to the updated subtree.
    
- Also allows inserting into an **empty tree**, where root changes.

## 5️⃣ Public Insert Function

```cpp
void Insert(int data)
{
    root = Insert(root, data);
}
```

**Explanation:**

- The user does **not** provide the current node.
    
- `root` is passed to the recursive helper.
    
- After insertion, `root` is updated in case the tree was empty.

## 6️⃣ Private Recursive Search Function

```cpp
bool Search(Node* currentNode, int key)
{
    if (currentNode == nullptr)
        return false;

    if (key == currentNode->m_data)
        return true;
    else if (key < currentNode->m_data)
        return Search(currentNode->left, key);
    else
        return Search(currentNode->right, key);
}
```

**Explanation:**

1. **Base Case**: If `currentNode` is `nullptr`, key is not found.
    
2. If `key` matches the current node, return `true`.
    
3. If `key` is **less**, go left; if **greater**, go right.
    

**Note:** Use `<` instead of `<=` to avoid unnecessary recursion.

## 7️⃣ Public Search Function

```cpp
bool Search(int key)
{
    return Search(root, key);
}
```

Provides a clean interface for the user.

Starts the recursive search from root.

## 8️⃣ How the BST Works
Example:

```cpp
BST tree;
tree.Insert(10);
tree.Insert(5);
tree.Insert(15);
tree.Insert(7);
```

Tree structure after insertion:

```cpp
       10
      /  \
     5    15
      \
       7
```

Searching for 7 → go left (10 → 5), then right (5 → 7) → found.

Searching for 20 → go right (10 → 15), then right (15 → nullptr) → not found.

## 9️⃣ Key Points to Remember

1. **Public vs Private Functions**:
    
    - Public functions handle **interface & root update**.
        
    - Private recursive functions handle **actual recursion**.
        
2. **Returning Node**: Always return the current node in recursion to maintain tree structure.
    
3. **Time Complexity**:
    
    - Average: `O(log n)`
        
    - Worst case (unbalanced tree): `O(n)`
        
4. **BST Property**: Left ≤ node < Right
    

---
# BST implementation - memory allocation in stack and heap

## 1️⃣ Overview of the Implementation

### Class Structure

```cpp
class BST
{
private:
    struct Node { int m_data; Node* left; Node* right; };
    Node* root {nullptr};
};
```

### Key Points

- `root` is a **data member**, not a local variable
    
- Tree nodes are created using `new`
    
- **Recursion** is used for both insert and search
    
- Nodes live in **heap**
    
- Recursive calls live in **stack**

## 2️⃣ Memory Segments Involved

### Stack

- Stores:
    
    - Function calls
        
    - Parameters
        
    - Local variables
        
- Automatically destroyed after function returns
    

### Heap

- Stores:
    
    - Dynamically allocated nodes (`new Node(data)`)
        
- Exists until explicitly deleted or program ends
    

📌 **BST nodes always live in heap**

## 3️⃣ Node Creation (Heap Behavior)

### Code

```cpp
return new Node(data);
```

### What Happens

- Memory is allocated in heap
    
- Constructor initializes `m_data`
    
- Pointer to node is returned
    

### Example Heap Node

```sql
Address: 500
┌───────────────┐
│ m_data = 100  │
│ left = NULL   │
│ right = NULL  │
└───────────────┘
```

## 4️⃣ First Insert: `tree.Insert(100)`

### Public Insert

```cpp
void Insert(int data)
{
    root = Insert(root, data);
}
```

### Stack

```cpp
┌────────────────────────┐
│ Insert(data=100)       │
└────────────────────────┘
```

### Private Recursive Insert Call

```cpp
Insert(currentNode = nullptr, data = 100)
```

### Condition

```cpp
if (currentNode == nullptr)
```

➡ New node created in heap  
➡ Returned to caller  
➡ Assigned to `root`

### Heap

```cpp
500 → [100 | NULL | NULL]
```

## 5️⃣ Second Insert: `tree.Insert(200)`

### Comparisons

```cpp
200 > 100 → go right
```

### Recursive Call Stack

```cpp
Insert(root=500, data=200)
  → Insert(currentNode=null, data=200)
```

### Heap After Insert

```cpp
500 → [100 | NULL | 600]
600 → [200 | NULL | NULL]
```

### Tree Shape

```cpp
   100
      \
       200
```

## 6️⃣ Third Insert: `tree.Insert(300)`

### Comparisons

```cpp
300 > 100 → right
300 > 200 → right
```

### Stack Growth (Recursion)

```cpp
Insert(500,300)
 → Insert(600,300)
   → Insert(nullptr,300)
```

### Heap After Insert

```cpp
500 → [100 | NULL | 600]
600 → [200 | NULL | 700]
700 → [300 | NULL | NULL]
```

### Final Tree

```cpp
100
   \
    200
        \
         300
```

📌 **Each recursive call gets its own stack frame**

## 7️⃣ Why `return currentNode;` Is Important

### Code

```cpp
return currentNode;
```

### Purpose

- Preserves tree links
    
- Ensures parent nodes keep correct child pointers
    
- Prevents loss of subtrees
    

❗ Without returning `currentNode`, tree structure breaks

---
# Finding height of a binary tree

```cpp
    int Height(Node* current)
    {
        if (current == nullptr)
        {
            return -1;
        }
        return max( Height(current->left) , Height(current->right) ) + 1;
        
    } 
```

### 🌳 What is Height (Max Depth) of a Binary Tree?

**Height = longest number of edges from the root down to a leaf**

- We **start from root**
    
- We go **downward**
    
- We choose the **longest path**
    
- We count **edges (connections)**, NOT nodes

### 📌 Important points

- A **leaf node** has height **0** (nothing below it)
    
- An **empty tree (null)** has height **–1** (by convention for edge-based height)
    
- **Height of tree = height of root**

### 🧠 How recursion calculates height

For every node:

```cpp
height(node) = max( height(left), height(right) ) + 1
```

- We take height of left subtree
    
- We take height of right subtree
    
- We pick the bigger one
    
- We add **+1** for the edge we just used to go down
    

### ❗ Why return –1 for null?

Because when we reach a leaf, its children are null:

```cpp
left = null  → return -1
right = null → return -1
```

Then:

```cpp
max(-1, -1) + 1 = 0 ✔ (correct height of leaf)
```

So returning –1 **removes the fake extra edge** that doesn't exist.

### 🔍 Small example

```cpp
    10
   /  \
  5   20
      /
     15
```

Paths from root to leaves:

1. 10 → 5 (1 edge)
    
2. 10 → 20 → 15 (2 edges)
    

Longest path has **2 edges**, so:

```cpp
Height of tree = 2
```

### ⏱ Time complexity

We visit each node **once** → so it's **O(N)**

### Let’s visualize recursion on a **more difficult tree**:

```
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8
          /
         9
```

We call: `findHeight(1)` (edge-based height, so `null → -1`)

### 🔁 Recursive breakdown

```css
findHeight(1)
├── findHeight(2)
│   ├── findHeight(4)
│   │   ├── findHeight(null) → -1
│   │   └── findHeight(null) → -1
│   │   ➤ 4 returns: max(-1,-1)+1 = 0
│   │
│   └── findHeight(5)
│       ├── findHeight(7)
│       │   ├── findHeight(null) → -1
│       │   └── findHeight(null) → -1
│       │   ➤ 7 returns: 0
│       │
│       └── findHeight(8)
│           ├── findHeight(null) → -1
│           └── findHeight(9)
│               ├── findHeight(null) → -1
│               └── findHeight(null) → -1
│               ➤ 9 returns: 0
│           ➤ 8 returns: max(-1,0)+1 = 1
│
│   ➤ 5 returns: max(0,1)+1 = 2
│
│➤ 2 returns: max(0,2)+1 = 3
│
└── findHeight(3)
    ├── findHeight(null) → -1
    └── findHeight(6)
        ├── findHeight(null) → -1
        └── findHeight(null) → -1
        ➤ 6 returns: 0
    ➤ 3 returns: max(-1,0)+1 = 1

➤ 1 returns: max(3,1)+1 = 4 ✔
Final Height = 4

```


---
# Binary tree traversal - breadth-first and depth-first strategies

### 🌳 What is Tree Traversal?

Tree traversal means **visiting every node exactly once** and **doing something with the data** (like printing it).  
Unlike arrays or linked lists, trees **branch into multiple directions**, so we need special strategies to visit nodes.

## 1. 🔵 Breadth-First Traversal (BFS)

- Visits nodes **level by level**, from **top → bottom**, **left → right**.
    
- In a binary tree, BFS is also called **Level Order Traversal**.
    

### Example order:

```
Level 0 → F  
Level 1 → D, J  
Level 2 → B, E, G, K  
Level 3 → A, C, I  
Level 4 → H
```

Final traversal: **F → D → J → B → E → G → K → A → C → I → H**

## 2. 🟡 Depth-First Traversal (DFS)

DFS goes **deep into a subtree first**, finishes it completely, then moves to the next subtree.

There are 3 main DFS types (remember using: **D = Data/Visit, L = Left, R = Right**):

### 🟢 Pre-Order (DLR)

Visit current node → Go Left → Go Right  
✔ Root comes **first**

### 🟢 In-Order (LDR)

Go Left → Visit node → Go Right  
✔ Root comes **middle**

If the tree is a **Binary Search Tree (BST)**, In-Order gives a **sorted list**.

pasted

### 🟢 Post-Order (LRD)

Go Left → Go Right → Visit node  
✔ Root comes **last**

## 🧠 Manual Traversal Example (from transcript tree)

Tree used in transcript:

```livescript
        F
       / \
      D   J
     / \   \
    B   E   K
   / \       \
  A   C       I
               \
                H
```

### Pre-Order Walkthrough (DLR)

```css
F → D → B → A → C → E → J → G → I → H → K
```

### In-Order (LDR)

```css
A → B → C → D → E → F → G → J → H → I → K
```

(Sorted if BST) ✔

### Post-Order (LRD)

```css
A → C → B → E → D → H → I → J → K → F
```

## 🚀 Key Takeaways

|Traversal|Pattern|Root Position|
|---|---|---|
|Pre-Order|D → L → R|First|
|In-Order|L → D → R|Middle|
|Post-Order|L → R → D|Last|
|Level Order|Level by Level|Uses Queue (BFS)|

---
# Implementation of Breadth-first and Depth-first Traversal

```cpp
#include <string>
#include <string_view>
#include <queue>
#include <iostream>

using namespace std;

class BST
{
private:
    struct Node
    {
        int m_data;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int data)
            : m_data{data}
        {
        }
    };
    Node* root {nullptr};
    // ===== Private Recursive Insert =====
    Node* Insert(Node* currentNode, int data)
    {
        if (currentNode == nullptr)
        {
            return new Node(data); 
        }
        else if(data <= currentNode->m_data)
        {
            currentNode->left = Insert(currentNode->left,data);
        }
        else
        {
            currentNode->right = Insert(currentNode->right,data);
        }
        return currentNode;
    }
    // ===== Private Recursive Search =====
    bool Search(Node* currentNode, int key)
    {
        if (currentNode == nullptr)
        {
            return false;
        }

        if(key == currentNode->m_data)
        {
            return true;
        }
        else if(key < currentNode->m_data)
        {
            return Search(currentNode->left,key);
        }
        else
            return Search(currentNode->right,key);
        
    }
    int FindMin_Recursion(Node* current)
    {
        if (current == nullptr)
        {
            cout << "Tree is empty!";
            return -1;
        }
        else if(current->left == nullptr)
        {
            return current->m_data;
        }
        else 
            return FindMin_Recursion(current->left);
        
    }
    int FindMax_Recursion(Node* current)
    {
        if (current == nullptr)
        {
            cout << "Tree is empty!";
            return -1;
        }
        else if(current->right == nullptr)
        {
            return current->m_data;
        }
        else 
            return FindMax_Recursion(current->right);
        
    }  
    int Height(Node* current)
    {
        if (current == nullptr)
        {
            return -1;
        }
        return max( Height(current->left) , Height(current->right) ) + 1;
        
    }  
    void PreOrder(Node* current)
    {
        if (current == nullptr) return;
        cout << current->m_data << " ";
        PreOrder(current->left);
        PreOrder(current->right);
    }
    void InOrder(Node* current)
    {
        if(current == nullptr) return;
        InOrder(current->left);
        cout << current->m_data << " ";
        InOrder(current->right);
    }
    void PostOrder(Node* current)
    {
        if (current == nullptr) return;
        PostOrder(current->left);
        PostOrder(current->right);
        cout << current->m_data << " ";
        
    }
public:
    // Insert Function:
    void Insert(int data)
    {
        root = Insert(root,data);
  
    }
    //
    bool Search(int key)
    {
        return Search(root,key);
    }
    int FindMin()
    {
        if (root == nullptr)
        {
            cout << "tree is empty!";
            return -1;
        }        
        Node* temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->m_data;
    }
    int FindMax()
    {
        if (root == nullptr)
        {
            cout << "tree is empty!";
            return -1;

        }
        
        Node* temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->m_data;
    }
    int FindMin_Recursion()
    {
        return FindMin_Recursion(root);
    }
    int FindMax_Recursion()
    {
       
        return FindMax_Recursion(root);
    }    
    int Height()
    {
        return Height(root);
    }
    void LevelTraversal()
    {
        if(root == nullptr) return;
        //
        queue<Node*> storage;
        storage.push(root);

        while (!storage.empty())
        {
            Node* temp = storage.front();
            cout << temp->m_data << " ";
            if(temp->left != nullptr) storage.push(temp->left);
            if(temp->right != nullptr) storage.push(temp->right);

            storage.pop();
        }
    }
    void PreOrder()
    {
        PreOrder(root); 
    }
    void InOrder()
    {
        InOrder(root);
    }
};

int main() {
    
    BST tree;
    tree.Insert(8); 
    tree.Insert(3); 
    tree.Insert(10); 
    tree.Insert(1); 
    tree.Insert(6); 
    tree.Insert(4); 

    // cout << "Min: " << tree.FindMin() << ".\n";
    // cout << "Recursion_Min: " << tree.FindMin_Recursion() << ".\n";
  
    // cout << "Max: " << tree.FindMax() << ".\n";
    // cout << "Recursion_Max: " << tree.FindMax_Recursion() << ".\n";   
    
    // Level Order Traversal:
    // tree.LevelTraversal();

    // PreOrder Traversal:
    tree.PreOrder();

    return 0;
}
```

# Space and time complexity

## **Breadth-First Traversal (BFS)**

Also called **Level-Order Traversal**. Uses a **queue**.

### **Time Complexity**

- We visit **every node once** → **O(N)**
    

### **Space Complexity**

Space depends on what we store in memory:

1. **Queue storage**:
    
    - In worst case, the queue holds the **entire last level** of the tree.
        
    - For a balanced binary tree, last level ≈ N/2 nodes.
        
    - So, **O(N)** space.
        
2. **Output / result array (if stored)**: also **O(N)**
    

### **Final**

- **Time: O(N)**
    
- **Space: O(N)**



---
