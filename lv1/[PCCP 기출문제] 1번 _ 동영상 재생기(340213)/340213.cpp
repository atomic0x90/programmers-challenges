#include <string>
#include <vector>
using namespace std;

int timeToInt(string s)
{
    int m1,m2,s1,s2;
    m1 = (s[0]-'0')*10*60;
    m2 = (s[1]-'0')*60;
    s1 = (s[3]-'0')*10;
    s2 = s[4]-'0';
    return m1+m2+s1+s2;
}

bool checkOpen(int a, int b, int c)
{
    if(a >= b && a <= c) return true;
    else return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int nVideo_len, nPos, nOp_start, nOp_end;
    int now;
    nVideo_len = timeToInt(video_len);
    nPos = timeToInt(pos);
    nOp_start = timeToInt(op_start);
    nOp_end = timeToInt(op_end);

    now = nPos;
        
    if(checkOpen(now, nOp_start, nOp_end)) now = nOp_end;

    for(int i = 0;i < commands.size();i++)
    {
        if(commands[i] == "next")
        {
            now += 10;
            if(now > nVideo_len) now = nVideo_len;
            if(checkOpen(now, nOp_start, nOp_end)) now = nOp_end;
        }
        else if(commands[i] == "prev"){
            now -= 10;
            if(now < 0) now = 0;
            if(checkOpen(now, nOp_start, nOp_end)) now = nOp_end;
        }
    }
    
    answer = to_string(now%60);
    if(answer.length() == 1) answer = "0" + answer;
    answer = to_string(now/60) + ":" + answer;
    if(answer.length() == 4) answer = "0" + answer;
    
    return answer;
}
