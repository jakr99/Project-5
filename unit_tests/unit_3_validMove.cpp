#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix = new string[3]{"|||", "|S@", "| |"};

    if (valid_move(matrix, 1, 1, "NORTH"))
      return false;
    if (valid_move(matrix, 1, 1, "EAST"))
      return false;
    if (valid_move(matrix, 1, 1, "WEST"))
      return false;
    if (valid_move(matrix, 0, 1, "SOUTH"))
      return false;

    if (valid_move(matrix, 1, 1, "SOUTH") == false)
      return false;

    return true;
  });
}
