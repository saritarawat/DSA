//{ Driver Code Starts
#include "common.h"


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        // Your code here
        if(n == 0)
        {
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int>> pQueue;
        for(int i = 0; i < n; ++i)
        {
            pQueue.push(arr[i]);
        }
        
        long long int cost = 0;
        while(pQueue.size() > 1)
        {
            long long int temp1 = pQueue.top();
            pQueue.pop();
            long long int temp2 = pQueue.top();
            pQueue.pop();
            pQueue.push(temp1+temp2);
            cost+=(temp1+temp2);
        }
        return cost+pQueue.top();
    }
};


//{ Driver Code Starts.

int main() {
    Solution sol;
    long long arr[] = {4,3,2,6};
    long long n = 4;
    sol.minCost(arr, n);
    return 0;
}

// } Driver Code Ends