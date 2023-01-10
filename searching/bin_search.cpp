// first and lost position of an element in sorted array
vector<int> searchRange(vector<int>& a, int target)
{
    vector<int> ans(2,-1);
    int mid,high=a.size()-1,low=0;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(a[mid]<target)
        {
            low=mid+1;
        }
        if(a[mid]>target)
        {
            high=mid-1;
        }
        if(a[mid]==target)
        {
            ans[0]=mid;
            high=mid-1;
        }
    }
    low=0;
    high=a.size()-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(a[mid]<target)
        {
            low=mid+1;
        }
        if(a[mid]>target)
        {
            high=mid-1;
        }
        if(a[mid]==target)
        {
            ans[1]=mid;
            low=mid+1;
        }
    }
    return ans;
}