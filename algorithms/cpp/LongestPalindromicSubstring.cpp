class Solution {
public:
    ////https://www.youtube.com/watch?v=omIP6yrVaJg
    string longestPalindrome(string s) {
        int n=s.length(),l=INT_MIN;
        if(n==0)    return "";
        string t;
        bool d[n+1][n+1];
        
        for(int i=0;i<n;i++){
            d[i][i]=true;
            t=s.substr(i,1);
        }
        
        for(int j=1;j<n;j++){
            for(int  i=0;i<j;i++){
                if(s[i]==s[j] && j-i<=2){
                    d[i][j]=true;
                    if(l<j-i+1){
                        t=s.substr(i, j-i+1);
                        l=max(l,j-i+1);
                    }
                }    
                else if(s[i]==s[j] && j-i>2){
                    if(d[i+1][j-1]==true){
                        d[i][j]=true;
                        if(l<j-i+1){
                        t=s.substr(i, j-i+1);
                        l=max(l,j-i+1);
                    }
                    }
                    else    d[i][j]=false;
                }else d[i][j]=false;
            }
        }
        return t;
    }
};
