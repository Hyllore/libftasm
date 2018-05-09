section .text
	global _ft_isprint

_ft_isprint:
	push rbp

_main:
	cmp rdi, 31
	jle _notprint
	cmp rdi, 127
	jae _notprint
	jmp _isprint

_notprint:
	mov rax, 0
	pop rbp
	ret

_isprint:
	mov rax, 1
	pop rbp
	ret
