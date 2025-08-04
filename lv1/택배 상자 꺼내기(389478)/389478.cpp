#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    
    int layer = num%w == 0 ? (num/w) : (num/w) + 1;
    
    bool flag = layer%2 == 0 ? true : false;
    
    int left_gap = 0;
    int right_gap = 0;
    
    int tmp = num;
    while(tmp%w != 0)
    {
        tmp++;
        left_gap++;
    }
    
    right_gap = w - left_gap - 1;
    
    if(flag == false) swap(left_gap, right_gap);
    
    int take_out_num = num;
    
    while(true)
    {
        if(flag == true)
        {
            take_out_num += left_gap*2 + 1;
            flag = false;
            if(take_out_num > n) break;
        }
        else if(flag == false)
        {
            take_out_num += right_gap*2 + 1;
            flag = true;
            if(take_out_num > n) break;
        }
        answer++;
    }
    
    return answer;
}
