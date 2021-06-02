#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[10001],b[10001],c[10001];
    for(int i = 0; i < 10001;i++){
        if((i+1)%5 == 1) a[i] = 1;
        else if((i+1)%5 == 2) a[i] = 2;
        else if((i+1)%5 == 3) a[i] = 3;
        else if((i+1)%5 == 4) a[i] = 4;
        else if((i+1)%5 == 0) a[i] = 5;
        
        if((i+1)%8 == 1) b[i] = 2;
        else if((i+1)%8 == 2) b[i] = 1;
        else if((i+1)%8 == 3) b[i] = 2;
        else if((i+1)%8 == 4) b[i] = 3;
        else if((i+1)%8 == 5) b[i] = 2;
        else if((i+1)%8 == 6) b[i] = 4;
        else if((i+1)%8 == 7) b[i] = 2;
        else if((i+1)%8 == 0) b[i] = 5;
        
        if((i%10)/ 2 == 0) c[i] = 3;
        else if((i%10)/ 2 == 1) c[i] = 1;
        else if((i%10)/ 2 == 2) c[i] = 2;
        else if((i%10)/ 2 == 3) c[i] = 4;
        else if((i%10)/ 2 == 4) c[i] = 5;
    }
    
    int checka = 0,checkb = 0,checkc = 0;
    for(int i = 0;i < answers.size();i++){
        if(answers[i] == a[i]) checka++;
        if(answers[i] == b[i]) checkb++;
        if(answers[i] == c[i]) checkc++;
    }
    
    if(checka > checkb && checka > checkc)
        answer.push_back(1);
    else if(checkb > checka && checkb > checkc)
        answer.push_back(2);
    else if(checkc > checka && checkc > checkb)
        answer.push_back(3);
    else if(checka == checkb && checka > checkc){
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(checka == checkc && checka > checkb){
        answer.push_back(1);
        answer.push_back(3);
    }
    else if(checkb == checkc && checkb > checka){
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(checka == checkb && checkb == checkc){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    return answer;
}
