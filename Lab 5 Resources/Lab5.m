%1
clear all;
clc;
% Step 1
load('SysIdenData001.mat'); 
V_min = 2.2;
V_max = 2.7;
u_offset = (V_max + V_min)/2;
t_cutoff = 138/0.75;
t = LogData.time(t_cutoff:end)-LogData.time(t_cutoff);
y_act = LogData.signals(1).values(t_cutoff:end,2);
y_actm = LogData.signals(1).values(t_cutoff:end,1);
u_act = LogData.signals(2).values(t_cutoff:end,1);

% Step 2
figure;
subplot(2,1,1);
plot(t, y_act, 'b', t, y_actm, 'r');
title('Actual Output Signal');
xlabel('Time (sec)');
ylabel('Water Level (V)');
xlim([0 1200]);
ylim([1 4]);
legend('Noise-Reduced Output', 'Measured Output');
grid on;

subplot(2,1,2);
plot(t, u_act, 'b');
title('Actual Input Signal');
xlabel('Time (sec)');
ylabel('Pump Voltage (V)');
legend('Actual Input');
xlim([0 1200]);
ylim([1 3]);
grid on;

% Step 3
i = 1;
while u_act(i) == u_act(1)
    i = i + 1;
end
% Output offset
u = u_act - u_offset;
% Input offset
y_offset = mean(y_act(1:i-1));
y = y_act - y_offset;

% Step 4
figure;
subplot(2,1,1);
plot(t, y, 'r');
title('Actual Offset-Free Output Signal');
xlabel('Time (sec)');
ylabel('Water Level (V)');
xlim([0 1200]);
ylim([-2 1]);
legend('Actual Output');
grid on;

subplot(2,1,2);
plot(t, u, 'b');
title('Actual Offset-Free Input Signal');
xlabel('Time (sec)');
ylabel('Pump Voltage (V)');
xlim([0 1200]);
ylim([-0.5 0.5]);
legend('Actual Input');
grid on;

% Part 2 step a
N = floor(length(y) / 2); % the first half of the offset-free input-output data
k_start = 3;
Y = y(k_start:N);
Phi = [y(k_start-1:N-1), y(k_start-2:N-2), u(k_start-1:N-1), u(k_start-2:N-2)];

% Part 2 step b
theta = inv((Phi' * Phi)) * (Phi' * Y);
a1 = -theta(1);  % a1
a2 = -theta(2);  % a2
b1 = theta(3);  % b1
b2 = theta(4);  % b2

% Part 2 step c
% transfer function
Ts = t(2)-t(1);
numerator = [b1 b2]; 
denominator = [1 a1 a2]; 
Gz = tf(numerator, denominator, Ts);% Eq1

% state space
G = [0 1; -a2 -a1];  % matrix G
H = [0; 1];  % matrix H
C = [b2 b1];  % matrix C
D = 0;  % matrix D
sys_ss = ss(G, H, C, D, Ts);

% Part3 Step a
t_half = t(N+1:end);
y_half = y(N+1:end);
t_half_shifted = t_half - t_half(1);
simulated_output = filter(numerator, denominator, u(N+1:end));

% Step b
figure;
subplot(2,1,1);
plot(t_half_shifted, y_half(),'r', t_half_shifted, simulated_output, 'b--');
title('Offset-Free Model Verification (2nd Half)');
xlabel('Time (sec)');
ylabel('Water Level (V)');
xlim([0 600]);
ylim([-2 2]);
legend('Actual Output', 'Simulated Output');
grid on;


simulated_output2 = filter(numerator, denominator, u(k_start:end));
t_simulated = t(k_start:end);

subplot(2,1,2);
plot(t_simulated, y(k_start:end), 'r', t_simulated, simulated_output2, 'b--');
title('Offset-Free Model Verification (Entire)');
xlabel('Time (sec)');
ylabel('Water Level (V)');
xlim([0 1200]);
ylim([-2 2]);
legend('Actual Output', 'Simulated Output');
grid on;



%%
%2
i=1;
while u_act(i)==u_act(i+1)
    i = i + 1;
end
y_offset=mean(y_act(1:i));
y=y_act-y_offset;
u_offset=u_act(1);
u=u_act-u_offset;
half=floor(length(y)/2);
Y=y(10:half);
Phi=[y(9:half-1) y(8:half-2) u(9:half-1) u(8:half-2)];
theta=((transpose(Phi)*Phi)^(-1)*transpose(Phi)*Y);
a1=-theta(1);
a2=-theta(2);
b1=theta(3);
b2=theta(4);
num=[b1 b2];
den=[1 a1 a2];
sys_tf=tf(num,den,Ts);
G=[0 1;-a2 -a1];
H=[0;1];
C=[b2 b1];
D=0;
sys_ss=ss(G,H,C,D,Ts);
G_obs=G';
H_obs=C';
C_obs=H';
D_obs=D';
% 1a
x0=[0;0.3];
y0=C_obs*x0;
display(y0);
% 1b
L_db=acker(G_obs,H_obs,[0 0]);
L_ndb=acker(G_obs,H_obs,[0.4 0.9]);
% 1c
sys_db_1=ss((G_obs-H_obs*L_db),H_obs,C_obs,D_obs,Ts);
sys_ndb_1=ss((G_obs-H_obs*L_ndb),H_obs,C_obs,D_obs,Ts);
t_initial=0:Ts:50;
[Y1, T1, X1]=initial(sys_db_1,x0,t_initial);
[Y2, T2, X2]=initial(sys_ndb_1,x0,t_initial);
U1_dp=-L_db*X1';
U1_ndp=-L_ndb*X2';

%%
%2
y_ref=[0 0.7 -0.2 0.5 0];
L_ndb_2=acker(G_obs,H_obs,[0.92 0.92]);
sys_ndb_2=ss((G_obs-H_obs*L_ndb_2),H_obs,C_obs,D_obs,Ts);
DCgain_ndb=dcgain(sys_ndb_2);%DC gain
Gcl_ndb=inv(DCgain_ndb);

% %%
Kp=0.56;
Ki=0.029;
load('PIDControlData010.mat')
sim_out=sim('sim5.slx');
t_sim=sim_out.ScopeData1.time;
yref_sim = sim_out.ScopeData1.signals(1).values;
yreal_sim = sim_out.ScopeData1.signals(3).values;
ureal_sim = sim_out.ScopeData1.signals(2).values;
y_sim=yreal_sim+y_offset;
u_sim=ureal_sim+u_offset;

treal = ScopeData1.time;
yref = ScopeData1.signals(1).values(:,1);
yreal = ScopeData1.signals(1).values(:,2);
ureal = ScopeData1.signals(2).values;

figure(3);
subplot(2,1,1)
plot(treal,yref,'g');
hold on;
plot(t_sim,y_sim,'b');
hold on;
plot(treal,yreal,'r');
% hold on;
% plot(treal,,'b');
hold off;
title({'PID Control Results','Output Signal'});
xlim([0,600]);
ylim([-1,6]);
xlabel({'Time(sec)';'(a)'});
ylabel({' Water Level(V)'});
grid on;
legend('Reference Output','Simulated Output','Actual Output');

subplot(2,1,2)
plot(treal,ureal,'r');
hold on;
plot(t_sim,u_sim,'b');
title('Control Input signal');
xlim([0,600]);
ylim([0,4]);
yline(3, '--', 'Vmax = 3','LabelHorizontalAlignment','left');
yline(1.9, '--', 'Vmin=1.9', 'LabelHorizontalAlignment', 'left');
xlabel({'Time(sec)';'(b)'});
ylabel({'Pump Voltage(V)'});
grid on;
legend('Simulated Control Input','Actual Control Input');