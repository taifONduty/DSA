#include <iostream>
#include <queue>

using namespace std;
int josephus_r(int n, int k) {
    // Base case: if there's only one person, they are the one who is freed
    if (n == 1) {
        return 1;
    } else {
        // Recursively find the position in a smaller circle of n-1 people
        // Adjust the position based on k to account for the skipping
        return (josephus_r(n - 1, k) + k - 1) % n + 1;
    }
}

int josephus(int n, int k) {
    queue<int> q;
    
    // Fill the queue with people numbered from 1 to n
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        // Move the first k elements to the end of the queue
        for (int i = 0; i < k -1  ; ++i) {
            q.push(q.front());
            q.pop();
        }
        // Remove the k-th element
        q.pop();
    }
    
    // The last remaining element is the answer
    return q.front();
}

int main() {
    int n = 5; // Number of people
    int k = 3; // Step rate

    cout << "The position of the last person left is " << josephus(n, k) <<endl;
    return 0;
}
