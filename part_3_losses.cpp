#include <iostream>
#include <math.h>

using namespace std;

void mse()
{
    double y[3] = {1,2,3};
    double y_pred[3] = {1,2,3};

    double sum=0;

    for(int i=0; i <3; i++)
    {
        sum += pow((y[i] - y_pred[i]), 2);
    }
    sum /= 3;

    cout<<"OUTPUT of mse : "<<sum;
    cout<<"\n\nACcuracy of mse : "<<100 - sum;
}

void bce()
{
    double y[1] = {0};
    double y_pred[1] = {0.001};

    double sum=0;
    for(int i=0; i <1; i++)
    {
        sum += (y[i]*log(y_pred[i]) + ((1-y[i]) * log(1 - y_pred[i])));
    }
    sum = -sum;
    sum /= 1;

    cout<<"output of bce : "<<sum;
}

void cce()
{
    double y[3] = {0,0,1};
    double y_pred[3] = {0.5,0.1,0.1};

    double sum=0;

    for(int i=0; i<3; i++)
    {

        sum += y[i]*log(y_pred[i]);

    }
    sum = -sum;
    sum /= 1;


    cout<<"Output of cce : "<<sum;

}

int main()
{

    cce();

    return 0;
}
