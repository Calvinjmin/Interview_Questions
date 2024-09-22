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
vector<vector<int>> init_2d(size, vector<int>(size, value) );

// ----- HEAPS ----- //
#include <queue>

// Min Heap
priority_queue<int, vector<int>, greater<int>> min_heap;

// Max Heap
priority_queue<int, vector<int>, less<int>> max_heap;

// Basic Functions
min_heap.push(1);
min_heap.pop();
min_heap.top();

// ----- Maps ----- //
#include <unordered_map>

unordered_map<int, string> dictionary;
dictionary[1] = "Testing"

// See if value is in a map
if ( dictionary.find(1) != dictionary.end() ) 

// ----- Set ----- //
#include <unordered_set>
#include <set>

set<int> test_set;

int value = 0;
test_set.insert(value);
test_set.erase(value);

if ( test_set.find( value ) != test_set.end() )