import java.util.Random;

public class Matrix
{
    private int[][] matrix;
    private int n;
    Matrix(int n)
    {
        this.n = n;
        matrix = new int[n][n];
        Random random = new Random();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n ; j++)
                matrix[i][j] = random.nextInt(2*n) - n;
    }

    public void shift(Direction dir, int k)
    {
        k %= n - 1;
        if (k == 0)
            return;
        int[][] tmp = new int[n][n];
        switch (dir)
        {
            case right:
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; j++)
                        tmp[i][(j + k) % n] = matrix[i][j];
                break;
            case up:
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; j++)
                        tmp[(k <= i ? i - k : n + i - k)][j] = matrix[i][j];
                break;
            case left:
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; j++)
                        tmp[i][(k <= j ? j - k : n+ j - k)] = matrix[i][j];
                break;
            case down:
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n ; j++)
                        tmp[(i + k) % n][j] = matrix[i][j];
                break;
        }
        matrix = tmp;
    }

    public void print()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                System.out.format("%3d ", matrix[i][j]);
            }
            System.out.println();
        }
    }
}
