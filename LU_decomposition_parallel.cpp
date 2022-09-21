#include<iostream>
#include<vector>


using namespace std;

int main()
{
    int n;
    cout<<"Enter the order of matrix"<<endl;
    cin>>n;
    float U[n][n];
    float L[n][n];
    float a[n][n];
    vector<int> p(n);
    cout<<"Enter the elements "<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)    ///  Taking input
        {
            cin>>a[i][j];
        }
    }
    
    
    
    
    
    
    
    
    
    
    cout<<"The values have been taken"<<endl;
   for(int i=0;i<n;i++){     /// taking lower values for U
        for(int j=0;j<n;j++){
            if(i>j){
                U[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){   /// Thaking upper values for L
        for(int j=0;j<n;j++){
            if(i==j){
                L[i][j]=1;
            }
            else if(i<j){
                L[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)  ///initializing vector
    {
        p[i] =i;
    }

 cout<<"Vector values initialize"<<endl;

    int max =0,k1;
    for(int k =1; k<n; k++) 
    {
        for(int i=k;i<n;i++)
        {
            if( max < a[i][k])
            {
                k1 = i;
                max = a[i][k];
            }
        }
        if(max==0)
        {
            cout<<"error";
            exit(0);
        }
        swap(p[k],p[k1]);

    for(int i =0; i<n;i++)  // Swapping the rows
        swap(a[k][i],a[k1][i]);

    for(int i=1; i<k;i++ )
          swap(a[k][i],a[k1][i]);


        U[k][k] = a[k][k];
        for(int i =k+1 ; i<n;i++)
        {
            L[i][k] = a[i][k]/U[k][k];
            U[k][i] = a[k][i];
        }
        for(int i = k+1 ;i<n;k++)
        {
            for(int j =k+1;j<n;j++)
            {
                a[i][j] = a[i][j] - L[i][k]*U[k][j];
            }
        }

    cout<<"chosen Pivot"<<endl;
    for(auto i:p)
        cout<<i<<" ";

    cout<<endl;

    cout<<"Lower triangular matrix(L):"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<L[i][j]<<" ";
        cout<<endl;

    cout<<endl;   
     
    cout<<"Upper triangular matrix(U):"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<U[i][j]<<" ";
        cout<<endl;

    }

}














