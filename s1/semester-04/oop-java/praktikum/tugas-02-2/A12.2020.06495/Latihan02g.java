public class Latihan02g {
  public static void main(String[] args) {
    // int[] myList = { 1.1, 2, 3, 4, 5 };
    // float[] myList = { 1.1, 2, 3, 4, 5 }; // entah kenapa ini juga error
    // Kode diatas error: Type mismatch: cannot convert from double to int

    // Apa solusinya apabila program Latihan02f dijalankan terdapat error?
    double[] myList = { 1.1, 2, 3, 4, 5 }; // Opsi-01
    double total = 0;
    // Output "double":
    // 1.1
    // Total: 1.1
    // 2.0
    // Total: 3.1
    // 3.0
    // Total: 6.1
    // 4.0
    // Total:
    // 10.1
    // 5.0
    // Total: 15.1

    // int[] myList = { 1, 2, 3, 4, 5 }; // Opsi-02
    // int[] myList = { (int) 1.1, 2, 3, 4, 5 }; // Opsi-02
    // int total = 0;
    // Output "int":
    // 1
    // Total: 1
    // 2
    // Total: 3
    // 3
    // Total: 6
    // 4
    // Total: 10
    // 5
    // Total: 15

    for (int i = 0; i < myList.length; i++) {
      System.out.println(myList[i]);

      // SUM myList
      total = total + myList[i];
      System.out.println("Total: " + total);
    }
  }
}
