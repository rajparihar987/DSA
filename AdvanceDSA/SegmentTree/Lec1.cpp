/*
1️⃣ What is a Segment Tree?
A Segment Tree is a binary tree data structure used to efficiently answer range queries on an array with updates.

👉 It allows:
Fast range queries
Fast point updates / range updates

Typical problems:
Range sum
Range minimum / maximum
Range GCD
Range XOR
Custom merge operations

2️⃣ Why do we need Segment Tree?
Suppose:
Array size = N
Queries = Q
❌ Naive approach:
Each range query → O(N)
Total → O(N × Q) ❌ (Too slow)
❌ Prefix sum approach:
Query → O(1)
Update → O(N) ❌

✅ Segment Tree:
Query → O(log N)
Update → O(log N)
Best of both worlds 💯
3️⃣ Core Idea (Intuition)
Divide the array into segments
Each node stores the answer for a segment
Parent node = merge(left child, right child)
Example (sum):
arr = [1, 3, 5, 7, 9, 11]
Root → sum of [0..5]
Left child → sum of [0..2]
Right child → sum of [3..5]

4️⃣ When should you think of Segment Tree? (MOST IMPORTANT 🔥)
✅ Observe this pattern → Segment Tree
✔ You have an array
✔ There are multiple queries
✔ Query asks about a range [L, R]
✔ There are updates to array values
✔ Constraints are large (N, Q ≤ 2e5)

Google Interview Trigger Keywords:
"Range queries"
"Update values"
"Dynamic queries"
"Multiple queries on array"
"Min / Max / Sum in range"

5️⃣ DO NOT use Segment Tree when:

❌ Only one query
❌ No updates + offline → use prefix sum
❌ Small constraints (N ≤ 1000)

6️⃣ Types of Segment Tree
Type	Use case
Normal Segment Tree	Point update + range query
Lazy Segment Tree	Range update + range query
Persistent Segment Tree	Previous versions needed
Iterative Segment Tree	Faster, simpler
Merge Sort Tree	Order statistics in range

7️⃣ Time & Space Complexity
⏱ Time Complexity
Operation	Time
Build	O(N)
Range Query	O(log N)
Point Update	O(log N)
Range Update (Lazy)	O(log N)
💾 Space Complexity
O(4 × N) (safe upper bound)

8️⃣ Typical Google Interview Questions

🔹 Range Sum Query
🔹 Range Minimum Query
🔹 Maximum subarray in range
🔹 Count of numbers > K in range
🔹 Hotel Queries (allocate rooms)
🔹 Dynamic frequency queries
🔹 Inversion count with updates
*/


// User function template for C++
// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree

// Function to update a value in input array and segment tree.
void updateSeg(ll* st,int i,int l,int r,int idx,int val){
    if(l==r){
        st[i] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid){
        updateSeg(st,2*i+1,l,mid,idx,val);
    }   
    else{
        updateSeg(st,2*i+2,mid+1,r,idx,val);
    }
    
    st[i] = st[2*i+1] + st[2*i+2];
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) {
    arr[index] = new_val;
    updateSeg(st,0,0,n-1,index,new_val);
}

// Function to return sum of elements in range from index qs (query start)
// to qe (query end).
ll segSum(ll* st,int start,int end,int i,int l,int r){
    if(end < l || start > r) return 0;
    if( l >= start && r <= end) return st[i];
    int mid = (l+r)/2;
    return segSum(st,start,end,2*i+1,l,mid)+segSum(st,start,end,2*i+2,mid+1,r);
}

ll getsum(ll *st, int n, int l, int r) {
    return segSum(st,l,r,0,0,n-1);
}

// segment tree was already build in this question
// This is question for range sum queries...


