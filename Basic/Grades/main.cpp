//
// Created by marri on 09.07.2025.
//

#include <iostream>

using namespace std;


float calculate_average(int grades[], int grades_size){
  float average = 0;
  for (int i = 0; i < grades_size; i++) {
    average += grades[i];
  }
  average /= grades_size;
  return average;
}

int findMinimum(int grades[], int grades_size){
  int minimum = grades[0];
  for (int i = 0; i < grades_size; i++){
    if ( grades[i] < minimum){
      minimum = grades[i];
    }
  }
  return minimum;
}

int findMaximum(int grades[], int grades_size){
  int maximum = 0;
  for (int i = 0; i < grades_size; i++){
    if ( grades[i] > maximum){
      maximum = grades[i];
    }
  }
  return maximum;
}

int countFIveOrSix(int grades[], int grades_size){
  int count = 0;
  for (int i = 0; i < grades_size; i++){
    if (grades[i] == 5 or grades[i] == 6){
      count++;
    }
  }
  return count;
}

int* countEverGrade(int grades[], int grades_size){
  static int count[6] = {0,0,0,0,0,0};
  for (int i = 0; i < grades_size; i++){
    count[grades[i]-1]++;
  }
  return count;
}

int findMedian(int grades[], int grades_size){
  for (int i = 0; i < grades_size; i++){
    for (int j = 0; j < grades_size; j++){
      if (grades[i] > grades[j]){
        int temp = grades[i];
        grades[i] = grades[j];
        grades[j] = temp;
      }
    }
  }
  int middle = grades_size/2;
  return grades[middle];
}

void printHistogram(int grades[], int grades_size){
  int * countedGrades;
  countedGrades = countEverGrade(grades, grades_size);
  for (int i = 0; i < 6; i++){
    cout << i+1 << " "<<countedGrades[i]<<endl;
  }
}

int main(){

  int n;
  cout<<"Quantity of students (max 100): ";
  cin>>n;
  while(n>100){
    cout<<"Too many students";
    cout<<"Quantity of students: ";
    cin>>n;
  }

  int * grades = new int[n];

  cout<<endl;
  cout<<"Enter Grades :";
  for(int i=0;i<n;i++){
    cin>>grades[i];
  }

  cout<<"======================================================"<<endl;

  cout<<"Avg: "<<calculate_average(grades, n)<<endl;
  cout<<"Min: "<<findMinimum(grades, n)<<endl;
  cout<<"Max: "<<findMaximum(grades, n)<<endl;
  cout<<"Median: "<<findMedian(grades, n)<<endl;
  printHistogram(grades, n);



  return 0;
}


