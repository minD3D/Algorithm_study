#include<iostream>
#include<vector>
using namespace std;
#define BIG 1000000

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=0,n2=0,l1=nums1.size(),l2=nums2.size();
    int c1=BIG,c2=BIG;
    int all_length=nums1.size()+nums2.size();
    vector<int> allnum;
    bool fin1=false,fin2=false;
    fin1 = (l1==0) ? true : false;
    fin2 = (l2==0) ? true : false;
    
    for(int i=0; i<all_length; i++){
        c1 = (!fin1)?nums1.at(n1);
        c2 = (!fin2)? nums2.at(n2);
        
        if(c1<=c2){
            allnum.push_back(c1);
            n1++;
        }
        if(c1>c2){
            allnum.push_back(c2);
            n2++;
        }
        if(n1==l1){
            fin1=true;
            c1=BIG;
        }
        if(n2==l2){
            fin2=true;
            c2=BIG;
        }
    }
    if(all_length%2==1)return allnum.at(all_length/2);
    else return (double)allnum.at(all_length/2-1)/2+(double)allnum.at(all_length/2)/2;
}

int main(){
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5,6};

    cout<<findMedianSortedArrays(v1,v2)<<endl;
    
}

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // double fs=0,fb=0;
    // while(all_length>2){ 
    //     cout<<"s1: "<< nums1[s1] <<endl;
    //     cout<<"s2: "<< nums2[s2] <<endl;
    //     cout<<"b1: "<< nums1[b1] <<endl;
    //     cout<<"b2: "<< nums2[b2] <<endl;
    //     if( nums1[s1] < nums2[s2] && s1<nums1.size())
    //     {
    //         s1++;
    //         all_length--;
    //         fs=nums2[s2];
    //     }   
    //     if( nums1[s1] > nums2[s2] && s2<nums2.size())
    //     {
    //         s2++;
    //         all_length--;
    //         fs=nums2[s1];
    //     }   
	// 	if( nums1[b1] > nums2[b2] && b1>0 )  
    //     {
    //         b1--;
    //         all_length--;
    //         fb=nums2[b2];
    //     }
    //     if( nums1[b1] < nums2[b2] && b2>0 )  
    //     {
    //         b2--;
    //         all_length--;
    //         fb=nums1[b1];
    //     }
    //     cout<<all_length<<endl<<endl;
    // }
    // if(all_length==1){
    //     if(fb>fs)return fb;
    //     else return fs;
    // }
    // else{
    //     return (fs+fb)/2;
    // }
        
//     }
// };

