import java.io.*;
class Sudoku
{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static int a[][]={
					{8,0,0, 0,0,0, 0,0,0},
					{0,0,3, 6,0,0, 0,0,0},
					{0,7,0, 0,9,0, 2,0,0},

					{0,5,0, 0,0,7, 0,0,0},
					{0,0,0, 0,4,5, 7,0,0},
					{0,0,0, 1,0,0, 0,3,0},

					{0,0,1, 0,0,0, 0,6,8},
					{0,0,8, 5,0,0, 0,1,0},
					{0,9,0, 0,0,0, 4,0,0},
				};
	static int b[][]=a;
	static int c=0;
	public static void main(String arghh[])throws IOException
	{
		Sudoku obj=new Sudoku();
		generate(a,0,-1);
		System.out.println("Total solutions = "+obj.c);
	}
	static void generate(int [][]a,int x,int y)
	{
		if(x==8&&y==8)
		{
			c++;
			display(a);
			return;
		}
		else if(x!=8&&y==8)
		{
			x++;
			y=0;
		}
		else
		y++;
		for(int i=x;i<9;i++)
		{
			for(int j=y;j<9;j++)
			{
				x=0;
				y=0;
				if(b[i][j]==0)
				{
					for(int k=1;k<=9;k++)
					{
						if(checkValidity(a,i,j,k))
						{
							a[i][j]=k;
							generate(a,i,j);
							a[i][j]=0;
						}
						if(k==9&&a[i][j]==0)
						return;
					}
				}
			}
		}
	}
	static void display(int [][]a)
	{
		for(int i=0;i<9;i++)
		{
			if(i%3==0)
			System.out.println("---------------------");
			for(int j=0;j<9;j++)
			{
				if(j%3==0)
				System.out.print(" | ");
				System.out.print(a[i][j]);
			}
			System.out.println(" | ");
		}
		System.out.println("---------------------");
	}
	static boolean checkValidity(int [][]a,int i,int j,int m)
	{
		for(int x=0;x<9;x++)
		{
			if(a[x][j]==m||a[i][x]==m)
			return false;
		}
		int p=i/3;
		int q=j/3;
		for(int x=3*p;x<3*(p+1);x++)
		{
			for(int y=3*q;y<3*(q+1);y++)
			{
				if(a[x][y]==m)
				return false;
			}
		}
		return true;
	}
}