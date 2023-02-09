#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int result = 9999;
    sort(array.begin(),array.end());
    for(int i = 0;i < array.size();i++){
        if(abs(array[i]-n) < abs(result)){
            answer = array[i];
            result = abs(array[i]-n);
        }
    }
    return answer;
}
