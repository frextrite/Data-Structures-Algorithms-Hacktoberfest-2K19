 
#include <bits/stdc++.h> 


{ 
	for (auto it = vec.begin(); it != vec.end(); it++) 
	{		 
		
		auto const insertion_point = 
				std::upper_bound(vec.begin(), it, *it); 
		
		
		std::rotate(insertion_point, it, it+1);		 
	} 
} 

void print(std::vector<int> vec) 
{ 
	for( int x : vec) 
		std::cout << x << " "; 
	std::cout << '\n'; 
} 


int main() 
{ 
	std::vector<int> arr = {2, 1, 5, 3, 7, 5, 4, 6};	 
	insertionSort(arr);	 
	print(arr); 
} 

