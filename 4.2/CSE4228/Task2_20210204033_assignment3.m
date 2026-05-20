clc;
clear;
close all;

% Read Image
I = imread('Input_20210204033.jpg');

% Convert to grayscale if RGB
if size(I,3) == 3
    I = rgb2gray(I);
end

I = uint8(I);
[M,N] = size(I);

% Bit-Plane Slicing (All 8)
bit_planes = zeros(M,N,8,'uint8');

for k = 1:8
    bit_planes(:,:,k) = bitand(I, 2^(k-1)) > 0;
end

% Reconstruct using 3rd,4th,5th,6th
reconstructed = zeros(M, N, 'uint8');
for bit = [2, 3, 4, 5]
    reconstructed = reconstructed + bitand(I, uint8(2^bit));
end

% Add Salt & Pepper Noise
noisy = imnoise(reconstructed,'salt & pepper',0.2);

% 3x3 Median Filter (Manual)
filtered = noisy;
for i = 2:M-1
    for j = 2:N-1
        window = noisy(i-1:i+1 , j-1:j+1);
        values = sort(window(:));
        filtered(i,j) = values(5); % Median of 9 elements
    end
end

% Write Output Image
imwrite(filtered,'Output_Task2_20210204033.jpg');

% Display Results------
figure;

subplot(2,3,1);
imshow(I);
title('Input Image');

subplot(2,3,2);
imshow(bit_planes(:,:,3));
title('3rd Bit Plane');

subplot(2,3,3);
imshow(bit_planes(:,:,4));
title('4th Bit Plane');

subplot(2,3,4);
imshow(reconstructed);
title('Reconstructed Image');

subplot(2,3,5);
imshow(noisy);
title('Salt & Pepper Noise (0.2)');

subplot(2,3,6);
imshow(filtered);
title('3x3 Median Filter Output');