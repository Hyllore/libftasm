section .text
	global _ft_isalnum

_ft_isalnum:
	push rbp

_main:
	cmp rdi, 47
	jle _notalnum
	cmp rdi, 58
	jge _notalnumcaps1
	jmp _isalnum

_notalnumcaps1:
	cmp rdi, 64
	jle _notalnum
	cmp rdi, 91
	jge _notalnumcaps2
	jmp _isalnum

_notalnumcaps2:
	cmp rdi, 96
	jle _notalnum
	cmp rdi, 123
	jge _notalnum
	jmp _isalnum

_notalnum:
	mov rax, 0
	pop rbp
	ret

_isalnum:
	mov rax, 1
	pop rbp
	ret
