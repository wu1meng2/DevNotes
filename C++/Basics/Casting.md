## Float to int

```cpp
// truncate towards zero
static_cast<int>(a);
// truncate towards negative infinity
floor(a);
// truncate towards nearest and towards even on a tie
round(a);
// truncate towards positive infinity
ceil(a);
```