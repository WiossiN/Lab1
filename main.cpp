#include <iostream>
#include <chrono>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <clocale>
using namespace std;

void bubble(int *arr, long size) {
    int x;
    for(int i=0; i < size; i++) {
        for(int j = size-1; j > i; j-- ) {
            if ( arr[j-1] > arr[j] ) {
                x=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=x;
            }
        }
    }
}

void cocktail(int *arr, int size){
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        if (arr[i - 1] > arr[i])
            swap(arr[i - 1], arr[i]);
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
        if (arr[i - 1] > arr[i])
            swap(arr[i - 1], arr[i]);
        rightMark--;
    }
}

void radix(int *arr, int *br, int *cr, int sizeC, int sizeAB)
{
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[arr[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[arr[i]]-1]=arr[i];
         cr[arr[i]]-=1;
      }
  }

int main() {
    setlocale(LC_ALL, "Russian");
    int n, q;
    int rotat[21];
    cout << "Input size: ";
    cin >> n;
    int *mass=new int [n];
    int *out=new int [n];



    do{
        //Генерация массива
        for (int j=0;j<n;j++){
            mass[j]=0+rand()%20;
            //Ввывод сгенерированного массива на экран
            //cout << mass[j] << " ";
        }
        cout << "\nSelect a sorting method:\n1 - Bubble sort\n2 - Cocktail sort\n3 - Radix sort\n";
        cin >> q;
        switch(q){
        case 1:{
            clock_t start2 = clock();
            auto begin = chrono::steady_clock::now();
            bubble(mass, n);
            clock_t end2 = clock();
            auto end = chrono::steady_clock::now();
            double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
            auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
            cout << "Time bubble with Chrono: " << elapsed_ms.count() << " ms\n";
            cout << "Time bubble with Time.h: " << (int)(seconds2*1000) << " ms\n";
            //for (int j=0;j<n;j++)
            //    cout << mass[j] << " ";
            break;
        }
        case 2:{
            clock_t start2 = clock();
            auto begin = chrono::steady_clock::now();
            cocktail(mass,n);
            clock_t end2 = clock();
            auto end = chrono::steady_clock::now();
            double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
            auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
            cout << "Time cocktail with Chrono: " << elapsed_ms.count() << " ms\n";
            cout << "Time cocktail with Time.h: " << (int)(seconds2*1000) << " ms\n";
            //for (int j=0;j<n;j++)
            //    cout << mass[j] << " ";
            break;
        }
        case 3:{
            clock_t start2 = clock();
            auto begin = chrono::steady_clock::now();
            radix(mass,out,rotat,20,n);
            clock_t end2 = clock();
            auto end = chrono::steady_clock::now();
            double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
            auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
            cout << "Time radix with Chrono: " << elapsed_ms.count() << " ms\n";
            cout << "Time radix with Time.h: " << (int)(seconds2*1000) << " ms\n";
            //for (int j=0;j<n;j++)
            //    cout << out[j] << " ";
            break;
        }
        }
    cout << "\nRepeat sorting? (1 - yes, 0 - exit)\n";
    cin >> q;
    }while(q!=0);
}
