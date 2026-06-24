#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int coinchange (int n,vector<int> &coins, int amount)
{
    vector<vector<int> > CC (n+1, vector<int>(amount+1, INT_MAX-1 ) );
    for(int i=0;i<=n;i++) {
        CC[i][0]=0;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=amount;j++) {
    if (j>=coins [i-1]) {
            CC[i][j]=min (CC[i-1][j], 1+CC[i][j-coins [i-1]]);
            }
            else{
                CC[i][j]=CC[i-1][j];
            }

        }
    }
 return CC[n] [amount];
}
int main()
{
    int n;
    cout<<"Enter the number of coins:";
    cin>>n;

    vector<int> coins (n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of:"<<i+1<<"coins:";
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter the amount:";
    cin>>amount;
    int result=coinchange (n, coins, amount);
    cout<<"Total coins:"<< result<<endl;

}






