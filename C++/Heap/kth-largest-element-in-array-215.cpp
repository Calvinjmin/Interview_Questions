// Min Heap O(n) Loop - [Leetcode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
  // Min Heap
  priority_queue<int, vector<int>, greater<int>> pq;

  // Feeds Elements into the Priority Queue
  for (auto n : nums) {
    pq.push(n);

    // Pop element from the Heap if the size is greater than k
    if (pq.size() > k) {
      pq.pop();
    }
  }
  return pq.top();
}