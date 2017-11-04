# Computer Architecture Lab

## 4 bit adder simulation
![4 bit adder simulation](https://github.com/menon92/ulabwork/blob/master/Computer%20Architecture/4%20bit%20adder.png)

## 4 bit adder-subrtactor simulation
![4 bit adder-subrtactor](https://github.com/menon92/ulabwork/blob/master/Computer%20Architecture/adder%20subttractor.png)

## 4 bit ALU
![4 bit ALU](https://github.com/menon92/ulabwork/blob/master/Computer%20Architecture/4%20bit%20alu.png)

## 4 bit AlU Function Table:

|S<sub>0</sub>|S<sub>0</sub>|C<sub>in</sub>|Y|D = A + Y + C<sub>in</sub>|   Operation perform |
|-------------|-------------|--------------|-|--------------------------|----------------------
|0            |0            |0             |B| D = A + B                | Addition            |
|0            |0            |1             |B| D = A + B + 1            | Addition With carry |
|0            |1            |0             | |                          | Subtraction         |
|0            |1            |1             | |                          | Subtraction         |
|1            |0            |0             |0| D = A                    | Transformation      |
|1            |0            |1             |0| D = A + 1                | Increment           |
|1            |1            |0             |1| D = A - 1                | Decrement           |
|1            |1            |1             |1| D = A                    | Transformation      |
