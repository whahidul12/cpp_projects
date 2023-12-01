#include <iostream>

using namespace std;
int main()
{
  int num[5] = {1, 2, 3, 4};
  for (int i = 0; i < sizeof(num); i++)
  {
    int pNum = num[i];
    cout << pNum;
  }
  int *pNum = num;
  cout << *pNum;
  return 0;
}
