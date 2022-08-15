# Test-driven development

## Minimal test program

```cpp
#define BOOST_TEST_MODULE Simple testcases
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(simple_test) {
  BOOST_CHECK_EQUAL(2+2, 4);
}

BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_CHECK_EQUAL(2+2, 4);
}

BOOST_AUTO_TEST_CASE(test2) {
    BOOST_CHECK_EQUAL(2*2, 4);
}

BOOST_AUTO_TEST_SUITE_END()
```

## CMake

##

# References
1. https://alexott.net/en/cpp/CppTestingIntro.html