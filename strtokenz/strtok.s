	.file	"strtok.c"
	.text
	.section	.rodata
.LC0:
	.string	", "
.LC1:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$448, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$8660457458502105136, %rax
	movabsq	$3472407460796182576, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$2016419884, -16(%rbp)
	movw	$12336, -12(%rbp)
	movb	$0, -10(%rbp)
	leaq	-432(%rbp), %rdx
	movl	$0, %eax
	movl	$50, %ecx
	movq	%rdx, %rdi
	rep stosq
	movl	$0, -448(%rbp)
	leaq	-32(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -440(%rbp)
	jmp	.L2
.L4:
	movq	-440(%rbp), %rax
	movl	$16, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtol@PLT
	movq	%rax, %rdx
	movl	-448(%rbp), %eax
	leal	1(%rax), %ecx
	movl	%ecx, -448(%rbp)
	cltq
	movl	%edx, -432(%rbp,%rax,4)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -440(%rbp)
.L2:
	cmpq	$0, -440(%rbp)
	je	.L3
	cmpl	$99, -448(%rbp)
	jle	.L4
.L3:
	movl	$0, -444(%rbp)
	jmp	.L5
.L6:
	movl	-444(%rbp), %eax
	cltq
	movl	-432(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -444(%rbp)
.L5:
	movl	-444(%rbp), %eax
	cmpl	-448(%rbp), %eax
	jl	.L6
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
