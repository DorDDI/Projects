clear all
close all
clc

%-------question  1.2-------
E_s = 1;

%-------task  1.2.1-------
s = randsrc(10^5,1);

%-------task  1.2.2-1.2.3-------
s_hat_g = [];
error_vector_g = [];
s_hat_l = [];
error_vector_l = [];
for SNR = -6:6
    error_cnt_g = 0;
    error_cnt_l = 0;
    r_g = transmittion_func(SNR,E_s,s,"Gaussian");
    for i = 1:length(r_g)
        if r_g(i)<0
            s_hat_g(i) = -E_s;
        else
            s_hat_g(i) = E_s;
        end
        if s_hat_g(i) ~=s(i)
            error_cnt_g = error_cnt_g +1;
        end
    end
    error_cnt_g = error_cnt_g/length(s);
    error_vector_g = [error_vector_g error_cnt_g];
    
    r_l = transmittion_func(SNR,E_s,s,"Laplace");
    for i = 1:length(r_l)
        if r_l(i) <0
            s_hat_l(i) = -E_s;
        else 
            s_hat_l(i) = E_s;
        end
        if s_hat_l(i)~= s(i)
            error_cnt_l = error_cnt_l+1;
        end
    end
    error_cnt_l = error_cnt_l/length(s);
    error_vector_l = [error_vector_l error_cnt_l];
end

%-------task  1.2.5-------
figure 
plot (-6:6,error_vector_g);
title('Probability of error for Gaussain noise');
xlabel('SNR [db]');
ylabel('P_e');

%-------task  1.2.6-------
figure
plot (-6:6,error_vector_l);
title('Probability of error for Laplacian noise');
xlabel('SNR [db]');
ylabel('P_e');

%-------task  1.2.7-------
figure
plot(-6:6,error_vector_g);
hold on 
plot(-6:6,error_vector_l);
hold off
title('Probability of error');
legend('Gaussain noise','Laplacian noise')
xlabel('SNR [db]');
ylabel('P_e');


function y  = laprnd(m, n, mu, sigma)
%LAPRND generate i.i.d. laplacian random number drawn from laplacian distribution
%   with mean mu and standard deviation sigma. 
%   mu      : mean
%   sigma   : standard deviation
%   [m, n]  : the dimension of y.
%   Default mu = 0, sigma = 1. 
%   For more information, refer to
%   http://en.wikipedia.org./wiki/Laplace_distribution

%   Author  : Elvis Chen (bee33@sjtu.edu.cn)
%   Date    : 01/19/07

%Check inputs
if nargin < 2
    error('At least two inputs are required');
end

if nargin == 2
    mu = 0; sigma = 1;
end

if nargin == 3
    sigma = 1;
end

% Generate Laplacian noise
u = rand(m, n)-0.5;
b = sigma / sqrt(2);
y = mu - b * sign(u).* log(1- 2* abs(u));
end

function r = transmittion_func(SNR,E,s,distri)
SNR = db2mag(SNR)/2;
if distri =="Gaussian"
    r = s+sqrt(E/(2*SNR))*randn(10^5,1);
elseif distri =="Laplace"
    r = s + laprnd(length(s),1,0,E/(2*SNR));
end
end
