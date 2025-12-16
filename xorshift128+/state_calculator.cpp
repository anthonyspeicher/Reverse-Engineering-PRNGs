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
  xorshift128p_state outputs[4];
  xorshift128p_state state = {3, 4};

  /// adds 4 values to outputs then shifts state once more - check state with function's result for 5th output
  for (size_t i = 0; i < 4; i++) {
    outputs[i] = state;
    xorshift128p(state);
  }

  return 0;
}
