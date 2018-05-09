section .text
	global _ft_tolower

_ft_tolower:
	push rbp

_main:
	cmp rdi, 64
	jle _nottolower
	cmp rdi, 91
	jae _nottolower
	jmp _tolower

_nottolower:
	mov rax, rdi
	pop rbp
	ret

_tolower:
	add rdi, 32
	mov rax, rdi
	pop rbp
	ret
