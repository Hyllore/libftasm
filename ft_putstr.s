%define WRITE 0x2000004
%define STDOUT 1

section .text
	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	push rbp

_main:
	mov r12, rdi
	call _ft_strlen
	mov rdi, r12
	mov rdx, rax
	lea rsi, [rel rdi]
	mov rdi, STDOUT
	mov rax, WRITE
	syscall
	pop rbp
	ret

_end:
	xor rax, rax
	pop rbp
	ret
