#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
namespace math {
  double binary_sigmoidal(double x) {
    return 1 / (1 + exp(-x));
  }
  double binary_sigmoidal_derivative(double fx) {
    return fx * (1 - fx);
  }
  double RandomNumber () {
    return ((double) rand() / (RAND_MAX));
  }
}
