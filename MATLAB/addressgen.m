clear
close all
clc

%user input
numAddresses = 250;
routenumber = 1; 

%select points and convert to double
addressesx = randi([-10 10], 1, numAddresses);
addressesx = double(addressesx);

addressesy = randi([-10 10], 1, numAddresses);
addressesy = double(addressesy);

plotx = [0, addressesx];
plotx = [plotx, 0];
ploty = [0, addressesy];
ploty = [ploty, 0];


figure
plot(plotx,ploty,"o-")
grid on
title('Original Route')

%write points to text file
fileID = fopen('addressgen.txt','w');

for i = 1:numAddresses
writetofile = fprintf(fileID, '\nroute%d.add_address( Address(%.1f, %.1f) );', routenumber, addressesx(i), addressesy(i));
end
