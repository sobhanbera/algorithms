// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of Trie
class node {
public:
	node* left;
	node* right;
};

// Function to insert binary
// representation of element x
// in the Trie
void insert(int x, node* head)
{
	// Store the head
	node* curr = head;

	for (int i = 30; i >= 0; i--) {

		// Find the i-th bit
		int val = (x >> i) & 1;

		if (val == 0) {

			// If curr->left is NULL
			if (!curr->left)
				curr->left = new node();

			// Update curr to curr->left
			curr = curr->left;
		}
		else {

			// If curr->right is NULL
			if (!curr->right)
				curr->right = new node();

			// Update curr to curr->right
			curr = curr->right;
		}
	}
}

// Function that finds the maximum
// Bitwise XOR value for all such pairs
int findMaximumXOR(int arr[], int n)
{
	// head Node of Trie
	node* head = new node();

	// Insert each element in trie
	for (int i = 0; i < n; i++) {
		insert(arr[i], head);
	}

	// Stores the maximum XOR value
	int ans = 0;

	// Traverse the given array
	for (int i = 0; i < n; i++) {

		// Stores the XOR with current
		// value arr[i]
		int curr_xor = 0;

		int M = pow(2, 30);

		node* curr = head;

		for (int j = 30; j >= 0; j--) {

			// Finding ith bit
			int val = (arr[i] >> j) & 1;

			// Check if the bit is 0
			if (val == 0) {

				// If right node exists
				if (curr->right) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->right;
				}

				else {
					curr = curr->left;
				}
			}

			else {

				// Check if left node exists
				if (curr->left) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}

			// Update M to M/2 for next set bit
			M /= 2;
		}

		// Update the maximum XOR
		ans = max(ans, curr_xor);
	}

	// Return the maximum XOR found
	return ans;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 1, 2, 3, 4 };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << findMaximumXOR(arr, N);

	return 0;
}
