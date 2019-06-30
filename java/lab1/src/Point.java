public class Point
{
    private double x;
    private double y;
    private boolean isEmpty;

    Point()
    {
        isEmpty = true;
    }

    Point(double x, double y)
    {
        this.x = x;
        this.y = y;
        isEmpty = false;
    }

    public double getX()
    {
        if (isEmpty)
            throw new NullPointerException();
        return x;
    }

    public double getY()
    {
        if (isEmpty)
            throw new NullPointerException();
        return y;
    }

    public void setX(double x)
    {
        this.x = x;
    }

    public void setY(double y)
    {
        this.y = y;
    }

    public void shift(double x, double y)
    {
        if (isEmpty)
            throw new NullPointerException();
        this.x += x;
        this.y += y;
    }

    public  void rotate(double angle)
    {
        if (isEmpty)
            throw new NullPointerException();
        if (x == 0 && y == 0)
            return;
        double r = Math.sqrt(x*x+y*y);
        double fi = Math.atan(y/x) + angle;
        x = r * Math.cos(fi);
        y = r * Math.sin(fi);
    }

    @Override
    public String toString()
    {
        return "(" + x + ", " + y + ")";
    }
}
