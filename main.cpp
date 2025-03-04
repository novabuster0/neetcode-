#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // first is the variable second is the longest
        pair<int, int> counter;
        vector<int> longest;
        map<int, int> sorted_map;
        for (int num : nums)
        {
            sorted_map[num] = num;
        }
        for (pair<int, int> row : sorted_map)
        {
            // if the vector(longest) is empty
            if (longest.empty())
            {
                longest.push_back(row.second);
                counter.first = longest.size();
                continue;
            }
            // else(not empty) and next elemant in the map(sorted_map) is greater than last elemant in vector(longest) by 1
            if (row.second - longest.back() == 1)
            {
                longest.push_back(row.second);
                counter.first = longest.size();
                continue;
            }
            // else (not empty) and next elemant in the map(sorted_map) isnt greater than last elemant in vector(longest) by 1
            longest.clear();
            longest.push_back(row.second);
            counter.second = counter.first > counter.second ? counter.first : counter.second;
            counter.first = longest.size();
        }
        counter.second = counter.first > counter.second ? counter.first : counter.second;
        // cout << counter.first << endl
        //      << counter.second << endl;
        return counter.second;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
