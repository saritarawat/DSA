//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    unordered_set<string> mDictionary;

    bool wordBreakUtil(string s, vector<string>& result)
    {
        // code here
        if(s.size() == 0)
        {
          return true;
        }
        for(int i = 0; i <= s.size(); ++i)
        {
          string subStr = s.substr(0, i);
          if(mDictionary.find(subStr) != mDictionary.end())
          {
            bool res = wordBreakUtil(s.substr(i, s.size()-i), result);
            if(res)
          }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto& words : dict)
        {
          mDictionary.emplace(words);
        }
        vector<string> result;
        //wordBreakUtil(s, 0, s.length()-1, result);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends