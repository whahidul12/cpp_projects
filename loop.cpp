#include <iostream>
using namespace std;
int main()
{
  int arrSize;
  cout << "Enter array size: ";
  cin >> arrSize;

  int array[arrSize];

  cout << "Enter " << arrSize << "elements";

  for (int i = 0; i < arrSize; i++)
  {
    int element;
    cin >> element;
    array[i] = element;
  }

  cout << "Delet a number: ";
  int delElemnt;
  cin >> delElemnt;
  for (int i = 0; i < arrSize; i++)
  {
    if (array[i] == delElemnt)
    {
      for (int j = i)
    }
  }
  return 0;
}