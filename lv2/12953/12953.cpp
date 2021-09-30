#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end(),greater<int>());
    int answer = arr[0];
    
    for(int i = 1;i < arr.size();i++){
        if(answer%arr[i] == 0) continue;
        int high = answer;
        int low = arr[i];
        int r;
        while(low != 0){
            r = high%low;
            high = low;
            low = r;
        }
        answer = (answer*arr[i])/high;
    }
    return answer;
}
