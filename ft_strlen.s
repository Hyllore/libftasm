section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	xor r8, r8

_main:
	repnz cmp [rdi + r8], byte 0
	je _end
	inc r8

_end:
	mov rax, r8
	pop rbp
	ret
