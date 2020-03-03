#include<iostream>
using namespace std;
int reflexive(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int count=0,i,j;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(arr1[i]==arr2[j]&&matr[i][j]==1)
				count++;
		}		
	}	
	if(size1+size2==count)
		return 1;
	else
		return 0;	
}

int symmetric(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int i,j,f,m,n;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
			{
				f=0;
				for(m=0;m<size1;m++)
				{
					for(n=0;n<size2;n++)
					{
						if(arr1[i]==arr2[n]&&arr1[j]==arr2[m]&&matr[m][n]==1)
							f=1,m=size1;										//to beak he loop
					}			
				} 
				if(f==0)
				{
					i=size1,j=size2;
				}
			}
		}		
	}
	return f;	
}

int transitive(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int i,j,f,m,n,r,c;
	for(i=0;i<size1;i++)												//1st loop
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
			{
				for(m=0;m<size1;m++)									//2nd loop 
				{
					for(n=0;n<size2;n++)
					{
						if(matr[m][n]==1&&arr1[j]==arr2[m])
						{
							f=0;
							for(r=0;r<size1;r++)								//3rd loop
							{
								for(c=0;c<size2;c++)
								{
									if(arr1[r]==arr1[i]&&arr2[c]==arr2[n]&&matr[r][c]==1)
									{
										f=1;
									}
								}
							}
							if(f==0)
								n=size2,m=size1,j=size2,i=size1;
						}			
					}
				}
			}			
		} 
	}	
	return f;	
}


int antisymmetric(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int i,j,f,m,n;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
			{
				f=0;
				for(m=0;m<size1;m++)
				{
					for(n=0;n<size2;n++)
					{
						if(arr1[i]==arr2[n]&&arr1[j]==arr2[m]&&matr[m][n]==1)
						{
							if(arr1[i]==arr2[j])
								f=1;
							else
								f=0;										
						}					//to beak he loop
					}			
				} 
				if(f==0)
				{
					i=size1,j=size2;
				}
			}
		}		
	}
	return f;		
}

int closurereflexive(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int m,n,i,j,f;
	cout<<endl<<"{";
	for(i=0;i<size1;i++)
	{f=0;
		for(m=0;m<size1;m++)
		{
			for(n=0;n<size2;n++)
			{
				if(arr1[i]==arr1[m]&&arr1[i]==arr2[n]&&matr[m][n]==1)
					f=1;
			}
		}
		if(f==0)
			cout<<"("<<arr1[i]<<","<<arr1[i]<<")";
	}
	for(j=0;j<size2;j++)
	{f=0;
		for(m=0;m<size1;m++)
		{
			for(n=0;n<size2;n++)
			{
				if(arr2[j]==arr1[m]&&arr2[j]==arr2[n]&&matr[m][n]==1)
					f=1;
			}
		}
		if(f==0)
		{
			for(i=0;i<size1;i++)
			{
				if(arr2[i]==arr1[j])
					i=size1;
				else if(i==size1-1)
					cout<<"("<<arr2[j]<<","<<arr2[j]<<"),";
			}
		}		
	cout<<"\b}";
	}
}

void closuresymmetric(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int i,j,f,m,n;
	cout<<"{";
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
			{
				f=0;
				for(m=0;m<size1;m++)
				{
					for(n=0;n<size2;n++)
					{
						if(arr1[i]==arr2[n]&&arr1[j]==arr2[m]&&matr[m][n]==1)
							f=1;										//to beak he loop
					}			
				} 
				if(f==0)
				{
					cout<<"("<<arr2[j]<<","<<arr1[i]<<"),";
				}
			}
		}		
	}
	cout<<"\b}";	
}

void closuretransitive(int matr[20][20],int arr1[20],int arr2[20],int size1,int size2)
{
	int i,j,f,m,n,r,c;
	cout<<endl<<"{";
	for(i=0;i<size1;i++)												//1st loop
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
			{
				for(m=0;m<size1;m++)									//2nd loop 
				{
					for(n=0;n<size2;n++)
					{
						if(matr[m][n]==1&&arr1[j]==arr2[m])
						{
							f=0;
							for(r=0;r<size1;r++)								//3rd loop
							{
								for(c=0;c<size2;c++)
								{
									if(arr1[r]==arr1[i]&&arr2[c]==arr2[n]&&matr[r][c]==1)
									{
										f=1;
									}
								}
							}
							if(f==0)
 								cout<<"("<<arr1[i]<<","<<arr2[n]<<"),";
						}			
					}
				}
			}			
		} 
	}	
	cout<<"\b}";
}


int main()
{
	int i,j,f1,f2,f3,f4,size1,size2,matr[20][20],arr1[20],arr2[20];
	cout<<"Enter the size of the first set : ";
	cin>>size1;
	cout<<"Enter the size of the second set : ";
	cin>>size2;
	cout<<"{";
	for(i=0;i<size1;i++)
	{
		cin>>arr1[i];
		cout<<",";
	}	
	cout<<"\b}";
	for(j=0;j<size1;j++)
	{
		cin>>arr2[j];
		cout<<",";
	}	
	cout<<"\b}";
	cout<<"Enter 1 if you want to take that element in the matrix otherwise enter 0"<<endl;
	
	int t;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			cout<<"("<<arr1[i]<<","<<arr2[j]<<")";
			cout<<" want to take the element in the relation ";
			cin>>t;
			if(t==1)
				matr[i][j]=1;
			else
				matr[i][j]=0;	
		}		
	}
	
	cout<<endl<<"The relation is : {";	
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(matr[i][j]==1)
				cout<<"("<<arr1[i]<<","<<arr2[j]<<"),";
		}		
	}	
	cout<<"\b}"<<endl;
	
	f1=reflexive(matr,arr1,arr2,size1,size2);
	f2=symmetric(matr,arr1,arr2,size1,size2);
	f3=transitive(matr,arr1,arr2,size1,size2);
	f4=antisymmetric(matr,arr1,arr2,size1,size2);
	
	if(f1==1)
		cout<<"The relation is reflexive."<<endl;
	else
		cout<<"The relation is not reflexive."<<endl;
	if(f2==1)
		cout<<"The relation is symmetric."<<endl;
	else
		cout<<"The relation is not symmetric."<<endl;
	if(f3==1)
		cout<<"The relation is transitive."<<endl;
	else
		cout<<"The relation is not transitive."<<endl;
	if(f4==1)
		cout<<"The relation is antisymmetric."<<endl;
	else
		cout<<"The relation is not antisymmetric."<<endl;
	cout<<"***********************************************************************************************************"<<endl;			 	
	if(f1==1&&f2==1&&f3==1)
		cout<<"The relation is a Equivalence relation"<<endl;
	else
		cout<<"not a equivalence relation"<<endl;
	if(f1==1&&f3==1&&f4==1)
		cout<<"The relation is a Partial order relation"<<endl<<endl;
	else	
		cout<<"not a partial order relation"<<endl;
	cout<<"***********************************************************************************************************"<<endl;			 	
	if(f1==0)
	{
		cout<<endl<<"The closure reflexive is : ";
		closurereflexive(matr,arr1,arr2,size1,size2);
	}
	if(f2==0)
	{
		cout<<endl<<"The closure symmetric is : ";
		closuresymmetric(matr,arr1,arr2,size1,size2);	
	}
	if(f3==0)
	{
		cout<<endl<<"The closure transitive is : ";
		closuretransitive(matr,arr1,arr2,size1,size2);	
	}
	
	return 0;
}
