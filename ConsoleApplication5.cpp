#include <iostream>  
using namespace std;
void  printMin(int arr[10]);
int main()
{
    int arr[10] = { 31,5,2,30,25,21,54,250,120,102, };
    int len = sizeof(arr[10]) / sizeof(arr[0]);
    cout << "velkost pola je:"<< sizeof(arr) << "bitov" << endl;
    cout << "velkost jedneho prvku je:"<< sizeof(arr[0]) << "bity" << endl;

    int c, i;
        float sum = 0.0, pri;
        float num[] = { 31,5,2,30,25,21,54,250,120,102, };
        c = sizeof(num) / sizeof(num[0]);
        for (i = 0; i < c; i++)
            sum += num[i];
        pri = sum / c;
        cout << "priemer cisel v poli je " << pri << endl;
    
    printMin(arr);  
} 
void  printMin(int arr[10])
{
    int min = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "minimalny element je: " << min << endl;

    int max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "maximalny element je: " << max << endl;         

   
    
        
}
