#include <algorithm>
#include <vector>

using namespace std;

int COL;

bool compare(vector<int> a, vector<int> b){
    if(a[COL-1] == b[COL-1]) return a[0] > b[0];
    return a[COL-1] < b[COL-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    vector<int> check;
    COL = col;
    sort(data.begin(),data.end(),compare);
    
    for(int i = row_begin-1;i < row_end;i++){
        int tmp = 0;
        
        for(int j = 0;j < data[i].size();j++) tmp += data[i][j]%(i+1);
        
        check.push_back(tmp);
    }
    
    int answer = 0;
    
    for(int i = 0;i < check.size();i++) answer ^= check[i];
    
    return answer;
}
