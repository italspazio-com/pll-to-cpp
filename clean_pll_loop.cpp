#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const short int k = 1024;

const short int sample_rate = 100;
const short int freq = 10;

vector<int> t;

const float K_p = 0.2667;
const float K_i = 0.0178;
const float K_0 = 1;

float integrator_out = 0;
vector<float> phase_estimate;
vector<float> e_D;
vector<float> e_F;
vector<float> sin_out;
vector<float> cos_out;
vector<double> input_signal;

void createCSV();
void stampaVettore(vector<float> vettore);

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

int main()
{
    init();

    //*********************************
    // DECOMENTERARE IL WHILE
    // è stato commentato per provare la funzione di esportazione CSV
    //*********************************
    int scelta = 1;

    while (scelta)
    {
        input_signal.clear();
        for (int i = 0; i < sample_rate; i++)
            input_signal.push_back(cos((2 * M_PI * freq * t[i] / sample_rate + M_PI)));

        phase_estimate[0] = phase_estimate[phase_estimate.size() - 1];
        cout << "PHASE STIMATE [0]" << phase_estimate[0] << endl;
        sin_out[0] = sin_out[sin_out.size() - 1];
        cos_out[0] = cos_out[cos_out.size() - 1];
        e_D.clear();
        e_F.clear();

        for (int i = 0; i < sample_rate - 1; i++)
        {
            // cout << input_signal[i] << " ";

            // Phase Detector
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

            try
            {
                if (i < phase_estimate.size() && i < e_F.size()) // Check if the input signal and sin out are minor than the index i
                {
                    phase_estimate[i + 1] = phase_estimate[i] + K_0 * e_F[i];
                }
                else
                {
                    throw std::out_of_range("Index out of range");
                }
            }
            catch (const std::out_of_range &e)
            {
                phase_estimate[i + 1] = K_0 * e_F[i];
                cout << "Calcolo il phase estimate nel catch: " << phase_estimate[i + 1] << endl;
            }
            // cout << "Pi: " << M_PI << " | freq:" << freq << " | (i + 1): " << (i + 1) << " | sample_rate: " << sample_rate << " | phase_estimate[" << i << "]: " << phase_estimate[i] << endl;
            sin_out[i + 1] = -sin(2 * M_PI * freq * (i + 1) / sample_rate + phase_estimate[i]);
            cos_out[i + 1] = cos(2 * M_PI * freq * (i + 1) / sample_rate + phase_estimate[i]);
        }
        cout << "Inserire 0 per terminare ciclo while: ";
        cin >> scelta;
    }
    createCSV();
    return 0;
}

void stampaVettore(vector<double> vettore)
{
    cout << "Stampo il vettore: " << endl;
    for (float i : vettore)
        cout << i << endl;
}

void createCSV()
{
    // file pointer
    std::fstream fout;
    std::fstream fout2;

    // opens an existing csv file or creates a new file.
    fout.open("esportazione.csv", ios::out | ios::app);

    fout << "cos, input_signal\n";
    for (int i = 0; i < cos_out.size(); i++)
        fout << cos_out[i] << "," << input_signal[i] << "\n";

    fout.close();

    // fout2.open("esportazione_e_F.csv", ios::out | ios::app);

    // for (int i = 0; i < e_F.size(); i++)
    //     fout2 << e_F[i] << "\n";

    // fout2.close();
}
