#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> v = {'A','C','F','J','M','N','R','T'};
    vector<string> per;
    do{
        string s = "";
        for(int i = 0;i < v.size();i++)
            s += v[i];
        per.push_back(s);
    }while(next_permutation(v.begin(),v.end()));
    
    int A,C,F,J,M,N,R,T;
    int i1,i2,i3,gap,flag;
    for(int i = 0;i < per.size();i++){
        flag = 0;
        A = per[i].find('A');
        C = per[i].find('C');
        F = per[i].find('F');
        J = per[i].find('J');
        M = per[i].find('M');
        N = per[i].find('N');
        R = per[i].find('R');
        T = per[i].find('T');
        
        for(int j = 0;j < data.size();j++){
            if(data[j][0] == 'A') i1 = A;
            else if(data[j][0] == 'C') i1 = C;
            else if(data[j][0] == 'F') i1 = F;
            else if(data[j][0] == 'J') i1 = J;
            else if(data[j][0] == 'M') i1 = M;
            else if(data[j][0] == 'N') i1 = N;
            else if(data[j][0] == 'R') i1 = R;
            else if(data[j][0] == 'T') i1 = T;
            
            if(data[j][2] == 'A') i2 = A;
            else if(data[j][2] == 'C') i2 = C;
            else if(data[j][2] == 'F') i2 = F;
            else if(data[j][2] == 'J') i2 = J;
            else if(data[j][2] == 'M') i2 = M;
            else if(data[j][2] == 'N') i2 = N;
            else if(data[j][2] == 'R') i2 = R;
            else if(data[j][2] == 'T') i2 = T;
            
            i3 = data[j][4] -'0';
            gap = abs(i1-i2)-1;
            if(data[j][3] == '='){
                if(gap != i3){
                    flag++;
                    break;
                }
            }
            else if(data[j][3] == '>'){
                if(!(gap > i3)){
                    flag++;
                    break;
                }
            }
            else if(data[j][3] == '<'){
                if(!(gap < i3)){
                    flag++;
                    break;
                }
            }
        }
        if(flag == 0) answer++;
    }
    return answer;
}
