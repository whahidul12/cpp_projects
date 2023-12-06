import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int sum = 0;
    int count = 0;

    while (count < 2) {
      System.out.print("Enter a number: ");
      int num = input.nextInt();

      if (num < 0) {
        System.out.println("Negative numbers are not allowed.");
        continue;
      }

      if (num == 0) {
        System.out.println("Zero detected. Exiting loop.");
        break;
      }

      sum += num;
      count++;
    }

    input.close();
    System.out.println("The sum of the two numbers is: " + sum);
  }
}

