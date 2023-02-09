int solution(int n) {
    int num = 0;
    for(int i = 1;;i++){
        if(i % 3 != 0){
            bool flag = true;
            int tmp = i;
            while(tmp){
                if(tmp%10 != 3) tmp /= 10;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) num++;
        }
        
        if(num == n) return i;
    }
}
