#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time = 0;
    int start = 25;
    
    for(int i = 0;i < musicinfos.size();i++){
        string s = "";
        int runtime = 0;
        int h1 = -1,h2 = -1,m1 = -1,m2 = -1;
        string music = "",ri = "",runri = "";
        for(int j = 0;j < musicinfos[i].size();j++){
            if(musicinfos[i][j] == ':'){
                if(h1 == -1) h1 = stoi(s);
                else if(h2 == -1) h2 = stoi(s);
                s = "";
            }
            else if(musicinfos[i][j] == ','){
                if(m1 == -1) m1 = stoi(s);
                else if(m2 == -1) m2 = stoi(s);
                else if(music == "") music = s;
                s = "";
            }
            else s += musicinfos[i][j];
        }
        
        ri = s;
        runtime = (h2-h1)*60 + (m2-m1);
        
        int num = 0;
        for(int j = 0;j < runtime;j++){
            runri += ri[num];
            if(num == ri.size()-1) num = 0;
            else{
                if(ri[num+1] == '#'){
                    runri += ri[num+1];
                    if(num+1 == ri.size()-1) num = 0;
                    else num += 2;
                }
                else num++;
            }
        }
        
        int it = 0;
        
        while(true){
            if(runri.find(m,it) != string::npos){
                string tmp = m+'#';
                if(runri.find(m,it)+m.size() != runri.size()){
                    if(runri[runri.find(m,it)+m.size()] != '#'){
                        if(time < runtime){
                            time = runtime;
                            answer = music;
                            start = h1;
                            break;
                        }
                        else if(time == runtime){
                            if(start > h1){
                                start = h1;
                                answer = music;
                                break;
                            }
                        }
                    }
                }
                else{
                    if(time < runtime){
                        time = runtime;
                        answer = music;
                        start = h1;
                        break;
                    }
                    else if(time == runtime){
                        if(start > h1){
                            start = h1;
                            answer = music;
                            break;
                        }
                    }
                }
                it = runri.find(m,it) + m.size();
            }
            else break;
        }
    }
    return answer;
}
