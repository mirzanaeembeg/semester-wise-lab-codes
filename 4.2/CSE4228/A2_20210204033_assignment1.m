
img1 = imread('image1.JPG');
img2 = imread('image2.JPG');

gray1 = rgb2gray(img1);
gray2 = rgb2gray(img2);

resized1 = imresize(gray1, [600, 600]);
resized2 = imresize(gray2, [600, 600]);

blank_img = zeros(600, 600);

col_width = 600 / 3;  

for section = 1:3

    col_start = (section - 1) * col_width + 1;
    col_end = section * col_width;
    
    if mod(section, 2) == 1  
       
        for row = 1:600
            for col = col_start:col_end
                blank_img(row, col) = resized1(row, col);
            end
        end
    else  
        
        for row = 1:600
            for col = col_start:col_end
                blank_img(row, col) = resized2(row, col);
            end
        end
    end
end

blank_img = uint8(blank_img);

figure;
subplot(1,3,1);
imshow(resized1);
title('First Image (Grayscale 600x600)');

subplot(1,3,2);
imshow(resized2);
title('Second Image (Grayscale 600x600)');

subplot(1,3,3);
imshow(blank_img);
title('Merged Image (Alternating Columns)');

imwrite(blank_img, 'A2_20210204033.jpg');
disp('Merged image saved as A2_20210204033.jpg');