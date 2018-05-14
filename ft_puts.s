section .data
hello:
	.string db 10, 0

section .text
	global _ft_puts
	extern _ft_putstr

_ft_puts:
	push rbp

_main:
	call _ft_putstr
	mov rdi, hello.string
	call _ft_putstr
	mov rax, 10
	pop rbp
	ret
