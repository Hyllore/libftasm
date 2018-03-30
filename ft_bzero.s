section .text
	global _ft_bzero

_ft_bzero:
	push rbp

_loop:
	cmp rsi, 0
	jle _end_loop_bzero
	mov [rdi + rsi - 1], byte 0
	dec rsi
	jmp _loop

_end_loop_bzero:
	pop rbp
	ret
