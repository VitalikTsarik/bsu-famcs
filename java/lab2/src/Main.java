/*2. Ввести с консоли n - размерность матрицы a[n][n]. Задать
        значения элементов матрицы в интервале значений от -n до n с
        помощью датчика случайных чисел. Выполнить циклический сдвиг
        заданной матрицы на k позиций вправо (влево, вверх, вниз). k
        ввести через параметры командной строки. Распечатать
        исходную матрицу и результат.
*/

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = in.nextInt();
        int k = Integer.parseInt(args[0]);
        System.out.println("k = " + k);

        Matrix matrix = new Matrix(n);
        System.out.println("Generated matrix:");
        matrix.print();

        System.out.println("Shift right:");
        matrix.shift(Direction.right, 2);
        matrix.print();

        System.out.println("Shift up:");
        matrix.shift(Direction.up, 2);
        matrix.print();

        System.out.println("Shift left:");
        matrix.shift(Direction.left, 2);
        matrix.print();

        System.out.println("Shift down:");
        matrix.shift(Direction.down,2);
        matrix.print();
    }
}
