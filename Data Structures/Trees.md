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

2i2^i2i

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

2i2^i2i

|Level|Max Nodes|
|---|---|
|0|1|
|1|2|
|2|4|
|3|8|

This happens because **each node can have two children**.

## 8. Maximum Nodes in a Binary Tree

For a binary tree with height `h`:

Max Nodes=2h+1−1\text{Max Nodes} = 2^{h+1} - 1Max Nodes=2h+1−1

Example:

- Height = 3
    
- Levels = 4
    
- Max nodes = 24−1=152^4 - 1 = 1524−1=15
    

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

