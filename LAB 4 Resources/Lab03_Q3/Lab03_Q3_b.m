% 加载数据
load('Lab3_Q3_VIP.mat');
load('Lab3_Q3_VIP2.mat');

% 提取 yk_3 数据
yk_3 = yk_3.signals.values; % 假设 'values' 是包含数据的子字段
y3_ref = y_ref3.signals.values;  % 同样提取参考信号的数据

% 绘制第一个子图 - 输出信号
subplot(3, 1, 1);
stairs(t_sim, yk_3, 'r'); % 使用 stairs 显示阶梯形状的系统输出信号
hold on;
stairs(t_sim, y3_ref, 'g'); % 使用 stairs 显示阶梯形状的参考信号
hold off;
grid on;
ylim([-1, 1]);
set(gca, 'YTick', [-1 -0.5 0 0.2 0.5 0.7 1]);
xlim([0, 600]);
title({'Set-Point Control Results: Simulation', 'Output Signal'});
legend('Simulated Output', 'Reference Output');
xlabel({'Time (sec)', '(a)'});
ylabel({'Offset-Free', 'Water Level (V)'});


% 提取 uk_3 数据
uk_3 = uk_3.signals.values; % 假设 'values' 是包含数据的子字段

% 绘制第二个子图 - 控制输入信号
subplot(3, 1, 2);
stairs(t_sim, uk_3, 'b'); % 使用 stairs 显示阶梯形状的控制输入信号
hold on;
plot([0, max(t_sim)], [0.5, 0.5], 'g--'); % 绘制上限
plot([0, max(t_sim)], [-0.5, -0.5], 'g--'); % 绘制下限
hold off;
grid on;
ylim([-1, 1]);
xlim([0, 600]);
title('Control Input Signal');
legend('Simulated Control Input');
xlabel({'Time (sec)', '(b)'});
ylabel({'Offset-Free', 'Pump Voltage (V)'});
text(100, 0.6, 'u_{max} = 0.5', 'Color', 'g');
text(100, -0.6, 'u_{min} = -0.5', 'Color', 'g');

% 提取状态估计误差数据
x1_error = State_Error.signals.values(:, 1); % 第一列为 x1 的误差
x2_error = State_Error.signals.values(:, 2); % 第二列为 x2 的误差

% 绘制第三个子图 - 状态估计误差
subplot(3, 1, 3);
stairs(t_sim, x1_error, 'r'); % 使用 stairs 显示阶梯形状的第一个状态误差
hold on;
stairs(t_sim, x2_error, 'b'); % 使用 stairs 显示阶梯形状的第二个状态误差
hold off;
grid on;
xlim([0, 3]); % 确保时间范围覆盖整个仿真时间
ylim([0, 0.4]); % 调整 y 轴范围
title('State Estimation Error');

% 更新图例，使用 LaTeX 解释器来处理上标符号
legend({'$x_1(k) - \hat{x}_1(k)$', '$x_2(k) - \hat{x}_2(k)$'}, ...
    'Interpreter', 'latex', 'Location', 'best');

xlabel({'Time (sec)', '(c)'});
ylabel('Estimation Error');

