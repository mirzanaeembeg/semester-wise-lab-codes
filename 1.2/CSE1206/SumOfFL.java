public class SumOfFL
{
	public static void main(String[] args)
	{
		int x=1234,y,i,rem,rev=0;
		int n,z;
		y=x%10;
		for(;x!=0;)
		{
			rem = x % 10;
			rev = rev*10+rem;
			x = x / 10;
		}
		z=rev%10;
		n=z+y;
		System.out.println("Sum of 1st & last digit = " + n);
	}
}