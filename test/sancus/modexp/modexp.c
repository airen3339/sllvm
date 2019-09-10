#include "modexp.h"

int modexp_enter(int base, __attribute__((secret)) int exp, int mod)
{
  int result = 0;

  if (mod != 1)
  {
    result = 1;
    base = base % mod;

#if 0
    while (exp > 0) /* Number of iterations should not depend on secret */
#else
    int i;
    for (i=0; i<(sizeof(int)*8); i++)
#endif
    {
      if ((exp & 0x01) == 0x01)
      {
        result = (result * base) % mod;
      }

      exp >>= 1;
      base = (base * base) % mod;
    }
  }

  return result;
}

// The following functions should be generated by the SLLVM but this feature
// is not supported yet.
#if 1
__attribute__((noinline, used))
static void _nds___mspabi_mpyi(int a, int b) { asm("nop"); }
__attribute__((noinline, used))
static void _ndd___mspabi_mpyi(int a, int b) { asm("nop"); }
__attribute__((noinline, used))
static void _nds___mspabi_remi(int a, int b) { asm("nop"); }
__attribute__((noinline, used))
static void _ndd___mspabi_remi(int a, int b) { asm("nop"); }
#endif
