% amplitude shift key
clear all;
close all;
clc;

f1=10;
f2=5;
a=3;
t=0:0.001:1;

x=a.*sin(2*pi*f1*t);
u=a/2*square(2*pi*f2*t)+a/2;
v=x.*u;

subplot(3,1,1);
plot(t,x);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal');
grid on;

subplot(3,1,2);
plot(t,u);
xlabel('Time');
ylabel('Amplitude');
title('Square pulses');
grid on;

subplot(3,1,3);
plot(t,v);
xlabel('Time');
ylabel('Amplitude');
title('Amplitude Shift Keying ');
grid on;
