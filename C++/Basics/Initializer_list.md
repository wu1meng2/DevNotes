# Many ways to initialize
```cpp
int i(1);
int i{1};
int i = 1;
int i = {1};
int i = int(1);
int i = int{1};
```

# Uniform initialization
https://stackoverflow.com/questions/50422129/differences-between-direct-list-initialization-and-copy-list-initialization#

https://stackoverflow.com/questions/25612262/why-does-auto-x3-deduce-an-initializer-list

### `auto` + uniform initialization
On the ond hand, a braced initializer expression `{...}` is a `std::initializer_list<T>` by itself. "By itself" means no other type specifiers. Also the elements within `{}` must be of the same type for the `{}` expression to be deduced as a `std::initializer_list<T>`. On the other hand, `{1}` in `int x{1}` will be treated as `int x(1)`. 
```cpp
auto x1 = {1, 2}; // x1 is a std::initializer_list<int>
auto x2 = {1, 2.0}; // error, cannot determine type T
auto x3{1, 2}; // error, not a single element
auto x4 = {3}; // x4 is std::initializer_list<int>
auto x5{3}; // x5 is int(3)
```

## Direct-list-initialization vs copy-list-initialization

`std::vector` has a copy assignment operator with `initializer_list<T>` as argument.
```cpp
// copy-list-initialization
std::vector<int> v2 = {1, 2, 3};
```

`std::vector` has a constructor with `initializer_list<T>` as argument.
```cpp
// direct-list-initialization
std::vector<int> v1 {1, 2, 3};
```

**Differences**
1. If a constructor is marked as `explicit`, then there is a compile error if the list-initialization is a copy-list-initialization
2. Given an enum-type with a fixed underlying size, you cannot copy-list-initialize from a value. `enumeration e{value}` works, but not `enumeration e = {value}`.

Caveat: Initializer lists will always favor a matching initializer_list constructor over other potentially matching constructors.

**Best practice**
If you provide list construction, it’s a good idea to provide list assignment as well.