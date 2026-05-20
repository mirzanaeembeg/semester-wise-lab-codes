clc;
clear;
close all;

I = imread('Input_20210204033.jpg');
if size(I, 3) == 3
    I = rgb2gray(I);
end

I = double(I);
[rows, cols] = size(I);
L = 256;
N = rows * cols;

% Manually compute histogram h
h = zeros(1, L);
for i = 1:rows
    for j = 1:cols
        h(I(i,j) + 1) = h(I(i,j) + 1) + 1;
    end
end

% Manually compute PDF
PDF = h / N;

% Manually compute CDF
CDF = zeros(1, L);
CDF(1) = PDF(1);
for k = 2:L
    CDF(k) = CDF(k-1) + PDF(k);
end

% Multiply CDF by L-1 and round to get new gray level s
s = round(CDF * (L - 1));

% Create the equalized image using s
equalized = zeros(rows, cols);
for i = 1:rows
    for j = 1:cols
        equalized(i,j) = s(I(i,j) + 1);
    end
end
equalized = uint8(equalized);

% Manually compute histogram H of the output image
H = zeros(1, L);
for i = 1:rows
    for j = 1:cols
        H(equalized(i,j) + 1) = H(equalized(i,j) + 1) + 1;
    end
end

% Write output image
imwrite(equalized, 'Output_Task1_20210204033.jpg');

% Display images and histograms
figure;
subplot(2,2,1); imshow(uint8(I));  title('Input Image');
subplot(2,2,2); bar(0:L-1, h, 'k'); title('Input Histogram'); xlabel('Gray Level'); ylabel('Count');
subplot(2,2,3); imshow(equalized); title('Equalized Image');
subplot(2,2,4); bar(0:L-1, H, 'k'); title('Output Histogram'); xlabel('Gray Level'); ylabel('Count');
