section .text
	global _ft_puts

_ft_puts:
	push rbp

_main:
	mov r12, rdi
	mov rax, 1
	mov rdi, 1
	mov r12, rsi
	mov rdx, 12
	syscall
	mov rax, 60
	mov rdi, 0
	syscall
