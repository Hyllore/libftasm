section .text
	global _ft_isascii

_ft_isascii:
	push rbp

_main:
	cmp rdi, -1
	jle _notascii
	cmp rdi, 128
	jae _notascii
	jmp _isascii

_notascii:
	mov rax, 0
	pop rbp
	ret

_isascii:
	mov rax, 1
	pop rbp
	ret
