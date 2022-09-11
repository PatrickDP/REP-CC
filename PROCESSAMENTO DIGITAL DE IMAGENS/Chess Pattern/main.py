import numpy as np
import matplotlib.pyplot as plt

x, y = 10, 10

W = np.ones((x, y))
B = np.zeros((x, y))

WB = np.c_[B, W]
plt.imshow(WB, cmap= "binary", vmin = 0, vmax = 1)
plt.show()

BW = np.c_[W, B]
plt.imshow(BW, cmap= "binary", vmin = 0, vmax = 1)
plt.show()

WB_tiled = np.tile(WB, 5)
plt.imshow(WB_tiled, cmap= "binary", vmin = 0, vmax = 1)
plt.show()

BW_tiled = np.tile(BW, 5)
plt.imshow(BW_tiled, cmap= "binary", vmin = 0, vmax = 1)
plt.show()

WB_BW = np.vstack((WB_tiled, BW_tiled))
chessPattern = np.tile(WB_BW, (5,1))
plt.imshow(chessPattern, cmap= "binary", vmin = 0, vmax = 1)
plt.show()

chessPattern = np.array(chessPattern, dtype = np.uint8)
chessPattern[np.where(chessPattern == 1)] = 127
plt.imshow(chessPattern, cmap= "gray", vmin = 0, vmax = 255)
plt.show()

chessPattern = np.array(chessPattern, dtype=np.uint8, order='F')
chessPattern.resize(x * 10, y * 10, 3)

white = [255, 255, 255]
red = [255, 0, 0]
green = [0, 255, 0]
blue = [0, 0, 255]
yellow = [255, 255, 0]
magenta = [255, 0, 255]

chessPattern_red = np.array(chessPattern, dtype=np.uint8)
chessPattern_green = np.array(chessPattern, dtype=np.uint8)
chessPattern_blue = np.array(chessPattern, dtype=np.uint8)
chessPattern_yellow = np.array(chessPattern, dtype=np.uint8)
chessPattern_magenta = np.array(chessPattern, dtype=np.uint8)

white_mask = green_mask = red_mask = blue_mask = yellow_mask = magenta_mask = chessPattern[:, :, 0] == 127

chessPattern[white_mask] = white
chessPattern_red[red_mask] = red
chessPattern_green[green_mask] = green
chessPattern_blue[blue_mask] = blue
chessPattern_yellow[yellow_mask] = yellow
chessPattern_magenta[magenta_mask] = magenta
 
plt.subplot(2, 3, 1)
plt.title("White")
plt.imshow(chessPattern, vmin = 0, vmax = 255)

plt.subplot(2, 3, 2)
plt.title("Red")
plt.imshow(chessPattern_red, vmin = 0, vmax = 255)

plt.subplot(2, 3, 3)
plt.title("Green")
plt.imshow(chessPattern_green, vmin = 0, vmax = 255)

plt.subplot(2, 3, 4)
plt.title("Blue")
plt.imshow(chessPattern_blue, vmin = 0, vmax = 255)

plt.subplot(2, 3, 5)
plt.title("Yellow")
plt.imshow(chessPattern_yellow, vmin = 0, vmax = 255)

plt.subplot(2, 3, 6)
plt.title("Magenta")
plt.imshow(chessPattern_magenta, vmin = 0, vmax = 255)

plt.show()