import java.util.*;

public class cchange{
	public static void main(String[] args) {
		int x,n,t;
		Scanner s = new Scanner(System.in);
		x = s.nextInt();
		n = s.nextInt();
		int[] m = new int[x+1];
		for (int i =1;i<=x;i++) m[i] = 99999;
		m[0] = 0;
		for(int i=0;i!=n;i++)
		{
			t = s.nextInt();
			for(int j=t;j<=x;j++)
			if( m[j-t]+1 < m[j])
				m[j] = m[j-t]+1;
		}
		System.out.println(m[x]);
	}
}
			