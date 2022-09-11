# Importando as bibliotecas
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# O primeiro método é responsável em ajudar a detectar as bordas graças ao filtro de Sobel
def sobel_Filter(gray_Image):
    
    # Utiliza 2 kernels (o primeiro é responsável pela eixo y, enquanto o segundo, x, que é uma matriz transposta do anterior)
    sy = np.array([[-1.0, 0.0, 1.0],
                   [-2.0, 0.0, 2.0],
                   [-1.0, 0.0, 1.0]])
    sx = np.transpose(sy)
    
    # Com os kernels definidos, é feito a operação de covolução da imagem em tons de cinzas para cada eixo x, y da imagem
    sy_Image = cv.filter2D(gray_Image, -1, sy)
    sx_Image = cv.filter2D(gray_Image, -1, sx)
    
    # Operação da magnitude do gradiente da imagem com o uso do método sqrt e np square, desta forma a magnitude do gradiente
    # é definida pela raiz quadrada de sy_Image e sx_Image, ambos ao quadrado
    magnitudeGradient_Image = np.sqrt(np.square(sy_Image) + np.square(sx_Image))
    magnitudeGradient_Image *= 255.0 / np.max(magnitudeGradient_Image)
    
    # Exibição dos resultados obtidos
    plt.subplot(1, 3, 1)
    plt.axis('off')
    plt.title('Vertical Edge')
    plt.imshow(sy_Image, cmap='gray')
    
    plt.subplot(1, 3, 2)
    plt.axis('off')
    plt.title('Horizontal Edge')
    plt.imshow(sx_Image, cmap='gray')
    
    plt.subplot(1, 3, 3)
    plt.axis('off')
    plt.title('Magnitude Gradient Image')
    plt.imshow(magnitudeGradient_Image, cmap='gray')

    plt.show()
    
    return magnitudeGradient_Image.astype(np.uint8)

# O segundo método fica responsável em gerar um threshold automatico utilizando THRESH_OTSU
def generateThreshold_image(magnitudeGradient_Image):
    
    # Primeiramente para que o resultado seja mais preciso (quase sem ruídos) uiliza-se novamente o filtro Gaussiano com kernel 5x5
    magnitudeGradientImage_blurred = cv.GaussianBlur(magnitudeGradient_Image, [5, 5], 0)
    
    # Em seguida, utiliza-se como argumentado da função threshold, cv.THRESH_OTSU que é um responsável em gerar automaticamente uma
    # imagem limiarizada, sem a necessidade de passar valores variáveis para que tenha um resultado mais objetivo
    threshold, thresh = cv.threshold(magnitudeGradient_Image, 0, 255, cv.THRESH_OTSU)

    # Exibição do resultado
    cv.imshow('Sobel Thresholded Image', thresh)
    cv.waitKey(0)


# Lendo a imagem, convertendo em tons cinzas e em seguida, aplicando um desfoque Gaussiano para que seja possível detectar as bordas
img = cv.imread('imagem/'+'lena'+'.jpg')[:,:,::-1]
gray_Image = cv.cvtColor(img, cv.COLOR_RGB2GRAY).astype(float)
gaussianBlur_Image = cv.GaussianBlur(gray_Image, [5, 5], 0)

# Impressão prévia da mudança da imagem escolhida
plt.subplot(1, 3, 1)
plt.axis('off')
plt.title('Image')
plt.imshow(img, cmap='BrBG')

plt.subplot(1, 3, 2)
plt.axis('off')
plt.title('Gray image')
plt.imshow(gray_Image, cmap='gray')

plt.subplot(1, 3, 3)
plt.axis('off')
plt.title('Gaussian Blur')
plt.imshow(gaussianBlur_Image, cmap='gray')

plt.show()

# Chamada das funções
magnitudeGradient_Image = sobel_Filter(gaussianBlur_Image)
threshold_Image = generateThreshold_image(magnitudeGradient_Image)