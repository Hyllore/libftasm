section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp

_main:
	cmp rdi, 47
	jle _notdigit
	cmp rdi, 58
	jae _notdigit
	jmp _isdigit

_notdigit:
	mov rax, 0
	pop rbp
	ret

_isdigit:
	mov rax, 1
	pop rbp
	ret
