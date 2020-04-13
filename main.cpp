#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

struct Point{

    int x=0,y=0,z=0;

};

Point a[10000];
Point b[10000];
Point ans[20000];

void mergeSort(int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    while (i<n1 && j <n2)
    {
        if (a[i].x < b[j].x){
            ans[k] = a[i];
            k++;
            i++;
        }
        else if (a[i].x == b[j].x && a[i].y < b[j].y){
            ans[k] = a[i];
            k++;
            i++;
        }
        else if (a[i].x == b[j].x && a[i].y == b[j].y && a[i].z < b[j].z){
            ans[k] = a[i];
            k++;
            i++;
        }
        else {
            ans[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1){
            ans[k] = a[i];
            k++;
            i++;
        }

    while (j < n2){
            ans[k] = b[j];
            k++;
            j++;
        }
}

int part(int l, int h)
{
    int k = h;
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (a[j].x > a[k].x)
        {
            i++;
            swap(a[i], a[j]);
        }else if (a[j].y>a[k].y && a[j].x==a[k].x){
            i++;
            swap(a[i], a[j]);
        }else if (a[k].z>a[k].z && a[k].x==a[j].x && a[k].y==a[j].y){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return (i + 1);
}

void Sort3( int l, int h)
{
    if (l < h)
    {
        int pi = part( l, h);
        Sort3(l, pi - 1);
        Sort3(pi + 1, h);
    }
}

void Sort2(int begin, int end){

    for (int i=begin;i<end-1;i++){
            int k=i;
        for (int j=i+1;j<end;j++){
            if (a[k].x>a[j].x)
                k=j;
            else if (a[k].y>a[j].y && a[k].x==a[j].x)
                k=j;
            else if (a[k].z>a[j].z && a[k].x==a[j].x && a[k].y==a[j].y)
                k=j;
        }
            swap(a[i],a[k]);
    }
    return;

}

void Sort(int begin, int end){

    for (int i=begin;i<end-1;i++){
        for (int j=i+1;j<end;j++){
            if (a[i].x>a[j].x)
                swap(a[i],a[j]);
            else if (a[i].y>a[j].y && a[i].x==a[j].x)
                swap(a[i],a[j]);
            else if (a[i].z>a[j].z && a[i].x==a[j].x && a[i].y==a[j].y)
                swap(a[i],a[j]);
        }
    }
    return;

}

int main(){
    ofstream out("BechArr.txt");
    srand(time(0));
    clock_t start, end;

    start = clock();
    end = clock();



    int n;
    cout << "Enter the number of points:";
    cin >> n;
    out << n << endl;
    for (int i=0;i<n;i++){
        a[i].x=rand()%20;
        a[i].y=rand()%20;
        a[i].z=rand()%20;
        b[i]=a[i];
        cout << a[i].x << " " <<  a[i].y << " " << a[i].z << endl;
        Sleep(500);
    }

    Sleep(3000);
    cout << "Sort1:\n";
    start = clock();
    Sort(0,n);
    end = clock();
    out << "Sort1:" << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*n << "\n";
    for (int i=0;i<n;i++){
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
        a[i]=b[i];
        Sleep(500);
    }
    Sleep(3000);

    start = clock();
    cout << "Sort2:\n";
    Sort2(0,n);
    end = clock();
    out << "Sort2:" << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*n << "\n";
    for (int i=0;i<n;i++){
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
        a[i]=b[i];
        Sleep(500);
    }
    Sleep(3000);

    start = clock();
    cout << "Sort3:\n";
    Sort3(0,n-1);
    reverse(a,a+n);
    end = clock();
    out << "Sort3:" << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*n << "\n";
    for (int i=0;i<n;i++){
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
        b[i]=a[i];
        Sleep(500);
    }
    Sleep(3000);

    start = clock();
    cout << "Sort4:\n";
    mergeSort(n,n);
    end = clock();
    out << "Sort4:" << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*n*2 << "\n";
    for (int i=0;i<n+n;i++){
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << "\n";
        Sleep(500);
    }



}
