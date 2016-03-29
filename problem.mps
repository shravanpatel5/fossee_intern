Minimize
 OBJ :    -20*XZERO - 40*XONE - 20*XTWO - 15*XTHREE - 30*XFOUR
 
Subject To
 ROW1:    5*XZERO + 4*XONE + 3*XTWOE + 7*XTHREE + 8*XFOUR       <= 25
 ROW2:    1*XZERO + 7*XONE + 9*XTWO + 4*XTHREE + 6*XFOUR         <= 25
 ROW3:    8*XZERO + 10*XONE + 2*XTWO + 1*XTHREE + 10*XFOUR       <= 25

Bounds
  0<= XZERO <= 1
  0<= XONE <= 1
  0<= XTWO <= 1
  0<= XTHREE <= 1
  0<= XFOUR <= 1
End
