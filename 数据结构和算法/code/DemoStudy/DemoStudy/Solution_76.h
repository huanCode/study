#include "common.h"
//https://leetcode-cn.com/problems/minimum-window-substring/
class Solution_76
{
public:
    string minWindow(string s, string t)
    {
        int map[128] = { 0 };
        //��¼�ַ���t��ÿ���ַ�������
        for (int i = 0; i < t.size(); i++)
            map[t[i]]++;
        //�ַ���t������
        int count = t.length();
        int left = 0;//���ڵ���߽�
        int right = 0;//���ڵ��ұ߽�
        //����t����С����
        int windowLength = 655536;
        //�����ַ���t��ʼ��λ��
        int strStart = 0;
        while (right < s.length()) {
            int index = s[right++];
            if (map[index]-- > 0)
                count--;
            //���ȫ������
            while (count == 0) {
                //����и�С�Ĵ��ھͼ�¼��С�Ĵ���
                if (right - left < windowLength) {
                    windowLength = right - left;
                    strStart = left;
                }

                index = s[left++];
                if (map[index]++ == 0)
                    count++;
            }
        }
        //����ҵ����ʵĴ��ھͽ�ȡ������ͷ��ؿ�
        if (windowLength != 65536)
            return s.substr(strStart, strStart + windowLength);
        return "";
    }
};

