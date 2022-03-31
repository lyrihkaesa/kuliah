public class Latihan02h {
  public static void main(String[] args) {
    double myDouble = 9.78;
    // int myInt = myDouble; // (int) ?
    // Kode diatas error: Type mismatch: cannot convert from double to int

    int myInt = (int) myDouble;

    System.out.println(myDouble); // Output: 9.78
    System.out.println(myInt); // Output: 9
  }
}
