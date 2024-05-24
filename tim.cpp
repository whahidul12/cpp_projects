#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int input = 0;
  cout << "=> ";
  cin >> input;
  string Sin = to_string(input);
  int lengthInput = Sin.length();

  double multiplication = 1;
  int addition = 0;
  for (int i = 0; i < 1; i++)
  {
    // multiplication *= Sin[i];
    // addition += Sin[i];
  }
  cout << Sin;
  cout << "\nmultiplication: " << multiplication;
  cout << "\naddition: " << addition;
  cout << "\nDifference: " << multiplication - addition;

  return 0;
}