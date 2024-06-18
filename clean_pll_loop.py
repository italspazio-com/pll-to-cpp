import matplotlib.pyplot as plt
import numpy as np

sample_rate = 100
freq = 10
t = np.arange(sample_rate) 

K_p = 0.2667
K_i = 0.0178
K_0 = 1

integrator_out = 0
phase_estimate = np.zeros(sample_rate)  
e_D = [] 
e_F = [] 
sin_out = np.zeros(sample_rate)     
cos_out = np.ones(sample_rate)

while 1: 

    input_signal = []
    input_signal.append(np.cos(2*np.pi*freq*t /sample_rate  + np.pi ))
    phase_estimate[0] = phase_estimate[-1]
    sin_out[0] = sin_out[-1]
    cos_out[0] = cos_out[-1]
    e_D = []
    e_F = []

    for n in range(sample_rate - 1):
        print(input_signal[0][n]) 

        # phase detector
        try:
            e_D.append(input_signal[0][n] * sin_out[n])
        except IndexError:
            e_D.append(0)

        #loop filter
        integrator_out += K_i * e_D[n]
        e_F.append(K_p * e_D[n] + integrator_out)

        #NCO
        try: 
            phase_estimate[n+1] = phase_estimate[n] + K_0 * e_F[n]
        except IndexError:
            phase_estimate[n+1] = K_0 * e_F[n]

        sin_out[n+1] = -np.sin(2*np.pi*freq*(n+1) /sample_rate + phase_estimate[n]) 
        cos_out[n+1] = np.cos(2*np.pi*freq*(n+1) / sample_rate + phase_estimate[n]) 
        
    # Create a Figure
    fig = plt.figure()

    ax1 = fig.add_subplot(211)
    ax1.plot(cos_out, label='PLL Output')
    plt.grid()
    ax1.plot(input_signal[0], label='Input Signal')
    plt.legend()
    ax1.set_title('Waveforms')

    ax2 = fig.add_subplot(212)
    ax2.plot(e_F)
    plt.grid()
    ax2.set_title('Filtered Error')
    plt.show()
