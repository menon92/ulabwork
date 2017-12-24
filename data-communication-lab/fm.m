clear all;
close all;
clc;

% Ac=2; %carrier amplitude
Fc=0.5; %carrier frequency
% Am=0.5;%Message signal amplitude
Fm=0.05;%Message signal frequency
mi=6;  %modulation index
t= 0:0.1:50;


m=sin(2*pi*Fm*t);
c=sin(2*pi*Fc*t);
y=sin(2*pi*Fc*t+(mi.*sin(2*pi*Fm*t)));

subplot(3,1,1);
plot(t,m);
xlabel('Time');
ylabel('Amplitude');
title('Message Signal');
grid on;

subplot(3,1,2);
plot(t,c);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal');
grid on;

subplot(3,1,3);
plot(t,y);
xlabel('Time');
ylabel('Amplitude');
title('FM Signal');
grid on;
