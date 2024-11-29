% Step1
t = (0:0.1:100)'; % Time column vector

% Step2
y1 = sin(0.02*pi*t)+0.4*rand(size(t))-0.2; % y1
y2 = cos(0.02*pi*t)+0.4*rand(size(t))-0.2; % y2


%Step3
t_new = t(201:end)-t(201); % Cut-off first 20s
y1_new = y1(201:end); %Cut-off sin wave
y2_new = y2(201:end); % Cut-off cos wave


%Step 4
data_new = [t_new y1_new y2_new];  % n×3 matrix


%Step 5
figure;
subplot(2,1,1); %First plot in a 2-row, 1-column layout, 1st fig
plot(t, y1, 'r');
hold on;
plot(t, y2, 'b');
hold on; %blue & red
title('Original Data');
xlabel('Time (sec)');
ylabel('Data');
xlim([0 140]);
ylim([-1.5 1.5]);
grid on;
legend('sin(0.02*pi*t)', 'cos(0.02*pi*t)');




%Step 6
subplot(2,1,2);%Second plot
plot(t_new, y1_new, 'g');
hold on;
plot(t_new, y2_new, 'color', [0.6 0.7 0.8]);
hold on;
title('Cut-off Data');
xlabel('Time (sec)');
ylabel('Data');
xlim([0 140]);
ylim([-1.5 1.5]);
grid on;
legend('sin(0.02*pi*t)', 'cos(0.02*pi*t)');