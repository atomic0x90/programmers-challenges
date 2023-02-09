#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int x1,x2,y1,y2;
    int fnum;
    vector<int> answer;
    vector<int> num;
    vector<vector<int> > v(rows,vector<int>(columns,0));
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size();j++) v[i][j] = i*columns + j+1;
    }
    
    for(int i = 0;i < queries.size();i++){
        num.clear();
        fnum = 0;
        x1 = queries[i][0]-1;
        y1 = queries[i][1]-1;
        x2 = queries[i][2]-1;
        y2 = queries[i][3]-1;
        for(int j = y1;j <= y2;j++){
            num.push_back(v[x1][j]);
            if(fnum != 0) v[x1][j] = fnum;
            fnum = num.back();
        }
        for(int j = x1+1;j <= x2;j++){
            num.push_back(v[j][y2]);
            v[j][y2] = fnum;
            fnum = num.back();
        }
        for(int j = y2-1;j >= y1;j--){
            num.push_back(v[x2][j]);
            v[x2][j] = fnum;
            fnum = num.back();
        }
        for(int j = x2-1;j >= x1;j--){
            num.push_back(v[j][y1]);
            v[j][y1] = fnum;
            fnum = num.back();
        }
        
        answer.push_back(*min_element(num.begin(),num.end()));
    }
    
    return answer;
}
