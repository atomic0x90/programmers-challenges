#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    sort(array.begin(),array.end());
    
    int maxCheck = -1, answer = array[0], check = 1;
    
    for(int i = 1;i < array.size();i++){
        if(array[i] == array[i-1]) check++;
        else{
            if(maxCheck < check){
                maxCheck = check;
                answer = array[i-1];
            }
            else if(maxCheck == check) answer = -1;
            
            check = 1;
        }
    }
    if(maxCheck < check) answer = array.back();
    else if(maxCheck == check) answer = -1;
    
    return answer;
}
