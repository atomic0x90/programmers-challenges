#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int> a,const vector<int>b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v1;
    vector<vector<int> > v2;
    vector<int> tu;
    int check = 0;
    
    s.erase(s.begin(),s.begin()+1);
    s.erase(s.size()-1,s.size());
    
    string st = "";
    for(int i = 0;i < s.size();i++){
        if(s[i] == '}'){
            st.erase(st.begin(),st.begin()+1);
            v1.push_back(st);
            st = "";
            i++;
        }
        else st += s[i];
    }
    
    v2.resize(v1.size());
    st = "";
    for(int i = 0;i < v1.size();i++){
        for(int j = 0;j < v1[i].size();j++){
            if(v1[i][j] != ',') st += v1[i][j];
            else{
                v2[i].push_back(stoi(st));
                st = "";
            }
        }
        if(st != ""){
            v2[i].push_back(stoi(st));
            st = "";
        }
    }
    
    sort(v2.begin(),v2.end(),compare);
    
    for(int i = 0;i < v2.size();i++){
        for(int j = 0;j < v2[i].size();j++){
            int flag = 0;
            for(int k = 0;k < tu.size();k++){
                if(v2[i][j] == tu[k]){
                    v2[i].erase(v2[i].begin()+j,v2[i].begin()+j+1);
                    flag = 1;
                }
            }
            if(flag == 1) j--;
        }
        
        tu.push_back(v2[i][0]);
    }
    
    answer = tu;
    return answer;
}
