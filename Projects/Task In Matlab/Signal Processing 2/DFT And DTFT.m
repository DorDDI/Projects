clc;
clear all;
close all;
%----------------------task 1.1------------------------
N = 30;
tet1 = pi/10.25;
tet2 = 2*pi/5;
n = 0:29;
sn = 2*cos(tet1.*n);
vn = 3*sin(tet2.*n);
xn = sn+vn;
figure
stem(n,sn,'r',"LineWidth",2);
hold on
stem(n,vn,'b',"LineWidth",2);
hold on
stem(n,xn,'k',"LineWidth",2);
xlabel ('Samples [n]');
ylabel ('x[n],s[n],v[n] [V]')
legend ('s[n]','v[n]','x[n]')
title ('Signals')
hold off
sk = fft(sn);
vk = fft(vn);
xk = fft(xn);
figure
stem(n,abs(sk),'r',"LineWidth",2);
hold on
stem(n,abs(vk),'b',"LineWidth",2);
hold on
stem(n,abs(xk),'--k',"LineWidth",2);
xlabel ('Samples [k]');
ylabel ('x[k],s[k],v[k]')
legend ('s[k]','v[k]','x[k]')
title ('Signals')
hold off


%----------------------task 1.2------------------------
xzn = fft(xn,45);
k = 0:44;
figure
stem(n,abs(xk),'r',"LineWidth",1.5);
hold on
stem(k*2/3,abs(xzn),'--k',"LineWidth",1.5);
xlabel ('Samples [k]');
ylabel ('x[k],xz[k]')
legend ('x[k]','xz[k]')
title ('Signals')
hold off

%----------------------task 1.3------------------------
N = 45;
n1 = 0:44;
sn1 = 2*cos(tet1.*n1);
vn1 = 3*sin(tet2.*n1);
xn1 = sn1+vn1;
xzn1 = fft(xn1);
figure
stem(n,abs(xk),'r',"LineWidth",1.5);
hold on
stem(n1*2/3,abs(xzn1),'--k',"LineWidth",1.5);
xlabel ('Samples [k]');
ylabel ('x[k],xz[k]')
legend ('x[k]','xz[k]')
title ('Signals')
hold off


%----------------------task 1.4------------------------
x_parsev = conj(xn) *xn.';
xk_parsev = 1/30*(conj(xk)*xk.');
xz_parsev = conj([xn zeros(1,15)]) * [xn zeros(1,15)].';
xzk_parsev = 1/45*(conj(xzn)*xzn.');

%----------------------task 1.5------------------------
te = 0:1/100:2*pi;
Htet = 1/3*(1+exp(-i*te)+exp(-i*2*te));
figure
plot(te*30/2/pi,abs(Htet),'k',"LineWidth",1.5);
hold on
stem(n,abs(xk),'--r',"LineWidth",1.5);
xlabel ('Samples');
ylabel ('x[k],H[tet]')
legend ('H[tet]','X^d[k]')
title ('Signals')
hold off

hnzeros = [1/3 1/3 1/3 zeros(1,29)];
xnzeros = [xn zeros(1,2)];
Hkzeros = fft(hnzeros);
Xkzeros = fft(xnzeros);
Y1k = Hkzeros.*Xkzeros;
n3 = 0:31
figure
stem(n3,abs(Xkzeros),'r',"LineWidth",1.5);
hold on
stem(n3,abs(Y1k),'--k',"LineWidth",1.5);
xlabel ('Samples [k]');
ylabel ('Y[k],X[k]')
legend ('X^d[k]','Y_1^d[k]')
title ('Signals')
hold off
y1 = ifft(Y1k);
figure
stem(n,sn,'r',"LineWidth",2);
hold on
stem(n,vn,'b',"LineWidth",2);
hold on
stem(n,xn,'k',"LineWidth",2);
hold on
stem(n,y1(n+1),'g',"LineWidth",2);
xlabel ('Samples [n]');
ylabel ('x[n],s[n],v[n],y[n] [V]')
legend ('s[n]','v[n]','x[n]','y_1[n]')
title ('Signals')
hold off


%----------------------task 1.6------------------------
te = 0:1/100:2*pi;
H2tet = (1+exp(-i*te));
figure
plot(te*30/2/pi,abs(H2tet),'k',"LineWidth",1.5);
hold on
stem(n,abs(xk),'--r',"LineWidth",1.5);
xlabel ('Samples');
ylabel ('x[k],H[tet]')
legend ('H_2[tet]','X^d[k]')
title ('Signals')
hold off
hn2zeros = [1 1  zeros(1,29)];
xn2zeros = [xn 0];
Hk2zeros = fft(hn2zeros);
Xk2zeros = fft(xn2zeros);
Y2k = Hk2zeros.*Xk2zeros;
n3 = 0:30
figure
stem(n3,abs(Xk2zeros),'r',"LineWidth",1.5);
hold on
stem(n3,abs(Y2k),'--k',"LineWidth",1.5);
xlabel ('Samples [k]');
ylabel ('Y[k],X[k]')
legend ('X^d[k]','Y_2^d[k]')
title ('Signals')
hold off
y2 = ifft(Y2k);
figure
stem(n,sn,'r',"LineWidth",2);
hold on
stem(n,vn,'b',"LineWidth",2);
hold on
stem(n,xn,'k',"LineWidth",2);
hold on
stem(n,y2(n+1),'g',"LineWidth",2);
xlabel ('Samples [n]');
ylabel ('x[n],s[n],v[n],y[n] [V]')
legend ('s[n]','v[n]','x[n]','y_2[n]')
title ('Signals')
hold off

%----------------------task 1.7------------------------
figure
plot(te/pi,abs(Htet),'k',"LineWidth",1.5);
hold on
plot(te/pi,abs(H2tet),'r',"LineWidth",1.5);
xlabel ('Theta/pi ');
ylabel ('H_1 , H_2')
legend ('H_1','H_2')
title ('Filters')
hold off

%----------------------task 2.4------------------------
load('data2020.mat');
Ny = length(y_test);
Nx = length(x_test);
xa_test = [x_test zeros(1, Ny-Nx)];
yk_test = fft(y_test);
yzk = fft(y_z);
xk_test = fft(xa_test);
Hk = xk_test./(yk_test-yzk);
hn = ifft(Hk);
figure 
n = linspace(0,3.8,Ny)
plot(n,hn,'b')
xlabel('t [s]');
ylabel('h_{new}');
title('h_{new}');
legend('h_{new}');
xlim ([0,3.8]);

%----------------------task 2.5------------------------
yk = fft(y);
yzk = fft(y_z);
Y_new = yk-yzk
xk_new = Y_new.*Hk;
x_rec = ifft(xk_new);
figure 
plot(n,y,'b')
hold on
plot(n,x_rec,'r')
xlabel('t [s]');
ylabel('x_{new}, y');
title('Signals');
legend('y','x_{new}');
xlim ([0,3.8]);

%----------------------task 2.6------------------------

x = 100*sin(200n)
soundsc(x_rec,44100);
