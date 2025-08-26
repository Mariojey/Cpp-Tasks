#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    const int N = 10;
    const int scale = 20;
    const int width = N * scale;
    const int height = N * scale;

    ifstream in("source.txt");
    vector<vector<int>> matrix(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> matrix[i][j];
        }
    }

    in.close();

    ofstream out("output.pgm");

    out << "P2\n";
    out << width << " "<< height << "\n";
    out << 255 << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int y = 0; y < scale; y++)
        {
            for (int j = 0; j < N; j++)
            {
                int value = (matrix[i][j] == 0 ? 0 : 255);

                for (int x = 0; x < scale; x++)
                {
                    out << value << " ";
                }
            }
            out << "\n";
        }
    }

    out.close();
    cout << "PGM Generated!!!"<<endl;
    return 0;
    
}