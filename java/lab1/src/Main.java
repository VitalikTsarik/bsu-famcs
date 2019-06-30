public class Main {

    public static void main(String[] args) {
        Point a = new Point(1,2);
        System.out.println("Initial point: " + a);
        a.shift(2,3);
        System.out.println("Shift point by vector (2, 3): " + a);
        a.rotate(Math.PI/2);
        System.out.println("Rotate point by PI/2: " + a);
    }
}
