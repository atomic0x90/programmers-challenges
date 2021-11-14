#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w){
    int answer = 0;
    double gap;
    
    if(stations.front()-w-1 > 0){
        gap = stations.front()-w-1;
        answer += ceil(gap/((w*2)+1));
    }
    
    for(int i = 0;i < stations.size()-1;i++){
        if(stations[i]+w+1 > stations[i+1]-w-1) continue;
        gap = (stations[i+1]-w-1)-(stations[i]+w+1)+1;
        answer += ceil(gap/((w*2)+1));
    }
    
    if(stations.back()+w+1 <= n){
        gap = n-(stations.back()+w+1)+1;
        answer += ceil(gap/((w*2)+1));
    }

    return answer;
}
