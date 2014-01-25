/*
*DESCRIPTION: Its just a fun program to be used as an exercise. The program
*takes in input the length of an n x n bufrefay. Then it fills this square
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
		exit(0);
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

void buf_free(int n,int ***buf)
{
	int i=0;
	while(i<n)
	{
		free((*buf)[i]);
		i++;
	}
	*buf = NULL;
	x=0;
	y=0;
	spiral_counter = 1;
	return;
}

void ulamn_spiral(int n,int **bufref)
{
	if(n<=0)
		return;
	else
		if(n==1)
		{
			bufref[x][y] = spiral_counter++;
			return;
		}
		else
		{
			int loc_x = x;
			int loc_y = y;
			for(;y<n+loc_y;y++)//TL to TR
				bufref[x][y] = spiral_counter++;
			for(x=x+1,y=y-1;x<n+loc_x;x++)//TR to BR
				bufref[x][y] = spiral_counter++;
			for(x=x-1,y=y-1;y>=loc_y;y--)//BR to BL
				bufref[x][y] = spiral_counter++;
			for(y=y+1,x=x-1;((x>loc_x) && (4*(n-1)));x--)//BL to TL
				bufref[x][y] = spiral_counter++;

			x++;
			y++;
			ulamn_spiral(n-2,bufref);
		}
}
int main()
{
	int n,i,j;
	printf("Please enter the number ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Please enter a valid number");
		exit(0);
	}
	int **buf = NULL;
	buf_loct(n,&buf);
	ulamn_spiral(n,buf);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{
			printf("%d\t",buf[i][j]);
		}
		printf("\n");
	}
	buf_free(n,&buf);
	return 0;
}
