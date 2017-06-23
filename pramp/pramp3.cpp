#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

vector<int> GetIndicesOfItemWeights(vector<int> , int);

int main()
{
  vector<int> arr = {4, 6, 10, 4, 16};
  int lim = 8;

  vector<int> ans;

  ans = GetIndicesOfItemWeights(arr, lim);

  cout << endl << ans[0] << " " << ans[1];
}

vector<int> GetIndicesOfItemWeights(vector<int> arr, int lim)
{
  unordered_map<int, int> match;
  vector<int> ans;

  for (int i = 0; i < arr.size(); i++) {
    // Check if another item is looking for current value as a match.
    if (match.count(arr[i]) == 0) {
      // Add unique pair that would match current value.
      // Store index as value since that is what is wished to be returned.
      match[lim - arr[i]] = i;
    } else {
      ans = {match[arr[i]], i};
      return ans;
    }
  }

  ans = {-1, -1};
  return ans;
}
