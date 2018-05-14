%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE 4
%define STDOUT 1

section .text
	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	push rbp

_main:
	call _ft_strlen
	cmp rax, 0
	je _end
	lea rsi, [rel rdi]
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rbp
	ret

_end:
	xor rax, rax
	pop rbp
	ret
