class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int arr[amount+1];
        for(int i=0; i<amount+1; i++)
            arr[i]=-1;
        arr[0]=0;
        
        for(int i=0; i<=amount; i++){
            if(arr[i]==-1)continue;            
            for(int j=0; j<coins.size(); j++){
                int tmp=i;
                if(coins[j]>amount)continue;
                tmp+=coins[j];
                if(tmp>amount)continue;
        
                if(arr[tmp]<0)
                    arr[tmp]=arr[i]+1;
                else{
                    arr[tmp]= (arr[i]+1)<arr[tmp] ? (arr[i]+1) : arr[tmp]; 
                }
            }    
        }
        return arr[amount];
    }
};

//O(n*m)