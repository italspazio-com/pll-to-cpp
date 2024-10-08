import matplotlib.pyplot as plt
import numpy as np


input_signal = 0
sample_rate = 100
freq = 10
t = np.arange(sample_rate)
phase_estimate = np.zeros(sample_rate)  
cos_out = np.ones(sample_rate)

input_signal = []
input_signal.append(np.cos(2*np.pi*freq*t /sample_rate  + np.pi ))


print(cos_out)