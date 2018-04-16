#include<iostream>
#include <fstream>
#include<string.h>
using namespace std;

int flag=0;

class Book
{
	public:
	char B_name[100];
	int price;
	char Auther_name[20];
	int stock;
	string ISBN_NO;
};

void create(Book p[],int n)
{
	for(int i=0;i<n;i++)
	{
		ifstream myfile("file.txt");
		if(myfile.is_open())
		{
			for(int i = 0; i < n; ++i)
			{
				myfile>>p[i].ISBN_NO;
				myfile>>p[i].B_name;
				myfile>>p[i].price;
				myfile>>p[i].Auther_name;
				myfile>>p[i].stock;
			}
		}
	}
}

void print(Book p[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<p[i].ISBN_NO;
		cout<<"\t";
		cout<<p[i].B_name;
		cout<<"\t";
		cout<<p[i].price;
		cout<<"\t";
		cout<<p[i].Auther_name;
		cout<<"\t";
		cout<<p[i].stock;
		cout<<"\n";
	}
}

void printrecord(Book p)
{
	cout<<"Book ISBN_NO : "<<p.ISBN_NO<<"\n";
	cout<<"Book B_name : "<<p.B_name<<"\n";
	cout<<"Book Price : "<<p.price<<"\n";
	cout<<"Book Auther_name : "<<p.Auther_name<<"\n";
	cout<<"Book Stock : "<<p.stock<<"\n";
}

int binary_search(Book obj[],int size,string key)
{
	int first = 0,last = size,mid,position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		mid = (first + last) / 2;
		if (obj[mid].ISBN_NO == key)
		{
			printrecord(obj[mid]);
			found = true;
			position = mid;
		}
		else if (obj[mid].ISBN_NO > key)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return position;
}

void merge(Book p[] , int low ,int high , int mid)
{
	int i , j , k;
	Book c[50];
	i =low;
	k=low;
	j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(p[i].ISBN_NO<p[j].ISBN_NO)
		{
			c[k] = p[i];
			k++;i++;
		}
		else
		{
			c[k] =p[j];
			k++;j++;
		}
	}
	while(i<=mid)
	{
		c[k]=p[i];
		k++;i++;
	}
	while(j<=high)
	{
		c[k]=p[j];
		k++;j++;
	}

	for(i=low ;i<k ; i++)
		p[i]=c[i];
}

void mergesort(Book p[] , int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(high+low)/2;
		mergesort(p , low ,mid);
		mergesort(p, mid+1, high);
		merge(p,low,high,mid);
	}
}

int main()
{
	Book s1[100];
	int n=7,res;
	int ch,ch0,ch2;
	string search;

	while(1)
	{
		cout<<"\n==== Library System=====";
		cout<<"\nSelect one of the following :";
		cout<<"\n1.Admin";
		cout<<"\n2.Student";
		cout<<"\n3.Exit";
		cout<<"\n===============================";
		cout<<"\nEnter your choice:";
		cin>>ch0;

		switch(ch0)
		{
			case 1:
				do
				{
					cout<<"\n==== Admin Side ======";
					cout<<"\n1.Load Records From File";
					cout<<"\n2.Exit";
					cout<<"\n===============================";
					cout<<"\nEnter the choice:";
					cin>>ch;
					switch(ch)
					{
						case 1: cout<<"Enter the number of records to load :";
							cin>>n;
							create(s1,n);
							mergesort(s1,0,n-1);
							cout<<"Sorted File Items Are :-\n";
							print(s1,n);
						break;

						case 2:
						break;

						default:
							cout<<"\nChoice Out of Match!!\n";
					}//switch 2 ch
				}while(ch!=2);//do 1
			break;// switch 1 case 1

			case 2:
				do
				{
					cout<<"\n==== Student Side ======";
					cout<<"\n1.Search for Book in library";
					cout<<"\n2.Exit";
					cout<<"\n===============================";
					cout<<"\nEnter the choice:";
					cin>>ch;
					switch(ch)
					{
						case 1: cout<<"Enter the ISBN_NO of Book to be searched:";
							cin>>search;
							res = binary_search(s1,n-1,search);
							if (res == -1)cout << "\n\nThis Item ISBN_NO Does Not Exist!!\nPlease Enter the proper ISBN_NO to search an Book.\n\n";
						break ;

						case 2:
						break;

						default:
							cout<<"\nChoice Out of Match!!\n";
					}
				}while(ch!=2);
			break;

			case 3:
				cout<<"exiting...!!\n";
				return 0;

			default:
				cout<<"Choice Out of Match!!";
		}
	}
return 0;
}


/*output:
student@210-15:~$ g++ lib.cpp
student@210-15:~$ ./a.out

==== Library System=====
Select one of the following :
1.Admin
2.Student
3.Exit
===============================
Enter your choice:1

==== Admin Side ======
1.Load Records From File
2.Exit
===============================
Enter the choice:1
Enter the number of records to load :3
Sorted File Items Are :-
1	Java	1500	Peterson	1000
3	C#	800	pachghare	980
7	C	400	balguruswami	200

==== Admin Side ======
1.Load Records From File
2.Exit
===============================
Enter the choice:2

==== Library System=====
Select one of the following :
1.Admin
2.Student
3.Exit
===============================
Enter your choice:2 

==== Student Side ======
1.Search for Book in library
2.Exit
===============================
Enter the choice:1
Enter the ISBN_NO of Book to be searched:7
Book ISBN_NO : 7
Book B_name : C
Book Price : 400
Book Auther_name : balguruswami
Book Stock : 200

==== Student Side ======
1.Search for Book in library
2.Exit
===============================
Enter the choice:1
Enter the ISBN_NO of Book to be searched:4


This Item ISBN_NO Does Not Exist!!
Please Enter the proper ISBN_NO to search an Book.


==== Student Side ======
1.Search for Book in library
2.Exit
===============================
Enter the choice:2

==== Library System=====
Select one of the following :
1.Admin
2.Student
3.Exit
===============================
Enter your choice:3
exiting...!!
student@210-15:~$ */
