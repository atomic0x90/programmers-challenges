#include <string>
#include <vector>

using namespace std;

bool blank = false;
vector<bool> bVector(26,false);
vector<bool> BVector(26,false);

string solution(string my_string) {
    string answer = "";
    for(int i = 0;i < my_string.size();i++){
        if(my_string[i] == ' '){
            if(!blank){
                answer += ' ';
                blank = true;
            }
        }
        else if(my_string[i] >= 'a'){
            if(!bVector[my_string[i]-'a']){
                answer += my_string[i];
                bVector[my_string[i]-'a'] = true;
            }
        }
        else{
            if(!BVector[my_string[i]-'A']){
                answer += my_string[i];
                BVector[my_string[i]-'A'] = true;
            }
        }
    }
    return answer;
}
