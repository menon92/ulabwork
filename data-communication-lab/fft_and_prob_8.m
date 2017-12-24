Fs = 1000; % sampling frequency
Ts = 1/Fs; %sampling period or time step

dt = 0:Ts:1.5-Ts; %signal duration

%user input of frequencies
f1= input('Enter the frequency of First signal : ');
f2= input('Enter the frequency of Second signal : ');
f3= input('Enter the frequency of Third signal : ');

%user input of Amplitude
a1 = input('Enter the amplitude of First signal : ');
a2 = input('Enter the amplitude of Second signal : ');
a3 = input('Enter the amplitude of Third signal : ');

%signal creatiing section

y1= a1*sin(2*pi*f1*dt);
y2= a2*sin(2*pi*f2*dt);
y3= a3*sin(2*pi*f3*dt);

X = y1 + y2 + y3; %create a composite signal

%the are the algorithm to normalize frequency axes and amplitude axes

L = length(X); %length of the composite signal
Y = fft(X); % here fft is a library function
p2 = abs(Y/L); % taking the one half of composite signal by diving it with its length
p1 = p2(1:L/2+1);
p1(2:L/2-1) = 2*p1(2:L/2-1); %normalization of the frequency axes
f= Fs*(0:(L/2))/L; %normalization of the amplitude axes

%plotting section

subplot(2,1,1); %plotting the composite signal
plot(dt,X);
xlabel('Time');
ylabel('Amplitude');
title('time domain signal');

subplot(2,1,2); %ploting the normalized form
plot(f,p1);
xlabel('Frequency');
ylabel(' Normalized Amplitude');
title('frequency domain signal');