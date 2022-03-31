package Latihan04;

public class MobilCoba {
    public static void main(String[] args) {
        Mobil avanza = new Mobil();

        avanza.setModel("Avanza");
        avanza.setSpeed(120);

        System.out.println("Mobil " + avanza.getModel() + " mempunyai maxSpeed " + avanza.getSpeed() + " km per jam.");
    }
}
