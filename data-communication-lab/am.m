clear all;
close all;
clc;

Ac=2; %carrier amplitude
Fc=0.5; %carrier frequency
Am=0.5;%Message signal amplitude
Fm=0.05;%Message signal frequency
% Fs=100; %sampling frequency/rate;
Ka=1; %Amplitude sensivity
t= 0:0.1:50;

carrier_signal=Ac*cos(2*pi*Fc*t);
message_signal=Am*cos(2*pi*Fm*t);
Amplitude_modulation=carrier_signal.*(1+Ka*message_signal);%Amplitude Modulated wave according to the standard definition

subplot(3,1,1);
plot(t, message_signal);
ylabel('Message Signal');
grid on

subplot(3,1,2);
plot(t, carrier_signal);
ylabel('Carrier Signal');

subplot(3,1,3);
plot(t, Amplitude_modulation);
ylabel('AM Signal');