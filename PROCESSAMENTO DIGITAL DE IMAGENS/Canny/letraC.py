import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def sobel_Filter(gray_Image):
    sy = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    sx = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]])
    
    sy_Image = cv.filter2D(gray_Image, -1, sy)
    sx_Image = cv.filter2D(gray_Image, -1, sx)
   
    magnitudeGradient_Image = np.sqrt(np.square(sy_Image) + np.square(sx_Image))
    magnitudeGradient_Image *= 255.0 / magnitudeGradient_Image.max()
    
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
    
    # Após o cálculo da magnitude do gradiente, é feito também o cálculo da direção do gradiente pelos os quais
    # irão fornecer dados precisos para fazer supresão não máxima
    def calculate_directionMagnitude():
        
        # Utiliza-se o método arcotan2 que é dada uma resposta em radiano do ângulo dos pixels. Em seguida
        # esses valores são convertidos em graus
        directionMagnitudeGradient_Image = np.arctan2(sy_Image, sx_Image)
        directionMagnitudeGradient_Image = np.rad2deg(directionMagnitudeGradient_Image)
        
        # Afim de evita erros, caso haja pixels negativos na imagem, é substituído pelo valor 180
        directionMagnitudeGradient_Image[directionMagnitudeGradient_Image < 0] = 180
        
        return directionMagnitudeGradient_Image
    
    directionMagnitudeGradient_Image = calculate_directionMagnitude()
    
    return (magnitudeGradient_Image, directionMagnitudeGradient_Image)

# Método responsável em gerar o filtro de Canny. Dentro dele, há outros 3 métodos. O primeiro é responsável pelo
# supressão não máxima, o segundo gerará 2 limiar, enquanto o terceiro gerará um histerese, trechos do código de
# bastante importância
def canny_Filter(magnitudeGradient_Image, directionMagnitudeGradient_Image):
    
    # Este método fica responsável pela supressão não máxima dos pixeis. Ele recebe como parâmetro magnitude do gradiente imagem da
    # imagem e a direção. Ele diminui e deixa as bordas mais finas na imagem de acordo com os angulos.
    def nonMaxSuppresion(magnitudeGradient_Image, directionMagnitudeGradient_Image):
        # As variáveis descritas abaixo correspondem respectivamente as e colunas da imagem
        rows_Image, colums_Image = magnitudeGradient_Image.shape
        
        # Variável que inicialmente recebe uma matriz de zeros do mesmo tamanho magnitud do gradiente da imagem
        # No último if descrito ela receberá o valor com base nas condições estabelecidas para cada if
        nonMaxSuppresion_Image = np.zeros(magnitudeGradient_Image.shape)
        
        # Esta variável fica em responsável em receber o valor 180, visto que o ângulo de 180° ser
        # expressado em PI e 90° em PI / 2 e assim adiante.
        PI = 180
        
        # Primeiro for para linhas
        for row in range(1, rows_Image-1):
            # Segundo for para colunas
            for colum in range(1, colums_Image-1):
                # Tem-se uma variável responsável receber o valor em graus do angulo da direção dos pixeis da imagem
                direction_Agle = directionMagnitudeGradient_Image[row, colum]

                # A sequência de IF's ajuda a verificar quais pixels tem uma maior intensidade quandos eles se encontram na mesma direção.
                # Cada if corresponde a qual ângulo será tratado na direção. Caso exista algum pixel mais intenso do o pixel processado,
                # apenas o mais intenso permance. Desta forma, dentro de cada IF's tem-se as variaveis before_Pixel e after_Pixel que recebem
                # respectivamente o pixel anterior e o pixel proximo
                if (0 <= direction_Agle < PI / 8) or (15 * PI / 8 <= direction_Agle <= 2 * PI):
                    before_Pixel = magnitudeGradient_Image[row, colum-1]
                    after_Pixel = magnitudeGradient_Image[row, colum+1]

                elif (PI / 8 <= direction_Agle < 3 * PI / 8) or (9 * PI / 8 <= direction_Agle < 11 * PI / 8):
                    before_Pixel = magnitudeGradient_Image[row+1, colum-1]
                    after_Pixel = magnitudeGradient_Image[row-1, colum+1]

                elif (3 * PI / 8 <= direction_Agle < 5 * PI / 8) or (11 * PI / 8 <= direction_Agle < 13 * PI / 8):
                    before_Pixel = magnitudeGradient_Image[row-1, colum]
                    after_Pixel = magnitudeGradient_Image[row+1, colum]

                else:
                    before_Pixel = magnitudeGradient_Image[row-1, colum-1]
                    after_Pixel = magnitudeGradient_Image[row+1, colum+1]
                    
                # Caso a magnitudeGradient_Image da imagem seja maior ou igual a before_Pixel e after_Pixel, então,
                # a matrix nonMaxSuppresion_Image recebe  os valores de magnitudeGradient_Image
                if((magnitudeGradient_Image[row, colum] >= before_Pixel) and (magnitudeGradient_Image[row, colum] >= after_Pixel)):
                    nonMaxSuppresion_Image[row, colum] = magnitudeGradient_Image[row, colum]
                    
        return nonMaxSuppresion_Image
    
    # O método threshold corresponde em gerar 2 limiares e ajudará identificar quais pixels vão constituir 
    # a borda e quais, são fracos e não constituem. Após a etapa, utilizaremos o hysteresiss
    def threshold(nonMaxSuppresion_Image):
        # Cria-se uma matriz de zero responsável pelo saída
        threshold_Image = np.zeros((nonMaxSuppresion_Image.shape), dtype=np.uint8)
        
        # A variável low fica responsável em identificar pixels com valores consideravelmente baixos em comparação aos altos
        # Enquanto a variável high é responsável em encontrar pixeis com intensidades fortes 
        low = 17
        high = 34
        
        # A variável weak fica responsável em analisar pixels fracos, enquanto a variável strong
        # funciona de forma análoga
        weak = 100
        strong = 255
        
        # weak_Row e weak_Col correspondem as linhas e colunas onde os pixels fracos se encontram, enquanto
        # strong_Rows e strong_Colum correspondem as dos pixels fortes. Utiliza-se o método np.where
        # que para as variaveis recebem respectivamente os valores baixos e altos dos pixels da imagem
        weak_Row, weak_Colum = np.where((nonMaxSuppresion_Image >= low) & (nonMaxSuppresion_Image <= high))
        strong_Row, strong_Colum = np.where(nonMaxSuppresion_Image >= high)
        
        # Por fim, threshold_Image entre linhas e coluna de respectiva entre weak e  row,, recebem os valores
        # fracos e fortes dos pixels
        threshold_Image[weak_Row, weak_Colum] = weak
        threshold_Image[strong_Row, strong_Colum] = strong
        
        return (threshold_Image, weak, strong)
    
    # O método hysteresis fica responsável em transformar pixels fracos da imagem em pixels fortes, caso estritamente
    # haja um pixel forte ao redor de um pixel que está sendo processado
    def hysteresis(threshold_Image, weak, strong):
        # hysteresis_Image é uma matriz iniciada com zeros e que será nossa saída. E também vai receber os pixels da imagem
        # dentro do for
        hysteresis_Image = np.zeros(threshold_Image.shape)   
        
        # row_Image, e colums_Image correspondem respectivamente as linhas e colunas da imagem
        rows_Image, colums_Image = threshold_Image.shape
        
        
        for row in range(1, rows_Image-1):
            for colum in range(1, colums_Image-1):
                hysteresis_Image[row, colum] = threshold_Image[row, colum]
                
                # O primeiro if tem como objetivo em analisar se determinado pixel da  imagem é igual ao valor de um pixel fraco
                if (hysteresis_Image[row, colum] == weak):
                    # O segundo if fica relacionado em analisar as adjacências dos pixels processados na imagem se é igual ao
                    # valor de um pixel forte (255). Como se trata de um operador or, mesmo que todas as condições conjuntas
                    # não seja, algumas delas podem ser verdadeiro e então, a matriz hysteresis_Image recebe um pixel com
                    # falor extremamente forte (equivalente a cor branca)
                    if ((hysteresis_Image[row+1, colum-1] == strong) or (hysteresis_Image[row+1, colum] == strong) 
                        or (hysteresis_Image[row+1, colum+1] == strong) or (hysteresis_Image[row, colum-1] == strong) 
                        or (hysteresis_Image[row, colum+1] == strong) or (hysteresis_Image[row-1, colum-1] == strong) 
                        or (hysteresis_Image[row-1, colum] == strong) or (hysteresis_Image[row-1, colum+1] == strong)):
                        hysteresis_Image[row, colum] = strong
                    # E se a condição não for cumprida, o que indica que não há presença de pixels fortes na vizinhança do pixel processado
                    # então, receberá um valor extremamente fraco (equivalente a cor preta), o que indica que não há nenhuma relação para
                    # constituir uma borda
                    else:
                        hysteresis_Image[row, colum] = 0
                            
        return hysteresis_Image
    
    nonMaxSuppresion_Image = nonMaxSuppresion(magnitudeGradient_Image, directionMagnitudeGradient_Image)
    threshold_Image, weak, strong = threshold(nonMaxSuppresion_Image)
    hysteresis_Image = hysteresis(threshold_Image, weak, strong)
    
    # Resultados gerados
    plt.subplot(1, 3, 1)
    plt.axis('off')
    plt.title('Image with Non Max Supression')
    plt.imshow(nonMaxSuppresion_Image, cmap='gray')
    
    plt.subplot(1, 3, 2)
    plt.axis('off')
    plt.title('Thresholded Image')
    plt.imshow(threshold_Image, cmap='gray')
    
    plt.subplot(1, 3, 3)
    plt.axis('off')
    plt.title('Image with hystereses')
    plt.imshow(hysteresis_Image, cmap='gray')
    
    plt.show()
    
img = cv.imread('imagem/'+'lena'+'.jpg')[:,:,::-1]
gray_Image = cv.cvtColor(img, cv.COLOR_RGB2GRAY).astype(float)
gaussianBlur_Image = cv.GaussianBlur(gray_Image, [5, 5], 0)

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

magnitudeGradient_Image, directionMagnitudeGradient_Image = sobel_Filter(gaussianBlur_Image)
canny_Filter(magnitudeGradient_Image, directionMagnitudeGradient_Image)