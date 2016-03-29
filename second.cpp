// Shravan R. Patel
// IIT Mandi
// 2nd year CSE
// gmail : shravanpatel5@gmail.com

// Here I couldn't be able to solve this problem using cbc functions because of some reasons. 
// But I got details about some Cbc functions and classes.

// To solve this problem, I am considering all possible solutions and then checking if it satisfies given constraints or not.
// I know, this algo will take much more time for big value of n. 
// But for n<=30 it will take just 1-2 seconds. 

#include<iostream>
#include<cstdlib>  // for malloc
#include<cmath>    // for pow
using namespace std;
double val(int *x, int n, double *p)    //returns the value of objective when solution is given
{
	double ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(*(x+i))*(*(p+i));
	}
	return ans;
}
void ntob(long long int sol,int n,int *x)   //converts decimal to binary
{
	for(int i=0;i<n;i++)
	{
		*(x+i)=sol%2;
		sol=sol>>1;
	}
}
int check_line(int *x,int n,double* r,double b)   //return 1 if a solution satisfies a constraint
{
	double ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(*(x+i))*(*(r+i));
	}
	if(ans<=b)
		return 1;
	return 0;
}
int check(int *x,int n,int m,double* r,double *b)    //return 1 if a solution satisfies all constraints
{
	if(m==0)
		return 1;
	int flag=0;
	for(int i=0;i<m;i++)
	{
		if(!check_line(x,n,r+n*i,*(b+i)))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return 1;
	return 0;
}
int main()
{
	long long int sol,tp,max_n;
	int n,m,*x=NULL;
	double *p=NULL,*r=NULL,*b=NULL,max,value;
	cout<<"Enter the value of n (number of variables) : ";
	cin>>n;
	if(n<=0)
	{	
		cout<<"n should be positive"<<endl;
		return 0;
	}	
	p = (double*) malloc(n*sizeof(double));       // dynamically allocate memory to pointers; 
	b = (double*) malloc(m*sizeof(double));
	x = (int*) malloc(n*sizeof(int));
	r = (double*) malloc(n*m*sizeof(double));	
	cout<<"Enter the value of m (number of constraints) : ";
	cin>>m;
	cout<<"Enter the coefficients of the variables x1 to xn in problem objective"<<endl;
	for(int i=0;i<n;i++)
		cin>>*(p+i);
	for(int i=0;i<m;i++)
	{
		cout<<"Enter the coefficients of the variables x1 to xn in constrain "<<i+1<<endl;
		for(int j=0;j<n;j++)
			cin>>*(r+i*n+j);
		cout<<"Enter b : "<<endl;
		cin>>*(b+i);
	}	
	tp=pow(2,n);
	int flag=0;
	for(sol=0;sol<tp;sol++)                        // sol is a number corresponds to each possible solution
	{
		ntob(sol,n,x);                         // Converting sol to the permutation of 0s and 1s
		if(check(x,n,m,r,b))                   // check whether the permutation satisfies the contraints
		{
			flag++;
			value=val(x,n,p);
			if(max<value||flag==1)		// update maximum value
			{
				max=value;
				max_n=sol;
			}						
		}							
	}
	
	// Print the solution
	
	if(flag>0)
	{
		cout<<"Maximum value of the problem objective : "<<max<<endl;
		ntob(max_n,n,x);
		cout<<"This is obtained when - "<<endl;
		for(int i=0;i<n;i++)
			cout<<"x"<<i+1<<" = "<<*(x+i)<<endl;
	}
	else
	{
		cout<<"No possible solution "<<endl;
	}
	return 0;
}
