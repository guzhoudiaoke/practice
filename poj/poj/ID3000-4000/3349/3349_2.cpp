#include<iostream>
#include<cstdio>
using namespace std;
int h[150000];
unsigned int a[100005][6];
int hash(int k)
{
	unsigned int i,h=1;
	for(i=0;i<6;i++)
	{
		h*=a[k][i];
	}
	h=h%149997;
	return h;
}
bool judge(int x,int y)
{
	int i,j,k;
	bool ch;
	for(i=0;i<6;i++)
	{
		ch=true;
		for(j=0;j<6;j++)
		{
			if(a[x][j]!=a[y][(j+i)%6])
			{
				ch=false;
				break;
			}
		}
		if(ch)
			return true;
	}
        for(i=0;i<6;i++)
	{
		ch=true;
		for(j=0,k=5;j<6;j++,k--)
		{
			if(a[x][j]!=a[y][(k+i)%6])
			{
				ch=false;
				break;
			}
		}
		if(ch)
			return true;
	}
	return false;
}
int main()
{
	int n,i,j,k,t,x,kk;
	bool ch=true,th,kh=true;
	char c;
	cin>>n;
        c=getchar();
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=5;j++)
		{
			x=0;
			c=getchar();
			while(c!=' '&&c!='\n')
			{
				x=x*10;
				x+=(c-48);
				c=getchar();
			}
			a[i][j]=x;
		}
	        k=hash(i);
		t=1;
		kk=k;
                if(h[kk]==0)
		    th=false;
		while(h[kk]!=0)
		{
			th=judge(h[kk],i);
			if(th)
			{
				ch=false;
				printf("Twin snowflakes found.\n");
				break;
			}
			kk=(k+t*t)%149997;
			t++;
		}
		if(!th)
		    h[kk]=i;
	}
	if(ch)
		printf("No two snowflakes are alike.\n");
	return 0;
}
