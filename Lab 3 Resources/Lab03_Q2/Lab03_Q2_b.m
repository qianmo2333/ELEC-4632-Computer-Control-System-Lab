% 加载数据
load('Lab03_Q2_VIP.mat');
load('Lab03_Q2_VIP2.mat');

% 检查并提取信号数据
if isstruct(yk)
    yk = yk.signals.values;  % 提取实际信号数据
end

if isstruct(y_ref)
    y_ref = y_ref.signals.values;  % 提取参考信号数据
end

if isstruct(uk)
    uk = uk.signals.values;  % 提取控制输入信号数据
end

% 检查数据长度是否一致
disp(['t_sim length: ', num2str(length(t_sim))]);
disp(['yk length: ', num2str(length(yk))]);
disp(['y_ref length: ', num2str(length(y_ref))]);
disp(['uk length: ', num2str(length(uk))]);

% 确保 t_sim 和 yk, y_ref, uk 长度一致，进行插值或截断
if length(t_sim) > 1 && length(t_sim) ~= length(yk)
    yk = interp1(linspace(0, max(t_sim), length(yk)), double(yk), t_sim);
end

if length(t_sim) > 1 && length(t_sim) ~= length(y_ref)
    y_ref = interp1(linspace(0, max(t_sim), length(y_ref)), double(y_ref), t_sim);
end

if length(t_sim) > 1 && length(t_sim) ~= length(uk)
    uk = interp1(linspace(0, max(t_sim), length(uk)), double(uk), t_sim);
end

% 检查并处理 NaN 值
yk = fillmissing(yk, 'previous');
y_ref = fillmissing(y_ref, 'previous');
uk = fillmissing(uk, 'previous');

% 设置图像
figure();

% 绘制第一个子图 - 输出信号
subplot(2, 1, 1);
plot(t_sim, yk, 'r', 'LineWidth', 1.5); % 绘制系统输出信号
hold on;
plot(t_sim, y_ref, 'g', 'LineWidth', 1.5); % 绘制参考信号
hold off;
grid on;
ylim([-1, 1]);
set(gca, 'YTick', [-1 -0.5 0 0.2 0.5 0.7 1]);
xlim([0, 600]);
title({'Set-Point Control Results: Simulation', 'Output Signal'});
legend('Simulated Output', 'Reference Output');
xlabel({'Time (sec)', '(a)'});
ylabel({'Offset-Free', 'Water Level (V)'});

% 绘制第二个子图 - 控制输入信号
subplot(2, 1, 2);
plot(t_sim, uk, 'b', 'LineWidth', 1.5); % 绘制控制输入信号
hold on;
plot([0, max(t_sim)], [0.5, 0.5], 'g--', 'LineWidth', 1.5); % 绘制上限
plot([0, max(t_sim)], [-0.5, -0.5], 'g--', 'LineWidth', 1.5); % 绘制下限
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
