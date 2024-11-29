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