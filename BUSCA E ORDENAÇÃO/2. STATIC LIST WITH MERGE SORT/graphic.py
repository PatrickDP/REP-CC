import matplotlib.pyplot as plt
import numpy as np


x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
      26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
      51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
      76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100]

y1 = [1, 2, 5, 8, 11, 14, 17, 23, 34, 40, 52, 55, 61, 72, 78, 91, 94, 97, 103, 114, 120, 132, 135, 141, 152, 
      155, 165, 179, 182, 185, 188, 194, 205, 211, 223, 226, 232, 243, 249, 262, 265, 268, 274, 285, 291, 303, 
      306, 312, 323, 326, 336, 351, 354, 357, 360, 363, 369, 380, 386, 398, 401, 407, 418, 424, 437, 440, 443, 
      449, 460, 466, 478, 481, 487, 498, 501, 511, 525, 528, 531, 534, 540, 551, 557, 569, 572, 578, 589, 595, 
      608, 611, 614, 620, 631, 637, 649, 652, 658, 669, 672, 682]

y2 = [1, 18, 43, 60, 85, 134, 151, 176, 193, 218, 267, 364, 381, 406, 423, 448, 497, 514, 539, 556, 573, 606, 
      663, 768, 969, 986, 1011, 1028, 1053, 1102, 1119, 1144, 1161, 1186, 1235, 1332, 1349, 1374, 1391, 1416, 1465, 
      1482, 1507, 1524, 1541, 1574, 1631, 1736, 1937, 2338, 2355, 2380, 2397, 2422, 2471, 2488, 2513, 2530, 2555, 2604,
      2701, 2718, 2743, 2760, 2785, 2834, 2851, 2876, 2893, 2910, 2943, 3000, 3105, 3306, 3323, 3348, 3365, 3390, 3439,
      3456, 3481, 3498, 3523, 3572, 3669, 3686, 3711, 3728, 3753, 3802, 3819, 3844, 3861, 3878, 3911, 3968, 4073, 4274,
      4675, 0]

y3 = [2, 20, 48, 68, 96, 148, 168, 199, 227, 258, 319, 419, 442, 478, 501, 539, 591, 611, 642, 670, 693, 738, 798, 909, 
      1121, 1141, 1176, 1207, 1235, 1287, 1307, 1338, 1366, 1397, 1458, 1558, 1581, 1617, 1640, 1678, 1730, 1750, 1781, 1809,
      1832, 1877, 1937, 2048, 2260, 2664, 2691, 2731, 2751, 2779, 2831, 2851, 2882, 2910, 2941, 3002, 3102, 3125, 3161, 3184, 
      3222, 3274, 3294, 3325, 3353, 3376, 3421, 3481, 3592, 3804, 3824, 3859, 3890, 3918, 3970, 3990, 4021, 4049, 4080, 4141, 
      4241, 4264, 4300, 4323, 4361, 4413, 4433, 4464, 4492, 4515, 4560, 4620, 4731, 4943, 5347, 682]

y4 = [2, 22, 70, 138, 234, 382, 550, 749, 976, 1234, 1553, 1972, 2414, 2892, 3393, 3932, 4523, 5134, 5776, 6446, 7139, 7877, 8675, 
      9584, 10705, 11846, 13022, 14229, 15464, 16751, 18058, 19396, 20762, 22159, 23617, 25175, 26756, 28373, 30013, 31691, 33421, 
      35171, 36952, 38761, 40593, 42470, 44407, 46455, 48715, 51379, 54070, 56801, 59552, 62331, 65162, 68013, 70895, 73805, 76746, 
      79748, 82850, 85975, 89136, 92320, 95542, 98816, 102110, 105435, 108788, 112164, 115585, 119066, 122658, 126462, 130286, 134145, 
      138035, 141953, 145923, 149913, 153934, 157983, 162063, 166204, 170445, 174709, 179009, 183332, 187693, 192106, 196539, 201003, 
      205495, 210010, 214570, 219190, 223921, 228864, 234211, 234893]

plt.plot(x, y4)
plt.grid(color = 'black', linestyle = '--', linewidth = 0.3)
plt.title('Gráfico do Merge Sort')
plt.xlabel('x - Quantidade de elementos contido na lista')
plt.ylabel('y - Acessos à memória da lista')

plt.show();