#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int what = 0;
    if(ext == "code") what = 0;
    else if(ext == "date") what = 1;
    else if(ext == "maximum") what = 2;
    else if(ext == "remain") what = 3;
    
    for(int i = 0;i < data.size();i++){
        if(data[i][what] < val_ext){
            answer.push_back(data[i]);
        }
    }
    
    if(sort_by == "code") what = 0;
    else if(sort_by == "date") what = 1;
    else if(sort_by == "maximum") what = 2;
    else if(sort_by == "remain") what = 3;
    
    sort(answer.begin(), answer.end(), [what](const vector<int>& a, const vector<int>& b) {
        return a[what] < b[what];
    });
    
    return answer;
}
