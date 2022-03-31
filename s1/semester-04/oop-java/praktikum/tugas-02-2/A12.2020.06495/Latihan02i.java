public class Latihan02i {
  public static void main(String[] args) {
    String string1 = "123";
    // String string2 = "ab123"; // kode[2] error: karena kode[1] dibawah saya komentari/hapus
    // Kode[2] diatas error: The value of the local variable string2 is not used

    int varstr1 = Integer.parseInt(string1);

    System.out.println(varstr1 + 2); // Output: 125
    System.out.println(string1 + varstr1); // Output: 123123

    // kode[1] dibawah adalah kode yang dikomentari/hapus
    // int varstr2 = Integer.parseInt(string2); // kode[1] error
    // System.out.println(varstr2); // kode[1] error

    // Kode[1] diatas error:
    // Exception in thread "main" java.lang.NumberFormatException: For inputstring: "ab123"
    // at java.base/java.lang.NumberFormatException.forInputString(NumberFormatException.java:67)
    // at java.base/java.lang.Integer.parseInt(Integer.java:668)
    // at java.base/java.lang.Integer.parseInt(Integer.java:786)
    // at Latihan02i.main(Latihan02i.java:11)
  }
}
