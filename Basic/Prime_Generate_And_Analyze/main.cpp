//
// Created by marri on 05.07.2025.
//
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
  if(n==1){
    return false;
  }
  if(n==2){
    return true;
  }
  if(n%2==0){
    return false;
  }
  for(int i =3; i<=sqrt(n); i=i+2){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

int printPrime(int n){
  if(isPrime(n)){
    return n;
  }else{
    return 0;
  }
}

int main(){

  int givenNumber;
  cin>>givenNumber;

  int foundedPrimeNumbers = 0;
  cout<<"Prime numbers from 1 to "<<givenNumber<<" are: ";
  for(int i =1; i<=givenNumber; i++){
    if(printPrime(i)!=0){
      cout<<printPrime(i)<<" ";
      foundedPrimeNumbers++;
    }
  }
  cout<<"\nNumber of prime numbers: "<<foundedPrimeNumbers;

  return 0;
}
