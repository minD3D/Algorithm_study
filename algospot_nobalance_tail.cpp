#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    vector<int> pos;
    for(int i=111; i<999; i++){
        if(i%10!=0&&i%100>10)
            pos.push_back(i);
    }

    for(int i=0; i<baseball.size(); i++){
        string n=to_string(baseball[i][0]);
        int s=baseball[i][1];
        int b=baseball[i][2];
        // cout<<baseball[i][0]<<endl;
        // cout<<s<<","<<b<<endl;
        // cout<<"--------------------"<<endl;
                
        vector<int> postmp;        
        for(int j=0; j<pos.size(); j++){
            string t=to_string(pos[j]);
            int ts=0, tb=0;
            
            for(int a=0; a<3; a++){
                for(int b=0; b<3; b++){
                    if(t[a]==n[b]){
                        if(a==b)
                            ts+=1;
                        else if(a!=b)
                            tb+=1;
                        break;
                    }
                }
            }
            // cout<<pos[j]<<endl;
            
            if(ts==s&&tb==b){
                // cout<<n<<endl;
                // cout<<t<<endl;
                // cout<<ts<<","<<tb<<endl;
                postmp.push_back(pos[j]);

            }
        }
        pos.swap(postmp);
    }

    
    return pos.size();
}

int main(){
    cout<<solution({{123,1,1},{356,1,0},{327,2,0},{489,0,1}});
}


