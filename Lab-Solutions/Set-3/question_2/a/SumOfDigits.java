public class SumOfDigits {
    public static void main(String[] args) {
        int number = 12345;
        int sum = 0;

        // Calculate sum of digits
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }

        // Display the sum of digits
        System.out.println("Sum of Digits: " + sum);
    }
}
