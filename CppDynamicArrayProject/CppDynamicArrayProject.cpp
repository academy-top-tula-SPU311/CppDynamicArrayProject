#include <iostream>

template <typename T>
struct DArray
{
    T* items = nullptr;
    int size = 0;
};

template <typename T>
void DarrayPushBack(DArray<T>& array, T value);
template <typename T>
void DarrayPushFront(DArray<T>& array, T value);
template <typename T>
void DarrayInsert(DArray<T>& array, T value, int index);

template <typename T>
T DarrayPopBack(DArray<T>& array);
template <typename T>
T DarrayPopFront(DArray<T>& array);
template <typename T>
T DarrayRemove(DArray<T>& array, int index);

template <typename T>
void DarrayPrint(DArray<T> array);

int main()
{
    DArray<int> array;
    DarrayPushBack(array, 100);
    DarrayPushBack(array, 200);
    DarrayPushBack(array, 300);
    DarrayPushFront(array, 400);
   
    DarrayPrint(array);

    std::cout << "\n" << DarrayPopBack(array) << "\n";
    std::cout << DarrayPopFront(array) << "\n";

    DarrayPrint(array);
}

template <typename T>
void DarrayPushBack(DArray<T>& array, T value)
{
    T* itemsNew = new T[array.size + 1];
    for (int i{}; i < array.size; i++)
        itemsNew[i] = array.items[i];
    itemsNew[array.size] = value;
    
    if (array.items) delete[] array.items;
    array.items = itemsNew;
    array.size++;
}

template <typename T>
void DarrayPushFront(DArray<T>& array, T value)
{
    T* itemsNew = new T[array.size + 1];
    for (int i{}; i < array.size; i++)
        itemsNew[i + 1] = array.items[i];
    itemsNew[0] = value;

    if (array.items) delete[] array.items;
    array.items = itemsNew;
    array.size++;
}

template <typename T>
T DarrayPopBack(DArray<T>& array)
{
    T value = array.items[array.size - 1];

    T* itemsNew = new T[array.size - 1];
    for (int i{}; i < array.size - 1; i++)
        itemsNew[i] = array.items[i];

    delete[] array.items;
    array.items = itemsNew;
    array.size--;

    return value;
}

template <typename T>
T DarrayPopFront(DArray<T>& array)
{
    T value = array.items[0];

    T* itemsNew = new T[array.size - 1];
    for (int i{}; i < array.size - 1; i++)
        itemsNew[i] = array.items[i + 1];

    delete[] array.items;
    array.items = itemsNew;
    array.size--;

    return value;
}

template <typename T>
void DarrayPrint(DArray<T> array)
{
    for (int i{}; i < array.size; i++)
        std::cout << array.items[i] << " ";
    std::cout << "\n";
}
