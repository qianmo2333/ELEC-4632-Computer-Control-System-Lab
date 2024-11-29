%1
clear all;
clc;
% Vmin=2;
% Vmax=3;
load('SysIdenData_1.mat');
a=floor(650/0.75);
t=LogData.time(a:end)-LogData.time(a);
y_act=LogData.signals(1).values(a:end,2);
y_actm=LogData.signals(1).values(a:end,1);
u_act=LogData.signals(2).values(a:end,1);
Ts=t(2)-t(1);

figure(1);
subplot(2,1,1);
plot(t,y_act,'b',t,y_actm,'r');
title('Actual Output Signal');
legend('Noise-Reduced Output','Measured Output');
xlim([0 700]);
ylim([1 4]);
xlabel('Time(sec) (a)');
ylabel('Water Level(V)');
grid on;

subplot(2,1,2);
plot(t,u_act,'b');
title('Actual Input Signal');
legend('Actual Input');
xlim([0 900]);
ylim([1 3]);
xlabel('Time(sec) (b)');
ylabel('Pump Voltage(V)');
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
%%
%3
k1=acker(G,H,[0 0]);
K=k1';
display(K);
L_ndb_3=acker(G_obs,H_obs,[0.9 0.9]);
ss_ndb_3=ss((G_obs-H_obs*L_ndb_3),H_obs,C_obs,D_obs,Ts);
DCgain_ndb_3=dcgain(ss_ndb_3);%DC gain
Gcl_ndb_3=inv(DCgain_ndb_3);
% simq3=sim('part3.slx');
% t_sim3=simq3.Scope3.time(:,1);
% 
% figure(2);
% subplot(3,1,1)
% plot(t_sim3,simq3.Scope3.signals(1).values(:,1),'g');
% hold on;
% plot(t_sim3,simq3.Scope3.signals(3).values(:,1),'r');
% hold off;
% title({'Set-Point Control Results: Simulation','Output Signal'});
% xlim([0,600]);
% ylim([-1,1]);
% xlabel({'Time(sec)';'(a)'});
% ylabel({'Offset-Free';' Water Level(V)'});
% grid on;
% legend('Simulated Output','Reference Output');
% 
% subplot(3,1,2)
% plot(t_sim3,simq3.Scope3.signals(2).values(:,1),'b');
% title('Control Input signal');
% xlim([0,600]);
% ylim([-0.75,0.75]);
% yline(0.5, 'g--', 'Umax = 0.5','LabelHorizontalAlignment','left');
% yline(-0.5, 'g--', 'Umin = -0.5', 'LabelHorizontalAlignment', 'left');
% xlabel({'Time(sec)';'(b)'});
% ylabel({'Offset-Free';' Pump Voltage(V)'});
% grid on;
% legend('Simulated Control Input');
% 
% subplot(3,1,3)
% plot(t_sim3,simq3.Scope4.signals.values(:,1),'r');
% hold on;
% stairs(t_sim3,simq3.Scope4.signals.values(:,2),'b');
% hold off;
% title('State Estimation Error');
% xlim([0,3]);
% ylim([0,0.4]);
% xlabel({'Time(sec)';'(c)'});
% ylabel('Estimation Error');
% grid on;
% legend('x1(k)-xˆ1(k)','x2(k)-xˆ2(k)');

%3a
L=L_ndb_3;
Gcl_1=Gcl_ndb_3;
% simq4=sim('WaterTankSysControl2024.slx');

%3c
load('SFControlData08.mat')
treal = ScopeData1.time; 
yref = ScopeData1.signals(1).values(:,1); 
yreal = ScopeData1.signals(1).values(:,2); 
ureal = ScopeData1.signals(2).values;
x0=[0;0];
L_ndb_301=acker(G_obs,H_obs,[0.9 0.9]);
L=L_ndb_301;

figure(3);
subplot(2,1,1)
plot(treal,yref,'g');
hold on;
plot(treal,yreal,'r');
% hold on;
% plot(treal,,'b');
hold off;
title({'Output Feedback Control Results','Output Signal'});
xlim([0,600]);
ylim([-1,6]);
xlabel({'Time(sec)';'(a)'});
ylabel({' Water Level(V)'});
grid on;
legend('Actual Output','Reference Output');
% legend('Simulated Output','Actual Output','Reference Output');

subplot(2,1,2)
plot(treal,ureal,'r');
% plot(treal,ureal,'b');
title('Control Input signal');
xlim([0,600]);
ylim([0,4]);
yline(3, 'g--', 'Vmax = 3','LabelHorizontalAlignment','left');
yline(1.5, 'g--', 'Vmin', 'LabelHorizontalAlignment', 'left');
xlabel({'Time(sec)';'(b)'});
ylabel({'Pump Voltage(V)'});
grid on;
legend('Actual Control Input');
% legend('Simulated Control Input','Actual Control Input');