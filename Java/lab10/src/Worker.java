public class Worker implements Comparable<Worker>
{
	protected String name, position;
	protected int salary;
	
	public Worker(String name, String position, int salary)
	{
		super();
		this.name = name;
		this.position = position;
		this.salary = salary;
	}

	public String getName()
	{
		return name;
	}

	public String getPosition()
	{
		return position;
	}

	public int getSalary()
	{
		return salary;
	}

	
	public String toString()
	{
		return name + ", " + position + ", " + salary;
	}

	public int compareTo(Worker w)
	{
		int cmp = position.compareTo(w.getPosition());
		if (cmp == 0)
		{
			cmp = name.compareTo(w.getName());
			if (cmp == 0)
			{
				return w.getSalary() - salary;
			}
		}
		return cmp;
	}
}
