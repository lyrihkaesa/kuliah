public class Latihan03c {
    public static void main(String[] args) {
        int x = 9;
        int y = 3;
        System.out.println("1. " + (x > 3 && x < 10)); // Output: 1. true
        // karena 9 > 3 (true) && "dan" 9 < 10 (true), maka
        // hasilnya (true/benar), karena operator perbandingan && "dan"
        // semuanya harus bernilai true/benar
        System.out.println("2. " + (x > 3 && y > 10)); // Ouput: 2. false
        // kedua perbandingan salah
        System.out.println("3. " + (x < 3 || y < 10)); // Ouput: 3. true
        // karena salah satu benar dalam perbandingan OR
        System.out.println("4. " + (x < 3 || y > 10)); // Ouput: 4. false
        // karena kedua perbandingan salah
        System.out.println("5. " + (x++ > 9 && y + 1 > 4)); // Ouput: 5. false
        // karena kedua perbandingan dalah dalam perbandingan AND
        System.out.println("6. " + (x > 9 && y + 1 > 4)); // Ouput: 6. false
        // karena salah satu salah dalam perbandingan AND
        System.out.println("7. " + (x++ > 9 || y + 1 == 4)); // Ouput: 7. true
        // karena kedua perbandingan benar
        System.out.println("8. " + (x > 9 || y + 1 == 4)); // Ouput: 8. true
        // karena kedua perbandingan benar

        System.out.println("\n========================");
        System.out.println("Program : Latihan03c");
        System.out.println("NIM     : A12.2020.06495");
        System.out.println("Nama    : Kukuh Setya A.");
    }
}