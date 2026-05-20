public class Dsum
{
	public static void main(String[] args){
		int x=51436,i,rem;
		int sum=0;
		for(i=1;i<5;i++)
		{
			rem=x%10;
			x=x/10;
			sum += rem;
		}
		System.out.println("The sum of the digits = "+sum);
	}
}