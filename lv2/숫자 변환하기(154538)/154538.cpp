#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    if(x == y) return 0;
    vector<vector<int>> v(1000001,vector<int>(3,12345678));
    v[y][0] = v[y][1] = v[y][2] = 0;
    
    for(int i = y;i != x;i--){
        if(min(v[i][0],min(v[i][1],v[i][2])) == 12345678) continue;
        if(i%3 == 0 && i/3 >= x) v[i/3][2] = min(v[i][0],min(v[i][1],v[i][2]))+1;
        if(i%2 == 0 && i/2 >= x) v[i/2][1] = min(v[i][0],min(v[i][1],v[i][2]))+1;
        if(i-n >= x) v[i-n][0] = min(v[i][0],min(v[i][1],v[i][2]))+1;
    }
    
    return min(v[x][0],min(v[x][1],v[x][2])) != 12345678 ? min(v[x][0],min(v[x][1],v[x][2])) : -1;
}
