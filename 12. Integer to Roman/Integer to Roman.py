class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        radix= [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbol = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        roman = ""
        n = len(radix)
        for i in range(n):
            while num >= radix[i]:
                num -= radix[i]
                roman += symbol[i]
            
        
        return roman
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        v1 = ["", "M", "MM", "MMM"]
        v2 = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        v3 = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        v4 = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10]    
        
