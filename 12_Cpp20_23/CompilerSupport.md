# Compiler Support

To see what features are already implemented for the compilers, see [here](https://en.cppreference.com/w/cpp/compiler_support).

## Important C++20 Features

| Feature          | GCC  | Clang | MSVC | Apple Clang |
| ---------------- | ---- | ----- | ---- | ----------- |
| Concepts         | Yes  | Yes   | Yes  | Part        |
| Ranges           | Part | Yes   | Yes  | No          |
| Modules          | Part | Part  | Yes  | Part        |
| Span             | Yes  | Yes   | Yes  | Yes         |
| Three-way Comp.  | Yes  | Yes   | Yes  | No          |
| Init. Range Loop | Yes  | Yes   | Yes  | Yes         |
| constinit        | Yes  | Yes   | Yes  | Yes         |
| Erase            | Yes  | Yes   | Yes  | Yes         |
| Coroutines       | Yes  | Part  | Yes  | Part        |
| Formatting       | Ye   | Yes   | Yes  | No          |

## Important C++23 Features

| Feature             | GCC  | Clang | MSVC | Apple Clang |
| ------------------- | ---- | ----- | ---- | ----------- |
| size_t suffix       | Yes  | Yes   | No   | Yes         |
| if consteval        | Yes  | Yes   | No   | Yes         |
| string contains     | Yes  | Yes   | Yes  | Yes         |
| range *_with        | No   | No    | Yes  | No          |
| view zip            | Yes  | Part  | Part | No          |
| view join           | Yes  | No    | Yes  | No          |
| ranges to           | No   | No    | Yes  | No          |
| ranges *_with       | No   | No    | Yes  | No          |
| format improve      | Yes  | Part  | Yes  | No          |
| expected            | Yes  | No    | Yes  | No          |
| Multi dim subscript | Yes  | No    | Yes  | No          |
