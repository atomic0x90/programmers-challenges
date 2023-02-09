#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector <string> v;
    string st = "A";
    for(int i = 0;i < 26;i++){
        v.push_back(st);
        st[0]++;
    }

    for(int i = 0;i < msg.size();i++){
        int check = msg[i]-64;
        string now = "";
        now += msg[i];
        string tmp = now;
        
        for(int j = i+1;j < msg.size();j++){
            tmp += msg[j];
            int flag = -1;
            
            for(int k = 0;k < v.size();k++){
                if(v[k] == tmp){
                    flag = k;
                    break;
                }
            }
            if(flag != -1){
                check = flag+1;
                i = j;
            }
            else{
                v.push_back(tmp);
                break;
            }
        }
        answer.push_back(check);
    }
    return answer;
}
