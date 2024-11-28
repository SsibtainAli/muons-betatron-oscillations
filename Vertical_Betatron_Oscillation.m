% MATLAB Script to plot the muon trajectory in cm vs seconds

% Load the data from the text file
data = load('muon_VBO_trajectory_cm.txt');

% Extract time, position, and velocity from the data
time = data(:, 1);      % First column is time (in seconds)
position = data(:, 2);  % Second column is position (in cm)
velocity = data(:, 3);  % Third column is velocity (in cm/s)

% Plot position vs time in centimeters
figure;
subplot(2, 1, 1); % Create a subplot (2 rows, 1 column, 1st plot)
plot(time, position, 'b-', 'LineWidth', 2);
title('Position vs Time (cm)');
xlabel('Time (s)');
ylabel('Position (cm)');
grid on;

% Plot velocity vs time in cm/s
subplot(2, 1, 2); % Create a subplot (2 rows, 1 column, 2nd plot)
plot(time, velocity, 'r-', 'LineWidth', 2);
title('Velocity vs Time (cm/s)');
xlabel('Time (s)');
ylabel('Velocity (cm/s)');
grid on;

% Show the plots
sgtitle('Muon Vertical Betatron Oscillation');
