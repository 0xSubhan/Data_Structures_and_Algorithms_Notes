
---
# Selection Sort

# Selection Sort (C++ Notes)

## Definition

Selection Sort is a simple sorting algorithm that repeatedly:

1. Finds the smallest element from the unsorted part
    
2. Places it at the correct position
    

# Algorithm Steps

For every index `i`:

- Assume current element is minimum
    
- Search remaining array for smaller element
    
- Update minimum index if found
    
- Swap minimum element with current position
    

# Code

```cpp
void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        std::swap(arr[i], arr[min_index]);
    }
}
```

# Working of Selection Sort

Initial Array:

```text
11 25 12 22 64
```

## Pass 1

Current position:

```text
i = 0
```

Find minimum from:

```text
11 25 12 22 64
```

Minimum = `11`

Swap with first element.

Array after pass:

```text
11 25 12 22 64
```

## Pass 2

```text
i = 1
```

Find minimum from:

```text
25 12 22 64
```

Minimum = `12`

Swap `25` and `12`

Array:

```text
11 12 25 22 64
```

## Pass 3

```text
i = 2
```

Find minimum from:

```text
25 22 64
```

Minimum = `22`

Swap:

```text
11 12 22 25 64
```

## Pass 4

```text
i = 3
```

Find minimum from:

```text
25 64
```

Minimum = `25`

No change.

Final Sorted Array:

```text
11 12 22 25 64
```

# Outer Loop

```cpp
for(int i = 0; i < size - 1; i++)
```

Purpose:

- Controls sorted portion
    
- Places one element correctly in each pass
    

Why `size - 1`?

Because last element automatically becomes sorted.

# Inner Loop

```cpp
for(int j = i + 1; j < size; j++)
```

Purpose:

- Searches unsorted portion
    
- Finds smallest element
    

# Minimum Index

```cpp
int min_index = i;
```

Stores index of smallest element.

# Swapping

```cpp
std::swap(arr[i], arr[min_index]);
```

Places smallest element at correct position.

# Time Complexity

## Best Case

```text
O(n²)
```

## Average Case

```text
O(n²)
```

## Worst Case

```text
O(n²)
```

Reason:

Nested loops perform approximately:

```
n(n-1) / 2
```

comparisons.

# Space Complexity

```text
O(1)
```

Reason:

- No extra array used
    
- Sorting done in same array
    

# Characteristics of Selection Sort

|Property|Value|
|---|---|
|In-place|Yes|
|Stable|No|
|Adaptive|No|
|Space Complexity|O(1)|
|Time Complexity|O(n²)|

# Advantages

- Simple to understand
    
- Uses very little memory
    
- Good for small datasets
    

# Disadvantages

- Slow for large datasets
    
- Performs unnecessary comparisons
    
- Not efficient compared to modern sorting algorithms

---
