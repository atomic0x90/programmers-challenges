#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    //1
    for(int i = 0;i < new_id.size();i++)
        new_id[i] = tolower(new_id[i]);
    
    //2
    for(int i = 0;i < new_id.size();i++){
        if( ( (int)new_id[i] > 96 && (int)new_id[i] < 123) || ( (int)new_id[i] > 47 && (int)new_id[i] < 58) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            tmp += new_id[i];
    }
    new_id = tmp;
    tmp = "";
    
    //3
    int check = 0;
    for(int i = 0;i < new_id.size();i++){
        if(new_id[i] == '.'){
            check = 1;
        }
        else{
            if(check == 1){
                tmp += '.';
                tmp += new_id[i];
                check = 0;
            }
            else
                tmp += new_id[i];
        }
    }
    new_id = tmp;
    tmp = "";
    
    //4
    if(new_id[0] == '.')
        new_id.erase(0,1);
    if(new_id[new_id.size()-1] == '.')
        new_id.erase(new_id.size()-1);
    
    //5
    if(new_id == "")
        new_id = 'a';
    
    //6
    if(new_id.size() > 15)
        new_id.erase(15);
    if(new_id[new_id.size()-1] == '.')
        new_id.erase(new_id.size()-1);
    
    //7
    if(new_id.size() < 3){
        while(new_id.size() != 3){
            new_id += new_id[new_id.size()-1];
        }
    }
    
    answer = new_id;
    return answer;
}
