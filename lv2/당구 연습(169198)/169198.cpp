#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0;i < balls.size();i++){
        int c1, c2, c3, c4;
        c1 = c2 = c3 = c4 = INT_MAX;
         
        if(startX != balls[i][0] || startY > balls[i][1]){
            //top
            c1 = pow(abs(balls[i][0]-startX),2) + pow(abs(n-startY)+abs(n-balls[i][1]),2);
        }
        if(startX != balls[i][0] || startY < balls[i][1]){
            //bottom
            c2 = pow(abs(balls[i][0]-startX),2) + pow(startY+balls[i][1],2);
        }
        if(startY != balls[i][1] || startX < balls[i][0]){
            //left
            c3 = pow(startX+balls[i][0],2) + pow(abs(startY-balls[i][1]),2);
        }
        if(startY != balls[i][1] || startX > balls[i][0]){
            //right
            c4 = pow(abs(m-balls[i][0])+abs(m-startX),2) + pow(abs(startY-balls[i][1]),2);
        }
        answer.push_back(min(min(c1,c2),min(c3,c4)));
    }
    
    return answer;
}
