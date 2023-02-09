#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    bool flag = false;
    for(int i = 0;i < str1.size();i++){
        if(str1[i] == str2[0]){
            int k = i;
            flag = true;
            for(int j = 0;j < str2.size();j++){
                if(str1[k] != str2[j] || k > str1.size()){
                    flag = false;
                    break;
                }
                k++;
            }
            if(flag) return 1;
        }
    }
    return 2;
}
