#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
private:
  unordered_map<string, set<string>> adjList;
  vector<string> result;
  int size = 0;
  bool findItineraryUtil(string src)
  {
    if (result.size() == size+1)
    {
      return true;
    }

    set<string> &list = adjList[src];
    for (auto itr = list.begin(); itr != list.end(); ++itr)
    {
      string temp = *itr;
      list.erase(itr);
      result.push_back(temp);
      bool res = findItineraryUtil(temp);
      if (res)
      {
        return true;
      }
      result.pop_back();
      list.insert(temp);
    }
    return false;
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets)
  {
    size = tickets.size();
    if (size == 0)
    {
      return result;
    }

    for (int i = 0; i < size; ++i)
    {
      adjList[tickets[i][0]].insert(tickets[i][1]);
    }
    result.push_back("JFK");
    bool res = findItineraryUtil("JFK");
    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<string>> tickets{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  vector<string> resu = sol.findItinerary(tickets);

  return 0;
}