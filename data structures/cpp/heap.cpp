

//C++ program Heap Implementation (Max-Heap)

#include<iostream>
#include<vector>

using namespace std;

//Swap position of two numbers with eachother
void swapNode(int *firstNumber, int *secondNumber){

	int  temporaryNumber = *secondNumber;
	*secondNumber = *firstNumber;
	*firstNumber = temporaryNumber;

}

//Performs heap operations to make largest number at root(top) position
void heapify( vector<int> &heapArray, int maxNumberIndex){

	int heapSize = heapArray.size();  //Size of heap
	int rootIndex = maxNumberIndex;  //Index of parent node
	int leftIndex = 2 * rootIndex + 1;  //Index of left node
	int rightIndex = 2* rootIndex + 2;  //Index of right node


	//If number at left node is greater than parent node
	//Change root index to index of left node
	if(leftIndex < heapSize && heapArray[leftIndex] > heapArray[rootIndex]){
		rootIndex = leftIndex;	
	}


	//If number at right node is greater than parent node
	//Change root index to index of right node
	if( rightIndex < heapSize && heapArray[rightIndex] > heapArray[rootIndex]){
		rootIndex = rightIndex;
	}


	//If root index is not same as number index
	//Swap numbers and perform heapify
	if( rootIndex != maxNumberIndex){

		swapNode( &heapArray[maxNumberIndex], &heapArray[rootIndex] );
		heapify( heapArray, rootIndex);

	}
}


//Insert new node in heap array
void insertNode( vector<int> &heapArray, int newNumber ){
	
	int heapSize = heapArray.size();  //Size of heap

	//If no element in heap
	if(heapSize == 0){

		heapArray.push_back(newNumber);
	}

	else{

		heapArray.push_back(newNumber);  //Insert new node

		//Perform heapify
		for(int i= heapSize/2 -1; i>=0; i--){

			heapify(heapArray, i);

		}
	}
}

//Delete node from heap array
void deleteNode(vector<int> &heapArray, int removeNumber){
	
	int heapSize = heapArray.size();  //Size of heap
	int nodeIndex;

	//Find index node to be removed
	for(int i=0; i<heapSize; i++){

		if(removeNumber == heapArray[i]){
		
			nodeIndex = i;
			break;
		}
	}

	//Swap removing node with last node
	swapNode(&heapArray[nodeIndex], &heapArray[heapSize-1]);

	heapArray.pop_back();  //remove the node from last

	//Performs heapify
	for(int i = (heapSize/2) - 1; i>=0; i--){

		heapify(heapArray, i);
	}
}


//Print heap array
void displayHeap(vector<int> &heapArray){

	//Visit each node in heap
	for(int i=0; i<heapArray.size(); i++){

		cout<<heapArray[i]<<" ";
	}

	cout<<"\n";
}

int main(){

	vector<int> heapTree;  //Stores heap array

	int newNumber;
	char response;

	x:
		cout<<"\nEnter a number to insert: ";
		cin>>newNumber;

		insertNode(heapTree, newNumber);  //Perform insertion

		cout<<"Want to insert more number (press 'Y' or 'N'): ";
		cin>>response;

		//Send controls to x: if user want to insert more number
		if(response == 'Y' || response == 'y'){

			goto x;
		}

	//Display heap after insertion
	cout<<"\nMax-Heap Array is:";
	displayHeap(heapTree);

	y:
		cout<<"\nEnter a number to delete: ";
		cin>>newNumber;

		deleteNode(heapTree, newNumber);  //Perform deletion

		cout<<"Want to delete more number (press 'Y' or 'N'): ";
		cin>>response;

		//Send controls to y: if user want to delete more number
		if(response == 'Y' || response == 'y'){
			goto y;
		}

	//Display heap after deletion
	cout<<"\nMax-Heap Array is:";
	displayHeap(heapTree);

}