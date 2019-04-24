class Solution {
    private static final Map<Character, Integer> maps = new HashMap<>();
    static{
        maps.put('I', 1);
        maps.put('V', 5);
        maps.put('X', 10);
        maps.put('L', 50);
        maps.put('C', 100);
        maps.put('D', 500);
        maps.put('M', 1000);
    }
    public int romanToInt(String s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(i == 0 || maps.get(s.charAt(i)) <= maps.get(s.charAt(i - 1))) res += maps.get(s.charAt(i));
            else res += (maps.get(s.charAt(i)) - 2 * maps.get(s.charAt(i - 1)));
        }
        return res;
    }
}
