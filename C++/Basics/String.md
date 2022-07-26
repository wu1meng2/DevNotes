### Conversion between int and string
Use `struct` to declare multiple variables within for loop.
```cpp
#include <iostream>
#include <string>  // for std::stoi(...)

int main() {
  for (
      struct {
        int num = 0;
        std::string cha = "0";
      } v{};
      v.num < 3 && v.cha.size() < 10; v.num++, v.cha += std::to_string(v.num)) {
    std::cout << v.num << " " << std::stoi(v.cha) << std::endl;
  }
}
```

### Difference between "" and ''
```cpp
char c = 'x'; // 'x' is a single character literal
char *s = "Hello World"; // "Hello World" is a string literal, as well as a null-terminated strings char* ending with '\0'
```
