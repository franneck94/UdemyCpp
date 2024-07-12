# Compiler Support

To see what features are already implemented for the compilers,  
see [here](https://en.cppreference.com/w/cpp/compiler_support).

## Important C++20 Features

| Feature          | GCC  | Clang | MSVC | Apple Clang |
| ---------------- | ---- | ----- | ---- | ----------- |
| Concepts         | Yes  | Yes   | Yes  | Part        |
| Ranges           | Yes  | Yes   | Yes  | Yes         |
| Modules          | Part | Part  | Yes  | Part        |
| Span             | Yes  | Yes   | Yes  | Yes         |
| Three-way Comp.  | Yes  | Yes   | Yes  | Yes         |
| Init. Range Loop | Yes  | Yes   | Yes  | Yes         |
| constinit        | Yes  | Yes   | Yes  | Yes         |
| Erase            | Yes  | Yes   | Yes  | Yes         |
| Coroutines       | Yes  | Part  | Yes  | Part        |
| Formatting       | Yes  | Yes   | Yes  | Yes         |

## Important C++23 Features

| Feature             | GCC  | Clang | MSVC | Apple Clang |
| ------------------- | ---- | ----- | ---- | ----------- |
| size_t suffix       | Yes  | Yes   | No   | Yes         |
| if consteval        | Yes  | Yes   | No   | Yes         |
| string contains     | Yes  | Yes   | Yes  | Yes         |
| range *_with        | Yes  | Yes   | Yes  | Yes         |
| view zip            | Yes  | Part  | Yes  | Part        |
| view join           | Yes  | Yes   | Yes  | Yes         |
| ranges to           | Part | Yes   | Yes  | No          |
| format improve      | Yes  | Yes   | Yes  | No          |
| expected            | Yes  | Yes   | Yes  | Yes         |
| Multi dim subscript | Yes  | Yes   | No   | Yes         |

## Important C++26 Features

| Feature                     | GCC  | Clang | MSVC | Apple Clang |
| --------------------------- | ---- | ----- | ---- | ----------- |
| Placeholder variables       | Yes  | Yes   | No   | No          |
| Arith. overloads to_string  | Yes  | No    | No   | No          |
| = delete("reason");         | Yes  | Yes   | No   | No          |
| constexpr stable sorting    | No   | No    | No   | No          |
| \<linalg>                   | No   | No    | No   | No          |
| views::concat               | Yes  | No    | No   | No          |
