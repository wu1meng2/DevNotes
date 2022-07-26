# Sequence

## `std::vector`
```cpp
// Element access
vector<int> vec{0,1,2};
int a = vec[0];
int b = vec.at(0);
int c = vec.front();
int d = vec.back();
int* p = vec.data();

// Iterators
// point to first element
vector<int>::iterator it_begin = vec.begin();
// point to last element + 1
vector<int>::iterator it_end = vec.end();

// Reverse iterator to reverse beginning
// point to last element
vector<int>::iterator rit_begin = vec.rbegin();
// Reverse iterator to reverse end
// point to first element - 1
vector<int>::iterator rit_end = vec.rend();
```