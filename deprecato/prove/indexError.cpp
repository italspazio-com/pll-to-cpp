
// try:
//     e_D.append(input_signal[0][n] * sin_out[n])
// except IndexError:
//     e_D.append(0)

#include <vector>
#include <cmath>
#include <stdexcept>

std::vector<std::vector<double>> input_signal;
std::vector<double> sin_out;
std::vector<double> e_D;

int main(int argc, char const *argv[])
{
    // try
    // {
    //     // Verifica se l'indice è valido
    //     if (n < input_signal[0].size() && n < sin_out.size())
    //     {
    //         e_D.push_back(input_signal[0][n] * sin_out[n]);
    //     }
    //     else
    //     {
    //         throw std::out_of_range("Index out of range");
    //     }
    // }
    // catch (const std::out_of_range &)
    // {
    //     e_D.push_back(0);
    // }
    return 0;
}
