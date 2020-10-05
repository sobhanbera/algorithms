class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        vector<int>ans;
        map<int,int>m;
        
        for(int i=0;i<a.size();i++){
            int dif= t-a[i];
            if(m.find(dif)!=m.end()){
                ans.push_back(m[dif]);
                ans.push_back(i);
            }m[a[i]]=i;
        }return ans;
    }
};
