package Series;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Liner extends Series
{
	public Liner(double firstElement, int n, double difference)
	{
		super(firstElement, n);
		this.difference = difference;
	}

	@Override
	public double getElement(int j)
	{
		return firstElement + difference*j;
	}

	@Override
	public void saveToFile(String path) throws IOException
	{
		super.saveToFile(path);
		FileWriter pw = new FileWriter(path, true);
		pw.append(Double.toString(difference));
		pw.close();
	}

	private double difference;

	public double getDifference()
	{
		return difference;
	}

	public void setDifference(double difference)
	{
		this.difference = difference;
	}
}
