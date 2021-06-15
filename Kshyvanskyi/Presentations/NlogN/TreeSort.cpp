#include<bits/stdc++.h>
 
using namespace std;
 
struct Node
{
    int key;
    struct Node *left, *right;
};
 
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
 
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
 
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
    int i = 0;
    storeSorted(root, arr, i);
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main()
{
    int arr[] = {23, 7, 15, 37, 50, 43 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array : ";
    printArray(arr, n);
    treeSort(arr, n);
    cout << "  Sorted array : ";
    printArray(arr, n);
    cout<<"\n";
    return 0;
}
