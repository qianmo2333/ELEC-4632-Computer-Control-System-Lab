% Step 1: 加载数据
load('Lab03_Q1_Data.mat');  % 加载文件，假设文件中有 DB_uk, DB_yk, nDB_uk, nDB_yk

% Step 2: 提取时间和信号值
% 提取 deadbeat 控制的时间数据和输出响应值
t_db = DB_yk.time;                   % 时间数据
yk_db_values = DB_yk.signals.values; % Deadbeat 输出响应值

% 提取 deadbeat 控制的控制输入值
t_db_uk = DB_uk.time;                % 时间数据
uk_db_values = DB_uk.signals.values; % Deadbeat 控制输入值

% 提取 non-deadbeat 控制的时间数据和输出响应值
t_ndb = nDB_yk.time;                 % 时间数据
yk_ndb_values = nDB_yk.signals.values; % Non-deadbeat 输出响应值

% 提取 non-deadbeat 控制的控制输入值
t_ndb_uk = nDB_uk.time;              % 时间数据
uk_ndb_values = nDB_uk.signals.values; % Non-deadbeat 控制输入值

% Step 3: 绘制响应图像 y(k)
figure;

% (a) 绘制 Offset-Free Water Level (Output Response)
subplot(2, 1, 1); % 创建上下排列的第一个图
xticks(0:10:50); % 设置 x 轴刻度为 0, 10, 20, 30, 40, 50
yticks(-1:1:1);
hold on;
stairs(t_db, yk_db_values, 'r', 'LineWidth', 1.5); % 使用 stairs 保持 deadbeat 的响应阶梯状
stairs(t_ndb, yk_ndb_values, 'b', 'LineWidth', 1.5); % 使用 stairs 保持 non-deadbeat 的响应阶梯状
hold off;
title('Regulation Response by State Feedback y(k)');
xlabel('Time (sec)');
ylabel('Offset-Free Water Level (V)');
legend('Deadbeat Response', 'Non-Deadbeat Response', 'Location', 'best');
grid on;
xlim([0, 50]); % 根据需要调整x轴范围
ylim([-1, 1]); % 根据需要调整y轴范围

% Step 4: 绘制控制输入图像 u(k)
% (b) 绘制 Offset-Free Pump Voltage (Control Input)
subplot(2, 1, 2); % 创建上下排列的第二个图
xticks(0:10:50); % 设置 x 轴刻度为 0, 10, 20, 30, 40, 50
yticks(-1:1:1);
hold on;
stairs(t_db_uk, uk_db_values, 'r', 'LineWidth', 1.5); % 使用 stairs 保持 deadbeat 控制的输入阶梯状
stairs(t_ndb_uk, uk_ndb_values, 'b', 'LineWidth', 1.5); % 使用 stairs 保持 non-deadbeat 控制的输入阶梯状
% 添加控制输入限制线
yline(0.5, 'g--', 'u_{max} = 0.5', 'LineWidth', 1.2); % 绿色虚线表示 u_max = 0.5
yline(-0.5, 'g--', 'u_{min} = -0.5', 'LineWidth', 1.2); % 绿色虚线表示 u_min = -0.5
hold off;
title('Offset-Free Control Input u(k)');
xlabel('Time (sec)');
ylabel('Offset-Free Pump Voltage (V)');
legend('Deadbeat Control Input', 'Non-Deadbeat Control Input', 'Location', 'best');
grid on;
xlim([0, 50]); % 根据需要调整x轴范围
ylim([-1, 1]); % 根据需要调整y轴范围

% Display the figure
figure(gcf);

