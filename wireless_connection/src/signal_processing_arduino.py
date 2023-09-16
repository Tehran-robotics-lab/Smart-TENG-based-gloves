import serial
import time
import numpy as np
import matplotlib.pyplot as plt
#from scipy.signal import butter , lfilter

# # Serial port settings
port = 'COM12'
baud_rate = 115200

# Initialize serial communication
ser = serial.Serial(port=port, baudrate=baud_rate)


# ButterWorth low-pass filter function
"""def butter_lowpass(cutoff, fs, order):
    nyquist = 0.5 * fs
    normal_cutoff = cutoff/nyquist
    b, a = butter(order, normal_cutoff, btype='low', analog=False)
    return b, a"""

# Filtering parameters
"""cutoff_frequency = 100
filter_order = 4
Wn = [0.000001, 0.005]"""

# Initialize the filter
# b, a = butter_lowpass(cutoff_frequency, baud_rate, order=filter_order)

# # Initialize an empty list to store data
data = []
filtered_ = []
time_ = []

# Read data from Arduino
try:
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line:
            line_2 = line.split()
            print(line, " ", time.strftime("%H:%M:%S"))
            value = float(line_2[0])
            filter_value = float(line_2[1])
            data.append(value)
            time_.append(time.strftime("%H:%M:%S"))
            filtered_.append(filter_value)
            filtered_value = lfilter(b, a, [value])[0]
            # print(f"original:{value:.2f}  filtered:{filtered_value:.2f}")
except KeyboardInterrupt:
    pass
finally:
    ser.close()





# Frequencies corresponding to FFT components
frequencies = np.fft.fftfreq(len(data), d=1/baud_rate)


# Plot the received and filtered data
plt.plot(data, label='Received Data')
# filtered_data = lfilter(b, a, data)

plt.plot(filtered_, label='Filtered Data')
plt.xlabel('Sample')
plt.ylabel('Value')
# plt.ylim(0, 500)
plt.title('Received and Filtered Data from Arduino')
plt.legend()
plt.show()

# Calculate the fft of the original and filtered signal
"""fft_original = np.fft.fft(data)
fft_filtered = np.fft.fft(filtered_data)

# Plot the FFT of the original and filtered signals in the frequency domain
plt.subplot(2, 1, 2)
plt.semilogy(frequencies, np.abs(fft_original), 'b-', label='Original Signal')
plt.semilogy(frequencies, np.abs(fft_filtered), 'g-', linewidth=2, label='Filtered Signal')
plt.xlabel('Frequency [Hz]')
plt.ylabel('Magnitude')
plt.legend()
plt.grid()"""

