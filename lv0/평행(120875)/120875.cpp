#include <vector>

using namespace std;
vector<vector<int>> v;

bool algo(int a,int b,int c,int d){
    if((double)(v[a][1]-v[b][1])/(v[a][0]-v[b][0]) == (double)(v[c][1]-v[d][1])/(v[c][0]-v[d][0])) return true;
    else return false;
}

int solution(vector<vector<int>> dots) {
    v = dots;
    if(algo(0,1,2,3)) return 1;
    if(algo(0,2,1,3)) return 1;
    if(algo(0,3,1,2)) return 1;
    
    return 0;
}
