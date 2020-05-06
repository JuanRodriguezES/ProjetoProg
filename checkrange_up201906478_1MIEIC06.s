.text
.global CheckRange
.type CheckRange, "function"


CheckRange:		mov x10 , #0
				mov x11 , #1
				smnegl x3, w0 , w11
LOOP:			cbz x1 , FIM
				ldrsw	x9 , [x2]
				cmp x9 , x3
				bge COMP
				str w3, [x2]
				add x10 , x10 ,#1
				b ADDREG
COMP:			cmp x9 , x0
				ble ADDREG
				str w0,[x2]
				add x10 , x10 , #1
ADDREG:			add x2,x2, #4
				sub x1 , x1 , #1
				b LOOP
FIM:			mov x0,x10
				ret









