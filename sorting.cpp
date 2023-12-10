#include <iostream>
using namespace std;

void sortArray(int myArray[], int size);

int main()
{
  int myArray[] = {10, 5, 8, 9, 7, 3, 4, 6, 1, 2};
  int size = sizeof(myArray) / sizeof(int);
  cout << size << "\n";

  sortArray(myArray, size);

  for (int i : myArray)
  {
    cout << i << " ";
  }

  return 0;
}

void sortArray(int myArray[], int size)
{
  int temp = 0;

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (myArray[j] > myArray[j + 1])
      {
        temp = myArray[j];
        myArray[j] = myArray[j + 1];
        myArray[j + 1] = temp;
      }
    }
  }
}
