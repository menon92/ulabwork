f1=20;
f2=50;
a=5;
fp=2;
t=0:0.001:1;

y1=a/2.*sin(2*pi*f1*t);
y2=a/2.*sin(2*pi*f2*t);
u=a/2.*square(2*pi*fp*t)+a/2;

subplot(4,1,1);
plot(t,y1);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal 1');
grid on;

subplot(4,1,2);
plot(t,y2);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal 2');
grid on;

subplot(4,1,3);
plot(t,u);
xlabel('Time');
ylabel('Amplitude');
title('Binary Message pulse ');