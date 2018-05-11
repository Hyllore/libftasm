%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE 4
%define STDOUT 1

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp

_main:
	mov r12, rdi
	sub rsp, 16
	mov rdi, STDOUT
	lea rsi, [rel r12]
	mov rdx, 12
;	call _ft_strlen
;	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	mov rax, 60
	mov rdi, 0
	syscall
