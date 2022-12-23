clear all
close all
clc

last_ID_1 = 6;                              %first id last number
last_ID_2 = 1;                              %second id last number
avg_ID = (last_ID_1+last_ID_2)/200;         %average number between the id's
d = avg_ID+0.4;                             %the distence for the q func

z = d;                                      %the distance in the reference func

M = 1024;                                   %hologram column
N = 1024;                                   %hologram row
b = zeros(N,M);                             %object create
pixel_M = 10^(-5);                          %pixel column
pixel_N = 10^(-5);                          %pixel row
lambda = 633*10^(-9);                       %wavelength
tet = 0.014;                                %the angle of the reference                      (angle)
A = 100;                                    %the amplitude                                   (wave ampitude)

for k=-20:20                                %make a circle with rad 20
    for l=-20:20
        if sqrt (k^2+l^2)<20
            b(k+N/2 ,l+M/2)=1;
        end
    end
end
b = A.*b;

figure(1);                                  %image of the object
imagesc(b);
title("image of the object");
[m,n]=meshgrid(-M/2:M/2-1,-N/2:N/2-1);      %grid for the q func
figure(7);
imagesc(m);
delta_pixel_M = lambda*d/(pixel_M*M);
delta_pixel_N =  lambda*d/(pixel_N*N);

q_func = exp((i*pi*((m.*pixel_M).^2+(n.*pixel_N).^2))/(lambda*d));                  %q func with ksay
delta_q_func = exp(i*pi*((m.*delta_pixel_M).^2+(n.*delta_pixel_N).^2)./(lambda*d)); %q func with x,y

reference=15000*exp((2*i*pi*(tet*m.*pixel_M+tet*n.*pixel_N +z))/(lambda));        %the reference func   (reference amplitude, 0 in one of x,y)

U_total = q_func.*(fftshift(fft2(fftshift(b.*delta_q_func))));                      %making the U total equation
hologram_total = (abs(U_total+reference)).^2;                                       %sum with the reference and do abs ^2

figure(2);                                  %figure the hologram
imagesc(hologram_total);
title("figure the hologram");
figure(3);                                  %figure the hologram angle 
imagesc(angle(U_total));        
title("figure the hologram angle");
hologram_total = hologram_total.*conj(reference);

%here we can change the d between the reference and the image                                  (d value)
%d=0.4;
%again the q func for the restoration (when we change the d)
q_func = exp((i*pi*((m.*pixel_M).^2+(n.*pixel_N).^2))/(lambda*d));                     %q func with ksay for the restoration
delta_q_func = exp(i*pi*((m.*delta_pixel_M).^2+(n.*delta_pixel_N).^2)./(lambda*d));    %q func with x,y for the restoration

hologram_total = (fftshift(fft2(fftshift(hologram_total.*q_func)))).*delta_q_func;

figure(4);                                 %figure the hologram restoration angle
imagesc(angle(hologram_total));
title("figure the hologram restoration angle");
figure(5);                                 %figure the hologram restoration 
imagesc((abs(hologram_total)));
title("figure the hologram restoration ");