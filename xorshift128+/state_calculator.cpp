/**
 * @author: Anthony Speicher
 * @date: 12/15/2025
 * @brief: algorithm to determing state of the xorshift128+ algorithm given at https://en.wikipedia.org/wiki/Xorshift
 * using 4 outputs of the function (t + s)
**/

#include "generators/cpp_generator.cpp"
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  /// initializing state and output list
  uint64_t outputs[4];
  /// seed state
  xorshift128p_state state = {3, 4};

  /// adds 4 return values to outputs
  for (size_t i{0}; i < 4; i++) {
    outputs[i] = xorshift128p(state);
  }

  /// shift a 5th time to check with function's result for 5th output
  xorshift128p(state);

  xorshift128p_state test1 {7, 4};
  xorshift128p_state test2 {3, 4};

  xorshift128p(test1);
  xorshift128p(test2);

  cout << test1.x[0] << ", " << test1.x[1] << endl;
  cout << test2.x[0] << ", " << test2.x[1] << endl;

  return 0;
}
