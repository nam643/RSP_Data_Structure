# Quick Sort

## Introduction

**Quick Sort** is a highly efficient sorting algorithm that follows the **Divide and Conquer** paradigm.

The main idea is:

1. Choose a pivot element.
2. Partition the array so that:
   - Elements smaller than the pivot go to the left.
   - Elements larger than the pivot go to the right.
3. Recursively sort the left and right partitions.

Quick Sort is one of the most commonly used sorting algorithms because it is fast in practice and requires very little extra memory.

---

## Divide and Conquer Strategy

Quick Sort works in three steps:

### Divide

Choose a pivot and partition the array into two parts.

### Conquer

Recursively sort both partitions.

### Combine

No merging is needed because partitioning places elements in their correct relative positions.

---

## Example

Sort:

```text
[7, 2, 1, 6, 8, 5, 3, 4]
```

Choose pivot:

```text
4
```

Partition:

```text
[2, 1, 3] 4 [7, 6, 8, 5]
```

Recursively sort:

```text
[1, 2, 3] 4 [5, 6, 7, 8]
```

Final result:

```text
[1, 2, 3, 4, 5, 6, 7, 8]
```

---

## Pivot Selection

The pivot is the element used to partition the array.

Common strategies:

### First Element

```cpp
pivot = arr[left];
```

### Last Element

```cpp
pivot = arr[right];
```

### Middle Element

```cpp
pivot = arr[(left + right) / 2];
```

### Random Pivot

```cpp
pivot = arr[randomIndex];
```

### Median of Three

Choose the median among:

```text
first
middle
last
```

This often improves performance.

---

## Partitioning

Partitioning rearranges elements around the pivot.

After partitioning:

```text
All elements < pivot are on the left.
All elements > pivot are on the right.
```

Example:

Before:

```text
[7, 2, 1, 6, 8, 5, 3, 4]
```

After partitioning around 4:

```text
[2, 1, 3] 4 [7, 6, 8, 5]
```

The pivot is now in its final sorted position.

---

## Lomuto Partition Scheme

Uses the last element as the pivot.

Example:

```cpp
pivot = arr[high];
```

Algorithm:

```text
i = low - 1

For j from low to high-1
    If arr[j] < pivot
        i++
        swap(arr[i], arr[j])

Swap arr[i+1] and pivot

Return i + 1
```

---

## Hoare Partition Scheme

Uses two pointers.

```text
left pointer moves right
right pointer moves left
```

Swap elements that are on the wrong side.

Advantages:

- Fewer swaps
- Usually faster than Lomuto

Often preferred in production implementations.

---

## Recursive Algorithm

```text
QuickSort(array)

Choose pivot

Partition array

QuickSort(left partition)

QuickSort(right partition)
```

---

## Pseudocode

```text
QuickSort(arr, low, high)

if low < high

    pivotIndex = partition(arr, low, high)

    QuickSort(arr, low, pivotIndex - 1)

    QuickSort(arr, pivotIndex + 1, high)
```

---

## Dry Run Example

Sort:

```text
[5, 3, 8, 4, 2]
```

Choose pivot:

```text
2
```

Partition:

```text
[2] [5, 3, 8, 4]
```

Pivot is now sorted.

---

Sort right side:

```text
[5, 3, 8, 4]
```

Choose pivot:

```text
4
```

Partition:

```text
[3] 4 [5, 8]
```

---

Sort:

```text
[5, 8]
```

Pivot:

```text
8
```

Partition:

```text
[5] 8
```

Final:

```text
[2, 3, 4, 5, 8]
```

---

## Why Quick Sort Works

After partitioning:

```text
Left side < Pivot < Right side
```

The pivot is already in its final sorted position.

Therefore:

- Sort left side
- Sort right side

Eventually all elements are placed correctly.

---

## Time Complexity

### Best Case

Balanced partitions:

```text
T(n) = 2T(n/2) + O(n)
```

Result:

```text
O(n log n)
```

---

### Average Case

Most random inputs:

```text
O(n log n)
```

This is why Quick Sort is very popular.

---

### Worst Case

Occurs when partitions are extremely unbalanced.

Example:

```text
[1,2,3,4,5,6,7]
```

Using the first element as pivot:

```text
1
 \
 2
  \
   3
    \
     4
```

Result:

```text
O(n²)
```

---

## Space Complexity

Quick Sort sorts **in-place**.

Extra memory:

```text
O(log n)
```

due to recursive calls.

Worst case:

```text
O(n)
```

recursive stack depth.

---

## Stability

A sorting algorithm is **stable** if equal elements maintain their relative order.

Example:

```text
(10,A)
(10,B)
```

After sorting:

```text
(10,A)
(10,B)
```

Stable.

---

### Is Quick Sort Stable?

No.

Standard Quick Sort is:

```text
Not Stable
```

because swaps can change the order of equal elements.

---

## In-Place Sorting

A sorting algorithm is **in-place** if it uses very little extra memory.

Quick Sort:

```text
In-Place = Yes
```

Merge Sort:

```text
In-Place = No
```

because Merge Sort needs extra arrays.

---

## Comparison with Merge Sort

| Feature | Quick Sort | Merge Sort |
|----------|----------|----------|
| Average Time | O(n log n) | O(n log n) |
| Worst Time | O(n²) | O(n log n) |
| Extra Space | O(log n) | O(n) |
| Stable | No | Yes |
| In-Place | Yes | No |
| Practical Performance | Very Fast | Fast |

---

## Advantages

✅ Very fast in practice

✅ In-place sorting

✅ Low memory usage

✅ Cache friendly

✅ Average complexity O(n log n)

✅ Widely used in real applications

---

## Disadvantages

❌ Worst-case O(n²)

❌ Not stable

❌ Recursive implementation

❌ Poor pivot selection can significantly reduce performance

---

## Common Interview Questions

### Why is Quick Sort called Divide and Conquer?

Because it:

1. Divides the array into partitions.
2. Recursively sorts each partition.
3. Combines results implicitly.

---

### What causes the O(n²) worst case?

Extremely unbalanced partitions.

Example:

```text
[1,2,3,4,5]
```

using:

```text
first element pivot
```

or

```text
last element pivot
```

---

### How can we reduce the chance of O(n²)?

Use:

- Random pivot
- Median-of-three pivot

These usually produce more balanced partitions.

---

### Why is Quick Sort often faster than Merge Sort?

Although both average:

```text
O(n log n)
```

Quick Sort:

- Uses less memory
- Has better cache performance
- Performs fewer memory allocations

Therefore it is often faster in practice.

---

## Real-World Applications

Quick Sort is commonly used in:

- Standard library implementations
- Database systems
- Search engines
- Data processing pipelines
- Competitive programming
- Large-scale sorting problems

Modern implementations often combine Quick Sort with:

- Heap Sort
- Insertion Sort

to create advanced algorithms such as **IntroSort**.

---

## Things to Implement

### Phase 1: Foundations

- [ ] Basic Quick Sort
- [ ] Lomuto Partition
- [ ] Hoare Partition
- [ ] Recursive Quick Sort

### Phase 2: Understanding the Algorithm

- [ ] Count Comparisons
- [ ] Count Swaps
- [ ] Visualize Each Partition
- [ ] Print Recursive Calls

### Phase 3: Optimizations

- [ ] Random Pivot Selection
- [ ] Median-of-Three Pivot
- [ ] Tail Recursion Optimization
- [ ] Hybrid Quick Sort + Insertion Sort

### Phase 4: Interview Problems

- [ ] Quick Select (Kth Smallest)
- [ ] Kth Largest Element
- [ ] Sort Colors (Dutch National Flag)
- [ ] Nuts and Bolts Problem
- [ ] Top K Frequent Elements

### Phase 5: Advanced

- [ ] Iterative Quick Sort using Stack
- [ ] Three-Way Quick Sort
- [ ] Dual-Pivot Quick Sort
- [ ] IntroSort

---

## Summary

Quick Sort is a Divide and Conquer sorting algorithm that:

```text
1. Chooses a pivot
2. Partitions the array
3. Recursively sorts both sides
```

Key points:

- Average Time Complexity: **O(n log n)**
- Worst Time Complexity: **O(n²)**
- Space Complexity: **O(log n)**
- In-Place: **Yes**
- Stable: **No**

Quick Sort is one of the most important sorting algorithms because of its excellent practical performance and its role as a foundation for many advanced sorting techniques.