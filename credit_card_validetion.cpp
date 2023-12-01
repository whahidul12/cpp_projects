#include <iostream>

using namespace std;

int evenNumber(string card_number, int length);
int oddNumber(string card_number, int length);
int getDigit(int oneDigit);

int main()
{
  string card_number = "0123456789";
  cout << "Enter Your Card Number For Validation: ";
  cin >> card_number;
  int length = card_number.size();

  int result = evenNumber(card_number, length) + oddNumber(card_number, length);

  if (result % 10 == 0)
  {
    cout << "\nYour card " << card_number << " is valid.\n";
  }
  else
  {
    cout << "\nYour card " << card_number << " is not valid.\n";
  }

  return 0;
}

int evenNumber(string card_number, int length)
{
  int sum = 0;
  for (int i = length - 2; i >= 0; i -= 2)
  {
    sum += getDigit((card_number[i] - '0') * 2);
  }

  return sum;
}
int oddNumber(string card_number, int length)
{
  int sum = 0;
  for (int i = length - 1; i >= 0; i -= 2)
  {
    sum += getDigit(card_number[i] - '0');
  }
  return sum;
}
int getDigit(int oneDigit)
{
  return oneDigit % 10 + (oneDigit / 10 % 10);
}
