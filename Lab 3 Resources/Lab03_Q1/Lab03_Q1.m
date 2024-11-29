% LAB_02_DATA
load('SysIdenData_1.mat'); 
V_min = 2.1;
V_max = 3;
u_offset = (V_max + V_min)/2;
t_cutoff = 132/0.75;
t = LogData.time(t_cutoff:end)-LogData.time(t_cutoff);
y_act = LogData.signals(1).values(t_cutoff:end,2);
y_actm = LogData.signals(1).values(t_cutoff:end,1);
u_act = LogData.signals(2).values(t_cutoff:end,1);
i = 1;
while u_act(i) == u_act(1)
    i = i + 1;
end
% Output offset
u = u_act - u_offset;
% Input offset
y_offset = mean(y_act(1:i-1));
y = y_act - y_offset;

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
G = [0 1; -a2 -a1];  % matrix G
H = [0; 1];  % matrix H
C = [b2 b1];  % matrix C
D = 0;  % matrix D
sys_ss = ss(G, H, C, D, h);

% Pre_Lab
% Step 1_a: Calculate eigenvalues of the state matrix G & determie whether stable
eig_G = eig(G);
disp('Eigenvalues of the system:');
disp(eig_G);
if all(abs(eig_G) < 1)
    disp('The open-loop system is stable.');
else
    disp('The open-loop system is unstable.');
end

% Step 1_b: Find zeros of the transfer function G(z)
zeros_Gz = zero(Gz);
disp('Zeros of the transfer function:');
disp(zeros_Gz);
% Check if the system is minimum phase: A minimum phase system has all its zeros inside the unit circle.
if all(abs(zeros_Gz) < 1)
    disp('The system is a minimum phase system.');
else
    disp('The system is not a minimum phase system.');
end

% Step 2: Check reachability (controllability) of (G, H)
controllability_matrix = ctrb(G, H);
rank_ctrb = rank(controllability_matrix);
disp('Rank of the controllability matrix:');
disp(rank_ctrb);

if rank_ctrb == size(G, 1)
    disp('The system is reachable (controllable).');
else
    disp('The system is not reachable (controllable).');
end

% Check observability of (G, C)
observability_matrix = obsv(G, C);
rank_obsv = rank(observability_matrix);
disp('Rank of the observability matrix:');
disp(rank_obsv);

if rank_obsv == size(G, 1)
    disp('The system is observable.');
else
    disp('The system is not observable.');
end

% Step 3: Find the canonical observable form using duality property
G_T = G';
H_T = C';  % Transpose of C becomes the new input matrix
C_T = H';  % Transpose of H becomes the new output matrix
D_T = D';

% Create the state-space representation in the canonical observable form
sys_obs = ss(G_T, H_T, C_T, D_T, h);

% Lab_Exercise
% Q1
% Given y(0) = C * x(0) = 0.3
y0 = 0.3;  % Initial offset-free output

% Assume y(k) = x2(k) in the observable form, so we set:
x2_0 = y0;  % Set x2(0) directly to y(0)

% Initial conditions for x(0)
x0 = [0; x2_0];  % Assuming x1(0) = 0

% Display the chosen initial conditions
disp('Chosen initial conditions for state vector x(0):');
disp(x0);
% Calculate the corresponding water level with offset
water_level = (y0 + y_offset) * (300 / 5);  % Convert from volts to ml

% Check if the water level is within the specified range
if water_level >= 80 && water_level <= 240
    disp('The initial conditions satisfy the specified output range.');
else
    disp('The initial conditions do not satisfy the specified output range. Adjust y_offset.');
end

% Display the calculated water level
disp(['Calculated water level (ml): ', num2str(water_level)]);

% Deadbeat control
% Choose desired closed-loop poles for deadbeat control (e.g., both at the origin)
desired_poles_db = [0 0];
L_db = acker(G_T, H_T, desired_poles_db);  % Calculate deadbeat control gain
disp('Deadbeat control gain (L_db):');
disp(L_db);

% Non-deadbeat control
% Choose desired closed-loop poles for non-deadbeat control (e.g., close to open-loop poles)
% Adjust these values based on your system's requirements
desired_poles_ndb = [0.4 0.9]; % You may need to adjust these for stability and input limits
L_ndb = acker(G_T, H_T, desired_poles_ndb);  % Calculate non-deadbeat control gain
disp('Non-deadbeat control gain (L_ndb):');
disp(L_ndb);

% Define the filename for the .mat file
filename = 'Lab03_Q1_Data.mat';

% Save all the important variables to the .mat file
save(filename, 'G', 'H', 'C', 'D', 'G_T', 'H_T', 'C_T', 'D_T', ...
    'Gz', 'a1', 'a2', 'b1', 'b2', 'sys_ss', 'sys_obs', 'eig_G', 'zeros_Gz', ...
    'controllability_matrix', 'rank_ctrb', 'observability_matrix', 'rank_obsv', ...
    'x0', 'y0', 'x2_0', 'y_offset', 'water_level', 'L_db', 'L_ndb', 'desired_poles_db', 'desired_poles_ndb');

% Display a message indicating that the file has been saved
disp(['Variables saved to ', filename]);