 Problem Statement:
 
 Coin Tower Game

Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus


Code:

#include<bits/stdc++.h>
using namespace std;
bool helper(int x, int y, int n) 
{ 
    int *dp=new int[n + 1];
   
    dp[0]=0;
    dp[1]=1;
    dp[x]=1;
    dp[y]=1;
    for (int i = 2; i <= n; i++) 
    {  
        if(i!=1 && i!=x && i!=y)
        {
          dp[i]=dp[i-1]^1;
            if (i - x >= 1) 
            {
                dp[i] =max(dp[i],dp[i - x]^1);    
            }
            if (i - y >= 1)
            {
                dp[i] =max(dp[i],dp[i - y]^1);    
            }
        } 
    
    } 
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" "<<dp[i]<<endl;
    }

    return dp[n];
} 
string findWinner(int n, int x, int y)
{
    string a="Whis";
    string b="Beerus";
	int k=helper(x,y,n);
    if(k==0)
        return a;
    else
        return b;
    
}
