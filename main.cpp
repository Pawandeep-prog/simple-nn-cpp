#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class Layer
{

    private:
        vector<double> bias;
        vector<vector<double>> weights;

        int out_neurons, batch_size;
        double lr = 0.1;

        vector<vector<double>> create_weights(int r, int c)
        {
            vector<vector<double>> weights(r, vector<double>(c));
            double n;

            srand(time(0));
            for(int i = 0; i < r; i++)
            {
                for(int j  = 0; j < c; j++)
                {
                    n = rand()%10;
                    n = n/10;
                    weights[i][j] = n;
                }
            }

            return weights;
        }


        vector<double> create_bias(int r)
        {
            srand(time(0));

            vector<double> bias(r);
            double v;
            for(int i = 0; i<r; i++)
            {
                v = rand()%10;
                v = v/10;
                bias[i] = v;
            }

            return bias;

        }

        double sigmoid(double v)
        {
            return (1 / (1 + exp(-v)));
        }
        double linear(double v)
        {
            return v;
        }
        double relu(double in)
        {
            if(in < 0)
                return 0;
            else
                return in;
        }
        double mse(double predicted, double true_value)
        {
            double diff = predicted - true_value;
            diff = pow(diff, 2);

            return diff;

        }
        double sgd(double loss, double old_Weight)
        {
            return lr*(loss/old_Weight);
        }



    public:



    Layer(int out, int bc)
    {
        cout<<"\nNumber of out neurons : "<<out<<endl;
        out_neurons = out;
        batch_size = bc;
        bias = create_bias(out_neurons);
        weights = create_weights(out_neurons, batch_size);
    }

    vector<vector<double>> forward_pass(vector<vector<double>> inputs)
    {
            vector<vector<double>>output(out_neurons, vector<double>(1));
            double sum=0;

            for(int i = 0; i < weights.size(); i++)
            {
                for(int j = 0; j < inputs[0].size(); j++)
                {
                    for(int k = 0; k < inputs.size(); k++)
                    {
                        sum += weights[i][k]*inputs[k][j];
                    }
                    output[i][0] = linear(sum + bias[i]);
                    sum = 0;
                }
            }

            return output;
    }

    void backward_pass(double pred,double true_v)
    {

        double loss = mse(pred, true_v);

        cout<<"\n============ backward performed =========== with loss : "<<loss<<endl;

        for(int i=0; i < weights.size(); i++)
        {
            for(int j = 0; j < weights[0].size(); j++)
            {
                cout<<endl<<"old weight was : "<<weights[i][j];
                weights[i][j] = sgd(loss, weights[i][j]);
                cout<<" new weight is : "<<weights[i][j]<<endl;
            }

        }
    }

    void show_ops(vector<vector<double>> op)
        {

            cout<<"\n========== another pass ==========\n";


            for(int i = 0; i < op.size(); i++)
            {
                for(int j=0; j < op[0].size(); j++)
                {
                    cout<<op[i][j]<<"  ";
                }
                cout<<endl;
            }
        }

    double score(double pred, double true_v)
        {
            return mse(pred, true_v);
        }



};

int main()
{
    vector<vector<double>> X(1, vector<double>(1));
    X[0][0] = 2;

    Layer l1(1, 1);
    vector<vector<double>> layer_1_output(1, vector<double>(1));



    int epochs = 100;
    double loss;
    for(int i = 0; i < epochs; i++)
    {
        layer_1_output = l1.forward_pass(X);
        l1.show_ops(layer_1_output);

        loss = l1.score(layer_1_output[0][0], 3);
        if(loss < 0.01)
        {
            cout<<"\nBest Accuracy found" << (100 - loss);
            break;
        }

        l1.backward_pass(layer_1_output[0][0], 3);
    }

    cout<<"\n\n\n==================================================\n\n\n";

    vector<vector<double>> x_test(1, vector<double>(1));
    x_test[0][0] = 0;
    while(x_test[0][0] != -1)
    {
        cout<<"\nEnter no to predict its next one : ";
        cin>>x_test[0][0];

        cout<<"\n\nPrediction is : "<<l1.forward_pass(x_test)[0][0];
    }


    return 0;
}
