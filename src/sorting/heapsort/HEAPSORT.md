# Heap Sort Notes (Sections 1-4)

# 1. What is a Heap?

A **heap** is a special kind of binary tree.

For a **Max Heap**:

- Every parent node is greater than or equal to its children.
- The largest element is always stored at the root.

Example:

```text
        10
       /  \
      8    5
     / \
    3   2
```

Notice:

```text
10 ≥ 8, 5
8 ≥ 3, 2
```

Every parent is larger than its children, so this is a valid max heap.

---

# 2. Why Does Heap Sort Work?

Consider the array:

```cpp
[4, 10, 3, 5, 1]
```

## Step 1: Build a Max Heap

Rearrange the elements into a max heap:

```text
       10
      /  \
     5    3
    / \
   4   1
```

Array representation:

```cpp
[10, 5, 3, 4, 1]
```

The largest element is now at the root.

---

## Step 2: Move the Maximum to the End

Swap the root with the last element:

```cpp
[1, 5, 3, 4, 10]
```

Now:

```cpp
10
```

is in its final sorted position.

---

## Step 3: Restore the Heap

The remaining heap is:

```cpp
[1, 5, 3, 4]
```

Tree representation:

```text
    1
   / \
  5   3
 /
4
```

This is not a valid max heap because:

```text
1 < 5
```

After heapifying:

```text
      5
     / \
    4   3
   /
  1
```

Array:

```cpp
[5, 4, 3, 1, 10]
```

---

## Step 4: Repeat

Again swap the root with the last element in the heap:

```cpp
[1, 4, 3, 5, 10]
```

Restore the heap and continue until only one element remains.

Final sorted array:

```cpp
[1, 3, 4, 5, 10]
```

---

# 3. Array Representation of a Heap

A heap is usually stored in an array instead of using tree nodes and pointers.

Given a node at index:

```cpp
i
```

its children are:

```cpp
left  = 2 * i + 1
right = 2 * i + 2
```

and its parent is:

```cpp
parent = (i - 1) / 2
```

Example:

```cpp
index: 0  1  2  3  4  5  6
value:10  8  5  3  2  1  4
```

Tree representation:

```text
          10
        /    \
       8      5
      / \    / \
     3   2  1   4
```

No pointers are needed because the parent-child relationships can be computed directly from the indices.

---

# 4. Heapify Operation

The purpose of **heapify** is to restore the heap property for a subtree.

Example:

```cpp
[1, 8, 5]
```

Tree:

```text
    1
   / \
  8   5
```

This is not a max heap because:

```text
1 < 8
```

Find the largest value among:

```text
1, 8, 5
```

The largest is:

```text
8
```

Swap:

```cpp
[8, 1, 5]
```

Resulting tree:

```text
    8
   / \
  1   5
```

This is now a valid max heap.

---

## Key Idea of Heapify

1. Compare a node with its children.
2. Find the largest value.
3. If a child is larger, swap them.
4. Continue fixing the affected subtree.

Heapify is the fundamental operation that allows Heap Sort to work efficiently.