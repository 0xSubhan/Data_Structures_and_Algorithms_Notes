# Introduction to Arrays

> We mentioned that arrays fall into two categories:

- **Fixed-size arrays** (also called *fixed-length arrays*) require that the length of the array be known at the point of instantiation, and that length cannot be changed afterward. C-style arrays and `std::array` are both fixed-size arrays.
- **Dynamic arrays** can be resized at runtime. `std::vector` is a dynamic array.

In the previous chapter, we focused on `std::vector`, as it is fast, comparatively easy to use, and versatile. This makes it our go-to type when we need an array container.

## So why not use dynamic arrays for everything?

Dynamic arrays are powerful and convenient, but like everything in life, they make some tradeoffs for the benefits they offer.

- `std::vector` is slightly less performant than the fixed-size arrays. In most cases you probably won’t notice the difference (unless you’re writing sloppy code that causes lots of inadvertent reallocations).
- `std::vector` only supports `constexpr` in very limited contexts.

In modern C++, it is really this latter point that’s significant. `constexpr` arrays offer the ability to write code that is more robust, and can also be optimized more highly by the compiler. Whenever we can use a `constexpr` array, we should — and if we need a `constexpr` array, `std::array` is the container class we should be using.

> [!Best practice]
> Use `std::array` for `constexpr` arrays, and `std::vector` for non-`constexpr` arrays.

## Defining a `std::array`

> `std::array` is defined in the `<array>` header. It is designed to work similarly to `std::vector`, and as you’ll see, there are more similarities than differences between the two.

One difference is in how we declare a `std::array`:

```cpp
#include <array>  // for std::array
#include <vector> // for std::vector

int main()
{
    std::array<int, 5> a{};  // a std::array of 5 ints

    std::vector<int> b(5);   // a std::vector of 5 ints (for comparison)

    return 0;
}
```

Our `std::array` declaration has two template arguments.

- The first (`int`) is a type template argument defining the type of the array element.
- The second (`5`) is an integral non-type template argument defining the array length.

## The length of a `std::array` must be a constant expression

Unlike a `std::vector`, which can be resized at runtime, the length of a `std::array` must be a constant expression.

Most often, the value provided for the length will be an integer literal, `constexpr` variable, or an unscoped enumerator (which is `constexpr` by default).

```cpp
#include <array>

int main()
{
    std::array<int, 7> a{}; // Using a literal constant

    constexpr int len{ 8 };
    std::array<int, len> b{}; // Using a constexpr variable

    enum Colors
    {
        red,
        green,
        blue,
        max_colors
    };

    std::array<int, max_colors> c{}; // Using an enumerator

#define DAYS_PER_WEEK 7
    std::array<int, DAYS_PER_WEEK> d{}; // Using a macro (don't do this, use a constexpr variable instead)

    return 0;
}
```

Note that non-`const` variables and runtime constants cannot be used for the length:

```cpp
#include <array>
#include <iostream>

void foo(const int length) // length is a runtime constant
{
    std::array<int, length> e{}; // error: length is not a constant expression
}

int main()
{
    // using a non-const variable
    int numStudents{};
    std::cin >> numStudents; // numStudents is non-constant

    std::array<int, numStudents>{}; // error: numStudents is not a constant expression

    foo(7);

    return 0;
}
```

### Runtime constant (like `const int`)

```cpp
void foo(const int length)
{
    std::array<int, length> e{}; // ❌ error
}
```

- Even though `length` is declared `const`, its value is passed at runtime when calling `foo(7)`.
- `const` here just means it **can’t change inside the function**, but it is not a **compile-time constant**.
- Therefore, the compiler still doesn’t know the value when generating code → error.

> [!Warning]
> Perhaps surprisingly, a `std::array` can be defined with a length of 0:
> ```cpp
> #include <array>
> #include <iostream>
>
> int main()
> {
>     std::array<int, 0> arr{}; // creates a zero-length std::array
>     std::cout << arr.empty(); // true if arr is zero-length
>
>     return 0;
> }
> ```
> A zero-length `std::array` is a special-case class that has no data. As such, calling any member function that accesses the data of a zero-length `std::array` (including `operator[]`) will fail.
> You can test whether a `std::array` is zero-length using the `empty()` member function, which returns `true` if the array is zero-length and `false` otherwise.

## Aggregate initialization of a `std::array`

Perhaps surprisingly, `std::array` is an aggregate. This means it has no constructors, and instead is initialized using aggregate initialization.

```cpp
#include <array>

int main()
{
    std::array<int, 6> fibonnaci = { 0, 1, 1, 2, 3, 5 }; // copy-list initialization using braced list
    std::array<int, 5> prime{ 2, 3, 5, 7, 11 };         // list initialization using braced list (preferred)

    return 0;
}
```

Each of these initialization forms initializes the array members in sequence, starting with element `0`.

If a `std::array` is defined without an initializer, the elements will be default initialized. In most cases, this will result in elements being left uninitialized.

Because we generally want our elements to be initialized, `std::array` should be value initialized (using empty braces) when defined with no initializers.

```cpp
#include <array>
#include <vector>

int main()
{
    std::array<int, 5> a;   // Members default initialized (int elements are left uninitialized)
    std::array<int, 5> b{}; // Members value initialized (int elements are zero initialized) (preferred)

    std::vector<int> v(5);  // Members value initialized (int elements are zero initialized) (for comparison)

    return 0;
}
```

> If more initializers are provided in an initializer list than the defined array length, the compiler will error. If fewer initializers are provided in an initializer list than the defined array length, the remaining elements will be value initialized.

```cpp
#include <array>

int main()
{
    std::array<int, 4> a{ 1, 2, 3, 4, 5 }; // compile error: too many initializers
    std::array<int, 4> b{ 1, 2 };          // b[2] and b[3] are value initialized

    return 0;
}
```

## `const` and `constexpr std::array`

A `std::array` can be `const`:

```cpp
#include <array>

int main()
{
    const std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    return 0;
}
```

Even though the elements of a `const std::array` are not explicitly marked as `const`, they are still treated as `const` (because the whole array is `const`).

`std::array` also has full support for `constexpr`:

```cpp
#include <array>

int main()
{
    constexpr std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    return 0;
}
```

This support for `constexpr` is the key reason to use `std::array`.

> [!Best practice]
> Define your `std::array` as `constexpr` whenever possible. If your `std::array` is not `constexpr`, consider using a `std::vector` instead.

### What `constexpr` means

1. The object/function can be **evaluated at compile time**.
2. Its value is a **constant expression** and can be used where a compile-time constant is required.

So if you make an `std::array` `constexpr`, it means:

- The array itself will be created **at compile time**, not at runtime.
- Its elements must all be **known at compile time** too.

## Class template argument deduction (CTAD) for `std::array` (C++17)

> Using CTAD (class template argument deduction) in C++17, we can have the compiler deduce both the element type and the array length of a `std::array` from a list of initializers:

```cpp
#include <array>

int main()
{
    constexpr std::array a1{ 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
    constexpr std::array a2{ 9.7, 7.31 };     // The type is deduced to std::array<double, 2>

    return 0;
}
```

We favor this syntax whenever practical. If your compiler is not C++17 capable, you’ll need to explicitly provide the type and length template arguments.

> [!Best practice]
> Use class template argument deduction (CTAD) to have the compiler deduce the type and length of a `std::array` from its initializers.

CTAD does not support partial omission of template arguments (as of C++23), so there is no way to omit just the length or just the type of a `std::array` using only core language features:

```cpp
#include <array>

int main()
{
    constexpr std::array<int> a2{ 9, 7, 5, 3, 1 }; // error: too few template arguments (length missing)
    constexpr std::array<5> a2{ 9, 7, 5, 3, 1 };   // error: too few template arguments (type missing)

    return 0;
}
```

## Omitting just the array length using `std::to_array` (C++20)

### The problem before C++20

When using `std::array`, you normally need to specify **both the type and the size** explicitly:

```cpp
std::array<int, 5> arr{ 9, 7, 5, 3, 1 };
```

This is fine, but sometimes redundant because the compiler already knows the size and type from the initializer list.

Unfortunately, template argument deduction (TAD) in C++17 and earlier could not deduce the `N` (size) part.

### The C++20 solution → `std::to_array`

C++20 introduced a helper function `std::to_array` that **deduces** template arguments automatically.

#### 1) Specify both type and size

```cpp
constexpr auto myArray1{ std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) };
```

- Here, you explicitly give both the element type (`int`) and length (`5`).
- Equivalent to:

```cpp
constexpr std::array<int, 5> myArray1{ 9, 7, 5, 3, 1 };
```

#### 2) Specify type only (size deduced)

```cpp
constexpr auto myArray2{ std::to_array<int>({ 9, 7, 5, 3, 1 }) };
```

- Compiler deduces that the size is `5` from the initializer list.
- Type is explicitly given (`int`).

#### 3) Deduce both type and size

```cpp
constexpr auto myArray3{ std::to_array({ 9, 7, 5, 3, 1 }) };
```

- Compiler deduces:
  - type = `int`
  - size = `5`
- Simplest form.

Equivalent to writing:

```cpp
constexpr std::array<int, 5> myArray3{ 9, 7, 5, 3, 1 };
```

### Why is `std::to_array` sometimes needed?

Normally, C++ literals default to `int`. But what if you want an `std::array<short>`?

```cpp
std::array<short, 5> arr{ 9, 7, 5, 3, 1 }; // works, but you must specify size
```

With `std::to_array`:

```cpp
constexpr auto shortArray{ std::to_array<short>({ 9, 7, 5, 3, 1 }) };
```

- Type = `short` (explicit)
- Size = deduced (`5`)

This avoids repetition and makes code cleaner.

### Performance caveat

`std::to_array` creates a temporary `std::array` and then copies it into your variable.

- For single global constants (`constexpr`), this cost is negligible.
- But if used inside a loop where arrays are created repeatedly, it may be inefficient compared to writing `std::array<int, 5>` directly.

### When to use `std::to_array`

- When you want **type or size deduction** to avoid redundancy.
- When working with **non-`int` literals** (like `short`, `char`, etc.).
- For **readability** in `constexpr` contexts.

Avoid it in tight loops or performance-critical sections.

## Accessing array elements using `operator[]`

> Just like a `std::vector`, the most common way to access elements of a `std::array` is by using the subscript operator (`operator[]`):

```cpp
#include <array> // for std::array
#include <iostream>

int main()
{
    constexpr std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3]; // print the value of element with index 3 (7)
    std::cout << prime[9]; // invalid index (undefined behavior)

    return 0;
}
```

As a reminder, `operator[]` does not do bounds checking. If an invalid index is provided, undefined behavior will result.

---

# `std::array` length and indexing

> `std::array` faces the same issue of unsigned values as `std::vector` because they are part of the same standard library container class.

Now would be a good time to refresh your memory on **“sign conversions are narrowing conversions, except when `constexpr`”**.

Because if it is `constexpr`, the compiler can determine at compile time whether it is a narrowing conversion or not.

## The length of a `std::array` has type `std::size_t`

`std::array` is implemented as a template struct whose declaration looks like this:

```cpp
template <typename T, std::size_t N> // N is a non-type template parameter
struct array;
```

As you can see, the non-type template parameter representing the array length (`N`) has type `std::size_t`.

> [!Important]
> The length of the `std::array` must be a constant expression (`constexpr`).

Thus, when we define a `std::array`, the length non-type template argument must either have type `std::size_t`, or be convertible to a value of type `std::size_t`.

Because this value must be `constexpr`, it must be known at compile time.

## The length and indices of `std::array` have type `size_type` (always `std::size_t`)

Just like a `std::vector`, `std::array` defines a nested typedef member named `size_type`, which is an alias for the type used for the length (and indices, if supported) of the container.

Note that the non-type template parameter defining the length of the `std::array` is explicitly `std::size_t` rather than `size_type`. This is because `size_type` is a member of the container type, and therefore not usable until after the container itself is instantiated.

```cpp
template <typename Container>
void printIndices(const Container& c)
{
    for (typename Container::size_type i = 0; i < c.size(); ++i)
    {
        std::cout << i << " ";
    }
}
```

- Works for `std::array`, `std::vector`, `std::deque`, etc.
- If instead you wrote `std::size_t`, it would still work in practice (since most containers use `std::size_t`), but using `size_type` makes it more correct and future-proof.

## Getting the length of a `std::array`

There are three common ways to get the length of a `std::array` object.

### 1) `size()` member function

Ask the array for its length using the `size()` member function (which returns the length as unsigned `size_type`):

```cpp
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr{ 9.0, 7.2, 5.4, 3.6, 1.8 };
    std::cout << "length: " << arr.size() << '\n';

    return 0;
}
```

This prints:

```
length: 5
```

### 2) `std::size()` (C++17)

In C++17, we can use the `std::size()` non-member function (which for `std::array` just calls the `size()` member function, thus returning the length as unsigned `size_type`).

### 3) `std::ssize()` (C++20)

In C++20, we can use the `std::ssize()` non-member function, which returns the length as a large **signed** integral type (usually `std::ptrdiff_t`).

## Getting the length of a `std::array` as a `constexpr` value

Because the length of a `std::array` is `constexpr`, each of the above functions will return the length of a `std::array` as a `constexpr` value (even when called on a non-`constexpr` `std::array`).

```cpp
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 }; // note: not constexpr for this example
    constexpr int length{ static_cast<int>(std::size(arr)) };

    std::cout << "length: " << length << '\n';

    return 0;
}
```

> [!Warning]
>
> ### The situation
>
> You want to get the length of a `std::array` at compile time using `std::size`.
>
> Works fine in `main`:
>
> ```cpp
> std::array arr{ 9, 7, 5, 3, 1 };
> constexpr int length{ std::size(arr) }; // ✅ okay
> ```
>
> Fails in a function:
>
> ```cpp
> void printLength(const std::array<int, 5>& arr)
> {
>     constexpr int length{ std::size(arr) }; // ❌ compile error (prior to C++23)
> }
> ```
>
> Why? When you pass `arr` as a function parameter, it is treated like a normal runtime reference. Due to a language defect (before C++23), the compiler doesn’t propagate the fact that `arr.size()` is known at compile time when the array is passed by reference.
>
> Fix in C++23 (P2280):
>
> ```cpp
> void printLength(const std::array<int, 5>& arr)
> {
>     constexpr int length{ std::size(arr) }; // ✅ works in C++23
> }
> ```

## Subscripting `std::array` using `operator[]` or the `at()` member function

We covered that the most common way to index a `std::array` is to use the subscript operator (`operator[]`). No bounds checking is done in this case, and passing in an invalid index will result in undefined behavior.

Just like `std::vector`, `std::array` also has an `at()` member function that does subscripting with runtime bounds checking.

Both of these functions expect the index to be of type `size_type` (`std::size_t`).

If either of these functions are called with a `constexpr` value, the compiler will do a `constexpr` conversion to `std::size_t`. This isn’t considered to be a narrowing conversion.

However, if either of these functions are called with a non-`constexpr` signed integral value, the conversion to `std::size_t` is considered narrowing and your compiler may emit a warning.

## `std::get()` does compile-time bounds checking for `constexpr` indices

C++ provides a function template:

```cpp
template <std::size_t I, class T, std::size_t N>
constexpr T& get(std::array<T, N>& arr) noexcept;
```

- The index `I` is a non-type template parameter, so it must be `constexpr`.
- This means the compiler knows the index at compile time.

Inside the implementation of `std::get`, there is a `static_assert(I < N)` which:

- passes if the index is valid,
- fails (compilation error) if the index is out of range.

Example:

```cpp
#include <array>
#include <iostream>

int main()
{
    constexpr std::array prime{ 2, 3, 5, 7, 11 };

    std::cout << std::get<3>(prime); // ✅ prints 7
    std::cout << std::get<9>(prime); // ❌ compile error, index 9 out of bounds
}
```

Unlike `at()` which throws at runtime, `std::get` stops compilation if you use an invalid `constexpr` index.

---

# Passing and returning `std::array`

An object of type `std::array` can be passed to a function just like any other object.

That means if we pass a `std::array` by value, an expensive copy will be made.

Therefore, we typically pass a `std::array` by (const) reference.

With a `std::array`, both the element type and array length are part of the type information of the object. Therefore, when we use a `std::array` as a function parameter, we have to explicitly specify `<T, N>`.

```cpp
#include <array>
#include <iostream>

void passByRef(const std::array<int, 5>& arr) // we must explicitly specify <int, 5> here
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 }; // CTAD deduces type std::array<int, 5>
    passByRef(arr);

    return 0;
}
```

CTAD doesn’t (currently) work with function parameters, so we cannot just specify `std::array` here and let the compiler deduce the template arguments.

## Using function templates to pass `std::array` of different element types or lengths

If you want a function to accept any `std::array` of any type and any length, you can make your function a template with the same parameters:

```cpp
template <typename T, std::size_t N>
void passByRef(const std::array<T, N>& arr)
{
    static_assert(N != 0); // disallow empty arrays
    std::cout << arr[0] << '\n';
}
```

When you call `passByRef()` with a `std::array`, the compiler deduces `T` and `N` from the argument.

### Why `N` must be `std::size_t`, not `int`

`std::array` is declared with `std::size_t` for its length.

If you mistakenly write:

```cpp
template <typename T, int N> // ❌ wrong
void func(const std::array<T, N>& arr) { /* ... */ }
```

Templates don’t do implicit conversions, so it won’t match `std::array<T, N>`.

### Templating only part of it

If you only care about the length and want to force the type to `int`:

```cpp
template <std::size_t N>
void passByRef(const std::array<int, N>& arr)
{
    std::cout << arr[0] << '\n';
}
```

This restricts the function to only `int` arrays, but any size.

### Auto non-type template parameters (C++20)

In C++20, we can use `auto` in a template parameter declaration to have a non-type template parameter deduce its type from the argument:

```cpp
template <typename T, auto N>
void passByRef(const std::array<T, N>& arr)
{
    static_assert(N != 0); // fail if this is a zero-length std::array
    std::cout << arr[0] << '\n';
}
```

## Static asserting on array length

You wrote a function template that assumes every array passed in has at least 4 elements (index `3` must exist). But templates don’t enforce that — so it can compile and cause undefined behavior.

Two solutions:

1) Use `std::get<Index>()` (compile-time checking)

```cpp
std::cout << std::get<3>(arr) << '\n';
```

2) Use `static_assert`

```cpp
template <typename T, std::size_t N>
void printElement3(const std::array<T, N>& arr)
{
    static_assert(N > 3, "Array must have at least 4 elements");
    std::cout << arr[3] << '\n';
}
```

### Key insight

Before C++23, `std::size(arr)` is only `constexpr` when `arr` is a local variable, not when it’s a function parameter. So before C++23, the only thing you can reliably use is the template parameter `N`, which is always a compile-time constant.

---

## Returning a `std::array`

Returning an `std::array` by value is okay when:

- The array isn’t huge.
- The element type is cheap to copy (or move).
- The code isn’t performance-sensitive.

```cpp
#include <array>
#include <iostream>
#include <limits>

// return by value
template <typename T, std::size_t N>
std::array<T, N> inputArray()
{
    std::array<T, N> arr{};
    std::size_t index{ 0 };

    while (index < N)
    {
        std::cout << "Enter value #" << index << ": ";
        std::cin >> arr[index];

        if (!std::cin) // handle bad input
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        ++index;
    }

    return arr;
}

int main()
{
    std::array<int, 5> arr{ inputArray<int, 5>() };

    std::cout << "The value of element 2 is " << arr[2] << '\n';

    return 0;
}
```

### Returning a `std::array` via an out parameter

In cases where return by value is too expensive, we can use an out-parameter instead:

```cpp
#include <array>
#include <limits>
#include <iostream>

template <typename T, std::size_t N>
void inputArray(std::array<T, N>& arr)
{
    std::size_t index{ 0 };

    while (index < N)
    {
        std::cout << "Enter value #" << index << ": ";
        std::cin >> arr[index];

        if (!std::cin) // handle bad input
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        ++index;
    }
}

int main()
{
    std::array<int, 5> arr{};
    inputArray(arr);

    std::cout << "The value of element 2 is " << arr[2] << '\n';

    return 0;
}
```

The primary advantage of this method is that no copy of the array is ever made, so this is efficient.

Downsides:

- It’s non-conventional (not obvious the function modifies the argument).
- You can only assign values to the array, not initialize it.
- Such a function cannot be used to produce temporary objects.

## Returning a `std::vector` instead

`std::vector` is move-capable and can be returned by value without making expensive copies. If you’re returning a `std::array` by value, your `std::array` probably isn’t `constexpr`, and you may want to consider returning a `std::vector` instead.

---

# `std::array` of class types and brace elision

A `std::array` isn’t limited to elements of fundamental types. The elements can be any object type.

### Defining and assigning to a `std::array` of structs

Let’s start with a simple struct:

```cpp
// (continued)