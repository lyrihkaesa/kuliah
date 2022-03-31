package Latihan04;

public class Mobil {
    // property.....
    private String model;
    private Integer maxSpeed;

    // behavior/method..............
    public void setModel(String param) {
        model = param;
    }

    public void setSpeed(Integer param) {
        maxSpeed = param;
    }

    public String getModel() {
        return model;
    }

    public int getSpeed() {
        return maxSpeed;
    }
}
