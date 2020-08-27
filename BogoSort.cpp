// BogoSort
// Ian Cramer
// 10/25/18
//

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <class Comparable>
void bogoSort(vector<Comparable> &dataSet);

template <class Comparable>
bool isSorted(const vector<Comparable> &dataSet);

template<class Primitive>
void print(const vector<Primitive> &dataSet);

int main()
{
   srand(time(NULL));
   clock_t startTime, stopTime;
   double timePassed;
   
   int n = 2;
   
   for (n; n < 20; n++)
   {
      vector<int> dataSet;
      
      for (int i = 0; i < n; i++)
         dataSet.push_back(rand()%100);
      
      print(dataSet);
      
      startTime = clock();
      bogoSort(dataSet);
      stopTime = clock();
      
      print(dataSet);

      timePassed = (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC;

      cout << n << " items took " << timePassed << " time." << endl;
      cout << "-----------------------------------------------------" << endl;
   }

}


template <class Comparable>
void bogoSort(vector<Comparable> &dataSet)
{
   srand(time(NULL));
   Comparable tmp;
   int index;
   while (!isSorted(dataSet))
   {
      for (int i = 0; i < dataSet.size(); i++)
      {
         index = rand()%dataSet.size();
         tmp = dataSet[i];
         dataSet[i] = dataSet[index];
         dataSet[index] = tmp;
      }
   }
}

template <class Comparable>
bool isSorted(const vector<Comparable> &dataSet)
{
   for (int i = 0; i < dataSet.size()-1; i++)
      if (dataSet[i] > dataSet[i+1])
         return false;
   return true;
}


template <class Primitive>
void print(const vector<Primitive> &dataSet)
{
   for (int i = 0; i < dataSet.size(); i++)
      cout << dataSet[i] << ", ";
   cout << endl;
}