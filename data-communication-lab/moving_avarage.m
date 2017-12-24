clear all
close all
clc


data=input('Enter the data:\n');
data_len = length(data);

window_size=input('Enter the window size:');
filter = ones(1,window_size);                           
filter_len = length(filter);

% Pad data vector with ones*mean(data)
datax = [data ones(1,filter_len)*mean(data)]; 

mavg = [];
for i = 1:data_len
    mavg = [mavg (filter * datax(i:i+filter_len-1)')/filter_len];
end


plot([1:data_len], data)
hold on

plot([1:data_len], mavg, '-r')
hold off
grid on
