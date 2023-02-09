int solution(int i, int j, int k) {
    int answer = 0;
    for(int start = i;start <= j;start++){
        int check = start;
        while(check){
            if(check%10 == k) answer++;
            check /= 10;
        }
    }
    return answer;
}
