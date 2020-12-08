#ifndef MCS_HPP
#define MCS_HPP

#include <iostream>

// Notes for MyCodeSchool Videos

namespace MCS
{
	struct Node
	{
		int data;
		Node *next;
	};


	void insert(Node **pointerToHead, int num) // double pointer because of passing pointer by reference
	{
		Node *temp = new Node();		// greates new Node pointer and points it at newly greated Node object
		temp->data = num; 				// allocates new Node with data
		temp->next = *pointerToHead;	// allocatest the new node's next to point the old Node.
		*pointerToHead = temp;			// makes the previous Node to point to the new making temp the first.
	}

	void print(Node *head)
	{
		while(head != NULL)
		{
			std::cout << head->data;
			head = head->next;			// modifying head->next to point the next Node of the current Node
		}
	}

	void testLinkedList()
	{
		Node *head = NULL;
		int ii;
		std::cin >> ii;
		for(int i = 0; i < ii; ++i)
		{
			int num;
			std::cin >> num;
			insert(&head, num);							// passing head by reference to the insert function
			print(head);
		}
	}
	// dynamical memory allocation using m(emory)alloc c(ontinuous)alloc realloc(-ation) and free
	// c++ equivalents are new, delete and delete[]
	void DynamicMemInC()
	{
		int *x{(int*)malloc(sizeof(int))}; 				// using c style dynamic memory allocation
		*x = 300;
		int *x2{(int*)calloc(3, sizeof(int))};			// calloc allocates to 0 and uses 2 args (amount, size)
		int *b{(int*)realloc(x, sizeof(int))};			// reallocates with contents from first arg
		std::cout << "dynamically allocated memory: " 
			<< *x << " Realloc: " << *b << std::endl;
		free(x); 										//freeing memory in c(equiv to c++ delete)
		free(x2);
	}
	int *add(int *a, int *b)
	{
		// int *c{new int};					// c++ style dynamic allocation
		int *c{(int*)malloc(sizeof(int))}; 	//allocate int pointer with heap int value address with c style
		*c = (*a) + (*b);					//allocate that address with value from a and b pointers
		return c;							//return heap address created by malloc
		//int c = (*a) + (*b);
		//return &c;				// do not return local variables by address, because of stack it will be over
								// written by next call made by the program (local variables are stored in stack instead of heap)
	}
	void PointersAsFuncReturns()
	{
		int a = 2, b = 4;
		int *ptr = add(&a, &b);
		std::cout << *ptr << std::endl;
	}
	int addFP(int a, int b)
	{
		return a + b;
	}
	void FuncPointers()
	{
		int c;
		int (*p)(int, int);					//declaring function pointer to a function with two args
		p = &addFP;							//allocating the function pointer with function address
		// p = addFP; does the same thing
		c = (*p)(10, 20);					//allocating c with the result of a function accessed through funcP
		// c = p(10, 20); does the same thing
		std::cout << "function pointer returns: " << c << std::endl;
	}
	int compare(int a, int b)
	{
		if(a > b) return 1;									// standard check if element b is bigger than element a
		else return -1;
	}
	void BubbleSort(int *A, int n, int (*compare)(int, int)) // takes two int and a function as an argument
	{
		int temp;
		for(int i{0}; i < n; ++i)							// iterates through array once per item
		{
			for(int j{0}; j < n; ++j)						// iterates every iteration through every item
			{
				if(compare(A[j], A[j+1]) > 0)				// uses the function pointer to return if element is
				{											// element A[j] is bigger than the next one and returns 1 or -1
					temp = A[j];							// standard bubblesort stuff which gets executed only if
					A[j] = A[j+1];							// compare returns bigger than zero
					A[j+1] = temp;
				}
			}
		}
	}
	void FuncPointNCallBacks()
	{
		int A[]{3, 1, 2, 3, 4, 5, 6};
		BubbleSort(A, 6, compare);							// feeding the bubblesort function the compare func as an arg
		for(int i{0}; i < 6; ++i) std::cout << A[i];		// when using only function name it returns the address(kinda)
	}
}
#endif