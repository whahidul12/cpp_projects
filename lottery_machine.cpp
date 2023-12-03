#include <iostream>
using namespace std;

int main()
{

  int student_numbers = 0;

  cout << "Enter the candidate number: ";
  cin >> student_numbers;

  int students[student_numbers];
  int selected_numbers[12];

  for (int i = 0; i < student_numbers; i++)
  {
    students[i] = i + 1;
    cout << students[i] << "\n";

    srand(time(NULL));

    int random_roll = (rand() % 10) + 1;

    int condition = student_numbers;

    do
    {
      if (random_roll == students[i])
      {
        break;
      }
      else
      {
        selected_numbers[i] = random_roll;
      }
      condition--;
    } while (condition != 0);
  }
  int selected_size = sizeof(selected_numbers) / sizeof(int);
  for (int i = 0; i < selected_size; i++)
  {
    cout << ">>>" << selected_numbers[i] << "\n";
  }
  return 0;
}