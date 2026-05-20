public class LeapYear
{
	public static void main(String[] args)
	{
		int x = 2030;
		if (x % 4 == 0 && x % 4 == 100 && x % 400 == 0)
			System.out.println(x+" is a leap year");
		else
			System.out.println(x+" is not a leap year");
	}
}