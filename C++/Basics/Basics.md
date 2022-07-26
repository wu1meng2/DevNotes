### Data type

Use the following to check the data type of C++ variables
```cpp
#include <typeinfo>

int i = 1;
std::cout << typeid(i).name() << std::endl;
```