clear
close all
clc

%user input
numAddresses = 6;
routenumber = 1; 

%select points and convert to double
addressesx = randi([-10 10], 1, numAddresses);
addressesx = double(addressesx);

addressesy = randi([-10 10], 1, numAddresses);
addressesy = double(addressesy);


%write points to text file
fileID = fopen('addressgen.txt','w');

for i = 1:numAddresses
writetofile = fprintf(fileID, '\nroute%d.add_address( Address(%.1f, %.1f) );', routenumber, addressesx(i), addressesy(i));
end
