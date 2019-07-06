#include <bits/stdc++.h>

using namespace std;

void merge (vector<int> &array, int l, int m, int r){
    vector<int> temp;
    int i = l, j = m + 1, s = 0;
    while (i <= m && j <= r){
        if (array[i] <= array[j]){
            temp.push_back(array[i]);
            i++;
        }else {
            temp.push_back(array[j]);
            j++;
        }
        s++;
    }
    while (i <= m){
        temp.push_back(array[i]);
        i++;
        s++;
    }
    while (j <= r){
        temp.push_back(array[j]);
        j++;
        s++;
    }
    s = 0;
    for (int x = l; x <= r; x++){
        array[x] = temp[s];
        s++;
    }
}

void merge_sort (vector<int> &array, int l, int r){
    if (l == r){
        return;
    }
    int k = floor((r - l) / 2);
    merge_sort(array, l, l + k);
    merge_sort(array, l + k + 1, r);
    merge(array, l, l + k, r);
}

void MergeSort (vector<int> &array){
    int s = array.size() - 1;
    merge_sort(array, 0, s);
}

void display (vector<int> &array){
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    MergeSort(array);
    display(array);
}
