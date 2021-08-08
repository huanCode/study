#include "common.h"
//https://leetcode-cn.com/problems/minimum-window-substring/
class Solution_76
{
public:
    string minWindow(string s, string t)
    {
        int map[128] = { 0 };
        //记录字符串t中每个字符的数量
        for (int i = 0; i < t.size(); i++)
            map[t[i]]++;
        //字符串t的数量
        int count = t.length();
        int left = 0;//窗口的左边界
        int right = 0;//窗口的右边界
        //覆盖t的最小长度
        int windowLength = 655536;
        //覆盖字符串t开始的位置
        int strStart = 0;
        while (right < s.length()) {
            int index = s[right++];
            if (map[index]-- > 0)
                count--;
            //如果全部覆盖
            while (count == 0) {
                //如果有更小的窗口就记录更小的窗口
                if (right - left < windowLength) {
                    windowLength = right - left;
                    strStart = left;
                }

                index = s[left++];
                if (map[index]++ == 0)
                    count++;
            }
        }
        //如果找到合适的窗口就截取，否则就返回空
        if (windowLength != 65536)
            return s.substr(strStart, strStart + windowLength);
        return "";
    }
};

