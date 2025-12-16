/**
 * @author: Anthony Speicher
 * @date: 12/15/2025
 * @brief: C++ implementation of the xorshift128+ algorithm referenced at https://en.wikipedia.org/wiki/Xorshift
**/

#include <cstdint>

struct xorshift128p_state {
  uint64_t x[2]; /// 128 bit state comprised of two 64-bit integers
};

/// state must not contain only 0's
uint64_t xorshift128p(xorshift128p_state &state)
{
  /// load previous state - t and s are the old state values
  uint64_t t = state.x[0];
  uint64_t const s = state.x[1];

  /// rotate state - first integer becomes the second (so they don't evolve independently)
  state.x[0] = s;

  /// core calculations
  t ^= t << 23; 
  t ^= t >> 18;
  t ^= s ^ (s >> 5);

  /// update second integer to hold new state
  state.x[1] = t;

  /// output
  return t + s;
}
