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
