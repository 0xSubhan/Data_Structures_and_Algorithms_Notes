# 🔍 **Understanding Binary Search in Detail**

Binary Search is a highly efficient algorithm used to **search for an element in a sorted array**. Unlike **Linear Search**, which checks each element one by one, Binary Search divides the search space in half at every step—making it much faster.

### 🆚 **Linear Search vs Binary Search**

| Aspect          | Linear Search         | Binary Search                                       |
| --------------- | --------------------- | --------------------------------------------------- |
| Requirement     | Array can be unsorted | Array **must be sorted** (increasing or decreasing) |
| Method          | Check **one-by-one**  | **Divide and conquer** (halve the array each time)  |
| Time Complexity | **O(n)**              | **O(log n)**                                        |
| Worst Case      | Check all elements    | Very few comparisons                                |
|                 |                       |                                                     |
### 🧠 Key Concept Before Using Binary Search

> **The array must be sorted** — either in **increasing order** or **decreasing order**.  
> This is because Binary Search makes decisions based on comparison — “Should I go left or right?”

### 🪜 Working of Binary Search – Step-by-Step Logic

Let’s say you have a **sorted** array:

You want to search for: **13**

#### ✅ Step 1: Define Start and End

- `start = 0`
    
- `end = n - 1`
    

#### ✅ Step 2: Find Mid

```CPP
mid = (start + end) / 2
```

- Here: `(0 + 4) / 2 = 2`
    
- `arr[mid] = 9`

#### ✅ Step 3: Compare Key with Mid

- Key = 13
    
- `13 > 9` → Go **right side** (because array is sorted in increasing order) , because if key is greater than mid element that would mean mid element is smaller than key so in left there would be smaller element which are not only smaller than key but also mid element so we have to go right.

#### ✅ Step 4: Narrow Down Search

Now focus on the **right half** only:

```cpp
[13, 27]
Index: 3, 4
```

Start = 3, End = 4 → mid = `(3 + 4) / 2 = 3`

- `arr[mid] = 13` → MATCH! ✅
    

Return index **3**

### 🎯 Decision Rules in Binary Search

|Comparison|Action|
|---|---|
|`key == arr[mid]`|Element FOUND → Return index|
|`key > arr[mid]`|Search in **RIGHT** half (`start = mid + 1`)|
|`key < arr[mid]`|Search in **LEFT** half (`end = mid - 1`)|
### 🤔 When Element is Not Found

Example:

```cpp
[5, 11, 13, 17, 19, 27]
Search: 25
```

You will keep reducing the search space until `start > end`.  
At that point ✅ **Return -1** → Element doesn’t exist.

### 🧮 Time Complexity Advantage

|Input Size|Linear Search|Binary Search|
|---|---|---|
|1000 elements|1000 comparisons|~10 comparisons|
|1,000,000 elements|1,000,000 comps|~20 comparisons|

🔋 Binary Search is **super fast** for large datasets!

### ⚠️ Important: Integer Overflow Mistake in Mid Formula

Naïve formula:

```cpp
mid = (start + end) / 2
```

If `start` and `end` are very large integers → Overflow ❌

Correct (Safe) formula:

```cpp
mid = start + (end - start) / 2
```

### 💻 Binary Search Code Logic (Simplified)

```cpp
int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) 
            return mid;
        else if(arr[mid] < key) 
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return -1; // Not found
}
```

My Version:

```cpp
int binarySearch(int arr[],int size,int key)
{
    int start = 0 , end = size - 1;
    int mid = start + (end-start)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(key > arr[mid]) // choosing right path  
        {
            start = mid + 1;
        }
        else // choosing left path
            end = mid - 1;

        int mid = start + (end-start)/2;   
    }
    return -1;    
}
```

### 🏆 Final Summary

✅ Binary Search works only on **sorted/monotonic arrays**  
✅ Repeatedly divides search space into halves  
✅ Uses **mid** to make decisions → left or right  
✅ Extremely fast → `O(log n)`  
✅ Return `index` if found, `-1` if not found

## O(log n) — Binary Search Complexity

### The Core Idea

Binary search works on a **sorted array** by repeatedly cutting the search space in **half**.

Each step eliminates 50% of remaining elements. So if you start with `n` elements:

|Step|Elements Remaining|
|---|---|
|0|n|
|1|n/2|
|2|n/4|
|3|n/8|
|k|n/2ᵏ|

You stop when 1 element remains: `n/2ᵏ = 1` → `k = log₂(n)`

So the number of steps = **log₂(n)** → **O(log n)**

### Real Numbers Example

|Array Size (n)|Binary Search Steps|Linear Search (worst)|
|---|---|---|
|8|3|8|
|1,000|~10|1,000|
|1,000,000|~20|1,000,000|
|1,000,000,000|~30|1,000,000,000|

> Searching **1 billion** elements takes only **~30 steps**. That's the power of O(log n).


## 🎤 How to Answer in an Interview

### Step 1 — State the complexity upfront

> _"Binary search runs in O(log n) time."_

### Step 2 — Explain WHY (the halving argument)

> _"At every step, we compare the target with the middle element. Based on the result, we discard half the array. So with n elements, we can only halve it log₂(n) times before the search space becomes 1."_

### Step 3 — Give the math intuitively

> _"If n = 1 million, log₂(1,000,000) ≈ 20. So we find the answer in at most 20 comparisons — that's incredibly efficient compared to a linear scan."_

### Step 4 — Mention the prerequisite

> _"The key requirement is that the array must be **sorted**. Binary search doesn't work on unsorted data."_

### Step 5 — Mention space complexity too (bonus points)

> _"Space complexity is O(1) for the iterative version since we only use a few pointers. The recursive version uses O(log n) space due to the call stack."_


### Bonus: If asked "Why log and not something else?"

> _"Because we're dividing by 2 each time. Repeated halving is the definition of a logarithm — the question 'how many times can I divide n by 2?' is answered by log₂(n)."_

---
# Question: [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

**Input:** nums = [5,7,7,8,8,10], target = 8
**Output:** [3,4]

**Example 2:**

**Input:** nums = [5,7,7,8,8,10], target = 6
**Output:** [-1,-1]

**Example 3:**

**Input:** nums = [], target = 0
**Output:** [-1,-1]


```cpp
class Solution {
public:
    // Finding first occurence:
    int firstOcc(vector<int>& arr,int target)
    {
        int s = 0 , e = arr.size() - 1;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e)
        {
            if(arr[mid] == target)
            {
                ans = mid;
                e = mid - 1; 
            }
            else if(arr[mid] < target) // move right
            {
                s = mid + 1;
            }
            else if(arr[mid] > target) // move left
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    // Finding second occurence:
    int secondOcc(vector<int>& arr,int target)
    {
        int s = 0 , e = arr.size() - 1;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e)
        {
            if(arr[mid] == target)
            {
                ans = mid;
                s = mid + 1; 
            }
            else if(arr[mid] < target) // move right
            {
                s = mid + 1;
            }
            else if(arr[mid] > target) // move left
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> firstAndlast;
        firstAndlast.push_back(firstOcc(nums,target));
        firstAndlast.push_back(secondOcc(nums,target)); 

        return firstAndlast;
    }
};
```

--> My Approach:

> For finding first occurrence, i made start and end and made mid and for storing index of first occurrence `ans` i followed binary search approach in which i started from mid and if mid match my target then we still don't know if its first occurrence so we know that our array is sorted so now we have to go left to check if target is also available in that portion and will do so until we find the first occurrence and we would do so by moving the end index to mid-1 which will take us to left portion.
> 

> Its same for last occurrence but now if we find target we move right by moving start to mid+1!


### 🔍 1️⃣ **Function: firstOcc()**

**Goal:** Find the **first (leftmost)** index where `target` appears.

#### ✨ Key Idea:

Even if you find the target, keep searching **left side** to check if it appears earlier.

#### 🧾 Notes:

- `ans = -1` → Default if target not found.
    
- `e = mid - 1` → Continue searching **left** side.
    
- Returns **first index** of target.

### 🔁 2️⃣ **Function: secondOcc()**

**Goal:** Find the **last (rightmost)** index where `target` appears.

#### ✨ Key Difference:

After finding target, search **right side** for later occurrence.

#### 🧾 Notes:

- Similar to `firstOcc()`, but searches in **right direction**.
    
- Returns **last index** of target.

### 🧭 Summary Table

|Function|Direction|When Found Target|Purpose|
|---|---|---|---|
|`firstOcc()`|Search Left|`e = mid - 1`|First Index|
|`secondOcc()`|Search Right|`s = mid + 1`|Last Index|

> If we wanted to find total number of occurrence of the target we can use same code with following logic:
> (last occurrence index - first occurrence index)+1 // +1 because of indexing because index starts from 0
> In between will be the same element as you may know because of the sorted array it cannot be higher than or less than target.
> Think of it like this that how many elements are being skipped in between of last and first occurrence and that will be our total number of occurrence.

---
# Peak Index in a Mountain Array

### Statement

You are given an integer **mountain** array `arr` of length `n` where the values increase to a **peak element** and then decrease.

Return the index of the peak element.

Your task is to solve it in `O(log(n))` time complexity.

# Intutive Approach

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1 , end = arr.size() - 2; // excluding first and last index!
        int mid = start + (end-start)/2;

        while(start<=end)
        {
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid-1] < arr[mid]) // we are on the left slope
            {
                start = mid+1; // move to right
            }
            else // we are on the right slope
            {
                end = mid -1;
            }
            mid = start + (end-start)/2;
        } 
        return -1;
    }
};
```

==first it checks if mid is peak if not then it checks if we are on the left increasing slope if yes then move to right but the thing to note here is that if we havent checked the peak condition first then it the increasing condition would mean two things that we are on the increasing slope or we are acutally on the peek so if we havent check for peak first then the logic will break and if we are not on the increasing slope and not at the peek that would mean that we are on the decreasing slope and peek logic is same as increasing logic that if we havent check for peek first then it would mean that we are on the decreasing slope or at the peek but we have already checked that we are not at peek so it would mean we are in decreasing slope which would mean move to left where we will find the peek!

### 🔍 Understanding the Logic Flow in That Code

That code does **three checks in order**, and the **order is VERY important**:

### ✅ Step-by-Step Logic

1️⃣ **First check → Is `mid` the peak?**

```cpp
if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
```

If we don't do this check first, we might accidentally move away from the real peak because both slopes can look like you're still going toward the peak.

2️⃣ **If not a peak, check → Are we on the _increasing_ slope?**

```cpp
else if (A[mid - 1] < A[mid])
```

This condition means:

- We might still be climbing toward the peak **OR**
    
- We are actually _at the peak_ — but that was already caught in check #1.
    

So moving `st = mid + 1` is safe here.

3️⃣ **Else → We must be on the _decreasing_ slope**

```cpp
else {
    end = mid - 1;
}
```

Why?

- If it's **not peak** (checked in #1)
    
- And **not increasing** (checked in #2)  
    👉 Then the only possibility left is decreasing (peak is behind).

### 💡 Why Peak Must Be Checked First?

|Without Peak Check First|Problem|
|---|---|
|`A[mid - 1] < A[mid]`|Might be **peak OR ascending** → confusion|
|`A[mid - 1] > A[mid]`|Might be **peak OR descending** → mistake|

You correctly understood:

> If we don't check the peak first, the logic **cannot distinguish** between the real peak and just a slope.

### ✅ Your Summary (Cleaned Up Version)

> "First, the code checks if `mid` is the peak. If we didn’t check that before checking slopes, the slope conditions would be confusing—`increasing` could mean we're either still climbing or already on the peak. Once peak is safely ruled out, only then we inspect whether we are on increasing or decreasing slope. Based on that, we move right or left to continue searching for the peak."

### 🤔 But why not just use `start < end`?

In many binary search variations (like **finding peak in a mountain array using comparisons**), you can use `start < end` because you're guaranteed to converge at the peak.

However, **in your approach**, you are explicitly checking `mid - 1` and `mid + 1`, and returning `mid` only when you satisfy:

```cpp
if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
```

That means your algorithm may **reduce the range fully** and needs to check even the last possible candidate, so you allow `start == end`.

### 🏔 Visualizing the shrinking search range

|start|end|mid|Still valid?|
|---|---|---|---|
|3|6|4|✅|
|5|6|5|✅|
|6|6|6|✅ (last possible)|
|7|6|❌ stop (crossed over)||

You must allow the loop to run **even when `start == end`**, or you might miss the peak.

### ✅ Summary: Why `start <= end`?

✔ Allows checking every possible valid index  
✔ Ensures peak detection even at the final narrowed point  
✔ Standard practice when return happens **inside** the loop

### ✨ In Short:

|Exclusion|Reason|
|---|---|
|First index (0)|Cannot be peak, no left neighbor|
|Last index (n-1)|Cannot be peak, no right neighbor|
|Middle only|Safe, fully checkable positions|
>first and last element of array cannot be peek because we know that array is sorted in a manner that it is forming a mountain !

### ❌ Why First Element (index 0) Cannot Be Peak?

At index `0`, there is **no left element** to compare with.  
For a peak, you must satisfy:

```cpp
arr[i-1] < arr[i] > arr[i+1]
```

But at `i = 0`:

- `arr[-1]` → Does not exist ❌
    
- Also, the array must _increase_ from index 0 to 1. That means:

```cpp
arr[0] < arr[1]   → already increasing
```

- So arr[0] is _not_ a peak.

> Same for decreasing slope because there is not element at the right of the last element!


---
# Question: - Find Pivot in an Sorted & Rotated Array using Binary Search

```cpp
class Solution {
  public:
    int getPivot(vector<int>& arr) {
        // Code Here
        int s = 0; int e = arr.size()-1;
        int mid = s + (e-s)/2;
        while(s<e)
        {
            if(arr[mid] >= arr[0])
            {
                s = mid+1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e-s)/2;

        }
        return s;
    }
};
```

# ✅ **What is a Sorted & Rotated Array?**

A **sorted & rotated array** is originally sorted in increasing order, but then some elements from the beginning are moved to the end.  
Example:

```cpp
Original sorted array: [1, 2, 3, 4, 5, 6, 7]
Rotated:               [4, 5, 6, 7, 1, 2, 3]
```

In such an array, there is one special point where the rotation happens.  
This point is called the **pivot**.

# 🎯 **What is the Pivot?**

The **pivot** is the **index of the smallest element** in the array.

It is the point where the sorted order breaks.

Example:

```cpp
[4, 5, 6, 7, 1, 2, 3]
               ↑
             pivot (value 1)
```

Why smallest element?  
→ Because rotation always puts the smallest element at the break point.


# ⭐ **Pivot Finding Using arr[mid] >= arr[0] (Short Notes)**

### **Purpose**

- To find the **pivot** (index of smallest element) in a **sorted & rotated array**.
    

### **Key Observation**

- The rotated array splits into two sorted parts:
    
    - **First block:** all elements **≥ arr[0]**
        
    - **Second block:** all elements **< arr[0]** (pivot lies here)

# ⭐ **Binary Search Logic**

### **1. Compute mid**

```cpp
mid = s + (e - s)/2

```

### **2. Check which block mid belongs to**

#### **Case A — arr[mid] >= arr[0]**

- Mid is in the **first sorted block**
    
- Pivot is on the **right**

```cpp
s = mid + 1

```

#### **Case B — arr[mid] < arr[0]**

- Mid is in the **second sorted block**
    
- Pivot is on the **left (or at mid)**

```cpp
e = mid

```

### **3. Recompute mid each iteration**

# ⭐ **Stopping Condition**

- When `s == e`, binary search finishes
    
- That index is the **pivot**

# ⭐ **Why This Works**

- In rotated array, all numbers before pivot are ≥ arr[0]
    
- All numbers after pivot are < arr[0]
    
- Comparing with arr[0] tells us exactly which block mid is in

# ⭐ **Final Output**

```cpp
return s;   // pivot index

```

# ⭐ **Why `while (s < e)` and not `<=`?**

### ✔ Reason 1:

We want to stop when the search space is reduced to **one index**.

When:

```cpp
s == e
```

→ Only **one element** is left  
→ That element **must** be the pivot  
→ No need to check further  
→ Loop stops

If we used `s <= e`, the loop would run even when only one element is left, causing extra steps or a wrong state.

---
# Question: - Search an Element in a Sorted & Rotated array using Binary Search

# ⭐ **Question Statement Explained**

You are given an array that was originally **sorted in ascending order**, but then it was **rotated** at some pivot point that is unknown to you.

### ✔ Example of rotation

Original sorted array:

```cpp
[1, 2, 3, 4, 5, 6, 7]
```

Rotated at pivot 3:

```cpp
[4, 5, 6, 7, 1, 2, 3]
```

The array is still made of **two sorted parts**, just shifted.

# ⭐ **Your Task**

Given:

- **A sorted & rotated array**
    
- **A target element**
    

You must **find the index of that target** using an algorithm that is **better than linear search (O(n))**.

The expected solution is to apply **binary search logic**, achieving **O(log n)** time.

# ⭐ **What Makes the Question Important?**

A normal binary search cannot be applied directly because the array is **not fully sorted** — only **two parts are sorted**.

So the challenge is:

### ✔ How to modify binary search

### ✔ How to identify which half is sorted

### ✔ How to decide where to move (left or right)

## Solution:

```cpp
class Solution {
public:
int binarySearch(vector<int>& arr,int s,int e,int key)
{
    int start = s , end = e;
    int mid = start + (end-start)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(key > arr[mid]) // choosing right path  
        {
            start = mid + 1;
        }
        else // choosing left path
            end = mid - 1;

        mid = start + (end-start)/2;   
    }
    return -1;    
}
    int getPivot(vector<int>& arr) {
        // Code Here
        int s = 0; int e = arr.size()-1;
        int mid = s + (e-s)/2;
        while(s<e)
        {
            if(arr[mid] >= arr[0])
            {
                s = mid+1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e-s)/2;

        }
        return s;
    }    
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);

        if(nums[pivot] <= target && nums[nums.size()-1] >= target)
        {
            // On the right slope!
            return binarySearch(nums,pivot,nums.size()-1,target);
        }else
        {
            return binarySearch(nums,0,pivot-1,target);
        }
        return -1;
    }
};
```

# 📌 **NOTES — Search in Sorted & Rotated Array (Binary Search Approach)**

# **1️⃣ Understanding `getPivot()` – Finding the Rotation Point**

### **Goal:**

Find the **index of the smallest element** → the place where rotation happened.  
This index divides the array into two sorted halves. So if we have pivot then we will have two missing element found! initially we knew the value of start and end but not the pivot by having pivot we have both those values now we decide based on this decision where to search!

### **Logic Behind It:**

- In a rotated sorted array:  
    Left part (before pivot) is **sorted but larger**, right part (from pivot onward) is **sorted but smaller**.
    
- Example: `[7,8,9,1,2,3]`  
    Pivot = index of **1**.
    

### **Algorithm Behavior:**

- Use binary search pattern with `s < e`
    
- Compute `mid`
    
- Compare with first element `arr[0]`
    

### **Key Observations:**

- If `arr[mid] ≥ arr[0]`  
    → Mid is in **left (larger)** part of rotation  
    → Move right: `s = mid + 1`
    
- Else  
    → Mid is in **right (smaller)** part  
    → Move left: `e = mid`
    
- Loop continues until `s == e`
    
- At the end:  
    **`s` and `e` both point to the pivot index**
    

### **Result:**

`return s;`

# **2️⃣ Understanding `binarySearch()` – Normal Binary Search**

We know that So move on kid!

# **3️⃣ Understanding `search()` – Use Pivot to Decide the Correct Half**

### **Goal:**

Use the pivot to divide the array into **two sorted subarrays**, then binary search in the correct one.

### **Step-by-step logic:**

## **Step 1: Find pivot index**

```cpp
pivot = getPivot(nums)
```

## **Step 2: Decide in which sorted half the target lies**

Two halves:

### **Left half:**

Indices → `0` to `pivot-1`  
Sorted and contains elements **≥ nums[0]**

### **Right half:**

Indices → `pivot` to `n-1`  
Sorted and contains elements **≤ nums[n-1]**

## **Check which half contains the target:**

```cpp
if (nums[pivot] <= target && nums[n-1] >= target)
```

This condition checks if target lies in the **right sorted half**.

- If true → search in `[pivot ... n-1]`
    
- Else → search in `[0 ... pivot-1]`

## **Step 3: Perform binary search on selected half**

```cpp
return binarySearch(nums, pivot, nums.size()-1, target)
```

OR

```cpp
return binarySearch(nums, pivot, nums.size()-1, target)
```

# ✅ **SUMMARY (Super Quick Notes)**

### **`getPivot()`**

- Finds smallest element index = rotation point.
    
- Uses binary search with condition:
    
    - `arr[mid] >= arr[0]` → move right
        
    - else → move left
        
- Ends when `s == e`.
    

### **`binarySearch()`**

- Standard binary search inside a sorted interval.
    

### **`search()`**

- Use pivot to determine which sorted half contains the target.
    
- Apply binary search only in that half.
    

# 📌 **Time Complexity Analysis (Big-O)**

For the whole algorithm:

# **1️⃣ Time Complexity of `getPivot()`**

### Why?

- `getPivot()` uses **binary search** logic.
    
- In every iteration:
    
    - You cut the search space in half.
        
- Loop runs until `s == e`.
    

### Complexity:

```cpp
O(log n)
```

# **2️⃣ Time Complexity of `binarySearch()`**

### Why?

- Standard binary search.
    
- Search range size ≤ n.
    
- Each step halves the range.
    

### Complexity:

```cpp
O(log n)
```

# **3️⃣ Time Complexity of `search()`**

`search()` does two things:

1. Calls `getPivot()` → `O(log n)`
    
2. Calls `binarySearch()` (once) → `O(log n)`
    

### Add them together:

```cpp
O(log n) + O(log n) = O(2 log n)
```

In Big-O notation, constants are ignored:

Final:

```cpp
O(log n)
```

# **Why O(log n)? (Intuition)**

- Even though the array is rotated, you still reduce the problem size by half in each step.
    
- You use binary search **twice**, but that still keeps complexity logarithmic.
    
- Therefore, total time is still **logarithmic**, not linear.

---
# [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/)

# 📘 **Explanation of the `mySqrt` Function (Binary Search Approach)**

The task is to compute the **integer square root** of a number `x`.  
Integer square root means:  
👉 the **largest number** whose square is **≤ x** (floor of √x).

Example:

- √10 = 3.16 → return **3**
    
- √16 = 4 → return **4**

## 🔹 **1. Initialize Search Space**

```cpp
int s = 0;
int e = x;
```

We assume the square root lies between **0 and x**.

- Smallest possible √x = 0
    
- Largest possible √x = x (e.g., √1 = 1)

## 🔹 **2. Calculate mid**

```cpp
long long int mid = s + (e - s) / 2;
```

- Prevents overflow
    
- Checks the middle number of the current range
    

## 🔹 **3. Main Binary Search Loop**

```cpp
while (s <= e)
```

We keep shrinking the search space until start crosses end.

## 🔹 **4. Check if mid is the exact square root**

```cpp
if(square == x)
    return mid;
```

Perfect square → immediately return.

## 🔹 **5. If mid² is too big, move LEFT**

```cpp
else if(mid*mid > x)
    e = mid - 1;
```

- mid is too large
    
- answer must be **smaller**
    
- shrink right boundary

## 🔹 **6. If mid² is smaller than x → move RIGHT**

```cpp
else {
    ans = mid;       // IMPORTANT
    s = mid + 1;
}
```

### Why `ans = mid`?

Because:

- mid² < x → mid is a **valid square root candidate**
    
- But there might be a **bigger valid number**, so search right
    
- Save `mid` as the **best answer found so far**
    

This ensures that if no perfect square is found,  
we still have the **correct floor value** in `ans`.

## 🔹 **7. Recalculate mid after updating s or e**

```cpp
mid = s + (e - s) / 2;
```

## 🔹 **8. Return ans**

```cpp
return ans;
```

If the loop ends without finding a perfect match,  
`ans` holds the **largest number whose square ≤ x**.

# ✅ **CASE 1: mid is TOO SMALL**

`mid * mid < x`

Example:  
You want √10.  
You try mid = 3 → 3×3 = 9 < 10 → TOO SMALL.

What does this mean?

- Maybe **3 is the answer**
    
- Maybe **something bigger** like 4 could be the answer
    
- So you **SAVE 3** because it is still a possible answer
    
- And you try bigger numbers
    

So we write:

```cpp
ans = mid;
```

Because **mid might be the correct answer**.

# ❌ **CASE 2: mid is TOO BIG**

`mid * mid > x`

Example:  
mid = 4 → 4×4 = 16 > 10 → TOO BIG.

What does this mean?

- 4 can **never** be the answer.
    
- 4 is **not possible**, not even close.
    
- Anything bigger than 4 is also impossible.
    
- So we NEVER save 4.
    

If we did:

```cpp
ans = 4;
```

We would be saving a **wrong** answer!

# ⭐ KEY IDEA

We only save `mid` when mid is **a possible answer**.

### ✔ mid² < x → mid might be right → SAVE IT

### ✖ mid² > x → mid can never be right → DON’T save it


---
```cpp
double precision(int n,int pre, int temp)
{
    double factor = 1;
    double ans = temp;
    for (int i = 0; i < pre; i++)
    {
        factor = factor / 10;

        for (double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

```

# 📘 Notes on `precision(int n, int pre, int temp)`

## 🔹 Purpose of the Function

This function improves the accuracy of a square root that was already computed in **integer form** (usually by binary search).  
It adds **decimal precision** to the answer by refining one digit at a time.

# 🔹 Function Meaning

```cpp
double precision(int n, int pre, int temp)
```

- **n** → number whose square root we want
    
- **pre** → number of decimal places (precision)
    
- **temp** → integer square root (floor value) already calculated
    

It returns a `double` containing √n accurate up to `pre` decimal places.

# 🔹 Key Variables

### **factor**

Starts as 1, and becomes smaller each loop:

- After 1st iteration → 0.1
    
- After 2nd → 0.01
    
- After 3rd → 0.001
    

This tells us how much to increase the number while searching decimals.

### **ans**

Stores the best (most accurate) square-root value found so far.  
Starts as `temp`, the integer square root.

# 🔹 Outer Loop Logic

```cpp
for(int i = 0; i < pre; i++)
{
    factor = factor / 10;
```

Each loop increases decimal precision:

|i|factor|Meaning|
|---|---|---|
|0|0.1|Find 1st decimal place|
|1|0.01|Find 2nd decimal place|
|2|0.001|Find 3rd decimal place|
# 🔹 Inner Loop Logic

```cpp
for(double j = ans; j*j < n; j = j + factor)
{
    ans = j;
}
```

### How this works:

- Start `j` from the current best answer (`ans`)
    
- Keep increasing `j` by small steps (`factor`)
    
- Stop when `j * j` becomes **greater than or equal** to `n`
    
- The last valid `j` (i.e., `j*j < n`) is saved in `ans`
    

This finds the correct digit at the current decimal place.

# 🔹 Example (n = 10, temp = 3, pre = 2)

**First decimal place:**  
factor = 0.1  
Try: 3.0 → 3.1 → 3.2 (stop at 3.2 because 3.2² > 10)  
→ ans = 3.1

**Second decimal place:**  
factor = 0.01  
Try: 3.1 → 3.11 → … → 3.16 (3.17² > 10)  
→ ans = 3.16

Final answer: **3.16**

# 🔹 Summary of Logic

1. Start with integer √n
    
2. Reduce step size each loop (0.1 → 0.01 → 0.001...)
    
3. Move forward step-by-step until the square exceeds `n`
    
4. Save the last valid value in `ans`
    
5. Repeat for required decimal places
    

# 🔹 Final Output

Returns a refined √n accurate up to `pre` decimal places.


---
# Book Allocation Problem

![[Book_allocation_problem_notes.pdf]]

# Solution

```cpp
class Solution {
  public:
  
    bool isPossible(vector<int> &arr, int k, int size, int mid)
    {
        int pageSum = 0;
        int student = 1;
        
        for(int i = 0; i < size; i++)
        {
            if( arr[i] + pageSum <= mid )
            {
                pageSum += arr[i]; 
            }
            else
            {
                student++;
                pageSum = arr[i];
                if( arr[i] > mid || student > k ) return false;
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int ans = -1;
        int maxi = -1;
        int size = arr.size();
        
        if(k > size) return ans;
        
        for(int i = 0; i < size; i++)
        {
            maxi = max(maxi,arr[i]);
        }
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        int low = maxi;
        int high = sum;
        
        int mid = low + (high-low) / 2;
        
        while(low <= high)
        {
            if( isPossible(arr,k,size,mid) )
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + (high-low) / 2;
        }
        return ans;
    }
};
```

# 🔹 Time Complexity

- `isPossible()` → O(n)
    
- Binary search → O(log(n)) : n = sum of pages !!!
    

### Total:

```
O(n * log(sum))
```

# 🔹 Intuition Summary

Think of it like:

> ==“What is the smallest maximum load I can assign so that all students are satisfied?”

- Try a value (`mid`)
    
- Check feasibility
    
- Adjust search space
    

==so book allocation problem in simple term is minimizing the maximum load

---
# Painter's Partition Problem

https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

```cpp
class Solution {
  public:
    
    bool isPossible(vector<int>& arr, int k,int size,int mid)
    {
        int painterCount = 1;
        int timeSum = 0;
        
        for(int i=0; i < size; i++)
        {
            if(arr[i]+timeSum <= mid)
            {
                timeSum += arr[i];
            }
            else
            {
                painterCount++;
                if(painterCount > k || arr[i] > mid)
                {
                    return false;
                }
                timeSum = arr[i]; 
            }
        }
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        // code here
        int ans = -1;
        int sum = 0;
        int size = arr.size();
        if( k > size ) return ans;
        for(int i=0; i < size; i++)
        {
            sum += arr[i];
        }
        int s = 0; int e = sum;
        
        int mid = s + (e-s) / 2;
        
        while(s <= e)
        {
            if( isPossible(arr,k,size,mid) )
            {
                e = mid - 1;
                ans = mid;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e-s) / 2;
        }
        return ans;
    }
};
```

---
# Aggressive Cows Problem

## Problem Statement

You are given:

- `N` stalls positioned on a number line
- An array `stalls[]` representing stall positions
- `K` aggressive cows

You must place the cows in the stalls such that:

- Only one cow can be placed in one stall
- The **minimum distance between any two cows is maximized**

Return that maximum possible minimum distance.

## Example

```
Stalls = [1, 2, 4, 8, 9]
K = 3
```

We need to place 3 cows in these stalls such that:

> The minimum distance between any two cows is as large as possible.

We are NOT trying to maximize:

- total distance
- average distance

We are trying to maximize:

	the smallest distance between any two cows

### Placement 1

```
1   2   4   8   9
C   C   C
```

Cow positions:

```
1, 2, 4
```

Distances:

```
2 - 1 = 1
4 - 2 = 2
```

Minimum distance:

```
min(1,2) = 1
```

So this arrangement gives minimum distance = 1.

### Placement 2

```
1   2   4   8   9
C       C   C    
```

Cow positions:

```
1, 4, 8
```

Distances:

```
4 - 1 = 3
8 - 4 = 4
```

Minimum distance:

```
min(3,4) = 3
```

This is better because:

```
3 > 1
```

### Placement 3

```
1   2   4   8   9
C           C   C
```

Cow positions:

```
1, 8, 9
```

Distances:

```
8 - 1 = 7
9 - 8 = 1
```

Minimum distance:

```
min(7,1) = 1
```

Bad arrangement again.

## Best Arrangement

The best arrangement is:

```
1, 4, 8
```

because the minimum distance becomes:

```
3
```

And we cannot make it larger.

## Key Observation

We are trying to:

> Maximize the minimum distance.

This sentence is the biggest hint for:

### Binary Search on Answer

Because:

- If a distance `d` is possible,  
    then all smaller distances are also possible.
- If a distance `d` is not possible,  
    then all larger distances are impossible.

This creates a **monotonic behavior**, which is perfect for binary search.


# Step-by-Step Approach

# Step 1: Sort the stalls

Why?

Because distances only make sense in sorted order.

```
sort(stalls.begin(), stalls.end());
```

Example:

```
[4, 1, 8, 2, 9]→ [1, 2, 4, 8, 9]
```

# Step 2: Define Search Space

What can be the minimum distance?

### Lowest possible

```
1
```

### Highest possible

```
last stall - first stall
```

Example:

```
9 - 1 = 8
```

So binary search range:

```
low = 1high = 8
```

# What Are We Binary Searching?

We are NOT binary searching the array.

We are binary searching:

## “possible minimum distance”

# Important Thought

We ask:

```
Can minimum distance = X work?
```

If YES:

```
maybe bigger distance also works // because we are maximizing the minimum distance
```

If NO:

```
we must reduce distance
```

That’s why binary search works.

# Binary Search Iteration 1

```
[1, 2, 4, 8, 9]
```

## Current Range

```
low = 1
high = 8
```

Compute middle:

`mid=4`

So now we ask:

### “Can we place 3 cows with minimum distance 4?”


## Check Distance = 4

### Place First Cow

Always place first cow at first stall.

```
Place at 1
```

Visual:

```
1   2   4   8   9
C
```

### Place Second Cow

Need next cow at:

`1+4=5`

Meaning:

```
next stall must be ≥ 5
```

Check stalls:

```
2 ❌4 ❌8 ✅
```

Place second cow at 8.

Visual:

```
1   2   4   8   9
C           C
```

### Place Third Cow

Need next cow at:

`8 + 4 = 12 `

Check stalls:

```
9 ❌
```

No valid stall.

Only 2 cows placed.

## Therefore

```
distance = 4 is NOT possible
```

## What Does This Tell Us?

If distance 4 cannot work:

```
5,6,7,8 also cannot work
```

Why?

Because larger distance is even harder.

So discard right half.

Move:

```
high = mid - 1
high = 3
```

Now:

```
low = 1
high = 3
```

# Binary Search Iteration 2

Compute middle:

`mid = 2`

Ask:

# “Can distance = 2 work?”


# Check Distance = 2

## Place First Cow

At 1.

```
1   2   4   8   9
C
```

## Place Second Cow

Need:

	`1 + 2 = 3`

Check:

```
2 ❌4 ✅
```

Place at 4.

```
1   2   4   8   9
C       C
```

## Place Third Cow

Need:

`4 + 2 = 6`

Check:

```
8 ✅
```

Place at 8.

```
1   2   4   8   9
C       C       C
```

Successfully placed all 3 cows.

# Therefore

```
distance = 2 works
```

# What Now?

Since 2 works:

```
maybe larger distance also works
```

So we try bigger answers.

Store:

```
ans = 2
```

Move:

```
low = mid + 1
low = 3
```

Now:

```
low = 3
high = 3
```

# Binary Search Iteration 3

Compute middle:

`mid = 3`

Ask:

# “Can distance = 3 work?”


# Check Distance = 3


## First Cow

At 1.

## Second Cow

Need:

`1 + 3 = 4`

Check:

```
2 ❌
4 ✅
```

Place at 4.

## Third Cow

Need:

`4 + 3 = 7`

Check:

```
8 ✅
```

Place at 8.

All cows placed successfully.

So:

```
distance = 3 works
```


# Since It Works

Store:

```
ans = 3
```

Try bigger:

```
low = 4
```

Now:

```
low = 4
high = 3
```

# Stop Condition

Binary search stops when:

```
low > high
```

because no search space remains.

# Final Answer

```
ans = 3
```

# Most Important Understanding

We tested:

```
2 → works
3 → works
4 → fails
```

So maximum possible minimum distance is:

```
3
```


# Why Binary Search Works

Notice the pattern:

```
1 → works
2 → works
3 → works
4 → fails
5 → fails
```

This is:

```
TTTTFFFF
```

Binary search is perfect for such monotonic behavior.

# The Greedy Placement Logic

Why do we always place cows as early as possible?

Because:

```
placing earlier leaves maximum roomfor remaining cows
```

If greedy placement cannot fit all cows:

```
no other placement can
```

That is the key proof behind the approach.









```cpp
class Solution {
  public:
  
    bool isPossible(vector<int> &stalls, int k,int size,int mid)
    {
        int cowCount = 1;
        int lastPos = stalls[0];
        
        for(int i = 0; i < size; i++)
        {
            if( stalls[i] - lastPos >= mid )
            {
                cowCount++;
                if(cowCount == k) return true;
                lastPos = stalls[i];
            }
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int ans = -1;
        int size = stalls.size();
        int s = 0;
        int maxi = -1;
        for(int i = 0; i < size; i++)
        {
            maxi = max(maxi,stalls[i]);
        }
        int e = maxi;
        int mid = s + (e-s) / 2;
        
        while( s <= e )
        {
            if( isPossible(stalls,k,size,mid) )
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s) / 2;
        }
        return ans;
    }
};
```


---
