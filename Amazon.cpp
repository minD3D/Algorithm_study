#include <bits/stdc++.h>

using namespace std;
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<pair<int, int> > nearestVegetarianRestaurant(int totalRestaurants, 
                                                    int** allLocations, 
										            int numRestaurants)
{
    vector<pair<int,int>> result;
    //input
    // num of restaurants
    // x,y -> location of restaurant 
    // num of restaurant I should return
    
    //distance => consider as x^2+y^2
    
    vector<pair<int,int>> distance_index;
    //save distance and its index on this vector 
    
    for(int i=0; i<totalRestaurants; i++){
        int x=*(*(allLocations+i)+0);
        int y=*(*(allLocations+i)+1);
        int dis=x*x+y*y;
        cout<<dis<<endl;
        
        distance_index.push_back(make_pair(dis, i));
    }
    
    sort(distance_index.front(),distance_index.end());
    
    int j=totalRestaurants-1;
    for(int i=0; i<numRestaurants; i++){
        int tmp_idx=distance_index[j].second;
        j-=1;
        result.push_back(make_pair(*(*(allLocations+tmp_idx)+0),*(*(allLocations+tmp_idx)+1)));
    }
    return result;
    
}
// FUNCTION SIGNATURE ENDS
int main(){

    int arr[8]={0,1,1,1,1};
    int* b=arr;
    // nearestVegetarianRestaurant(3,{{1,1},{2,1},{4,1}},1);
}