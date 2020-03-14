import java.util.Scanner;

public class Main {
	static int[][] maze;
	static int n;
	static int short_path;
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		short_path=n*n;
		maze=new int[n][n];
		for (int i=0;i<n;i++) 
		{
			for (int j=0;j<n;j++) 
			{
				maze[i][j]=sc.nextInt();
			}
		}
		findBestpath(1,1,0);
		if(short_path==n*n)
			System.out.println("No solution");
		else
			System.out.println(short_path);
	}
	public static void findBestpath(int x,int y,int count) {
		if(x==n-2&&y==n-2) 
		{
			short_path=Math.min(count,short_path);
		}
		else 
		{
			maze[x][y]=1;
			if(x>1&&maze[x-1][y]==0)
			{
				findBestpath(x-1,y,count+1);
			}
			if(x<n-1&&maze[x+1][y]==0)
			{
				findBestpath(x+1,y,count+1);
			}
			if(y>1&&maze[x][y-1]==0)
			{
				findBestpath(x,y-1,count+1);
			}
			if(y<n-1&&maze[x][y+1]==0)
			{
				findBestpath(x,y+1,count+1);
			}
			maze[x][y]=0;
		}
		
	}

}