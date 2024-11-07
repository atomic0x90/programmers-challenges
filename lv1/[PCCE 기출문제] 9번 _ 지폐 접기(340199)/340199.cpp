#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int wallet_min;
    int wallet_max;
    int bill_min = (bill[0] > bill[1] ? bill[1] : bill[0]);
    int bill_max = (bill[0] > bill[1] ? bill[0] : bill[1]);
    
    if(wallet[0] > wallet[1])
    {
        wallet_min = wallet[1];
        wallet_max = wallet[0];
    }
    else
    {
        wallet_min = wallet[0];
        wallet_max = wallet[1];
    }
    
    while(true)
    {
        if(bill_max < bill_min) swap(bill_max,bill_min);
        
        if(bill_min <= wallet_min && bill_max <= wallet_max) break;
        
        bill_max /= 2;
        answer++;
    }
    
    return answer;
}
