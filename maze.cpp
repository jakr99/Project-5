/* Here in the .cpp you should define and implement everything declared in the
 * .h file.
 */

#include "maze.h"

string *build_matrix(int rows) {
  string *matrix = new string[rows];
  return matrix;
}

void fill_matrix(string *matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    getline(cin, matrix[i]);
  }
}

void print_matrix(const string *matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    cout << matrix[i] << endl;
  }
}

void delete_matrix(string *&matrix) {
  delete[] matrix;
  matrix = nullptr;
}

void find_start(string *matrix, int rows, int &row, int &col) {
  for (int i = 0; i < rows; i++) {
    for (std::string::size_type j = 0; j < matrix[i].length(); j++) {
      if (matrix[i][j] == 'S') {
        row = i;
        col = static_cast<int>(j);
        return;
      }
    }
  }
}

bool find_exit(string *matrix, int row, int col) {
  if (at_end(matrix, row, col)) {
    return true;
  }

  const string directions[] = {"NORTH", "SOUTH", "EAST", "WEST"};

  for (const string &direction : directions) {
    if (valid_move(matrix, row, col, direction)) {
      matrix[row][col] = '@';

      int newRow = row;
      int newCol = col;
      if (direction == "NORTH")
        newRow--;
      else if (direction == "SOUTH")
        newRow++;
      else if (direction == "EAST")
        newCol++;
      else if (direction == "WEST")
        newCol--;

      if (find_exit(matrix, newRow, newCol)) {
        return true;
      }

      matrix[row][col] = ' ';
    }
  }

  return false;
}

bool at_end(string *matrix, int row, int col) {
  return matrix[row][col] == 'E';
}

bool valid_move(string *matrix, int row, int col, const string &direction) {
  int numRows = matrix[0].length();
  int numCols = matrix[0].length();

  if (direction == "NORTH" && row > 0) {
    return matrix[row - 1][col] == ' ' || matrix[row - 1][col] == 'E';
  } else if (direction == "SOUTH" && row < numRows - 1) {
    return matrix[row + 1][col] == ' ' || matrix[row + 1][col] == 'E';
  } else if (direction == "EAST" && col < numCols - 1) {
    return matrix[row][col + 1] == ' ' || matrix[row][col + 1] == 'E';
  } else if (direction == "WEST" && col > 0) {
    return matrix[row][col - 1] == ' ' || matrix[row][col - 1] == 'E';
  }

  return false;
}
