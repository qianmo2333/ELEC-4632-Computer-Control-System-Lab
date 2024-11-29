% Pre_Lab
% 加载数据
load('SysIdenData_1.mat'); 
% 截取数据，去除前132/0.75秒的内容，并重新定义时间轴
t_cutoff = 600/0.75;  % 确保这个常数符合实验要求
t_cutoff=round(t_cutoff);
t = LogData.time(t_cutoff:end) - LogData.time(t_cutoff);
y_act = LogData.signals(1).values(t_cutoff:end, 2);
y_actm = LogData.signals(1).values(t_cutoff:end, 1);
u_act = LogData.signals(2).values(t_cutoff:end, 1);
% 计算控制输入的偏移量
u_offset = u_act(1);
i = 1;
while u_act(i) == u_act(1)
    i = i + 1;
end
% 输出偏移处理
u = u_act - u_offset;
% 输入偏移处理
y_offset = mean(y_act(1:i-1))-0.15;
y = y_act - y_offset;
% 使用前一半的数据进行建模
N = floor(length(y) / 2);
k_start = 3;  % 偏移数据起点
Y = y(k_start:N);
Phi = [y(k_start-1:N-1), y(k_start-2:N-2), u(k_start-1:N-1), u(k_start-2:N-2)];
% 计算参数 theta，进行系统辨识
theta = inv((Phi' * Phi)) * (Phi' * Y);
a1 = -theta(1);  % 系数 a1
a2 = -theta(2);  % 系数 a2
b1 = theta(3);   % 系数 b1
b2 = theta(4);   % 系数 b2
% 构建离散时间传递函数 G(z)
h = t(2) - t(1);  % 采样时间
numerator = [b1 b2]; 
denominator = [1 a1 a2]; 
Gz = tf(numerator, denominator, h);  % 离散时间传递函数
% 构建状态空间模型
G = [0 1; -a2 -a1];  % 矩阵 G
H = [0; 1];          % 矩阵 H
C = [b2 b1];         % 矩阵 C
D = 0;               % 矩阵 D
sys_ss = ss(G, H, C, D, h);
% Step 1_a: 计算状态矩阵 G 的特征值，并判断系统是否稳定
eig_G = eig(G);
disp('Eigenvalues of the system:');
disp(eig_G);
if all(abs(eig_G) < 1)
    disp('The open-loop system is stable.');
else
    disp('The open-loop system is unstable.');
end
% Step 1_b: 找出传递函数 G(z) 的零点
zeros_Gz = zero(Gz);
disp('Zeros of the transfer function:');
disp(zeros_Gz);
if all(abs(zeros_Gz) < 1)
    disp('The system is a minimum phase system.');
else
    disp('The system is not a minimum phase system.');
end
% Step 2: 检查系统的可控性 (G, H)
controllability_matrix = ctrb(G, H);
rank_ctrb = rank(controllability_matrix);
disp('Rank of the controllability matrix:');
disp(rank_ctrb);
if rank_ctrb == size(G, 1)
    disp('The system is reachable (controllable).');
else
    disp('The system is not reachable (controllable).');
end
% 检查系统的可观测性 (G, C)
observability_matrix = obsv(G, C);
rank_obsv = rank(observability_matrix);
disp('Rank of the observability matrix:');
disp(rank_obsv);
if rank_obsv == size(G, 1)
    disp('The system is observable.');
else
    disp('The system is not observable.');
end
% Step 3: 使用对偶性求解可观测标准型
G_T = G';
H_T = C';  % 矩阵 C 的转置作为输入矩阵
C_T = H';  % 矩阵 H 的转置作为输出矩阵
D_T = D';
x0 = [0; 0];
y0 = 0.3;
% 创建可观测标准型的状态空间模型
sys_obs = ss(G_T, H_T, C_T, D_T, h);
% Q3: 设计状态反馈和观测器
K_db = (acker(G, H, [0 0]))';  % 状态反馈增益矩阵
L_ndb3 = acker(G_T, H_T, [0.9 0.9]);  % 观测器增益矩阵
sys_ndb3 = ss(G_T - H_T * L_ndb3, H_T, C_T - D_T * L_ndb3, D_T, h);
gain_ndb3 = dcgain(sys_ndb3);
DC_gain3 = 1 / gain_ndb3;
L=L_ndb3;
K=K_db;
Gcl_1 = DC_gain3;
% 定义可观测标准形式的矩阵
G_obs = G';
H_obs = C';
C_obs = H';
D_obs = D';
% 仿真时间向量
t_sim = 0:h:600; 
% 将变量分配到 MATLAB Workspace
assignin('base', 'G', G);
assignin('base', 'H', H);
assignin('base', 'C', C);
assignin('base', 'D', D);
assignin('base', 'L', L);
assignin('base', 'K', K);
assignin('base', 'Gcl_1', Gcl_1);
assignin('base', 'u_offset', u_offset);
assignin('base', 'y_offset', y_offset);
assignin('base', 'G_obs', G_obs);
assignin('base', 'H_obs', H_obs);
assignin('base', 'C_obs', C_obs);
assignin('base', 'D_obs', D_obs);
% 输出成功提示
disp('控制参数已成功初始化并存储在 MATLAB Workspace 中。');
% 保存数据以供 Simulink 使用
%filename = 'Lab03_Q3_Data.mat';
%save(filename, 'G', 'H', 'C', 'D', 'G_T', 'H_T', 'C_T', 'D_T', ...
   % 'L_ndb3', 'K_db', 'DC_gain3', 'y_offset', 'u_offset', 't_sim','x0','y0');
% 提示保存成功
%disp(['Variables saved to ', filename]);