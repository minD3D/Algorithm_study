#include <cstdio>
#include <queue>
#include <iostream>  
#include <functional>
#pragma warning(disable: 4996) 
using namespace std;

// global
priority_queue<int> pq;
int N;

int main() {
    scanf("%d", &N);
    for (int n_idx = 0; n_idx < N; n_idx++) {
        int _input_int;
        scanf("%d", &_input_int);

        // 0이면 하나 빼서 출력
        // 아니면 삽입 
        switch (_input_int) {
        case 0:
            if (pq.size()){
                printf("%d\n", pq.top());
                pq.pop();
            }
            else {
                printf("%d\n", 0);
            }
            break;
        default:
            pq.push(_input_int);
            break;
        } 
    } 

    return 0;
}
