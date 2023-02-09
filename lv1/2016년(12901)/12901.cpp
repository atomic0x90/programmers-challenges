#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector <int> month;
    int check = 0;
    
    month.push_back(31);
    month.push_back(29);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(30);
    
    for(int i = 0;i < a-1;i++)
        check += month[i];
    
    check += b-1; //1.1과 차이를 구하기 위해 -1
    
    if(check % 7 == 0) answer = "FRI";
    else if(check % 7 == 1) answer = "SAT";
    else if(check % 7 == 2) answer = "SUN";
    else if(check % 7 == 3) answer = "MON";
    else if(check % 7 == 4) answer = "TUE";
    else if(check % 7 == 5) answer = "WED";
    else if(check % 7 == 6) answer = "THU";
        
    return answer;
}
