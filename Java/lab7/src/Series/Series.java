package Series;

import java.io.IOException;
import java.io.PrintWriter;

abstract public class Series
{
	public Series(double firstElement, int n)
	{
		this.firstElement = firstElement;
		this.n = n;
	}

	abstract public double getElement(int j);

	public double sum()
	{
		double sum = 0;
		for (int i = 0; i < n; ++i)
			sum += getElement(i);
		return sum;
	}

	@Override
	public String toString()
	{
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n - 1; ++i)
		{
			sb.append(getElement(i));
			sb.append(", ");
		}
		sb.append(getElement(n-1));
		return sb.toString();
	}

	public void saveToFile(String path) throws IOException
	{
		PrintWriter pw = new PrintWriter(path);
		pw.println(n);
		pw.println(firstElement);
		pw.close();
	}

	protected double firstElement;
	protected int n;

	public double getFirstElement()
	{
		return firstElement;
	}

	public void setFirstElement(double firstElement)
	{
		this.firstElement = firstElement;
	}

	public int getN()
	{
		return n;
	}

	public void setN(int n)
	{
		this.n = n;
	}
}
