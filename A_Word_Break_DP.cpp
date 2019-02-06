#include <vector>
#include <map>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

//save points
//1. when it's start to increase (max)
//2. when it's start to decrease (max)

//decrease and increase make a hole

class Solution {
int res;
public:
    void pullup(vector<int>& height){
        vector<int> point;
        bool is_up=true; //false is decrease
        int pnt=height[0];
        for(int i=1; i<height.size(); i++){
            if(pnt>height[i]){//start to decrease
                if(is_up){
                    point.push_back(i-1);
                }
                is_up=false;
                
            }
            if(pnt<height[i]){//start to increase
                is_up=true;
            }
            pnt=height[i];
        }
        if(is_up)point.push_back(height.size()-1);

        if(point.size()<=1){
            return;
        }
        else {
            int sp,ep;
            ep=point[0];
            for(int i=1; i<point.size(); i++){
                sp=ep;
                ep=point[i];
                int m=min(height[sp],height[ep]);
                for(int j=sp+1; j<ep; j++){
                    if(height[j]<m){
                        res+=m-height[j];
                        height[j]=m;
                    }
                }
                cout<<"r"<<res<<endl;
            }
            pullup(height);
        }
    }
    int trap(vector<int>& height) {
        if(height.size()==0)return 0;
        res=0;
        pullup(height);
        return res;
    }
};