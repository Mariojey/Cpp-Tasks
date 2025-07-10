//
// Created by marri on 10.07.2025.
//

#include <iostream>

using namespace std;

class FloatingPointSimulator{
  private:
    float x;
    float y;
    double x1;
    double y1;

  public:
    void setX(float param){
      this->x = param;
    }
    void setY(float param){
      this->y = param;
    }
    float getX(){
      return this->x;
    }
    float getY(){
      return this->y;
    }
    void setX1(double param){
      this->x1 = param;
    }
    void setY1(float param){
      this->y1 = param;
    }
    float getX1(){
      return this->x1;
    }
    float getY1(){
      return this->y1;
    }

    FloatingPointSimulator(float x0,  double x2){
       this->x = x0;
//       this->y = y0;
       this->x1 = x2;
//       this->y1 = y2;
    };

  void simulateAddition(float increment, int times){

    float sum_float = this->x;
    double sum_double = this->x1;

    for(int i = 0; i < times; i++){
      sum_float = sum_float + increment;
      sum_double = static_cast<double>(increment);
    }

    this->y = sum_float;
    this->y1 = sum_double;
  }

};

int main(){
  FloatingPointSimulator f = FloatingPointSimulator(1.0f, 1.0);
  f.simulateAddition(1e-7, 1000000);
  cout << f.getY() << endl;
  cout << f.getY1() << endl;
  return 0;
}
