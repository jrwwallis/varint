	.intel_syntax noprefix
	.globl	f
f:
	bsr eax, edi
	pushw 7
	pop cx
	cdq
	idiv	cl
	mov	cl, al
	movabs	rdx, 140185576636287
	pdep	rdi, rdi, rdx
	mov al, 1
	shl	al, cl
	dec	al
	not rdx
	pdep	rax, rax, rdx
	or	rax, rdi
	ret
