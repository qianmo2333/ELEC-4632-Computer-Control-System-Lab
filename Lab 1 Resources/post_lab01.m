
% Step 1
load('SysIdenData_StudentVersion.mat'); 
t = LogData.time;
y_act = LogData.signals(1).values(:,2);
y_actm = LogData.signals(1).values(:,1);
u_act = LogData.signals(2).values;

i = 1;
while u_act(i) == u_act(1)
    i = i + 1;
end
% Output offset
u_offset = u_act(1);
u = u_act - u_offset;
% Input offset
y_offset = mean(y_act(1:i-1));
y = y_act - y_offset;

% Step 2 second order model
N = floor(length(y) / 2); % the first half of the offset-free input-output data
k_start = 3;
Y = y(k_start:N);
Phi = [y(k_start-1:N-1), y(k_start-2:N-2), u(k_start-1:N-1), u(k_start-2:N-2)];

theta = inv((Phi' * Phi)) * (Phi' * Y);
a1 = -theta(1);  % a1
a2 = -theta(2);  % a2
b1 = theta(3);  % b1
b2 = theta(4);  % b2

% transfer function
h = t(2)-t(1);
numerator = [b1 b2];
denominator = [1 a1 a2]; 
Gz = tf(numerator, denominator, h);% Eq1

% state space
G = [0 1; -a2 -a1];  % martix G
H = [0; 1];  % martix H
C = [b2 b1];  % martix C
D = 0;  % martix D
sys_ss = ss(G, H, C, D, h);

% Step 3 first order model
N = floor(length(y) / 2); % the first half of the offset-free input-output data
k_start_2 = 3;
Y_2 = y(k_start:N);
Phi_2 = [y(k_start-1:N-1), u(k_start-1:N-1)];

theta_2 = inv((Phi_2' * Phi_2)) * (Phi_2' * Y_2);
a1_2 = -theta_2(1);  % a1
b1_2 = theta_2(2);  % b1

% transfer function
numerator_2 = b1_2;  
denominator_2 = [1 a1_2];
Gz_2 = tf(numerator_2, denominator_2, h);% Eq1

% state space
G_2 = -a1_2;  % 矩阵 G
H_2 = 1;  % 矩阵 H
C_2 = b1_2;  % 矩阵 C
D_2 = 0;  % 矩阵 D
sys_ss_2 = ss(G_2, H_2, C_2, D_2, h);

% Simulating both models
simulated_output_1st = filter(numerator, denominator, u(k_start:end));
simulated_output_2nd = filter(numerator_2, denominator_2, u(k_start:end));
t_simulated = t(k_start:end);

% First Order MSE
MSE_1st = mean((y(k_start:end) - simulated_output_1st).^2);

% Second Order MSE
MSE_2nd = mean((y(k_start:end) - simulated_output_2nd).^2);
mse_str_1 = sprintf('%.8f', MSE_1st);
mse_str_2 = sprintf('%.8f', MSE_2nd);

figure;
subplot(1,1,1);
plot(t_simulated, y(k_start:end), 'r', t_simulated, simulated_output_1st, 'g--',t_simulated, simulated_output_2nd, 'b--');
title('Comparison of Different Offset-Free Order Models','FontWeight', 'bold');
xlabel('Time (sec)');
ylabel('Water Level (V)');
xlim([0 700]);
ylim([-1.5 1]);
legend('Actual Output', '1st Order Model Response', '2nd Order Model Response');
grid on;

text(10, 0.56, ['MSE1 = ', num2str(mse_str_1)], 'FontSize', 9.5);
text(10, 0.44, ['MSE2 = ', num2str(mse_str_2)], 'FontSize', 9.5);