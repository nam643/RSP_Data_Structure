# Binary Search Tree (BST)

## Introduction

A **Binary Search Tree (BST)** is a hierarchical data structure that stores data in a sorted manner. It is a special type of binary tree where each node follows a specific ordering rule, allowing efficient searching, insertion, and deletion operations.

BSTs are widely used in databases, file systems, compiler symbol tables, and many searching applications.

---

## Structure of a BST

Each node contains:

- A value (key)
- A reference to the left child
- A reference to the right child

Example:

```text
        50
       /  \
     30    70
    / \    / \
   20 40 60 80
```

Node `50` is the root.

---

## BST Property

For every node:

```text
All values in left subtree  <  Node Value
All values in right subtree >  Node Value
```

Example:

```text
        50
       /  \
     30    70
```

- 30 < 50 → left side
- 70 > 50 → right side

This property must hold for **every node** in the tree.

---

## Terminology

### Root

The topmost node of the tree.

```text
    50
```

Here, `50` is the root.

### Parent and Child

```text
      50
     /
   30
```

- 50 is the parent of 30
- 30 is the child of 50

### Leaf Node

A node with no children.

```text
    50
   /  \
 30   70
```

Here, `30` and `70` are leaf nodes.

### Subtree

A tree contained within another tree.

```text
        50
       /  \
     30    70
    / \
   20 40
```

The tree rooted at `30` is a subtree.

### Height

The number of edges on the longest path from the root to a leaf.

Example:

```text
      50
     /
   30
   /
 20
```

Height = 2

---

## Search Operation

Searching in a BST takes advantage of its ordering property.

### Example

Find `60`.

```text
        50
       /  \
     30    70
          /
        60
```

Steps:

1. Compare with 50

```text
60 > 50
```

Move right.

2. Compare with 70

```text
60 < 70
```

Move left.

3. Reach 60

```text
Found
```

### Algorithm

```text
current = root

while current exists
    if current.value == target
        found
    else if target < current.value
        current = current.left
    else
        current = current.right
```

---

## Insertion Operation

Insertion follows the same path as searching.

### Insert 65

Initial tree:

```text
        50
       /  \
     30    70
          /
        60
```

Steps:

```text
65 > 50  → go right
65 < 70  → go left
65 > 60  → go right
```

Result:

```text
        50
       /  \
     30    70
          /
        60
          \
           65
```

The BST property is preserved.

---

## Deletion Operation

Deletion is the most complicated BST operation.

### Case 1: Delete a Leaf Node

Delete `20`.

Before:

```text
      50
     /
   30
   /
 20
```

After:

```text
      50
     /
   30
```

Simply remove the node.

### Case 2: Delete a Node with One Child

Delete `30`.

Before:

```text
    50
   /
 30
 /
20
```

After:

```text
   50
   /
 20
```

The child replaces the deleted node.

### Case 3: Delete a Node with Two Children

Delete `50`.

Before:

```text
       50
      /  \
    30    70
         /
       60
```

Find the **inorder successor** (smallest node in the right subtree).

Successor:

```text
60
```

Replace 50 with 60.

After:

```text
       60
      /  \
    30    70
```

---

## Tree Traversals

Traversal means visiting every node exactly once.

### Inorder Traversal

Order:

```text
Left → Root → Right
```

Example:

```text
        50
       /  \
     30    70
```

Output:

```text
30 50 70
```

### Important

For a BST, **Inorder Traversal always produces sorted order**.

---

### Preorder Traversal

Order:

```text
Root → Left → Right
```

Output:

```text
50 30 70
```

Common uses:

- Copying trees
- Serializing trees

---

### Postorder Traversal

Order:

```text
Left → Right → Root
```

Output:

```text
30 70 50
```

Common uses:

- Deleting trees
- Expression evaluation

---

## Time Complexity

Let:

- `n` = number of nodes
- `h` = height of the tree

| Operation | Average Case | Worst Case |
|------------|------------|------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

---

## Balanced vs Unbalanced BST

### Balanced BST

```text
        50
       /  \
     30    70
```

Height:

```text
O(log n)
```

Operations remain efficient.

---

### Unbalanced BST

Insert values:

```text
10, 20, 30, 40, 50
```

Result:

```text
10
 \
 20
   \
    30
      \
       40
         \
          50
```

This behaves like a linked list.

Height:

```text
O(n)
```

All operations degrade to O(n).

---

## Self-Balancing BSTs

To avoid degeneration, special trees rebalance themselves automatically.

### AVL Tree

Characteristics:

- Strictly balanced
- Faster search performance
- More rotations during updates

Complexities:

```text
Search = O(log n)
Insert = O(log n)
Delete = O(log n)
```

---

### Red-Black Tree

Characteristics:

- Loosely balanced
- Faster insertions and deletions
- Used by many standard libraries

Examples:

- C++ `std::map`
- C++ `std::set`
- Java `TreeMap`
- Java `TreeSet`

Complexities:

```text
Search = O(log n)
Insert = O(log n)
Delete = O(log n)
```

---

## Advantages

✅ Fast searching

✅ Fast insertion

✅ Maintains sorted order

✅ Dynamic size

✅ Supports range queries

✅ Inorder traversal is naturally sorted

---

## Disadvantages

❌ Can become unbalanced

❌ Worst-case performance is O(n)

❌ Deletion is relatively complex

❌ Requires extra memory for node references

---

## BST vs Binary Tree

| Feature | Binary Tree | Binary Search Tree |
|----------|----------|----------|
| Maximum children | 2 | 2 |
| Ordering Rule | None | Left < Root < Right |
| Efficient Search | No guarantee | Yes |
| Sorted Traversal | No | Yes |
| Average Search | O(n) | O(log n) |

---

## Common Interview Questions

### Why is inorder traversal important?

Because inorder traversal of a BST produces elements in **sorted order**.

### What is the inorder successor?

The next larger element in sorted order.

Usually:

```text
Smallest node in the right subtree
```

### Why can a BST become slow?

When it becomes skewed:

```text
1
 \
 2
  \
   3
    \
     4
      \
       5
```

Height becomes:

```text
O(n)
```

Operations degrade from O(log n) to O(n).

### How do AVL Trees and Red-Black Trees help?

They automatically rebalance themselves after insertions and deletions, ensuring:

```text
Height ≈ O(log n)
```

and keeping operations efficient.

---

## Real-World Applications

BSTs are used in:

- Database indexing
- Symbol tables in compilers
- Memory management systems
- File and directory organization
- Ordered sets and maps
- Range searching applications

---

## Summary

A Binary Search Tree (BST) is a binary tree that maintains the ordering rule:

```text
Left Subtree < Node < Right Subtree
```

Key points:

- Search, insert, and delete are O(log n) on average.
- Inorder traversal produces sorted output.
- An unbalanced BST can degrade to O(n).
- AVL Trees and Red-Black Trees solve the balancing problem.
- BSTs are one of the most fundamental data structures for maintaining dynamically sorted data.