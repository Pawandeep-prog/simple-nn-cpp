#include <iostream>

using namespace std;

int main()
{

    double inputs[2][1] = {{0.001}, {3}};
    double weights[3][2] = {{0.1, 0.2},
                            {0.2, 0.4},
                            {0.3, 0.4}};
    double biases[3] = {1,1,1};
    double output[3];

    //output[0] = (weights[0][0]*inputs[0] + weights[0][1]*inputs[1]) + biases[0];
    //output[1] = (weights[1][0]*inputs[0] + weights[1][1]*inputs[1]) + biases[1];
    //output[2] = (weights[2][0]*inputs[0] + weights[2][1]*inputs[1]) + biases[2];

    double sum = 0;

    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 1; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    sum += inputs[k][j]*weights[i][k];
                }
                output[i] = sum + biases[i];
                sum = 0;
            }
        }




    for(int i = 0; i < 3; i++)
    {
        cout<<output[i]<<" ";
    }

    return 0;
}
