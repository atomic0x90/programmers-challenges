#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
using namespace std;

bool compare(pair<pair<string,int>,pair<string,int>> a, pair<pair<string,int>,pair<string,int>> b){
    if(a.second.first < b.second.first) return true;
    else if(a.second.first > b.second.first) return false;
    else{
        if(a.second.second < b.second.second) return true;
        else if(a.second.second > b.second.second) return false;
        else return a.first.second < b.first.second;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string,int>,pair<string,int> > > v;//files name,input num ,files tolower name ,files mid num
    for(int i = 0;i < files.size();i++){
        string head = "";
        int num = 0;
        string tail = "";
        int check;
        for(check = 0;!isdigit(files[i][check]);check++) head += tolower(files[i][check]);
        for(;isdigit(files[i][check]);check++) num = num*10 + (files[i][check]-'0');
        for(;check < files[i].size();check++) tail += files[i][check];
        
        v.push_back(make_pair(make_pair(files[i],i),make_pair(head,num)));
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0;i < v.size();i++) answer.push_back(v[i].first.first);
    return answer;
}
