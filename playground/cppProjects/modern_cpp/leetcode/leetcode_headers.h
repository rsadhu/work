//
// Created by rsadhu on 01.10.20.
/*
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3*/
//

#ifndef PLAYGROUND_LEETCODE_HEADERS_H
#define PLAYGROUND_LEETCODE_HEADERS_H
#pragma  once
#include <map>
#include <iostream>

using namespace std;

class Test
{
public:
    Test ()
    {
    }
    Test (const Test & rhs)
    {
        std::cout << " copy const\n";
    }

    Test & operator = (const Test &rhs)
    {
        std::cout << " = overloaded\n";
        return *this;
    }
};

class Utility
{
    Test tt;
public:
    Test  get ()
    {
        return tt;
    }
};

void merge(vector<int>& nums1, vector<int>& nums2) {

    for (auto it : nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] <= it) {
                for (int j = nums1.size() - 1; j > i; j--) {
                    nums1[j] = nums1[j - 1];
                }
                nums1[i + 1] = it;
            }
        }
    }
}


int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int cnt = 0;
    for(int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals.size(); j++)
        {
            if (i != j)
            {
                if ( intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    cnt++;
                    break;
                }
            }
        }
    }
    return intervals.size() - cnt;

}


#endif //PLAYGROUND_LEETCODE_HEADERS_H
