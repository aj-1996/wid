#include<iostream>


using namespace std;

void swp(int* a, int* b)
{

    int t= *a;
    *a=*b;
    *b=t;
}

int part(int arr[],int low, int high)

{
    int index=low-1;
    int pivot = arr[high];

    for(int j=0;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            index++;
            swp(&arr[index],&arr[j]);

        }
    }
    swp(&arr[index+1],&arr[high]);
    return (index+1);
};

void quick(int arr[],int l,int up)
{


if(l<up)
    {
      int pi= part(arr,l,up);
      quick(arr,l,pi-1);
      quick(arr,pi+1,up);

    }

};


int main()
{
    int ar[5]={7,1,22,4,9};
    int n = sizeof(ar)/sizeof(ar[0]);

    quick(ar,0,n-1);
    for(int i=0;i<5;i++)
        cout<<ar[i]<<":";

    return 0;
}
