//
// Created by mariojey on 04.07.2025.
//

#include <iostream>
#include <climits>

using namespace std;

int main(){
  int numbers[10];
  int sum = 0;
  float average = 0.0f;
  int max = INT_MIN;
  int min = INT_MAX;

  for (int i = 0; i < 10; i++){
    cin >> numbers[i];
    sum += numbers[i];
    if (numbers[i] > max){
      max = numbers[i];
    }
    if (numbers[i] < min){
      min = numbers[i];
    }
  }
  average = sum / 10.0;

  cout << "Sum = " << sum << endl;
  cout << "Avg = " << average << endl;
  cout << "Max = " << max << endl;
  cout << "Min = " << min << endl;

  return 0;
}