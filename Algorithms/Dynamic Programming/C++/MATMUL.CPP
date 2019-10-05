#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void main()
{
    int r1,c1,r2,c2;
    clrscr();
    cout<<"Enter the number of rows and columns for matrix 1:"<<endl;
    cin>>r1;
    cin>>c1;
    int mat1[10][10];
    int i,j,k;
    int flag;

    cout<<"Enter the elements of first matrix:"<<endl;
    for(i=0;i<r1;i++)
        {
        for( j=0;j<c1;j++)
            {
                cin>>mat1[i][j];
            }
        }
    cout<<"Enter the number of rows and columns for the second matrix"<<endl;
    cin>>r2;
    cin>>c2;
    int mat[10][10];
    cout<<"Enter the elements  of the second matrix:"<<endl;
    for( k=0;k<r2;k++)
        {
        for(int l=0;l<c2;l++)
            {
                cin>>mat[k][l];
            }
        }
    int output[10][10];
    if(c1==r2)
    {
        flag=1;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                output[i][j]=0;
                for(k=0;k<c1;k++)
                {
                    output[i][j]+=mat1[i][k]*mat[k][j];
                }
            }
        }

    }
    else
        cout<<"Not possible"<<endl;

    if(flag==1)
    {
        cout<<"The answer is:"<<endl;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                cout<<output[i][j]<<" " ;
            }
            cout<<"\n";
        }
    }
    getch();
}
