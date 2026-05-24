
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
# Bubble Sort

## Definition

Bubble Sort is a sorting algorithm that:

- compares adjacent elements
- swaps them if they are in the wrong order
- repeats the process until the array becomes sorted

Largest elements “bubble up” to the end after every pass.

```cpp
// Online C++ compiler to run C++ program online
#include <iostream>
#include <utility>

void BubbleSort(int arr[],int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main() {
    
    int arr[5] = {12,5,10,6,11};
    int size = 5;
    
    for(int i = 0 ; i < size ; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    BubbleSort(arr,size);
    
    for(int i = 0 ; i < size ; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";    

    return 0;
}
```

# Outer Loop

```cpp
for (int i = 0; i < n - 1; i++)
```

Controls number of passes.

## Why `n - 1` passes?

Because after every pass:

- one largest element reaches correct position

Imagine arranging 5 students by height.

If first 4 positions are already correct:

- the last student automatically stands in correct place.

No extra checking needed.

>In our case last element mean first element which will already be sorted !

# Main Idea

When we say:

```
last remaining element
```

we mean:

- the only element whose position was not explicitly fixed by passes

In Bubble Sort:

- large elements get fixed from the end
- eventually only the smallest/front element remains

And yes:  
that remaining first element is automatically sorted.

# Why `n - i - 1`?

After every pass:

- largest element reaches correct position at the end

So we don't need to check that portion again.

# Time Complexity

## Worst Case

Reverse sorted array.

```
O(n²)
```

---
