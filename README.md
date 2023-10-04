# F2_rng_mersenne_twister

Code for *Bunny* :

Based on https://perso.isima.fr/~dahill/Simu-ZZ2/Lab%20%23%202%20-%20Gen%20Rand%20Variates.pdf

This project use the following Mersenne Twister generator by Makoto Matsumoto :


http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/emt19937ar.html

This time I used C++ over C.

Compilation : 

- Place yourself at the parent folder of `src`
- Don't forget to create a `bin` directory in the same folder as `src`

`g++ -O0 -g ./src/betterCPP/*.c* ./src/low_level/*.c* ./src/debug_verification/*.c* ./src/mersenne_twister/*.c* ./src/prog/*.c* -o ./bin/test.exe -Wall -Wextra -lstdc++ -Wcomment -Wno-unknown-pragmas`

Run :

`./bin/test.exe`

(The compilation command for Visual Code is also configured, just change the compiler/debugger path if needed)

Ouput :

```c
Compilation de 12:40:00 
valeur aléatoire entre [-89.2000000, 56.7000000] : -45.4503670

class | proba   |     nb     (%)
  0 : 0.5000000 :       449 (44.9000000 %)
  1 : 0.1500000 :       151 (15.1000000 %)
  2 : 0.3500000 :       400 (40.0000000 %)

class | proba   |     nb     (%)
  0 : 0.5000000 :    499905 (49.9905000 %)
  1 : 0.1500000 :    150288 (15.0288000 %)
  2 : 0.3500000 :    349807 (34.9807000 %)

mt_neg_exp(11) = 7.973027
average mt_neg_exp(11) for 1000 repetitions = 11.200378
average mt_neg_exp(11) for 1000000 repetitions = 10.991900

test_continuous_distributions with 1000 repetition : nb | %
 =  0 :      92 9.2000000 %
 =  1 :      84 8.4000000 %
 =  2 :      71 7.1000000 %
 =  3 :      69 6.9000000 %
 =  4 :      59 5.9000000 %
 =  5 :      71 7.1000000 %
 =  6 :      52 5.2000000 %
 =  7 :      53 5.3000000 %
 =  8 :      43 4.3000000 %
 =  9 :      48 4.8000000 %
 = 10 :      32 3.2000000 %
 = 11 :      31 3.1000000 %
 = 12 :      26 2.6000000 %
 = 13 :      27 2.7000000 %
 = 14 :      23 2.3000000 %
 = 15 :      18 1.8000000 %
 = 16 :      16 1.6000000 %
 = 17 :      21 2.1000000 %
 = 18 :      16 1.6000000 %
 = 19 :      14 1.4000000 %
 = 20 :      12 1.2000000 %
 = 21 :      14 1.4000000 %
 = 22 :      10 1.0000000 %
 = 23 :       7 0.7000000 %
 = 24 :      10 1.0000000 %
>= 25 :       6 0.6000000 %

test_continuous_distributions with 1000000 repetition : nb | % 
 =  0 :   95082 9.5082000 %
 =  1 :   86231 8.6231000 %
 =  2 :   78240 7.8240000 %
 =  3 :   70421 7.0421000 %
 =  4 :   63370 6.3370000 %
 =  5 :   57630 5.7630000 %
 =  6 :   52316 5.2316000 %
 =  7 :   47077 4.7077000 %
 =  8 :   42809 4.2809000 %
 =  9 :   38805 3.8805000 %
 = 10 :   35027 3.5027000 %
 = 11 :   31500 3.1500000 %
 = 12 :   28729 2.8729000 %
 = 13 :   25907 2.5907000 %
 = 14 :   23275 2.3275000 %
 = 15 :   21394 2.1394000 %
 = 16 :   18986 1.8986000 %
 = 17 :   17360 1.7360000 %
 = 18 :   15704 1.5704000 %
 = 19 :   14447 1.4447000 %
 = 20 :   12954 1.2954000 %
 = 21 :   11625 1.1625000 %
 = 22 :   10575 1.0575000 %
 = 23 :    9594 0.9594000 %
 = 24 :    8638 0.8638000 %
>= 25 :    7764 0.7764000 %

(20 lancés sommé) * (1000000 simulation)
somme =  20,     0, 0.0000000% :
somme =  21,     0, 0.0000000% :
somme =  22,     0, 0.0000000% :
somme =  23,     0, 0.0000000% :
somme =  24,     0, 0.0000000% :
somme =  25,     0, 0.0000000% :
somme =  26,     0, 0.0000000% :
somme =  27,     0, 0.0000000% : 
somme =  28,     0, 0.0000000% :
somme =  29,     0, 0.0000000% :
somme =  30,     0, 0.0000000% :
somme =  31,     0, 0.0000000% :
somme =  32,     0, 0.0000000% :
somme =  33,     0, 0.0000000% : 
somme =  34,     0, 0.0000000% :
somme =  35,     0, 0.0000000% :
somme =  36,     1, 0.0001000% :
somme =  37,     2, 0.0002000% :
somme =  38,     6, 0.0006000% : 
somme =  39,     8, 0.0008000% :
somme =  40,    11, 0.0011000% :
somme =  41,    21, 0.0021000% :
somme =  42,    51, 0.0051000% :
somme =  43,    78, 0.0078000% :
somme =  44,   134, 0.0134000% : 
somme =  45,   219, 0.0219000% :
somme =  46,   350, 0.0350000% :
somme =  47,   534, 0.0534000% :
somme =  48,   766, 0.0766000% :
somme =  49,  1130, 0.1130000% : #
somme =  50,  1624, 0.1624000% : ##
somme =  51,  2361, 0.2361000% : ##
somme =  52,  3166, 0.3166000% : ###
somme =  53,  4380, 0.4380000% : #####
somme =  54,  5945, 0.5945000% : #######
somme =  55,  7716, 0.7716000% : #########
somme =  56,  9815, 0.9815000% : ############
somme =  57, 12310, 1.2310000% : ###############
somme =  58, 15551, 1.5551000% : ###################
somme =  59, 18852, 1.8852000% : #######################
somme =  60, 22442, 2.2442000% : ###########################
somme =  61, 25865, 2.5865000% : ###############################
somme =  62, 30269, 3.0269000% : #####################################
somme =  63, 34369, 3.4369000% : ##########################################
somme =  64, 38506, 3.8506000% : ###############################################
somme =  65, 41968, 4.1968000% : ###################################################
somme =  66, 45682, 4.5682000% : ########################################################
somme =  67, 47892, 4.7892000% : ###########################################################
somme =  68, 50169, 5.0169000% : ##############################################################
somme =  69, 51739, 5.1739000% : ################################################################
somme =  70, 51470, 5.1470000% : ###############################################################
somme =  71, 51455, 5.1455000% : ###############################################################
somme =  72, 50617, 5.0617000% : ##############################################################
somme =  73, 47979, 4.7979000% : ###########################################################
somme =  74, 45431, 4.5431000% : ########################################################
somme =  75, 41817, 4.1817000% : ###################################################
somme =  76, 38221, 3.8221000% : ###############################################
somme =  77, 34665, 3.4665000% : ##########################################
somme =  78, 30332, 3.0332000% : #####################################
somme =  79, 26195, 2.6195000% : ################################
somme =  80, 22784, 2.2784000% : ############################
somme =  81, 18682, 1.8682000% : #######################
somme =  82, 15470, 1.5470000% : ###################
somme =  83, 12410, 1.2410000% : ###############
somme =  84,  9947, 0.9947000% : ############
somme =  85,  7761, 0.7761000% : #########
somme =  86,  5918, 0.5918000% : #######
somme =  87,  4505, 0.4505000% : #####
somme =  88,  3168, 0.3168000% : ###
somme =  89,  2349, 0.2349000% : ##
somme =  90,  1656, 0.1656000% : ##
somme =  91,  1125, 0.1125000% : #
somme =  92,   771, 0.0771000% :
somme =  93,   518, 0.0518000% : 
somme =  94,   311, 0.0311000% :
somme =  95,   215, 0.0215000% :
somme =  96,   130, 0.0130000% :
somme =  97,    64, 0.0064000% :
somme =  98,    49, 0.0049000% :
somme =  99,    30, 0.0030000% : 
somme = 100,    12, 0.0012000% :
somme = 101,     5, 0.0005000% :
somme = 102,     3, 0.0003000% :
somme = 103,     1, 0.0001000% :
somme = 104,     1, 0.0001000% :
somme = 105,     1, 0.0001000% : 
somme = 106,     0, 0.0000000% :
somme = 107,     0, 0.0000000% :
somme = 108,     0, 0.0000000% :
somme = 109,     0, 0.0000000% :
somme = 112,     0, 0.0000000% :
somme = 113,     0, 0.0000000% :
somme = 114,     0, 0.0000000% :
somme = 115,     0, 0.0000000% :
somme = 116,     0, 0.0000000% :
somme = 117,     0, 0.0000000% :
somme = 118,     0, 0.0000000% :
somme = 119,     0, 0.0000000% :
somme = 120,     0, 0.0000000% :

memory : 0 malloc actif
```
