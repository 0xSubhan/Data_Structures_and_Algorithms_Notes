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
> n/2^k=1⇒k=log⁡2(n)\frac{n}{2^k} = 1 \Rightarrow k = \log_2(n)2kn​=1⇒k=log2​(n)
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

| Condition                 | Meaning                                 | Move                       |
| ------------------------- | --------------------------------------- | -------------------------- |
| `arr[mid] < arr[mid + 1]` | You are on **ascending slope**          | Move Right → `s = mid + 1` |
| `arr[mid] > arr[mid + 1]` | You are on **peak or descending slope** |                            |

### 🧪 Why `while (s < e)` and NOT `s <= e`?

#### ✅ Key Difference

| Condition | What It Means                                                                            |
| --------- | ---------------------------------------------------------------------------------------- |
| `s < e`   | We stop when **start meets end** (single index left → peak found)                        |
| `s <= e`  | Typical binary search for exact value (may over-shoot + cause mid+1 out of bound checks) |

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
    int search(vector<int>& arr, int key) {
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

---

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
