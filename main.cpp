#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    int n,i,a[10000],search;
    clock_t t1,t2;
    float dtime;

    cout<<"enter the number of elements\n";
    cin>>n;
    cout<<"enter the element\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ofstream outfile("rishabh.txt");
    for(i=0;i<n;i++)
    {
        outfile<<a[i]<<"  ";
    }
    outfile.close();
    ifstream infile("rishabh.txt");
    for(i=0;i<n;i++)
    {
        infile>>a[i];
    }
    infile.close();
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
for(i=0;i<n-1;i++)
{
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}

cout<<"sorted elements are \n";
for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}

    int first=0;
    int last=n-1;
    int middle=(first+last)/2;

cout<<"\nmiddle element is "<<a[middle]<<"\n";
t1=clock();

cout<<"enter the element to search\n";
    cin>>search;

    while(first<=last)
    {
        if(a[middle]==search)
        {
            cout<<"element "<<a[middle]<<" found at location "<<(middle+1);
            break;
        }
        else if(search>a[middle])
        {
            first=middle+1;
        }
        else
        {
            last=middle-1;
        }
    middle=(first+last)/2;
    }
    if(first>last)
    {
        cout<<"\nelement not found\n";
    }
    t2=clock();
    cout<<"time t1 and t2 are \n"<<float(t1)/CLOCKS_PER_SEC<<" and "<<float(t2)/CLOCKS_PER_SEC;
    dtime=float(t2)-float(t1);
    cout<<"\nIt tooks me seconds "<<(dtime)/CLOCKS_PER_SEC;
    return 0;
}
