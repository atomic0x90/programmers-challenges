#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    set<string> s;
    int check = 1;
    int a = 1,b = 1;
    s.insert(words[0]);
    
    for(int i = 1;i < words.size();i++){
        a++;
        if(words[i-1][words[i-1].size()-1] != words[i][0]){
            answer[0] = a;
            answer[1] = b;
            break;
        }
        else{
            s.insert(words[i]);
            if(s.size() != check+1){
                answer[0] = a;
                answer[1] = b;
                break;
            }
            else check++;
        }
        
        if(a == n){
            a = 0;
            b++;
        }
    }

    return answer;
}
