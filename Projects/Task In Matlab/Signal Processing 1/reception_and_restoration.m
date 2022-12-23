clc;
clear all;
close all;
%----------------------task 1.1------------------------
t = 0.2:1/100:3;
wm = 3*pi;
x = 4./(wm*pi*t.^2).*(sin(wm*t)).^2.*(cos(wm*t)).*(sin(2*wm*t));
plot(t,abs(x))
ylabel ("x(t)");
xlabel("t(sec)");
title("x(t)")
legend("x(t)")


%----------------------task 1.2------------------------
syms w
Xw=(1)/(i)*(triangularPulse(wm,3*wm,5*wm,w)+triangularPulse(-wm,wm,3*wm,w)-triangularPulse(-3*wm,-wm,wm,w)-triangularPulse(-5*wm,-3*wm,-wm,w));
figure;
fplot(abs(Xw),[-17*pi,17*pi])
ylabel ("X(w)");
xlabel("w(rad/sec)");
title("task 1.b")
legend("x(w)")


%----------------------task 1.3------------------------
tn = 0.2:1/15:3;
xn = 4./(wm*pi*tn.^2).*(sin(wm*tn)).^2.*(cos(wm*tn)).*(sin(2*wm*tn));
figure;
stairs(tn,xn)
hold on
plot(t,x)
xlabel("t(sec)");
ylabel ("v");
title("task 1.c");
legend("xn(t)","x(t)");
hold off



%----------------------task 1.4------------------------
syms k w
Ts=1/15;
ws=(2*pi)/Ts;
xzoh=symsum((pi)/(1i)*(triangularPulse(wm-k*ws,3*wm-k*ws,5*wm-k*ws,w)-triangularPulse(-3*wm-k*ws,-1*wm-k*ws,wm-k*ws,w)+triangularPulse(-1*wm-k*ws,wm-k*ws,3*wm-k*ws,w)-triangularPulse(-5*wm-k*ws,-3*wm-k*ws,-1*wm-k*ws,w))*sinc(w/ws)*exp(-1i*w*Ts/2),k,-1,1);
figure;
fplot(abs(xzoh),[-17*pi,17*pi]);
xlabel("w (rad/sec)");
ylabel ("v");
title("task 1.d");
legend("|Xzoh(w)|");





%----------------------task 1.5------------------------
wrange = -17*pi:0.01:17*pi;
Xw = 1/(i)*(triangularPulse(wm,3*wm,5*wm,wrange)-triangularPulse(-3*wm,-1*wm,wm,wrange)+triangularPulse(-1*wm,wm,3*wm,wrange)-triangularPulse(-5*wm,-3*wm,-1*wm,wrange));
xzohw = Xw - triangularPulse(5*wm,9*wm,wrange) + triangularPulse(-9*wm,-5*wm,wrange); 
xzohw = xzohw.*sinc((wrange/ws)).*exp(-i*(Ts/2)*wrange);
H = (exp(i*pi/ws*wrange))./(sinc(wrange/ws)).*rectpuls(wrange/ws);   
Xrecw = xzohw.*H;                                        
x_rec = zeros(1,length(t));
for k = 1:length(t)
    x_rec(k)= (1/(2*pi))*trapz(wrange,Xrecw.*exp(i.*wrange*t(k))); 
end
figure();
plot(t,x,'b','Linewidth', 1.5);
hold on
plot(t,x_rec,'--r','Linewidth', 1.5);
title("task 1.e");
xlabel('t [sec]');
ylabel('V');
legend('x(t)','x_{rec}(t))');
grid on
hold off

%----------------------task 1.6------------------------
ws = 9*wm;
H = (exp(i*pi/ws*wrange))./(sinc(wrange/ws)).*rectpuls(wrange/ws);  
Xrecw = xzohw.*H;                                        
x_rec = zeros(1,length(t));
for k = 1:length(t)
    x_rec(k)= (1/(2*pi))*trapz(wrange,Xrecw.*exp(i.*wrange*t(k))); 
end
figure();
plot(t,x,'b','Linewidth', 1.5);
hold on
plot(t,x_rec,'r');
title("task 1.f");
xlabel('t [sec]');
ylabel('V');
legend('x(t)','x_{rec}(t))');
grid on
hold off

%----------------------task 2.1------------------------
wa=7*pi;
wb=4*pi;
t=0:1/100:2;
Ts=2/15;      %Ts = 2/14 and we need a little smaller to get all the points in the original signal
xt=5*cos(wa*t)-3*sin(wb*t);    
n=0:1:14;
n=n*Ts;
xs=5*cos(wa*n)-3*sin(wb*n);    
figure;
plot(t,xt,'k');     
hold on
plot(n,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.a');
hold off

%----------------------task 2.2------------------------
xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
f = [exp(-i*wa*n(1)) exp(i*wa*n(1)) exp(-i*wb*n(1)) exp(i*wb*n(1)) 
    ; exp(-i*wa*n(2)) exp(i*wa*n(2)) exp(-i*wb*n(2)) exp(i*wb*n(2)) 
    ; exp(-i*wa*n(3)) exp(i*wa*n(3)) exp(-i*wb*n(3)) exp(i*wb*n(3)) 
    ; exp(-i*wa*n(4)) exp(i*wa*n(4)) exp(-i*wb*n(4)) exp(i*wb*n(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;
condO = cond (f);

%----------------------task 2.3------------------------
t=0:1/100:2;
wa=7*pi;
wb=4*pi;
Ts=2/15;
xt=5*cos(wa*t)-3*sin(wb*t);
evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.c');
grid on
hold off

%----------------------task 2.4------------------------
randt = 2.*rand(15,1);
wa=7*pi;
wb=4*pi;
t=0:1/100:2;
Ts=2/15;      %Ts = 2/14 and we need a little smaller to get all the points in the original signal
xt=5*cos(wa*t)-3*sin(wb*t);   
xs=5*cos(wa*randt)-3*sin(wb*randt);
figure;
plot(t,xt,'k');     
hold on
plot(randt,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.d.a');
hold off

xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
f = [exp(-i*wa*randt(1)) exp(i*wa*randt(1)) exp(-i*wb*randt(1)) exp(i*wb*randt(1)) 
    ; exp(-i*wa*randt(2)) exp(i*wa*randt(2)) exp(-i*wb*randt(2)) exp(i*wb*randt(2)) 
    ; exp(-i*wa*randt(3)) exp(i*wa*randt(3)) exp(-i*wb*randt(3)) exp(i*wb*randt(3)) 
    ; exp(-i*wa*randt(4)) exp(i*wa*randt(4)) exp(-i*wb*randt(4)) exp(i*wb*randt(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;

evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.d.c');
grid on
hold off


%----------------------task 2.5.a------------------------
wa=7*pi;
wb=4*pi;
t=0:1/100:2;
Ts=2/15;      %Ts = 2/14 and we need a little smaller to get all the points in the original signal
xt=5*cos(wa*t)-3*sin(wb*t);    
n=0:1:14;
n=n*Ts;
xs=5*cos(wa*n)-3*sin(wb*n);    
figure;
plot(t,xt,'k');     
hold on
plot(n,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.e.1');
hold off
xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
%----------------------task 2.5.b------------------------
for k = 1:15
    n(k)= n(k)+0.01*rand(1);
end
f = [exp(-i*wa*n(1)) exp(i*wa*n(1)) exp(-i*wb*n(1)) exp(i*wb*n(1)) 
    ; exp(-i*wa*n(2)) exp(i*wa*n(2)) exp(-i*wb*n(2)) exp(i*wb*n(2)) 
    ; exp(-i*wa*n(3)) exp(i*wa*n(3)) exp(-i*wb*n(3)) exp(i*wb*n(3)) 
    ; exp(-i*wa*n(4)) exp(i*wa*n(4)) exp(-i*wb*n(4)) exp(i*wb*n(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;
cond1 = cond(f);

%----------------------task 2.5.c------------------------
evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.e.3');
grid on
hold off

%----------------------task 2.5.d------------------------
randt1 = 2.*rand(15,1);
xs=5*cos(wa*randt1)-3*sin(wb*randt1); 
figure;
plot(t,xt,'k');     
hold on
plot(randt1,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.e.4');
hold off
for k = 1:15
    randt(k) = randt1(k)+0.01*rand(1);
end
xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
f = [exp(-i*wa*randt(1)) exp(i*wa*randt(1)) exp(-i*wb*randt(1)) exp(i*wb*randt(1)) 
    ; exp(-i*wa*randt(2)) exp(i*wa*randt(2)) exp(-i*wb*randt(2)) exp(i*wb*randt(2)) 
    ; exp(-i*wa*randt(3)) exp(i*wa*randt(3)) exp(-i*wb*randt(3)) exp(i*wb*randt(3)) 
    ; exp(-i*wa*randt(4)) exp(i*wa*randt(4)) exp(-i*wb*randt(4)) exp(i*wb*randt(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;
cond2 = cond(f);

evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.e.5');
grid on
hold off


%----------------------task 2.6.a------------------------
wa=7*pi;
wb=4*pi;
t=0:1/100:2;
Ts=2/41;      %Ts = 2/14 and we need a little smaller to get all the points in the original signal
xt=5*cos(wa*t)-3*sin(wb*t);    
n=0:1:39;
n=n*Ts;
xs=5*cos(wa*n)-3*sin(wb*n);    
figure;
plot(t,xt,'k');     
hold on
plot(n,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.f.1');
hold off
xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
%----------------------task 2.6.b------------------------
for k = 1:39
    n(k)= n(k)+0.01*rand(1);
end
f = [exp(-i*wa*n(1)) exp(i*wa*n(1)) exp(-i*wb*n(1)) exp(i*wb*n(1)) 
    ; exp(-i*wa*n(2)) exp(i*wa*n(2)) exp(-i*wb*n(2)) exp(i*wb*n(2)) 
    ; exp(-i*wa*n(3)) exp(i*wa*n(3)) exp(-i*wb*n(3)) exp(i*wb*n(3)) 
    ; exp(-i*wa*n(4)) exp(i*wa*n(4)) exp(-i*wb*n(4)) exp(i*wb*n(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;
cond1 = cond(f);

%----------------------task 2.6.c------------------------
evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.f.3');
grid on
hold off

%----------------------task 2.6.d------------------------
randt1 = 2.*rand(40,1);
xs=5*cos(wa*randt1)-3*sin(wb*randt1); 
figure;
plot(t,xt,'k');     
hold on
plot(randt1,xs,'*r');   
legend('x(t)','x[n]');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.f.4');
hold off
for k = 1:39
    randt(k) = randt1(k)+0.01*rand(1);
end
xtcheck = [xs(1) xs(2) xs(3) xs(4)]';
f = [exp(-i*wa*randt(1)) exp(i*wa*randt(1)) exp(-i*wb*randt(1)) exp(i*wb*randt(1)) 
    ; exp(-i*wa*randt(2)) exp(i*wa*randt(2)) exp(-i*wb*randt(2)) exp(i*wb*randt(2)) 
    ; exp(-i*wa*randt(3)) exp(i*wa*randt(3)) exp(-i*wb*randt(3)) exp(i*wb*randt(3)) 
    ; exp(-i*wa*randt(4)) exp(i*wa*randt(4)) exp(-i*wb*randt(4)) exp(i*wb*randt(4))];
fMinus1 = inv(f);
a = fMinus1*xtcheck;
cond2 = cond(f);

evec = [exp(-i.*wa.*t) ;exp(i.*wa.*t) ;exp(i.*wb.*t) ;exp(-i.*wb.*t)];
xtnew = a'*evec;
plot(t,xt,'b');     
hold on
plot(t,xtnew,'--k','LineWidth',1.5)
legend('x(t)','x_{new}(t)');
xlabel('t [sec]'); 
ylabel('x(t) [V]');
title('task 2.f.5');
grid on
hold off


%----------------------task 3.2------------------------
T = 10;
t = 0:1/100:T;
nPi = -20:1:20;
pin = exp(i*2*(pi/T)*t'*nPi);
nPsy = 0:19;
psy = zeros(size(t'*nPsy));
[numRows,numCols] = size(nPsy);
for k = 1:numCols
    psy(:,k) = rectpuls(t-(0.5*nPsy(k)+1/4)*ones(size(t)),1/2);
end
ft = (4*cos(4*(pi/T)*t) + sin(10*(pi/T)*t)).';
gt = (2*sign(sin(6*(pi/T)*t))-4*sign(sin(4*(pi/T)*t))).';
cfPsy = task3a(ft,psy,T);
cgPsy = task3a(gt,psy,T);
cfPi = task3a(ft,pin,T);
cgPi = task3a(gt,pin,T);

%----------------------task 3.3------------------------
fPhi = pin*cfPi;
fPsy = psy*cfPsy;
gPhi = pin*cgPi;
gPsy = psy*cgPsy;
figure()
plot(t,ft,'g','LineWidth',2);
hold on
plot(t,fPhi,'--k','LineWidth',2);
hold on
plot(t,fPsy,'--r');
hold off
legend('ft','f phi','f psy')
xlabel('t[sec]');
ylabel('V [volt]');
title('f(t) and his reconstruction');
figure()
plot(t,gt,'g','LineWidth',2);
hold on
plot(t,gPhi,'k','LineWidth',2);
hold on
plot(t,gPsy,'--r');
hold off
legend('gt','g phi','g psy')
xlabel('t[sec]');
ylabel('V [volt]');
title('g(t) and his reconstruction');



%----------------------task 3.1------------------------
function cn = task3a (vec,A,T)
    [numRows,numCols] = size(A);
    cn = zeros(numCols,1);
    t = linspace(0,T,length(vec));
    for k = 1:numCols
        cn(k) = trapz(t,vec.*conj(A(:,k)))/trapz(t,A(:,k).*conj(A(:,k)));
    end
end


