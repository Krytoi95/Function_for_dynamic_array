#include <iostream>

void Fill_array(int* const arr,const int size);
void Show_array(int* const arr, const int size);
void Copy_array(int* const arr1,int*const arr2,const int size);
void Add_element_in_end_array(int *&arr,int &size,int value);
void Delete_element_in_end_array(int*& arr, int& size);
void Add_element_in_begin_array(int*& arr, int& size, const int value);
void Delete_element_in_begin_array(int*& arr, int& size);
void Add_element_any_in_array(int*& arr, int& size, const int place, const int value);
void Delete_element_any_in_array(int*& arr, int& size, const int place);
int main()
{
    int size{ 10 };
    int* Dynamic_array{ new int[size] };
	int* Dynamic_array2{ new int[size] };
	Fill_array(Dynamic_array, size);
	Show_array(Dynamic_array, size);
	Fill_array(Dynamic_array2, size);
	Show_array(Dynamic_array2, size);
	Delete_element_any_in_array(Dynamic_array, size, 7);
	Show_array(Dynamic_array, size);
	delete[] Dynamic_array; 	delete[] Dynamic_array2;
	Dynamic_array = nullptr; 	Dynamic_array2 = nullptr;
	return 0;
}


void Fill_array(int* const arr, const int size) 
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void Show_array(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";

	}
	std::cout << std::endl;
}
void Copy_array(int* const arr1, int* const arr2, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr2[i];
	}
}
void Add_element_in_end_array(int*& arr, int& size, const int value)
{
	int* buffer{ new int[size + 1] };
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[size] = value;
	size++;
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}
void Delete_element_in_end_array(int*& arr, int& size)
{
	size--;
	int* buffer{ new int[size] };
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}
void Add_element_in_begin_array(int*&arr,int&size,const int value) 
{
	int* buffer{ new int[size + 1] };
	buffer[0] = value;
	for (int i = 0; i < size; i++)
	{
		buffer[i+1] = arr[i];
	}
	size++;
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}
void Delete_element_in_begin_array(int*& arr, int& size) 
{
	size--;
	int* buffer{ new int[size] };
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}
void Add_element_any_in_array(int*& arr, int& size,const int place, const int value)
{
	int* buffer{ new int[size+1] };
	for (int i = 0; i < place; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[place] = value;
	size++;
	for (int i = place+1; i < size; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}
void Delete_element_any_in_array(int*& arr, int& size,const int place)
{
	size--;
	int* buffer{ new int[size] };
	for (int i = 0; i < place; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = place+1; i < size+1; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}


void Rewrite_element_end_array() {}
void Rewrite_element_begin_array(){}
void Rewrite_element_any_array(){}
