clc
clear all
% Q1
% ---------1.1-----------
[v_m,fs] = audioread('in-the-air.wav');
v_m=v_m(:,1);
Ts=1/fs;
N=length(v_m);
t=0:Ts:(N-1)*Ts;
f=linspace(-fs/2,fs/2,N);
V_m=fftshift(fft(v_m))/sqrt(N);

figure();
subplot(2,1,1);
plot(t,v_m);
xlabel('t');
ylabel('vm(t)');
title('vm(t) Signal');
grid on;
subplot(2,1,2);
plot(f,V_m);
xlabel('f');
ylabel('Vm(f)');
title('Vm(f) FT');
grid on;

% ---------1.2-----------
f_c=15*10^3;
K_am=0.02;
v_am = ammod(v_m,f_c,fs,0,K_am);
V_Am = fftshift(fft(v_am))/sqrt(N);

figure();
plot(f,V_Am);
xlabel('f');
ylabel('Vm(f)');
title('Vm(f) Modulation Signal');
grid on;
%sound(v_am,fs);
Bw=obw(V_m,fs);

% ---------1.3-----------
z=(0.02)*randn(1,N)';
x_r=v_am+z;
X_r=fftshift(fft(x_r))/sqrt(N);

figure();
plot(f,X_r);
xlabel('f');
ylabel('Xr(f)');
title('Xr(f) Modulation Signal With Noise');
grid on;

figure();
plot(f,x_r);
xlabel('f');
ylabel('xr(t)');
title('xr(t) Signal With Noise');
grid on;


% ---------1.4-----------
x_l=bandpass(x_r,[f_c-5000,f_c+5000],fs);
X_l=fftshift(fft(x_l))/sqrt(N);

figure();
plot(f,X_l);
xlabel('f');
ylabel('X_l(f)');
title('X_l(f) signal');
grid on;

figure();
plot(f,x_l);
xlabel('t');
ylabel('X_l(t)');
title('x_l(t) signal');
grid on;

x_d=amdemod(x_l,f_c,fs,0,K_am);
figure();
plot(t,x_d,'r');
hold on;
plot(t,v_m,'b');
xlabel('t');
title('X_d and V_m Signals');
legend('x_d(t)','v_m(t)');
grid on;
%sound(x_d,fs);

x_d=lowpass(x_d,9000,fs);
X_d=fftshift(fft(x_d))/sqrt(N);
figure();
plot(f,X_d,'r');
hold on;
plot(f,V_m,'b');
xlabel('f(Hz)');
title('X_d and V_m FT Signals');
legend('X_d(f)','V_m(f)');
corr1_4=xcorr(x_d, v_m, 0, 'coeff');

% ---------1.5.1-----------
% ---------1.3-----------
z=(0.1)*randn(1,N)';
x_r=v_am+z;
X_r=fftshift(fft(x_r))/sqrt(N);

figure();
plot(f,X_r);
xlabel('f');
ylabel('Xr(f)');
title('Xr(f) Modulation Signal With Noise');
grid on;

figure();
plot(f,x_r);
xlabel('t');
ylabel('xr(t)');
title('xr(t) Signal With Noise');
grid on;

% ---------1.4-----------
x_l=bandpass(x_r,[f_c-5000,f_c+5000],fs);
X_l=fftshift(fft(x_l))/sqrt(N);

figure();
plot(f,X_l);
xlabel('f');
ylabel('X_l(f)');
title('X_l(f) signal');
grid on;

figure();
plot(f,x_l);
xlabel('t');
ylabel('x_l(t)');
title('x_l(t) signal');
grid on;

x_d=amdemod(x_l,f_c,fs,0,K_am);
figure();
plot(t,x_d,'r');
hold on;
plot(t,v_m,'b');
xlabel('t');
title('X_d and V_m Signals');
legend('x_d(t)','v_m(t)');
grid on;
%sound(x_d,fs);

x_d=lowpass(x_d,9000,fs);
X_d=fftshift(fft(x_d))/sqrt(N);
figure();
plot(f,X_d,'r');
hold on;
plot(f,V_m,'b');
xlabel('f(Hz)');
title('X_d and V_m FT Signals');
legend('X_d(f)','V_m(f)');
corr1_5_1=xcorr(x_d, v_m, 0, 'coeff');


% ---------1.5.2-----------
delta_f_d = 10^4;
v_fm = fmmod(v_m,f_c,fs,delta_f_d);
V_fm = fftshift(fft(v_fm))/sqrt(N);

% ---------1.3-----------
z=(0.02)*randn(1,N)';
x_r=v_fm+z;
X_r=fftshift(fft(x_r))/sqrt(N);

figure();
plot(f,X_r);
xlabel('f');
ylabel('Xr(f)');
title('Xr(f) Modulation Signal With Noise');
grid on;

figure();
plot(f,x_r);
xlabel('t');
ylabel('xr(t)');
title('xr(t) Signal With Noise');
grid on;

% ---------1.4-----------
x_l=bandpass(x_r,[f_c-5000,f_c+5000],fs);
X_l=fftshift(fft(x_l))/sqrt(N);

figure();
plot(f,X_l);
xlabel('f');
ylabel('X_l(f)');
title('X_l(f) signal');
grid on;

figure();
plot(f,x_l);
xlabel('t');
ylabel('x_l(t)');
title('x_l(f) signal');
grid on;

x_d=fmdemod(x_l,f_c,fs,delta_f_d);
figure();
plot(t,x_d,'r');
hold on;
plot(t,v_m,'b');
xlabel('t');
title('X_d and V_m Signals');
legend('x_d(t)','v_m(t)');
grid on;
%sound(x_d,fs);

x_d=lowpass(x_d,9000,fs);
X_d=fftshift(fft(x_d))/sqrt(N);
figure();
plot(f,X_d,'r');
hold on;
plot(f,V_m,'b');
xlabel('f(Hz)');
title('X_d and V_m FT Signals');
legend('X_d(f)','V_m(f)');
corr1_5_2_1=xcorr(x_d, v_m, 0, 'coeff');

% ---------1.5.1-----------
% ---------1.3-----------
z=(0.1)*randn(1,N)';
x_r=v_fm+z;
X_r=fftshift(fft(x_r))/sqrt(N);

figure();
plot(f,X_r);
xlabel('f');
ylabel('Xr(f)');
title('Xr(f) Modulation Signal With Noise');
grid on;

figure();
plot(f,x_r);
xlabel('t');
ylabel('xr(t)');
title('xr(t) Signal With Noise');
grid on;

% ---------1.4-----------
x_l=bandpass(x_r,[f_c-5000,f_c+5000],fs);
X_l=fftshift(fft(x_l))/sqrt(N);

figure();
plot(f,X_l);
xlabel('f');
ylabel('X_l(f)');
title('X_l(f) signal');
grid on;

figure();
plot(f,x_l);
xlabel('t');
ylabel('x_l(t)');
title('x_l(f) signal');
grid on;

x_d=fmdemod(x_l,f_c,fs,delta_f_d);
figure();
plot(t,x_d,'r');
hold on;
plot(t,v_m,'b');
xlabel('t');
title('X_d and V_m Signals');
legend('x_d(t)','v_m(t)');
grid on;
%sound(x_d,fs);

x_d=lowpass(x_d,9000,fs);
X_d=fftshift(fft(x_d))/sqrt(N);
figure();
plot(f,X_d,'r');
hold on;
plot(f,V_m,'b');
xlabel('f(Hz)');
title('X_d and V_m FT Signals');
legend('X_d(f)','V_m(f)');
corr1_5_2_2=xcorr(x_d, v_m, 0, 'coeff');

