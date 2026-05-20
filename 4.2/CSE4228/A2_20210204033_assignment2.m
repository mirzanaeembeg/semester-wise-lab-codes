clear; clc; close all;

img = imread('nature.jpg');

img = im2double(img);

[rows, cols, channels] = size(img);

mid_row = round(rows / 2);
mid_col = round(cols / 2);

% Top-left box
TL = img(1:mid_row, 1:mid_col, :);

% Top-right box
TR = img(1:mid_row, mid_col+1:end, :);

% Bottom-left box
BL = img(mid_row+1:end, 1:mid_col, :);

% Bottom-right box
BR = img(mid_row+1:end, mid_col+1:end, :);


TL_out = TL;
c = 0.6;  
gamma = 3; 

TL_out(:, :, 3) = c * (TL(:, :, 3) .^ gamma);


TR_out = TR;
TR_out(:, :, 1) = TR(:, :, 3);  
TR_out(:, :, 3) = TR(:, :, 1);  

BL_out = BL;

BR_out = BR;
c_log = 5;  

BR_out = c_log * log(1 + BR);

final_image = zeros(rows, cols, channels);

final_image(1:mid_row, 1:mid_col, :) = TL_out;           % Top-left
final_image(1:mid_row, mid_col+1:end, :) = TR_out;       % Top-right
final_image(mid_row+1:end, 1:mid_col, :) = BL_out;       % Bottom-left
final_image(mid_row+1:end, mid_col+1:end, :) = BR_out;   % Bottom-right


final_image = max(0, min(1, final_image));

imwrite(final_image, 'final_transformed_image.png');
disp('Image saved as: final_transformed_image.png');
