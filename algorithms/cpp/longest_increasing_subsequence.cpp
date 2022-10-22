class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        if(n<=1)    return n;
        vector<int>h(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i])
                    h[i]=max(h[i],h[j]+1);
            }
        }
        sort(h.begin(),h.end());
        return h[n-1];
    }
};
