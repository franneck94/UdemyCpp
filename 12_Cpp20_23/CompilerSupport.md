# Compiler Support

To see what features are already implemented for the compilers,  
see [here](https://en.cppreference.com/w/cpp/compiler_support).

## Important C++20 Features

| Feature          | GCC  | Clang | MSVC | Apple Clang |
| ---------------- | ---- | ----- | ---- | ----------- |
| Concepts         | Yes  | Yes   | Yes  | Part        |
| Ranges           | Part | Yes   | Yes  | Yes         |
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
| range *_with        | No   | Yes   | Yes  | No          |
| view zip            | Yes  | Part  | Yes  | Part        |
| view join           | Yes  | Yes   | Yes  | Yes         |
| ranges to           | No   | Yes   | Yes  | No          |
| format improve      | Yes  | Part  | Yes  | No          |
| expected            | Yes  | Yes   | Yes  | Yes         |
| Multi dim subscript | Yes  | Yes   | No   | Yes         |

## Important C++26 Features

| Feature                     | GCC  | Clang | MSVC | Apple Clang |
| --------------------------- | ---- | ----- | ---- | ----------- |
| Placeholder variables       | Yes  | Yes   | No   | No          |
| Arith. overloads to_string  | Yes  | No    | No   | No          |
