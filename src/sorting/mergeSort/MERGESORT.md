# Merge Sort Notes

# 1. What is Merge Sort?

Merge Sort is a sorting algorithm based on the **Divide and Conquer** paradigm.

The idea is simple:

1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves together.

Example:

```cpp
[4, 10, 3, 5, 1]
```

becomes

```text
            [4,10,3,5,1]
              /      \
       [4,10,3]      [5,1]
         /    \       /  \
      [4,10] [3]   [5]  [1]
      /   \
    [4]  [10]
```

Eventually each subarray contains one element.

Example:

```cpp
[4]
```

A single element is already sorted.

---

# Why Does Merge Sort Work?

When every piece has length 1:

```cpp
[4]
[10]
[3]
[5]
[1]
```

they are trivially sorted.

We then repeatedly merge sorted arrays to build larger sorted arrays until the whole array becomes sorted.

---

# 2. The Merge Operation

The merge operation is the heart of Merge Sort.

Suppose we already have two sorted arrays:

```cpp
Left  = [4, 10]
Right = [1, 5]
```

Our goal is to combine them into one sorted array.

---

## Step 1

Compare:

```cpp
4 vs 1
```

Take the smaller value:

```cpp
1
```

Result:

```cpp
[1]
```

Remaining:

```cpp
Left  = [4,10]
Right = [5]
```

---

## Step 2

Compare:

```cpp
4 vs 5
```

Take:

```cpp
4
```

Result:

```cpp
[1,4]
```

Remaining:

```cpp
Left  = [10]
Right = [5]
```

---

## Step 3

Compare:

```cpp
10 vs 5
```

Take:

```cpp
5
```

Result:

```cpp
[1,4,5]
```

Remaining:

```cpp
Left  = [10]
Right = []
```

---

## Step 4

Copy the remaining elements.

Result:

```cpp
[1,4,5,10]
```

Merge complete.

---

# Key Observation

Because both halves are already sorted:

```cpp
[4,10]
[1,5]
```

we only need to compare the front elements.

This makes merging very efficient.

---

# 3. Dry Run on [4,10,3,5,1]

Initial array:

```cpp
[4,10,3,5,1]
```

---

## First Split

```text
[4,10,3,5,1]

Left  = [4,10,3]
Right = [5,1]
```

---

## Sort Left Half

Current:

```cpp
[4,10,3]
```

Split:

```text
[4,10]
[3]
```

---

### Split Again

```text
[4]
[10]
```

Both arrays have one element.

Already sorted.

---

### Merge

Merge:

```cpp
[4]
[10]
```

Result:

```cpp
[4,10]
```

---

### Merge With [3]

Merge:

```cpp
[4,10]
[3]
```

Compare:

```cpp
4 vs 3
```

Take:

```cpp
3
```

Result:

```cpp
[3]
```

Copy remaining:

```cpp
[4,10]
```

Final result:

```cpp
[3,4,10]
```

---

## Sort Right Half

Current:

```cpp
[5,1]
```

Split:

```cpp
[5]
[1]
```

Merge:

```cpp
5 vs 1
```

Take:

```cpp
1
```

Copy remaining:

```cpp
5
```

Result:

```cpp
[1,5]
```

---

## Final Merge

Merge:

```cpp
[3,4,10]
[1,5]
```

---

Compare:

```cpp
3 vs 1
```

Take:

```cpp
1
```

Result:

```cpp
[1]
```

---

Compare:

```cpp
3 vs 5
```

Take:

```cpp
3
```

Result:

```cpp
[1,3]
```

---

Compare:

```cpp
4 vs 5
```

Take:

```cpp
4
```

Result:

```cpp
[1,3,4]
```

---

Compare:

```cpp
10 vs 5
```

Take:

```cpp
5
```

Result:

```cpp
[1,3,4,5]
```

---

Copy remaining:

```cpp
10
```

Final result:

```cpp
[1,3,4,5,10]
```

---

# Visual Summary

```text
                    [4,10,3,5,1]
                    /           \
              [4,10,3]         [5,1]
              /      \         /    \
          [4,10]    [3]      [5]    [1]
          /   \
        [4]  [10]

Merge:
[4] + [10]
    ↓
 [4,10]

[4,10] + [3]
    ↓
 [3,4,10]

[5] + [1]
    ↓
 [1,5]

[3,4,10] + [1,5]
     ↓
 [1,3,4,5,10]
```

---

# Mental Model

Merge Sort works in two phases:

## Divide

```text
Split
Split
Split
```

until every subarray contains one element.

## Conquer

```text
Merge
Merge
Merge
```

until the entire array becomes sorted.

Think of Merge Sort as:

"Break everything apart until it is trivially sorted, then rebuild it in sorted order."