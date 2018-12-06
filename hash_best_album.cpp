#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genrecnt;//장르별 재생수 합산값
    map<string,int> isone;//장르별 노래의 개수 저장
    map<string,int[2]> pop1st;//장르 주소에 가장 재생수가 높은 곡의 횟수와 인덱스 저장
    map<string,int[2]> pop2nd;//[재생횟수, 인덱스]
        
    for(int i=0; i<genres.size(); i++){
        genrecnt[genres[i]]+=plays[i];
        isone[genres[i]]++;
        if(pop1st[genres[i]][0]<plays[i]){
            //기존 1위를 2위로 옮긴다
            pop2nd[genres[i]][0]=pop1st[genres[i]][0];
            pop2nd[genres[i]][1]=pop1st[genres[i]][1];
            //새로운 최댓값을 저장
            pop1st[genres[i]][0]=plays[i];
            pop1st[genres[i]][1]=i;
        }
        else if(pop2nd[genres[i]][0]<plays[i]){
            pop2nd[genres[i]][0]=plays[i];
            pop2nd[genres[i]][1]=i;   
        }
    }


    map<string,int> ::iterator it;
    vector<pair<int, string>> genresort;//소팅을 위한 벡터
    for(it=genrecnt.begin(); it!=genrecnt.end(); it++){
        genresort.push_back(make_pair(it->second,it->first));
    }
    
    sort(genresort.begin(),genresort.end());

    //크기 순서대로 입력
    for(int i=genresort.size()-1; i>=0; i--){
        string a=genresort[i].second;
        if(isone[a]==0){
            continue;
        }        
        else if(isone[a]==1){
            answer.push_back(pop1st[a][1]);
        }
        else{
            answer.push_back(pop1st[a][1]);
            answer.push_back(pop2nd[a][1]);
        }   
    }
    return answer;
}

int main(){
    vector<string> genres={"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays={500, 600, 150, 800, 2500};	
    vector<int>a=solution(genres, plays);
    for(int i=0; i<a.size(); i++)
    cout<<"r-"<<a[i]<<endl;

}