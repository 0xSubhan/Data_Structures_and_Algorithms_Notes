# 🔍 **Understanding Binary Search in Detail**

Binary Search is a highly efficient algorithm used to **search for an element in a sorted array**. Unlike **Linear Search**, which checks each element one by one, Binary Search divides the search space in half at every step—making it much faster.

### 🆚 **Linear Search vs Binary Search**

|Aspect|Linear Search|Binary Search|
|---|---|---|
|Requirement|Array can be unsorted|Array **must be sorted** (increasing or decreasing)|
|Method|Check **one-by-one**|**Divide and conquer** (halve the array each time)|
|Time Complexity|**O(n)**|**O(log n)**|
|Worst Case|Check all elements|Very few comparisons|
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

### ✂️  How the Search Space Reduces

Binary Search doesn’t check all elements.  
It **cuts the array into half** each step:

| Step                                      | Elements Remaining |
| ----------------------------------------- | ------------------ |
| Start                                     | n                  |
| 1st step                                  | n / 2              |
| 2nd step                                  | n / 4              |
| 3rd step                                  | n / 8              |
| …                                         | …                  |
| k-th step, at kth step there is 1 element | n / (2^k)          |

We stop when **only 1 element** is left.

### ❓ **When Will It Stop?**

The algorithm stops when:

`n/2^k = 1 => n=2^k => k=log2(n)`

👉 This `k` is the **number of steps/iterations**.

### 🧾 **Time Complexity Calculation**

| Case             | Explanation                         | Complexity   |
| ---------------- | ----------------------------------- | ------------ |
| **Best Case**    | Middle is the target in first check | **O(1)**     |
| **Worst Case**   | Keep dividing until 1 element left  | **O(log n)** |
| **Average Case** | Similar to worst case               | **O(log n)** |
### 📌 **Why O(log n)? (Connecting to Log Definition)**

Recall the definition of logarithm:

> `log2(n)` = “The power to which 2 must be raised to get to n”.

OR

>  `log2(n)`= “How many times can we divide n by 2 to reach 1?”

Binary Search **divides by 2 each time**, so it takes **log₂(n) steps**, not n steps.

### 📊 **Growth Rate Understanding**

| n (elements) | Linear Search Steps (O(n)) | Binary Search Steps (O(log n)) |
| ------------ | -------------------------- | ------------------------------ |
| 16           | 16                         | 4                              |
| 1024         | 1024                       | 10                             |
| 1,000,000    | 1,000,000                  | 20                             |

🚀 Even for **1 million** elements, Binary Search uses only **20 steps!**

### 🎤 **Interview Answer: Time Complexity of Binary Search**

**Answer:**

> “Binary Search works on a sorted array by repeatedly dividing the search space in half.  
> In each step, it compares the target with the middle element and eliminates half of the elements.  
> So, instead of checking all `n` elements like linear search, it reduces the problem size to `n/2`, then `n/4`, `n/8`, and so on.
> 
> We stop when the search space becomes 1.
> 
> Mathematically, this happens when:
> 
> n2k=1⇒k=log⁡2(n)\frac{n}{2^k} = 1 \Rightarrow k = \log_2(n)2kn​=1⇒k=log2​(n)
> 
> Therefore, the time complexity of Binary Search in the worst and average case is **O(log n)**, because it performs approximately `log₂(n)` comparisons.”

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

### Code

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0 , e = arr.size() - 1;
        int mid = s + (e-s)/2;

        while(s<e)
        {
            if(arr[mid] < arr[mid+1])
            {
                s = mid + 1;
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

### ⛰️ Problem: Peak Index in a Mountain Array (Binary Search Approach)

We are given a **mountain array** (strictly increases then strictly decreases).  
The goal is to **find the peak index** — the highest point.

### 🧭 Understanding the Mountain Shape

```cpp
Index:  0   1   2   3   4   5   6
Array: [1,  3,  5,  7,  6,  4,  2]
                 ↑
               Peak = 7 at index 3
```

### 💡 Intuition Behind Binary Search on Mountain

At any point `mid`:

|Condition|Meaning|Move|
|---|---|---|
|`arr[mid] < arr[mid + 1]`|You are on **ascending slope**|Move Right → `s = mid + 1`|
|`arr[mid] > arr[mid + 1]`|You are on **peak or descending slope**||

### 🧪 Why `while (s < e)` and NOT `s <= e`?

#### ✅ Key Difference

|Condition|What It Means|
|---|---|
|`s < e`|We stop when **start meets end** (single index left → peak found)|
|`s <= e`|Typical binary search for exact value (may over-shoot + cause mid+1 out of bound checks)|

#### ⚠️ Why Risk With `s <= e`?

- In this problem, we always check `arr[mid + 1]`.
    
- If `mid == last index`, `mid + 1` becomes **out of bounds** → CRASH.
    

✅ Using `s < e` ensures `mid + 1` is ALWAYS valid.

### 🔁 Why `e = mid` and NOT `e = mid - 1`?

When `arr[mid] > arr[mid + 1]`:

```cpp
  (Descending Part)
    /\
   /  \
  /    \
      mid   mid+1
```

- This means **peak is on the left side OR mid itself can be the peak**.
    
- So, we must **keep mid** in our search.  
    → `e = mid`
    

#### ❌ If we use `e = mid - 1`:

We would **skip the current mid**, possibly missing the peak.

==we use first if part to check if we are on the left slope and if we are on left slope then we will just move start to mid+1 which will eventually points to peek when arr[mid(peek)] and arr[mid+1(now right slope)] so false now s is pointing to peek and for the right slope i dont understand why its storing mid always

### ✅ First, What You Already Understood (Correct)

✔ **Left slope** (`arr[mid] < arr[mid+1]`)  
→ Move `start = mid + 1`  
→ Because peak is on the **right side**

### 🤔 Your Doubt:

> On the right slope (descending), why do we use `e = mid` and **not `e = mid - 1`**?

### 🧭 Understanding the Right Slope (Descending Part)

On the **descending side**, `arr[mid] > arr[mid+1]`.

Example:

```Cpp
[1, 3, 5, 7, 6, 4, 2]
          ↑   ↑
        mid  mid+1
```

here:

```cpp
arr[mid] = 7   (bigger)
arr[mid+1] = 6 (smaller)
```

📌 This means:  
➡ We **already passed the peak or are at the peak**.  
➡ The **peak is on the left side**, but **mid can still be the peak**.

### 🧠 Key Rule:

When `arr[mid] > arr[mid+1]` ↠ `mid` might be the **actual peak**!

So we **cannot skip mid** by doing `e = mid - 1`.  
We **must include mid again** → `e = mid`.

### 🗺️ Visual Direction of Search

#### On Left Slope (Increasing) → Peak is RIGHT

```cpp
   /  (move right)
  /
 /
s     mid      e
```

→ **`s = mid + 1`**

#### On Right Slope (Decreasing) → Peak is LEFT or HERE!

```cpp
    \ (move left but include mid)
     \
s     mid     e
```

→ **`e = mid`** (include mid because it might be peak!)

### 🔍 Final Converging to Peak

Eventually `s == e`, and both point to the peak index. // this will cause the loop to exit

### 🧾 Summary in Your Own Terms (Easy to Memorize):

|Situation|Condition|Movement|Why|
|---|---|---|---|
|Left slope (still climbing)|`arr[mid] < arr[mid+1]`|`s = mid + 1`|Peak is ahead (right)|
|Right slope / Peak area|`arr[mid] > arr[mid+1]`|`e = mid`|Mid _might be the peak_|

### 💬 In Your Words (What You Should Say in Interview)

> "We move right when slope is ascending.  
> But on descending, we move left using `e = mid`, not `mid-1`, because `mid` can still be the peak itself."

### ⛰ Example Where `mid` Is the Peak

```cpp
Array:
[1,   3,   5,   8,   6,   4,   2]
              ↑
             mid  (peak = 8)
```

Let’s assume during binary search we calculate:

```cpp
s = 0, e = 6
mid = (0 + 6) / 2 = 3
arr[mid] = 8
arr[mid + 1] = 6
```

✅ Condition:

```cpp
arr[mid] > arr[mid + 1]   → 8 > 6 → TRUE  (Descending side)
```

### 🧠 Now Important Decision!

If we do:

|Choice|Update|Result|
|---|---|---|
|❌ `e = mid - 1`|Remove mid|We LOSE the peak (mid = 8)|
|✅ `e = mid`|Keep mid|Peak is still in search|
### ❌ WRONG: `e = mid - 1` (We lose the peak!)

```cpp
[1, 3, 5, 8, 6, 4, 2]
           ↑   (lost)
           mid
```

You remove `8`, the actual peak → **Wrong answer!**

### ✅ CORRECT: `e = mid` (We keep the peak)

Because **mid itself can be the peak** if:

```cpp
arr[mid] > arr[mid - 1]  AND  arr[mid] > arr[mid + 1]
```

(Which is true in this case: `8 > 5` and `8 > 6`)

### 🗣 Final Interview Answer from You

> "When `arr[mid] > arr[mid+1]`, we are on the right side or at the peak.  
> We set `e = mid` because mid might still be the peak itself.  
> If we used `mid-1`, we might skip and lose the peak."

**Array:**  
`[1, 3, 5, 8, 6, 4, 2]`

We are using **Binary Search** with the condition:

```cpp
while (s < e) {
    int mid = s + (e - s) / 2;
    if (arr[mid] < arr[mid + 1]) { // We're on the left slope
        s = mid + 1;
    } else {                      // We're on the right slope or at peak
        e = mid;
    }
}
return s; // or return e;
```

### **Index View**

|Index|0|1|2|3|4|5|6|
|---|---|---|---|---|---|---|---|
|Value|1|3|5|8|6|4|2|

Peak = `8` at index **3**

### 🔎 **Dry Run Step-by-Step**

|Step|`s`|`e`|`mid`|`arr[mid]`|`arr[mid+1]`|Condition|Action|
|---|---|---|---|---|---|---|---|
|**1**|0|6|`3`|8|6|`8 < 6` → **false**|`e = mid` → `e = 3`|
|**2**|0|3|`1`|3|5|`3 < 5` → **true**|`s = mid + 1` → `s = 2`|
|**3**|2|3|`2`|5|8|`5 < 8` → **true**|`s = mid + 1` → `s = 3`|

Now:  
`s = 3`, `e = 3` → `while(s < e)` stops.

🔚 **Return `s = 3`**, which is the peak index (value = 8).

### 🤔 Why Did We Set `e = mid` When Falling Down?

At **Step 1**, mid = 3 → `8 < 6` → false  
This means **we are on the right side of the peak or at the peak itself**

- We **do not drop `mid`**, because `mid` itself **may be the peak**.
    
- That’s why we assign **`e = mid`**, not `mid - 1`.
    

If we used `mid - 1`, we might **skip the peak**!

### 🎯 Key Observations

#### 🔼 Left Slope Case (`arr[mid] < arr[mid+1]`)

We move **right → `s = mid + 1`** because we know peak is ahead.

#### 🔽 Right Slope or Peak (`arr[mid] >= arr[mid+1]`)

We move **left, but safely → `e = mid`** because `mid` could be the peak.

### 🧠 Final Logic

|Situation|What it means|Move|
|---|---|---|
|`arr[mid] < arr[mid+1]`|You are on **left slope**|`s = mid + 1`|
|`arr[mid] >= arr[mid+1]`|You are on **right slope or at peak**|`e = mid`|

---
