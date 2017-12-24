clear all;
close all;
clc;
Ac=2; %carrier amplitude
Fc=0.5; %carrier frequency
Am=0.5;%Message signal amplitude
Fm=0.05;%Message signal frequency
%Fs=100; %sampling frequency/rate;
t = 0:0.1:50;
mi=6;

carrier_signal=Ac*sin(2*pi*Fc*t);
message_signal=Am*sin(2*pi*Fm*t);
phase_modulation=carrier_signal.*sin(2*pi*Fc*t+mi.*sin(2*pi*Fm*t));

subplot(3,1,1);
plot(t,message_signal);
xlabel('Time');
ylabel('Amplitude');
title('Message Signal');
grid on;

subplot(3,1,2);
plot(t,carrier_signal);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal');
grid on;

subplot(3,1,3);
plot(t,phase_modulation);
xlabel('Time');
ylabel('Amplitude');
title('PM Signal');
grid on;
