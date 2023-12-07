#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *boardBox);
void playerTurn(char *boardBox, char player);
void computerTurn(char *boardBox, char computer);
bool checkWinner(char *boardBox, char player, char computer);
bool checkTie(char *boardBox);

int main()
{
  char boardBox[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool game_running = true;
  char player = 'X';
  char computer = 'O';

  while (game_running)
  {
    drawBoard(boardBox);
    playerTurn(boardBox, player);
    computerTurn(boardBox, computer);
  }

  return 0;
}

void drawBoard(char *boardBox)
{
  cout << "     |     |     \n";
  cout << "  " << boardBox[0] << "  |  " << boardBox[1] << "  |  " << boardBox[2] << "  \n";
  cout << "_____|_____|_____\n";
  cout << "     |     |     \n";
  cout << "  " << boardBox[3] << "  |  " << boardBox[4] << "  |  " << boardBox[5] << "  \n";
  cout << "_____|_____|_____\n";
  cout << "     |     |     \n";
  cout << "  " << boardBox[6] << "  |  " << boardBox[7] << "  |  " << boardBox[8] << "  \n";
  cout << "     |     |     \n";
}
void playerTurn(char *boardBox, char player)
{
  int choise = 0;
  cout << "Enter Your Choise (1-9): ";
  cin >> choise;
  choise -= 1;
  boardBox[choise] = player;
}
void computerTurn(char *boardBox, char computer)
{
  srand(time(NULL));
}
bool checkWinner(char *boardBox, char player, char computer)
{
  return 0;
}
bool checkTie(char *boardBox)
{
  return 0;
}
