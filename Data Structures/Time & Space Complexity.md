
### Time Complexity

> It is the amount of time taken by an algorithm to run.
> 

> Why? For making better programs and for doing comparison of algorithms, deciding which is better.
> 

E.g: If we have 2 algorithm's A and B and lets assume A require high processing and B require low processing but we ran the A on fast machine and B on the slow machine so on the perspective of the user the A will take less time and B will take more time so we cant measure time complexity by using this method we need to find another method which will be `Time Complexity.` 

> For Time complexity we have three units to write the time complexity which are following:
> - Big O Notation (preferred)
> - Theta
> - Omega

We Use Big O Notation because it describes the time complexity as Upper Bound, which tells the maximum time it will take to run the algorithm meaning worst maximum time it can take and it will not take time greater than that.  
e.g, a classic car takes maximum 6 seconds to go from 0 to 100 speed, It will not take 7 seconds ever.

### 📌 Definition:

**Time complexity** describes the **amount of time** an algorithm takes to run as a function of the input size `n`.

- It doesn’t give the exact time in seconds (since that depends on hardware, compiler, etc.).
    
- Instead, it gives a **general growth rate** (like linear, quadratic, logarithmic, etc.).
    
- It helps compare algorithms without actually running them.

#### Explanation of Point 2:

When I say **“general growth rate”**, I mean:

➡️ **We don’t care about the exact time in seconds**, but rather **how the runtime increases as input size grows**.

##### Example 1: Linear vs Quadratic

Imagine you have an algorithm that works on `n` elements.

1. **Linear (O(n))**
    
    - If `n = 10`, it does about `10` steps.
        
    - If `n = 100`, it does about `100` steps.
        
    - If `n = 1000`, it does about `1000` steps.  
        ✅ The work grows **proportionally** with input size.
        
2. **Quadratic (O(n²))**
    
    - If `n = 10`, it does about `100` steps.
        
    - If `n = 100`, it does about `10,000` steps.
        
    - If `n = 1000`, it does about `1,000,000` steps.  
        ⚠️ The work grows **much faster** than the input size — because doubling `n` makes the work grow four times.

##### Example 2: Logarithmic (O(log n))

Binary search is a good example:

- If array size = 8 → needs about 3 steps.
    
- If array size = 16 → needs about 4 steps.
    
- If array size = 1,000,000 → needs only about 20 steps!  
    ✅ Growth is **very slow** compared to input size.

👉 So by **“growth rate”** we mean: _how quickly the steps (or time taken) increase as the problem size increases._  
It’s not the exact number of operations, but the **trend** or **pattern** of growth.

### 📌 Why Important?

- For small inputs, almost any algorithm is fine.
    
- But for large inputs (like millions of data points), an efficient algorithm makes a huge difference.
    
- Example:
    
    - An `O(n)` algorithm can handle millions of elements quickly.
        
    - An `O(n^2)` algorithm may become **too slow** on the same input.

### 📌 Common Notations:

We often express time complexity using **Big-O notation**:

- **O(1)** → Constant time (fastest)
    
- **O(log n)** → Logarithmic time
    
- **O(n)** → Linear time
    
- **O(n log n)** → Log-linear time
    
- **O(n^2)** → Quadratic time

-  **O(n^3)** → Cubic time
    
- **O(2^n), O(n!)** → Exponential or factorial (very slow)

### 📌 Example:

Suppose we want to check if a number `x` exists in an array of size `n`.

1. **Linear Search** → check one by one
    
    - Worst case: `n` checks → **O(n)**
        
2. **Binary Search** (on sorted array) → divide array by 2 each time
    
    - Worst case: about `log2(n)` steps → **O(log n)**
        

👉 Binary search is much faster for large inputs.

✅ In short:  
**Time complexity tells us how the runtime of an algorithm scales with input size.** It’s a tool to reason about efficiency before coding or testing.

### Some Question:

>Since we know we are expressing the complexity in Big O Notation and in big o notation we express it as a upper bound which means we will ignore the lower degrees in the function and only count higher degree and also ignore constants. 

1. f(n) --> 2n^2 + 3n

		Since n is the lower degree we will ignore it and also constants and the high degree will remain which is n^2 and that will be our Big O Notation. O(n^2)

2. f(n) --> 4n^4 + 3n^3

		Ignore lower degree and constant which gives us 
		O(n^4)

3. f(n) --> N^2 + LogN

		Since LogN is less complex then N^2 so we will ignore the LogN and it will give us O(N^2)

4. f(n) --> 200
		Since 200 is a constant then this Big O notation will be Constant Time
		O(1)

### Time Complexity Examples Through Code

#### 1. Printing An Array from 0 to N

> For Printing an array we are iterating from 0 to n and it will iterate n number of times so our Time Complexity will be:

O(n)

#### 2. Reversing an Array

> For Reversing an Array, our approach was to first use two pointer approach and make two index one starting from start and one starting from end and swap the elements and move the index next and our loop condition was to run the loop as long as left <= right which will be N/2 where N is the size of array so our Time Complexity will be:
 
O(N) --> Where 2 was constant

#### 3. Two Loops Separate

![[Screenshot from 2025-10-01 19-06-15 1.png]]

> So if we have two separate loops then we will add the time complexity but if we have nested loop then we multiply the time complexity.
 
So for our given question the first loop is iterating from 0 To N so the time complexity will be `O(N)` and for our next loop it is also iterating from 0 To M so time complexity will be `O(M)` and after that we add the time complexity and get the following:

`O(N+M)`

#### 4. 

![[Screenshot from 2025-10-01 19-11-54.png]]

> First Loop -- > iterating from 0 to N so notation becomes O(N) and inside the nested loop it is iterating from 0 to N so Notation becomes O(N) and if we are finding complexity time of nested loop then we multiply the outerloop with inner loop and after that, Second Loop --> It is iterating from 0 to N So time complexity will be O(N) And After that we add the both complexity and get the total time complexity:
 
Loop 1 --> `O(N*N)` --> O(N^2)

Loop 2 --> O(N)

Total Time Complexity = O(N^2) + O(N) --> Lower Degree Ignored --> O(N^2)

#### 5. 

![[Screenshot from 2025-10-01 19-25-50.png]]

For Outer Loop the loop is iterating from 0 to N so the time complexity for the outer loop will be O(N) and in nested loop the loop is iterating from N To i times so in Big O Notation we count the worst case so our worst case will be that loop will iterate From N to i=0 which means complete N So the time complexity of nested loop will be O(N) And then we multiply the Complexity and get:

`O(N^2)`

>[!Important]
>Let me clear this, if there is a for loop which is iterating from 0 To N it doesn't always mean that its time complexity will be O(N) Because inside the loop lets assume we call another function which have another loop then complexity time will vary but we saw in printArray function that there were loop Which was iterating from 0 to n and its complexity was O(N) Because inside the loop there was `std::cout` whose complexity time was constant time so that's why! 

If instead of a loop, you call a function whose complexity is `O(N)`, then overall complexity also grows:

```cpp
for (int i=0; i<N; i++) {
    someFunction(N);  // suppose this function is O(N)
}
```

- Outer loop: `N`
    
- Inside call: `O(N)`
    
- Total = `O(N × N) = O(N²)`

### TLE (Time Limit Exceeded)

#### 🔹 1. What is TLE?

**TLE (Time Limit Exceeded)** means your program did not finish execution within the time limit set by the problem (usually 1–2 seconds on platforms like LeetCode, Codeforces, etc.).

Even if your algorithm is correct, if it’s too slow for the given **constraints**, the judge will stop it and give TLE.

#### 🔹 2. The **10^8 operations rule**

A common rule of thumb in C++/Java/Python competitive programming:

👉 A modern online judge can process about **10^8 simple operations per second** in C++  
(and ~10^7 for Python, since it’s slower).

So, if your algorithm requires more than `~10^8` operations for `N = max constraint`, it will probably TLE.

#### 🔹 3. Example with Constraints

Suppose LeetCode problem says:

```cpp
Constraints:
1 <= N <= 10^5
```

##### Case A: O(N²) solution

If `N = 10^5`, operations =

`(10^5)^2=10^10`

This is **100 times more than 10^8** → ❌ Will TLE.

##### Case B: O(N log N) solution

For `N = 10^5`:

`NlogN≈10^5×17≈1.7×10^6`

This is way below `10^8` → ✅ Fast enough.

##### Case C: O(N³) solution

If `N = 1000`,

`N^3=10^9`

That’s **too big** → ❌ TLE.

So typically, if constraints are `N = 10^5`, you need **O(N log N)** or better.  
If `N = 10^2` or `N = 10^3`, sometimes **O(N²)** or even **O(N³)** is acceptable.

#### 🔹 4. A LeetCode Example

**Two Sum problem** (`N` up to 10^5):

- **Brute force (O(N²))**:

```cpp
for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
        if (nums[i] + nums[j] == target) return {i,j};
    }
}
```

Worst case = `10^10` operations → ❌ TLE.

#### 🔹 5. Quick Rule of Thumb

| N (max input size) | Acceptable Complexity |
| ------------------ | --------------------- |
| 10^18+             | O(log N) or O(1)      |
| 10^7 – 10^8        | O(N)                  |
| 10^5 – 10^6        | O(N log N)            |
| 10^3 – 10^4        | O(N²)                 |
| ≤ 500              | O(N³) sometimes okay  |

✅ **Summary:**

- TLE means your algorithm is too slow for the constraints.
    
- Use the **10^8 operations rule** to quickly estimate if your solution will pass.
    
- Always check problem constraints to guess the needed time complexity.

### Space Complexity

>Space complexity ==measures the total memory an algorithm requires to run as a function of its input size, encompassing both the input data's space and any additional, temporary memory (auxiliary space) it uses==.

Creating variables doesn't create space complexity it is just constant space complex  
and same for arrays because it is known at compile time, its size so it also has constant space complexity but when we create a vector of n elements from the user then the space complexity will be O(N). 

#### 🔹 1. Space complexity = memory that **grows with input size**

- Space complexity only counts memory that depends on **input size** `N`.
    
- If the memory usage does **not grow with N** (it stays fixed), it is treated as **O(1) constant space**.

#### 🔹 2. Variables

```cpp
int x, y, z;
```

- A few integers take constant memory (e.g., 4 bytes each).
    
- Even if you write 100 variables, that’s still a **fixed amount** (doesn’t depend on N).  
    👉 Space complexity = **O(1)**.

#### 🔹 3. Arrays with fixed size

```cpp
int arr[1000];
```

- This always takes space for 1000 integers (e.g., 4000 bytes).
    
- **Known at compile time**, doesn’t depend on input.  
    👉 Space complexity = **O(1)**.
    

⚠️ Note: it’s not “tiny”, but it’s still **constant** relative to N, because it doesn’t scale when N increases.

#### 🔹 4. Arrays with size depending on input

```cpp
int arr[n];   // where n comes from user input
```

- Now the size depends on `n`.
    
- Space grows linearly with input size.  
    👉 Space complexity = **O(N)**.
    

(_In standard C++, variable-length arrays aren’t allowed, but in some compilers / C99 it works. The same idea applies if we allocate dynamically with `new int[n]`._)

#### 🔹 5. Vectors

```cpp
vector<int> v(n);   // n comes from user
```

- A vector allocates memory dynamically at runtime.
    
- If user gives `n = 1e6`, it allocates space for 1e6 integers.  
    👉 Space complexity = **O(N)**.

#### ✅ Final clarification

- **Variables (int, float, etc.)** → always O(1).
    
- **Fixed-size arrays** → O(1), because size doesn’t grow with input.
    
- **User-defined size arrays or vectors** → O(N), because memory depends on input.

####  Problem Set For Space Complexity:

```cpp
for (int i = 0; i < N; i++) {
    vector<int> a(N);
}
```

##### 🔹 Step 1: Inside the loop

`vector<int> a(N);`

- This creates a vector of size `N`.
    
- Space used in **one iteration** = `O(N)`.

##### 🔹 Step 2: Effect of loop

Now, does the vector accumulate memory across iterations?

- ❌ No. Because `a` is a **local variable** inside the loop.
    
- At the **end of each iteration**, `a` goes out of scope → memory is freed.
    
- In the next iteration, a new vector is allocated again.
    

So at **any given time**, there’s only **one vector of size N in memory**.

##### 🔹 Step 3: Final Space Complexity

- Maximum memory in use at a time = `O(N)` (for the vector).
    
- The loop does not multiply space usage, because old vectors are destroyed.
    

✅ **Answer:**  
The **space complexity** = **O(N)**.

##### ⚠️ If instead you wrote:

```cpp
vector<vector<int>> arr;
for (int i = 0; i < N; i++) {
    arr.push_back(vector<int>(N));
}
```

👉 Then memory accumulates → total space = `O(N²)`.


---
>[!Notice]
>The above is just intro to space and time complexity I we will come back to it after doing recursion and we will go in more depth.




