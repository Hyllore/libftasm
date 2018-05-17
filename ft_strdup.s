section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov r12, rdi
	call _ft_strlen
	mov rdi, rax
	mov r13, rax
	call _malloc
	mov rdx, r13
	mov rsi, r12
	mov rdi, rax
	call _ft_memcpy
	pop rbp
	ret
