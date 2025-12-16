/**
 * @author: Anthony Speicher
 * @date: 12/15/2025
 * @brief: reversal of the xorshift128+ algorithm given at https://en.wikipedia.org/wiki/Xorshift
**/

#include "generators/cpp_generator.cpp"
#include <cstdint>
#include <iostream>
using namespace std;

void reverse_xorshift128p(xorshift128p_state &state)
{
  /// these are backwards because the state is switched
  uint64_t s = state.x[0];
  uint64_t t = state.x[1];

  /// since bit shifting is linear, we can use the unaffected bits (string of digits
  /// of length n when t << n as each character shifted is 0, and anything xor'd with 0
  /// is itself) to gain pieces of the original code one segment of n length at a time.

  /// reverse t ^= s ^ (s >> 5)
  t ^= s ^ (s >> 5);

  /// reverse t ^= t >> 18
  t ^= t >> 18;

  /// reverse t ^= t << 23
  t ^= t << 23;
  t ^= t << 46;

  state.x[1] = s;
  state.x[0] = t;
}

int main() {
  /// initialize state and perform a shift cycle
  xorshift128p_state state = {45, 643};
  cout << "Original state: " << state.x[0] << ", " << state.x[1] << endl;

  xorshift128p(state);
  cout << "Shifted state: " << state.x[0] << ", " << state.x[1] << endl;

  /// reverse and output results
  reverse_xorshift128p(state);
  cout << "Reversed state: " << state.x[0] << ", " << state.x[1] << endl;

  return 0;
}
