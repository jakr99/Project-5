#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix =
        new string[7]{"|||||||||", "|      S|", "||| ||| |", "| |   |||",
                      "| | |||E|", "|       |", "|||||||||"};

    try {
      if (find_exit(matrix, 1, 7) == false)
        return false;
    } catch (...) {
      cerr << " Exception Thrown";
      return false;
    }

    return true;
  });
}

//#########
//#      S#
//### ### #
//# #   ###
//# # ###E#
//#       #
//#########

// {1,0},{3,1},{2,7},{5,8}
