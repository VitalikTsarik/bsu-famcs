import java.awt.*;
import java.util.ArrayList;
public class Line
{
	public Line()
	{
		this.points = new ArrayList<>();
	}

	public Line(Color color)
	{
		this.points = new ArrayList<>();
		this.color = color;
	}

	public void draw(Graphics g)
	{
		g.setColor(color);
		Point prev = points.get(0);
		for (int i = 1; i < points.size(); ++i)
		{
			Point cur = points.get(i);
			g.drawLine(prev.x, prev.y, cur.x, cur.y);
			prev = cur;
		}
	}

	private ArrayList<Point> points;
	private Color color;

	public void addPoint(Point p)
	{
		points.add(p);
	}

	public ArrayList<Point> getPoints()
	{
		return points;
	}

	public Color getColor()
	{
		return color;
	}

	public void setColor(Color color)
	{
		this.color = color;
	}
}
