#include<iostream>
#include <ctime>

using namespace std;

void MassIn(int aArray[], int size);
void MassOut(int aArray[], int size);
bool prNum(int a);
int *check(int aArray[], int size);

int main()
{
   srand(time(NULL));
   int size = 0;
   cout << "Enter the size of the array: " << endl;
   cin >> size;
   int *aArray = nullptr;
   aArray = new int[size];
   MassIn(aArray, size);
   cout << endl;
   MassOut(aArray, size);
   cout << endl << endl;
   int *result = *check(*aArray, size);
   cout << endl << endl;

   delete[] aArray;
   delete[] result;

   system("pause");
   return 0;
}

void MassIn(int aArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        aArray[i] = rand() % 20;
    }
    return;
}

void MassOut(int aArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << aArray[i] << " ";
    }
    return;
}

bool prNum(int a)
{
    bool result(true);

    if ((a == 2) || (a == 3))
    {
        result = true;
    } 
    else
    {
        for (int i = 2; i <= floor(sqrt(a)); ++i)
        {
            if (a % i == 0)
            {
                result = false;
                break;
            }
        }
    }  
    return (result && (a != 1));
}

int *check(int *aArray[], int size)
{
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (!prNum(*aArray[i]))
        {
            ++count;
        }    
    }

    int *bArray = nullptr;
    bArray = new int[count];
    int j = 0;

    for (int i = 0; i < size; ++i)
    {
        if (!prNum(*aArray[i]))
            bArray[j++] = *aArray[i];

    } 

    for (int j = 0; j < count; j++)
    {
        cout << bArray[j] << " ";
    } 

    return bArray;
    delete[] bArray;
}