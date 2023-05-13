//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    int neighbour[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void closedIslandsUtil(vector<vector<int>>& matrix, int r, int c, int N, int M, vector<vector<bool>>& visited, bool& reachedBoundary) 
    {
        // Code here
        if(r < 0 || r >= N || c < 0 || c>= M)
        {
          reachedBoundary = true;
          return;
        }
        
        if(visited[r][c] || matrix[r][c] == 0)
        {
            visited[r][c] = true;
            return;
        }
        
        visited[r][c] = true;
        
        
        for(int i = 0; i < 4; ++i)
        {
            closedIslandsUtil(matrix, r+neighbour[i][0], c+neighbour[i][1], N, M, visited, reachedBoundary);
        }
    }
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        // Code here
        vector<vector<bool>> visited(N+1,vector<bool>(M+1, false));
        int count = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                if(visited[i][j] == false && matrix[i][j] != 0)
                {
                    bool reachedBoundary = false;
                    closedIslandsUtil(matrix, i, j, N, M, visited, reachedBoundary);
                    if(reachedBoundary == false)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
  vector<vector<int>>matrix{{0, 0, 0, 0, 0,},
{0, 1, 0, 0, 0,},
{0, 0, 0, 0, 0,},
{1, 1, 1, 0, 0,},
{1, 0, 1, 0, 0,},
{0, 0, 1, 0, 0,},
{0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0 }};

                
        Solution obj;
        int ans = obj.closedIslands(matrix, 8, 5);
        cout << ans << "\n";
	
	return 0;
	
}


// } Driver Code Ends