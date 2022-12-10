clear 
close all
clc

newaddressesx = importdata('xaddresses.txt');
newaddressesy = importdata('yaddresses.txt');

figure
plot(newaddressesx,newaddressesy)
grid on
title('New Route: *NAME OF* Method')

