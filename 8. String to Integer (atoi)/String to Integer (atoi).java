class Solution {
    public int myAtoi(String str) {
        int num = 0;
        int sign = 1;
        int i = 0;
        int n = str.length();
        while(i < n && str.charAt(i) == ' ') i++;
        if(i < n && str.charAt(i) == '+'){
            i++;
        } else if(i < n && str.charAt(i) == '-'){
            sign = -1;
            i++;
        }
        for(; i < n; i++){
            if(str.charAt(i) < '0' || str.charAt(i) > '9') break;
            if(num > Integer.MAX_VALUE / 10 || (num == Integer.MAX_VALUE / 10 && (str.charAt(i) - '0') > Integer.MAX_VALUE % 10)){
                return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            num = num * 10 + (str.charAt(i) - '0');
        }
        return sign * num;
    }
}
