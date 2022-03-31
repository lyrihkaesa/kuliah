public class LabelledBreak {
    public static void main(String[] args) {
        loop2: for (int i = 0; i < 2; i++)
            for (int j = 0; j < 5; j++) {
                if (j == 2) {
                    break loop2;
                }
                System.out.println("i = " + i);
                System.out.println("j = " + j);
            }
        System.out.println("Out of the loop");
    }
}