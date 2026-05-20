public class Prime
{
	public static void main(String[] args)
	{
		int x=19;
		int i,t=0;
		for(i=2;i<=x/2;i++)
		{
			if(x%i==0)
				t=1;
			break;
		}
		if(t==1)
			System.out.println(x+" is not a prime number");
		else
			System.out.println(x+" is a prime number");
	}
}