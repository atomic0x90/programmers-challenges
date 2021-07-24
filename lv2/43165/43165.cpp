#include <string>
#include <vector>

using namespace std;

int check = 0;

void dfs(vector<int> num,int target,int index,int sum){
    if(index == num.size()){
        if(target == sum) check++;
        return;
    }
    dfs(num,target,index+1,sum + num[index]);
    dfs(num,target,index+1,sum - num[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return check;
}
