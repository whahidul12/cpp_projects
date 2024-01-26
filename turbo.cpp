#include <iostream>
#include <ctime>
#include <vector>
// using namespace std;

// int main()
// {
//   int age = 12;
//   string info = "finite";
//   printf("my age is %d years %c old", age, info);
//   cout << "\nmy age is %d years %c old", age, info;
//   return 0;
// }

// Pawn - 1, Knight - 3, Bishop - 2, rook - 5,queen - 6,king - 10
const int WHITE_PAWN = 1;
const int WHITE_BISHOP = 2;
const int WHITE_KNIGHT = 3;
const int WHITE_ROOK = 5;
const int WHITE_QUEEN = 6;
const int WHITE_KING = 10;
const int BLACK_PAWN = -1;
const int BLACK_BISHOP = -2;
const int BLACK_KNIGHT = -3;
const int BLACK_ROOK = -5;
const int BLACK_QUEEN = -6;
const int BLACK_KING = -10;
const int EMPTY_SQUARE = 0;

int board[8][8] = {
    {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
    {BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
    {WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN},
    {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK}};

// A base class for all pieces
class Piece
{
public:
  // A constructor that takes the type, color, and position of the piece
  Piece(int type, bool color, int row, int col)
  {
    this->type = type;
    this->color = color;
    this->row = row;
    this->col = col;
  }

  // A virtual destructor
  virtual ~Piece() {}

  // A virtual function that returns a vector of possible moves for the piece
  virtual std::vector<std::string> get_moves(int board[8][8]) = 0;

  // A function that returns the type of the piece
  int get_type()
  {
    return type;
  }

  // A function that returns the color of the piece
  bool get_color()
  {
    return color;
  }

  // A function that returns the row of the piece
  int get_row()
  {
    return row;
  }

  // A function that returns the column of the piece
  int get_col()
  {
    return col;
  }

  // A function that sets the row and column of the piece
  void set_position(int row, int col)
  {
    this->row = row;
    this->col = col;
  }

protected:
  // A helper function that converts a position to a string
  std::string to_string(int row, int col)
  {
    return std::to_string(row) + std::to_string(col);
  }

  // The type of the piece
  int type;

  // The color of the piece (true for white, false for black)
  bool color;

  // The row and column of the piece
  int row;
  int col;
};

// A subclass for the pawn piece
class Pawn : public Piece
{
public:
  // A constructor that calls the base constructor
  Pawn(bool color, int row, int col) : Piece(1, color, row, col) {}

  // A function that overrides the base function and returns a vector of possible moves for the pawn
  std::vector<std::string> get_moves(int board[8][8])
  {
    std::vector<std::string> moves;
    // If the pawn is white
    if (color)
    {
      // If the pawn can move one square forward
      if (row > 0 && board[row - 1][col] == 0)
      {
        moves.push_back(to_string(row, col) + to_string(row - 1, col));
      }
      // If the pawn can move two squares forward from the initial position
      if (row == 6 && board[row - 1][col] == 0 && board[row - 2][col] == 0)
      {
        moves.push_back(to_string(row, col) + to_string(row - 2, col));
      }
      // If the pawn can capture a black piece diagonally to the left
      if (row > 0 && col > 0 && board[row - 1][col - 1] < 0)
      {
        moves.push_back(to_string(row, col) + to_string(row - 1, col - 1));
      }
      // If the pawn can capture a black piece diagonally to the right
      if (row > 0 && col < 7 && board[row - 1][col + 1] < 0)
      {
        moves.push_back(to_string(row, col) + to_string(row - 1, col + 1));
      }
    }
    // If the pawn is black
    else
    {
      // If the pawn can move one square forward
      if (row < 7 && board[row + 1][col] == 0)
      {
        moves.push_back(to_string(row, col) + to_string(row + 1, col));
      }
      // If the pawn can move two squares forward from the initial position
      if (row == 1 && board[row + 1][col] == 0 && board[row + 2][col] == 0)
      {
        moves.push_back(to_string(row, col) + to_string(row + 2, col));
      }
      // If the pawn can capture a white piece diagonally to the left
      if (row < 7 && col > 0 && board[row + 1][col - 1] > 0)
      {
        moves.push_back(to_string(row, col) + to_string(row + 1, col - 1));
      }
      // If the pawn can capture a white piece diagonally to the right
      if (row < 7 && col < 7 && board[row + 1][col + 1] > 0)
      {
        moves.push_back(to_string(row, col) + to_string(row + 1, col + 1));
      }
    }
    return moves;
  }
};

// A subclass for the bishop piece
class Bishop : public Piece
{
public:
  // A constructor that calls the base constructor
  Bishop(bool color, int row, int col) : Piece(2, color, row, col) {}

  // A function that overrides the base function and returns a vector of possible moves for the bishop
  std::vector<std::string> get_moves(int board[8][8])
  {
    std::vector<std::string> moves;
    int a, b;
    // If the bishop can move diagonally up-left
    a = row;
    b = col;
    if (a > 0 && b > 0)
    {
      for (;;)
      {
        a--;
        b--;
        // If the bishop encounters a piece of the same color, break the loop
        if (color && board[a][b] > 0)
          break;
        if (!color && board[a][b] < 0)
          break;
        // If the bishop encounters a piece of the opposite color, add the move and break the loop
        if (color && board[a][b] < 0)
        {
          moves.push_back(to_string(row, col) + to_string(a, b));
          break;
        }
        if (!color && board[a][b] > 0)
        {
          moves.push_back(to_string(row, col) + to_string(a, b));
          break;
        }
      }
    }
    return moves;
  }
};
