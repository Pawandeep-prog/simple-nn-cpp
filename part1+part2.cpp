#include <iostream>
#include <math.h>

using namespace std;

/// linear function
double linear(double x)
{
    return x;
}

/// sigmoid activation
double sigmoid(double x)
{
    return (1 / (1 + exp(-x)));
}

/// tanh function
double tanh_func(double x)
{
    return tanh(x);
}

/// relu

double our_max(double x)
{
    if(x < 0)
    {
        return 0;
    }
    else{
        return x;
    }
}

double relu(double x)
{
    return our_max(x);
}


/// softmax function



int main()
{

    double inputs[2][1] = {{1}, {3}};
    double weights[3][2] = {{0.1, 0.2},
                            {0.2, 0.4},
                            {0.3, 0.4}};
    double biases[3] = {1,1,1};
    double output[3];

    double sum = 0;

    /// matrix multiplication
    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 1; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    sum += inputs[k][j]*weights[i][k];
                }

                /// apply activation function
                output[i] = relu(sum + biases[i]);
                sum = 0;
            }
        }

    /// output layer
    for(int i = 0; i < 3; i++)
    {
        cout<<output[i]<<" ";
    }


    /// softmax function
    double exp_sum=0;

    for(int i=0; i < 3; i++)
    {
        exp_sum += exp(output[i]);
    }
    cout<<endl<<endl;
    cout<<"OUTPUT OF SOFTMAX \n";

    for(int i=0; i < 3; i++)
    {
        cout<< exp(output[i]) / exp_sum<<"  ";
    }



    return 0;
}
