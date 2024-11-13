#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <fstream>

using namespace std;

void bubleSort(vector<int>& arr) 
{
    int count = 1;
    while (count != 0) 
    {
        count = 0;
        for (int i = 0; i + 1 < arr.size(); i++) 
        {
            if(arr[i] > arr[i + 1]) 
            {
                int s = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = s;
                count++;
            }
        }
    }
}


void swapSort(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[i] > arr[j]) {
                int s = arr[i];
                arr[i] = arr[j];
                arr[j] = s;
            }
        }
    }
}

vector<int> quickSort(vector<int>& arr)
{
    if(arr.size() == 2)
    {
        if (arr[0] > arr[1])
        {
                int s = arr[0];
                arr[0] = arr[1];
                arr[1] = s;
        }
        return arr;
        
    }
    else if (arr.size() < 2)
        return arr;
    else
    {
        int fixed = arr[round(arr.size() / 2)];
        vector<int> left, right;
        for (int i = 0; i < arr.size(); i++)
        {
            if(i == round(arr.size() / 2))
                continue;
            else if (arr[i] < fixed)
                left.push_back(arr[i]);
            else
                right.push_back(arr[i]);
        }
        left = quickSort(left);
        right = quickSort(right);
        arr.clear();
        arr.insert(arr.end(), left.begin(), left.end());
        arr.push_back(fixed);
        arr.insert(arr.end(), right.begin(), right.end());
        return arr; 
    }
    

}

void shellSort(vector<int>& arr)
{
    int d = round(arr.size() / 2);
    while (d > 0)
    {
        for (int i = 0; i < arr.size() - d; i++)
        {
            if (arr[i] > arr[i + d])
                {
                    int s = arr[i];
                    arr[i] = arr[i + d];
                    arr[i + d] = s;   
                }
            int t = i;
            while (t - d >= 0)
            {
                if (arr[t - d] > arr[t])
                {
                    int s = arr[t];
                    arr[t] = arr[t - d];
                    arr[t - d] = s; 
                    t -= d;
                }
                else
                    break;
            }
        }
        d = round(d / 2);   
    }
}

void mergeSort(vector<int>& arr)
{
    int n = arr.size();
    vector<int> temp(n);

    for (int width = 1; width < n; width *= 2)
    {
        for (int i = 0; i < n; i += 2 * width)
        {
            int left = i;
            int mid = min(i + width, n);
            int right = min(i + 2 * width, n);

            int l = left, r = mid, t = left;

            while (l < mid && r < right)
                temp[t++] = (arr[l] < arr[r]) ? arr[l++] : arr[r++];

            while (l < mid)
                temp[t++] = arr[l++];

            while (r < right)
                temp[t++] = arr[r++];
        }

        arr = temp;
    }
}

void countSort(vector<int>& arr)
{
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
        min = (arr[i] < min) ? arr[i] : min;
    }
    vector<int> countPositive (max + 1, 0), countNegative (fabs(min) + 1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < 0)
            countNegative[fabs(arr[i])]++;
        else
            countPositive[arr[i]]++;
    }
        
    arr.clear();
    for (int i = 0; i < fabs(min) + 1; i++)
    {
        for(int j = 0; j < countNegative[i]; j++)
            arr.push_back(-i);
    }
    for (int i = 0; i < max + 1; i++)
    {
        for(int j = 0; j < countPositive[i]; j++)
            arr.push_back(i);
    }
}

void siftDown(vector<int>& heap, int i, int heapSize)
{
    while (2 * i + 1 < heapSize)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < heapSize && heap[right] > heap[left])
            j = right;
        if (heap[i] >= heap[j])
            break;
        swap(heap[i], heap[j]);
        i = j;
    }
}

void buildHeap(vector<int>& heap)
{
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        siftDown(heap, i, heap.size());
}

void heapSort(vector<int>& arr)
{
    buildHeap(arr);
    int heapSize = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        swap(arr[0], arr[heapSize - 1]);
        heapSize--;
        siftDown(arr, 0, heapSize);
    }
}
int main () 
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    in >> n;
    vector<int> mas(n);

    for (int i = 0; i < n; i++)
        in >> mas[i];

    bubleSort(mas);

    for (int i = 0; i < n; i++)
        out << mas[i] << " ";

    return 0;
}