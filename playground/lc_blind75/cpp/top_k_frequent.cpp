#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    // Step 1: Count the frequency of each element
    std::unordered_map<int, int> freqMap;
    for (int num : nums)
    {
        freqMap[num]++;
    }

    // Step 2: Define a lambda function for comparing elements in the priority queue
    auto compare = [&](const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return a.second > b.second; // min-heap based on frequency
    };

    // Step 3: Create a min-heap to store the k most frequent elements
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> minHeap(compare);

    // Step 4: Add elements to the min-heap, maintaining the size k
    for (const auto &entry : freqMap)
    {
        minHeap.push(entry);
        if (minHeap.size() > k)
        {
            minHeap.pop(); // Remove the least frequent element if heap size exceeds k
        }
    }

    // Step 5: Extract elements from the min-heap
    std::vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    // Step 6: Reverse the result to get the most frequent elements first
    std::reverse(result.begin(), result.end());

    return result;
}

int main()
{
    std::vector<int> nums = {
        1,
        1,
        1,
        2,
        2,
        3,
        3,
        3,
        3,
    };
    int k = 2;

    std::vector<int> result = topKFrequent(nums, k);

    std::cout << "The " << k << " most frequent elements are: ";
    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
