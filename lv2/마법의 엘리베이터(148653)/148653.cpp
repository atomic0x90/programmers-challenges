int solution(int storey) {
    int answer = 0;
    
    while(storey >= 10){
        if(storey%10 > 5){
            answer += 10-(storey%10);
            storey = (storey/10)+1;
        }
        else if(storey%10 < 5){
            answer += storey%10;
            storey = storey/10;
        }
        else{
            int tmp = storey/10;
            
            while(tmp%10 == 5 && tmp >= 10) tmp /= 10;
    
            if(tmp%10 >= 5){
                answer += 10-(storey%10);
                storey = (storey/10)+1;
            }
            else if(tmp%10 < 5){
                answer += storey%10;
                storey = storey/10;
            }
        }
    }
    
    answer += storey <= 5 ? storey : 10 - storey + 1;
    
    return answer;
}
