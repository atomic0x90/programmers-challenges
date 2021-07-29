#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int check;
    string s1,s2,s3;
    vector<pair<string,string> > v;     //state, id
    map<string,string> m;               //id, name
    for(int i = 0;i < record.size();i++){
        check = 0;
        s1 = s2 = s3 = "";
        for(int j = 0;j < record[i].size();j++){
            if(record[i][j] != ' '){
                if(check == 0) s1 += record[i][j];
                else if(check == 1) s2 += record[i][j];
                else if(check == 2) s3 += record[i][j];
            }
            else check++;
        }
        v.push_back(make_pair(s1,s2));
        if(s3 != ""){
            if(!m.count(s2)) m.insert(make_pair(s2,s3));
            else m.find(s2)->second = s3;
        }
    }
    
    for(int i = 0;i < v.size();i++){
        if(v[i].first == "Enter") answer.push_back(m.find(v[i].second)->second+"님이 들어왔습니다.");
        else if(v[i].first == "Leave") answer.push_back(m.find(v[i].second)->second+"님이 나갔습니다.");
    }
    return answer;
}
