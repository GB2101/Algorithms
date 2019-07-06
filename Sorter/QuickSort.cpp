#include <bits/stdc++.h>

using namespace std;

void change (vector<int> &array, int x, int y){
    int t = array[x];
    array[x] = array[y];
    array[y] = t;
}

int lomuto (vector<int> &array, int l, int r){
    int p = array[l];
    int i = l + 1, s = l;
    while (i <= r){
        if (array[i] < p){
            s++;
            change(array, s, i);
        }
        i++;
    }
    change(array, l, s);
    return s;
}

int hoare (vector<int> &array, int l, int r){
    int p = array[l];
    int i = l, j = r;
    while (i < j){
        while (i <= r && array[i] <= p){
            i++;
        }
        while (array[j] > p){
            j--;
        }
        change(array, i, j);
    }
    change(array, i, j);
    change(array, l, j);
    return j;
}

void quick_sort (vector<int> &array, int l, int r){
    if (l == r || r < l){
        return;
    }
    int k = hoare(array, l, r);
    quick_sort(array, l, k - 1);
    quick_sort(array, k + 1, r);
}

void QuickSort (vector<int> &array){
    int s = array.size() - 1;
    quick_sort(array, 0, s);
}

void display (vector<int> array){
    int s = array.size();
    for (int i = 0; i < s; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        array.push_back(k);
    }
    QuickSort(array);
    display(array);
}