import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def join_Images(foreground_Img, background_Img):
    def generate_Mask(BGR_img):
        plt.figure()
        plt.title('BGR Histogram')
        plt.xlabel('Bins')
        plt.ylabel('# of pixels')
        
        colors = ('b', 'g', 'r')      
        
        for i, col in enumerate(colors):
            histogram_Img = cv.calcHist([BGR_img], [i], None, [256], [0, 256])
            
            plt.plot(histogram_Img, color = col)
            plt.xlim([0, 256])
            
        plt.show()
        
        HSV_img = cv.cvtColor(BGR_img, cv.COLOR_BGR2HSV)
        
        cv.imshow('HSV Image', HSV_img)
        cv.waitKey(0)
        
        lower_Green = np.array([35, 100, 100])
        upper_Green = np.array([75, 255, 255])
        
        green_Mask = cv.inRange(HSV_img, lower_Green, upper_Green)
        cv.imshow('Green Mask', green_Mask)
        cv.waitKey(0)
        
        invert_Mask = 255 - green_Mask
        
        def adjust_Edge_Image(img):
            img = cv.GaussianBlur(img, (0, 0), sigmaX = 2, sigmaY = 2, borderType = cv.BORDER_DEFAULT)
            img = (2 * (img.astype(np.float32)) - 255.0).clip(0, 255).astype(np.uint8)
            
            return img
        
        invert_Mask = adjust_Edge_Image(invert_Mask)
        
        cv.imshow('Invert Mask', invert_Mask)
        cv.waitKey(0)
        
        return invert_Mask
  
    def resize_Image(img):
        
        wight = 1280
        height = 720
        points = (wight, height)
        
        resized_img = cv.resize(img, points, interpolation = cv.INTER_LINEAR)
        
        return resized_img
    
    invert_Mask = generate_Mask(foreground_Img)
       
    foreground_Img = cv.bitwise_and(foreground_Img, foreground_Img, mask = invert_Mask)
    cv.imshow('Foreground Image', foreground_Img)
    cv.waitKey(0)
    
    background_Img = resize_Image(background_Img)
    cv.imshow('Resized Background', background_Img)
    cv.waitKey(0)
    
    invert_Mask = cv.cvtColor(invert_Mask, cv.COLOR_BGR2BGRA).astype(float) / 255
    foreground_Img = cv.cvtColor(foreground_Img, cv.COLOR_BGR2BGRA).astype(float)
    background_Img = cv.cvtColor(background_Img, cv.COLOR_BGR2BGRA).astype(float)
    
    foreground_Img = cv.multiply(invert_Mask, foreground_Img)
    background_Img = cv.multiply(1.0 - invert_Mask, background_Img)
    
    # cv.imshow('Foreground Image', foreground_Img)
    # cv.imshow('Background Image', background_Img)
      
    new_Image = cv.add(foreground_Img, background_Img) / 255
    
    cv.imshow('New image', new_Image)
    cv.waitKey(0)
    
img1 = cv.imread('imagens/miley.jpg')
img2 = cv.imread('imagens/Exemplo_fundo.jpg')

cv.imshow('Image 1', img1)
cv.waitKey(0)
cv.imshow('Image 2', img2)
cv.waitKey(0)

join_Images(img1, img2);

cv.destroyAllWindows()

