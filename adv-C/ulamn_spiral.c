/*
*DESCRIPTION: Its just a fun program to be used as an exercise. The program
*takes in input the length of an n x n array. Then it fills this square
*according to the option provided.
*
*LOGIC: Fill the buffer. Display the buffer. For the horizontal and vertical
*fill, its pretty simple. Just iterate and fill. For Spiral fill, oh yeah, its
*tricky. Use recursion. Just fill the outer edge, and then pass the size as 
*(n - 2) to the recursive call. The x and y keep track of the location in the 
*buffer and spiral_counter is the count you're filling in it.
*/

//Header files
#include<stdio.h>
#include<stdlib.h>

//Global Variables
int spiral_counter = 1;
int x = 0;
int y = 0;

//Functions
void buf_loct(int n, int ***bufref)
{
	*bufref = (int**)malloc(n*sizeof(int *));
	if((*bufref) == 0)
		end_exit("Wrong Allocation of memory, Exiting");
	else
	{
		int i = 0;
		while(i<n)
		{
			(*bufref)[i] = (int*)malloc(n*sizeof(int));
			i++;
		}	
	}	
}	

void end_exit(char *arg)
{
	
	printf(arg[]);
	exit(0);
}

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
	int n;
	printf("Please enter the number ");
	scanf("%d",&n);
	
}
