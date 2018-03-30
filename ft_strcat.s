section .text
	global _ft_strcat

_ft_strcat:
	push rbp
	xor r8, r8
	xor r9, r9

_loop:
	cmp [rdi + r8], byte 0
	jle _loop2
	inc r8
	jmp _loop

_loop2:
	cmp [rsi + r9], byte 0
	jle _end
	mov r10, [rsi + r9]
	mov [rdi + r8], r10
	inc r8
	inc r9
	jmp _loop2

_end:
	mov [rdi + r8], byte 0
	mov rax, rdi
	pop rbp
	ret
