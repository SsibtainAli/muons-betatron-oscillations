% Load the data from the text file
data = load('horizontal_betatron_oscillation_cm.txt');

% Separate the data into variables
time = data(:, 1);    % Time values (in seconds)
x = data(:, 2);       % Position values (in cm)
x_dot = data(:, 3);   % Velocity values (in cm/s)

% Create a figure with two subplots
figure;

% First subplot: Position vs Time
subplot(2, 1, 1); % 2 rows, 1 column, first plot
plot(time, x, 'b-', 'LineWidth', 2);
xlabel('Time (s)');
ylabel('Position x (cm)');
title('Muon Horizontal Betatron Oscillation: Position vs Time');
grid on;

% Second subplot: Velocity vs Time
subplot(2, 1, 2); % 2 rows, 1 column, second plot
plot(time, x_dot, 'r-', 'LineWidth', 2);
xlabel('Time (s)');
ylabel('Velocity \dot{x} (cm/s)');
title('Muon Horizontal Betatron Oscillation: Velocity vs Time');
grid on;

% Add a general title for both subplots
sgtitle('Muon Horizontal Betatron Oscillation');
