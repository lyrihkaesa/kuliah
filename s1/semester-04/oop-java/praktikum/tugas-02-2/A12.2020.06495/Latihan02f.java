public class Latihan02f {
  public static void main(String[] args) {
    // int[] myList = { 1.1, 2, 3, 4, 5 };
    // float[] myList = { 1.1, 2, 3, 4, 5 }; // entah kenapa ini juga error
    // Kode diatas error: Type mismatch: cannot convert from double to int

    // Apa solusinya apabila program Latihan02f dijalankan terdapat error?
    double[] myList = { 1.1, 2, 3, 4, 5 }; // Opsi-01
    // Output "double":
    // 1.1
    // 2.0
    // 3.0
    // 4.0
    // 5.0

    // int[] myList = { 1, 2, 3, 4, 5 }; // Opsi-02
    // int[] myList = { (int) 1.1, 2, 3, 4, 5 }; // Opsi-02
    // Output "int":
    // 1
    // 2
    // 3
    // 4
    // 5

    for (int i = 0; i < myList.length; i++) {
      System.out.println(myList[i]);
    }
  }
}
