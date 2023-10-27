#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix = new string[3]{"###", "###", "###"};
    matrix[1][1] = 'E';

    if (at_end(matrix, 1, 1) == false)
      return false;

    if (at_end(matrix, 0, 0))
      return false;

    return true;
  });
}
