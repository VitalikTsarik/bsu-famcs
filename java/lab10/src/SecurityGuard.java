public class SecurityGuard extends Worker
{
	private String objectName;

	public SecurityGuard(String name, String position, int salary, String objectName) {
		super(name, position, salary);
		this.objectName = objectName;
	}

	public String toString()
	{
		return name + ", " + position + ", " + salary + ", " + objectName ;
	}
}
