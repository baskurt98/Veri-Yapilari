#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int x[10],k,g;
	srand(time(NULL));
	for(int i=0;i<10;i++)
	x[i]=rand()%9+1;
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			k=x[j];
			if(k>x[j+1] )
			{
				g=x[j+1];
				x[j+1]=k;
				x[j]=g;
			}
			
		}
	}
	
for(int i=0;i<10;i++)
cout<<x[i]<<endl;
}

// Code writer: Hasan BASKURT
