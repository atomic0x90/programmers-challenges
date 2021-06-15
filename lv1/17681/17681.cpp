#include <string>
#include <vector>

using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int> > a1(n);
    vector<vector<int> > a2(n);
    vector<vector<int> > add(n);
    
    int num,num2;
    for(int i = 0; i < n;i++){
        num = arr1[i];
        num2 = arr2[i];
        for(int j = 0;j < n;j++){
            a1[i].insert(a1[i].begin(),num%2);
            a2[i].insert(a2[i].begin(),num2%2);
            num = num/2;
            num2 = num2/2;
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            add[i].push_back(a1[i][j] + a2[i][j]);
    }
    
    string s;
    for(int i = 0;i < n;i++){
        s = "";
        for(int j = 0;j < n;j++){
            if(add[i][j] == 0) s += " ";
            else s += "#";
        }
        answer.push_back(s);
    }
    
    return answer;
}
