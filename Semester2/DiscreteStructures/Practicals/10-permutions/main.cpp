#include <iostream>
using namespace std;

void printArray(int *ar, int v)
{
    cout << " {";
    for (int i = 0; i < v; i++)
    {
        if (i == 0)
            cout << ar[i];
        else
            cout << "," << ar[i];
        ;
    }
    cout << "}";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int n, int curr_i, int *permut_arr, int permut_i)
{
    if (curr_i >= n)
    {
        printArray(permut_arr, permut_i);
    }
    for (int i = curr_i; i < n; i++)
    {
        swap(arr[curr_i], arr[i]);
        permut_arr[permut_i] = arr[curr_i];
        permutation(arr, n, curr_i + 1, permut_arr, permut_i + 1);
        swap(arr[curr_i], arr[i]);
    }
}

int main()
{
    int *arr, pArr[100];
    int size;

    cout << endl
         << endl
         << "Enter the no. of digits : ";
    cin >> size;

    cout << endl
         << "Enter the digits : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "--> Given set of digits :";
    printArray(arr, size);
    cout << endl
         << endl
         << "--> All possible permutations of digits :";
    permutation(arr, size, 0, pArr, 0);
    cout << endl
         << endl;

    return 0;
}

------------------------------------------------------------
    ---------------------------------------------------------

#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void generatePermutations(int* nums, bool* used, int* perm, int size, int index, bool allowRepetition) {
    if (index == size) {
        for (int i = 0; i < size; i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        if (!allowRepetition && i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        if (!used[i]) {
            used[i] = true;
            perm[index] = nums[i];
            generatePermutations(nums, used, perm, size, index + 1, allowRepetition);
            used[i] = false;
        }
    }
}

void permute(int* nums, int size, bool allowRepetition) {
    bool* used = new bool[size];
    int* perm = new int[size];

    for (int i = 0; i < size; i++)
        used[i] = false;

    generatePermutations(nums, used, perm, size, 0, allowRepetition);

    delete[] used;
    delete[] perm;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* nums = new int[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    bool allowRepetition;
    cout << "Allow repetition? (1 for yes, 0 for no): ";
    cin >> allowRepetition;

    permute(nums, size, allowRepetition);

    delete[] nums;

    return 0;
}
