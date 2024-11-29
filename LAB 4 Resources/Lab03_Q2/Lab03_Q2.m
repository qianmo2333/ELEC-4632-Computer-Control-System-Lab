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


% 找到u_act中非初始值的位置
i = 1;
while u_act(i) == u_act(1)
    i = i + 1;
end

% 输出和输入的偏移调整
u = u_act - u_offset;
y_offset = mean(y_act(1:i-1));
y = y_act - y_offset;

% 系统参数估计
N = floor(length(y) / 2);
k_start = 3;
Y = y(k_start:N);
Phi = [y(k_start-1:N-1), y(k_start-2:N-2), u(k_start-1:N-1), u(k_start-2:N-2)];
theta = inv((Phi' * Phi)) * (Phi' * Y);
a1 = -theta(1);
a2 = -theta(2);
b1 = theta(3);
b2 = theta(4);

% 传递函数和状态空间模型
h = t(2) - t(1);
numerator = [b1 b2]; 
denominator = [1 a1 a2]; 
Gz = tf(numerator, denominator, h);

% 状态空间矩阵
G = [0 1; -a2 -a1];  
H = [0; 1];  
C = [b2 b1];  
D = 0;  
sys_ss = ss(G, H, C, D, h);

% 转置状态空间模型 (可观测形式)
G_T = G';
H_T = C';
C_T = H';
D_T = D';

x0 = [0; 0];
y0 = 0.3;
% 计算反馈增益
desired_poles_db = [0 0]; 
L_db = acker(G_T, H_T, desired_poles_db);

desired_poles_ndb = [0.92 0.92]; 
L_ndb = acker(G_T, H_T, desired_poles_ndb);
% 计算 DC 增益的倒数，用于补偿
sys_db = ss(G_T - H_T * L_db, H_T, C_T-D_T*L_db, D_T, h);
G_dc_inv_db = 1 / dcgain(sys_db);
% 计算 DC 增益的倒数，用于补偿
sys_ndb = ss(G_T - H_T * L_ndb, H_T, C_T-D_T*L_ndb, D_T, h);
G_dc_inv_ndb = 1 / dcgain(sys_ndb);

% 仿真时间向量
t_sim = 0:h:600; 

% 保存数据以供 Simulink 使用
filename = 'Lab03_Q2_Data.mat';
save(filename, 'G', 'H', 'C', 'D', 'G_T', 'H_T', 'C_T', 'D_T', ...
    'L_db', 'L_ndb', 'G_dc_inv_db','G_dc_inv_ndb', 'y_offset', 'u_offset', 't_sim','x0','y0');

% 提示保存成功
disp(['Variables saved to ', filename]);
% 显示系统模型矩阵
disp('System Model Matrices:');
disp('G (State Matrix):');
disp(G);
disp('H (Input Matrix):');
disp(H);
disp('C (Output Matrix):');
disp(C);

% 显示状态反馈增益
disp('State Feedback Gains:');
disp('L_db (Deadbeat Feedback Gain):');
disp(L_db);
disp('L_ndb (Non-Deadbeat Feedback Gain):');
disp(L_ndb);

% 显示闭环直流增益的逆
disp('Inverse of the DC Gain:');
disp('G_dc_inv_db (Deadbeat Inverse DC Gain):');
disp(G_dc_inv_db);
disp('G_dc_inv_ndb (Non-Deadbeat Inverse DC Gain):');
disp(G_dc_inv_ndb);

% 显示输入和输出偏移量
disp('Input and Output Offsets:');
disp('u_offset (Input Offset):');
disp(u_offset);
disp('y_offset (Output Offset):');
disp(y_offset);

% 显示初始条件
disp('Initial Conditions:');
disp('x0 (Initial State):');
disp(x0);
disp('y0 (Initial Output):');
disp(y0);

% 提示保存成功
disp(['Variables saved to ', filename]);

