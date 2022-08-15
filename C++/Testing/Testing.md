## Compare floating number in BOOST

https://www.boost.org/doc/libs/1_65_1/libs/test/doc/html/boost_test/testing_tools/extended_comparison/floating_point/floating_points_comparison_impl.html

#### Absolute tolerance
```cpp
#include <boost/test/unit_test.hpp>
namespace tt = boost::test_tools;
constexpr double eps = 1e-2;
double u = 0, v = 0;
BOOST_TEST( u - v == 0, tt:tolerance(eps));
```

#### Relative tolerance
```cpp
constexpr double eps = 1e-4;
double u = 2, v = 2.001;
BOOST_TEST(u == v, tt:tolerance(eps));
```