	.option nopic
	.attribute arch, "rv32i2p1"
	.text
	.section	.text.start,"ax",@progbits
	.align	4
	.globl	_start
	.type	_start, @function
_start:
    lui	gp,%hi(__global_pointer$)
	addi	gp,gp,%lo(__global_pointer$)

	lui	sp,%hi(__stack_top)
	addi	sp,sp,%lo(__stack_top)

	lui	a5,%hi(__BSS_START__)
	addi	a5,a5,%lo(__BSS_START__)
	lui	a4,%hi(__BSS_END__)
	addi	a4,a4,%lo(__BSS_END__)
    
.L2:
	bltu	a5,a4,.L3
	call	main
.L4:
	nop #remove maybe 
	j	.L4
.L3:
	addi	a5,a5,1
	sb	zero,-1(a5)
	j	.L2