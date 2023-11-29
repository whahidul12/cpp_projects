#include <iostream>
using namespace std;

int main()
{
  // int num[5] = {1, 2, 3, 4, 5};
  // int towDnum[3][3] = {
  //     {10, 20, 30},
  //     {11, 22, 33},
  //     {77, 88, 99}};
  // int size = sizeof(num) / sizeof(num[0]);
  // cout << size << endl;
  // cout << num[2] << endl;
  // cout << "hello: " << towDnum[0][0];

  string questions[] = {
      "1. What is your name? ",
      "2. What is your fav color? ",
      "3. What is your userID? ",
      "4. What is your date of birth? "};

  int size = sizeof(questions) / sizeof(questions[0]);

  string options[][3] = {
      {"A. Yusuf", "B. Zakir", "C. Whahid"},
      {"A. Red", "B. Green", "C. Orenge"},
      {"A. whahid-sd", "B. whahid12", "C. md-whahid"},
      {"A. 14", "B. 63", "C. 12"}};

  char answers[] = {'C', 'B', 'C', 'A'};
  char gess;
  int count = 0;
  double score = 0;

  for (int i = 0; i < size; i++)
  {
    cout << "\n***   ***   ***\n";
    cout << questions[i] << "\n";
    cout << "***   ***   ***\n";

    for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++)
    {
      cout << options[i][j] << "\n";
    }
    cin >> gess;
    gess = toupper(gess);
    if (gess == answers[i])
    {
      cout << "::: Correct :::";
      cout << "\n***   ***   ***\n";
      count++;
    }
    else
    {
      cout << "!!! Worng !!!\n";
      cout << "Correct answer: >>> " << answers[i] << " <<<\n";
      cout << "***   ***   ***\n";
    }
  }
  score = (count / (double)size) * 100;
  cout << "You got " << count << " questions correct out of " << size << " questions.\n";
  cout << "Your accuracy score is: " << score << "%";

  return 0;
}
