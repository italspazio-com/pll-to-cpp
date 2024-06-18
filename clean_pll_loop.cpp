#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const short int k = 1024;

const short int sample_rate = 100;
const short int freq = 10;

vector<int> t; // int *t = new int[sample_rate];

const float K_p = 0.2667;
const float K_i = 0.0178;
const float K_0 = 1;

float integrator_out = 0;
vector<float> phase_estimate; // float *phase_estimate = new float[sample_rate];
vector<float> e_D;            // float *e_D = new float[k];
vector<float> e_F;            // float *e_F = new float[k];
vector<float> sin_out;        // float *sin_out = new float[sample_rate];
vector<float> cos_out;        // float *cos_out = new float[sample_rate];

void arange()
{
    for (int i = 0; i < sample_rate; i++)
        t.push_back(i);
}

void zeros()
{
    for (int i = 0; i < sample_rate; i++)
    {
        phase_estimate.push_back(0);
        sin_out.push_back(0);
    }
}

void ones()
{
    for (int i = 0; i < sample_rate; i++)
        cos_out.push_back(1);
}

void init()
{
    arange();
    zeros();
    ones();
}

// input_signal.append(np.cos(2*np.pi*freq*t /sample_rate  + np.pi ))

int main()
{
    init();

    // for (int i : t)
    //     cout << i << ' ';

    while (true)
    {
        // double *input_signal = new double[k];
        vector<double> input_signal;
        for (int i = 0; i < sample_rate; i++)
            input_signal.push_back(2 * M_PI * freq * t[i] / sample_rate + M_PI);

        phase_estimate[0] = phase_estimate[phase_estimate.size() - 1];
        sin_out[0] = sin_out[sin_out.size() - 1];
        cos_out[0] = cos_out[cos_out.size() - 1];
        vector<float> e_D;
        vector<float> e_F;

        for (int i = 0; i < sample_rate - 1; i++)
        {
            cout << input_signal[i];

            // Phase Detector
            // try
            // {
            //     e_D.push_back(input_signal[i] * sin_out[i]);
            // }
            // catch (const std::exception &e)
            // {
            //     e_D.push_back(0);
            // }
            try
            {
                if (i < input_signal.size() && i < sin_out.size()) // Check if the input signal and sin out are minor than the index i
                {
                    e_D.push_back(input_signal[i] * sin_out[i]);
                }
                else
                {
                    throw std::out_of_range("Index out of range");
                }
            }
            catch (const std::out_of_range &e)
            {
                e_D.push_back(0);
            }

            // Loop Filter
            integrator_out += K_i * e_D[i];
            e_F.push_back(K_p * e_D[i] + integrator_out);

            // NCO
            try
            {
                phase_estimate[i + 1] = phase_estimate[i] + K_0 + e_F[i];
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }

    return 0;
}