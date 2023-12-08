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
  char player = 'X';
  char computer = 'O';
  bool game_running = true;

  drawBoard(boardBox);
  while (game_running)
  {
    playerTurn(boardBox, player);
    computerTurn(boardBox, computer);
    drawBoard(boardBox);
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
  int number = 0;
  do
  {
    cout << "Enter a number (1-9): ";
    cin >> number;
    number--;
    if (boardBox[number] == ' ')
    {
      boardBox[number] = player;
      break;
    }
  } while (number < 1 || number > 9);
}
void computerTurn(char *boardBox, char computer)
{
  int number = 0;
  srand(time(NULL));

  while (true)
  {
    number = rand() % 9;
    number++;
    if (boardBox[number] == ' ')
    {
      boardBox[number] = computer;
      break;
    }
  }
}
bool checkWinner(char *boardBox, char player, char computer)
{
  return 0;
}
bool checkTie(char *boardBox)
{
  return 0;
}
