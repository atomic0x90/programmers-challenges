#include <string>

using namespace std;

string solution(string my_string) {
    for(int i = 0;i < my_string.size();i++){
        if(my_string[i] >= 'a') my_string[i] -= 32;
        else my_string[i] += 32;
    }
    return my_string;
}
