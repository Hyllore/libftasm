section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp

_main:
	cmp rdi, 64
	jle _notalpha
	cmp rdi, 91
	jge _notalphacaps
	jmp _isalpha

_notalphacaps:
	cmp rdi, 96
	jle _notalpha
	cmp rdi, 123
	jge _notalpha
	jmp _isalpha

_notalpha:
	mov rax, 0
	pop rbp
	ret

_isalpha:
	mov rax, 1
	pop rbp
	ret
