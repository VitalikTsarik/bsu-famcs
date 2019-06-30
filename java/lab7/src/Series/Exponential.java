package Series;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Exponential extends Series
{
	public Exponential(double firstElement, int n, double commonRatio)
	{
		super(firstElement, n);
		this.commonRatio = commonRatio;
	}

	@Override
	public double getElement(int j)
	{
		return firstElement*Math.pow(commonRatio, j);
	}

	@Override
	public void saveToFile(String path)throws IOException
	{
		super.saveToFile(path);
		FileWriter pr = new FileWriter(path);
		pr.append(Double.toString(commonRatio));
		pr.close();
	}

	private double commonRatio;

	public double getCommonRatio()
	{
		return commonRatio;
	}

	public void setCommonRatio(double commonRatio)
	{
		this.commonRatio = commonRatio;
	}
}
