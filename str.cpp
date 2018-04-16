#include<iostream>

using namespace std;

int main()
{
    int len=3*2;
int array1[len],array2[len],median,array3[len];

    for(int i=0;i<len; i++)
    {
        cin>>array1[i];
        array3[i]=i=array1[2];
    }


    for(int i=0 ; i<len;i++)
    {
        for(int j=0;j<=len;j++)
        {
            int temp=0;
            if(array3[i]>array3[i+1])
            {
                temp=array3[i];
                array3[i]=array3[i+1];
                array3[i+1]=temp;
            }

        }
    }
    for(int i=0;i<2*len;i++)
        cout<<array3[i] << endl;

return 0;

}
