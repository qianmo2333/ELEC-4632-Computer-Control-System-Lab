% Lab04
load('SysIdenData_1.mat'); 
V_min = 2.2;
V_max = 2.8;
u_offset = (V_max + V_min)/2;
t_cutoff = 146/0.75;
t_cutoff = round(t_cutoff); % 将 t_cutoff 四舍五入为整数
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
h = t(2)-t(1);
numerator = [b1 b2]; 
denominator = [1 a1 a2]; 
Gz = tf(numerator, denominator, h);% Eq1

% state space
G = [0 1; -a2 -a1];  % matrix G
H = [0; 1];  % matrix H
C = [b2 b1];  % matrix C
D = 0;  % matrix D
sys_ss = ss(G, H, C, D, h);

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

