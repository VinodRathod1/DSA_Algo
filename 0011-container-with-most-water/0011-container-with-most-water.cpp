class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,maxans=0;
        while(l<r){
            int width=r-l;
            int h=min(height[l],height[r]);
            maxans=max(maxans,h*width);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxans;
    }
};