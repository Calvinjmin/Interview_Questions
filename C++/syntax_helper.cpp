/*
    Basic Data Structures
*/

using namespace std;

// ----- Vectors and Matrices ----- //
#include <vector>

vector<int> basic_arr;
vector<vector<int>> twoD_arr;

int size = 1;
int value = 0;
vector<int> init_arr(size, value);

// ----- HEAPS ----- //
#include <queue>

// Min Heap
priority_queue<int, vector<int>, greater<int>> min_heap;

// Max Heap
priority_queue<int, vector<int>, less<int>> max_heap;

// ----- Maps ----- //
#include <unordered_map>

unordered_map<int, string> dictionary;
dictionary[1] = "Testing"
