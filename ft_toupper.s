section .text
	global _ft_toupper

_ft_toupper:
	push rbp

_main:
	cmp rdi, 96
	jle _nottoupper
	cmp rdi, 123
	jae _nottoupper
	jmp _toupper

_nottoupper:
	mov rax, rdi
	pop rbp
	ret

_toupper:
	add rdi, -32
	mov rax, rdi
	pop rbp
	ret
