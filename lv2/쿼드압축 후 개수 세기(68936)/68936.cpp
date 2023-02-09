#include <string>
#include <vector>

using namespace std;

vector<vector<int> > v;
int result0 = 0;
int result1 = 0;

void algo(int a,int b,int size){
    int check = 0;
    for(int i = a;i < a+size;i++){
        for(int j = b;j < b+size;j++){
            if(v[i][j] != v[a][b]){
                check = 1;
                break;
            }
        }
    }
    
    if(check == 1){
        algo(a,b,size/2);
        algo(a,b+size/2,size/2);
        algo(a+size/2,b,size/2);
        algo(a+size/2,b+size/2,size/2);
    }
    else if(check == 0){
        v[a][b] == 1 ? result1++ : result0++;
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    v = arr;
    algo(0,0,arr.size());
    answer.push_back(result0);
    answer.push_back(result1);
    return answer;
}
