#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define multi ll t;cin>>t;while(t--)
#define present(c,i) (c.find(i)!=c.end())
#define cpresent(c,i) (find(all(c),i)!=c.end())
#define mod 1000000007

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
  sort(all(nums));
  int k;
  cin>>k;
  return kSum(nums, target, 0, k);
}

vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k)
{
    vector<vector<int>> res;    
    // If we have run out of numbers to add, return res.
    if (start == nums.size())
      return res;
    
    // There are k remaining values to add to the sum. The 
    // average of these values is at least target / k.
    long long average_value = target / k;
    
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest 
    // value in nums is smaller than target / k.
    if  (nums[start] > average_value || average_value > nums.back())
      return res;
        
    if (k == 2)
      return twoSum(nums, target, start);

    for (int i = start; i < nums.size(); ++i)
    {
      if (i == start || nums[i - 1] != nums[i])
      {
        for (vector<int>& subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1))
        {
          res.push_back({nums[i]});
          res.back().insert(end(res.back()), begin(subset), end(subset));
        }
      }
    }
                                        
    return res;
}

vector<vector<int>> twoSum(vector<int>& nums, long long target, int start)
{
    vector<vector<int>> res;
    unordered_set<long long> s;

    for (int i = start; i < nums.size(); ++i)
    {
        if (res.empty() || res.back()[1] != nums[i])
        {
            if (s.count(target - nums[i]))
                res.push_back({int(target - nums[i]), nums[i]});
        }
        s.insert(nums[i]);
    }
                                          
    return res;
}  