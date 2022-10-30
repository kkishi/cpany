#include <iomanip>

#include "constants.h"
#include "debug.h"
#include "fix.h"
#include "io.h"
#include "macros.h"

void Main();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}

using namespace std;

#define int i64
