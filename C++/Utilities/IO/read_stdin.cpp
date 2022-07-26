#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  // declaration:
  int i2, i = 0;
  double d2, d = 0.0;
  string s2, s = " ";
  // reading by keyboard

  cin >> i2;
  cin >> d2;
  cin.get();
  getline(cin, s2);
  // printing:
  cout << i + i2 << endl;
  cout << std::fixed << std::setprecision(1) << d + d2 << endl;
  cout << s << s2;
}
