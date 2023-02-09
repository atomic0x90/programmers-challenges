#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int check = 0;
    int x = -1,y = 0;
    int num = 1;
    int bot = n;
    vector<vector<int> >v(n,vector<int>(n,0));
    
    while(n){
        if(check == 0){
            for(int i = 0;i < n;i++) v[++x][y] = num++;
        }
        else if(check == 1){
            for(int i = 0;i < n;i++) v[x][++y] = num++;
        }
        else if(check == 2){
            for(int i = 0;i < n;i++) v[--x][--y] = num++;
        }
        n--;
        if(check == 2) check = 0;
        else check++;
    }
    
    for(int i = 0;i < bot;i++){
        for(int j = 0;j < bot;j++){
            if(v[i][j] != 0) answer.push_back(v[i][j]);
            else break;
        }
    }
    
    return answer;
}
