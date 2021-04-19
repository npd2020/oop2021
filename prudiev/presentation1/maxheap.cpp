#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int>& hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest]) 
        largest = l;                     
    if (r < size && hT[r] > hT[largest]) 
        largest = r;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void insertEle(vector<int>& hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}
void deleteEle(vector<int>& hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}
void showHeap(vector<int>& hT)
{   
    for (int i = 0; i < hT.size(); ++i)
    {
        cout << hT[i] << " ";
        if (i == 0) cout << "\n";
        if (i % 2 == 0 && (i/2)%2 != 0) cout << "\n";
    }
    cout << "\n";
}

void replaceEle(vector<int>& hT, int numToReplace, int replacement)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (numToReplace == hT[i])
            break;
    }

    hT[i] = replacement;

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

int main()
{
    vector<int> heapTree;

    insertEle(heapTree, 3);
    insertEle(heapTree, 4);
    insertEle(heapTree, 9);
    insertEle(heapTree, 5);
    insertEle(heapTree, 6);
    insertEle(heapTree, 7);
    insertEle(heapTree, 10);


    cout << "Max-Heap: \n";
    showHeap(heapTree);

    deleteEle(heapTree, 6);
    cout << "Deleted 6: \n";
    showHeap(heapTree);

    replaceEle(heapTree, 10, 1);
    cout << "Replaced 10 with 1: \n";
    showHeap(heapTree);

}