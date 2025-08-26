#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    int width = 3, height = 2;
    ofstream file("output.pgm");

    file << "P2\n";
    file << width << " " << height << "\n";
    file << 255 << "\n";

    int pixels[6] = {0, 128, 255, 64, 128, 192};

    for (int i = 0; i < width; i++)
    {
        file << pixels[i] << " ";
    }
    file.close();
}