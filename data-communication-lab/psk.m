clear all;
close all;
clc;

f1 = input(''); % 10;
f2=5;
a=3;
t=0:0.001:1;

x=a.*sin(2*pi*f1*t);%sine wave
u=square(2*pi*f2*t);%square wave
v=x.*u;%Phase Shift

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
title('Phase Shift Keying ');
grid on;
