#include<stdio.h>

//Global Variables
static int spiral_counter = 1;
static int x = 0;
static int y = 0;

void ulamn_spiral(int arr[][10],int n)
{
	if(n<=0)
		return;
	else
		if(n==1)
		{
			arr[x][y] = spiral_counter++;
			return;
		}
		else
		{
			int loc_x = x;
			int loc_y = y;
			for(;y<n+loc_y;y++)//TL to TR
				arr[x][y] = spiral_counter++;
			for(x=x+1,y=y-1;x<n+loc_x;x++)//TR to BR
				arr[x][y] = spiral_counter++;
			for(x=x-1,y=y-1;y>=loc_y;y--)//BR to BL
				arr[x][y] = spiral_counter++;
			for(y=y+1,x=x-1;((x>loc_x) && (4*(n-1)));x--)//BL to TL
				arr[x][y] = spiral_counter++;

			x++;
			y++;
			ulamn_spiral(arr,n-2);
		}
}
int main()
{
	int n,i,j;
	int arr[10][10];
	printf("Enter the Size of the array (<10)");
	scanf("%d",&n);
	ulamn_spiral(arr,n);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");	
	}
	return 0;
}
