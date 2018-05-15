section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rax, 0
	mov rcx, -1
	cld
	repnz scasb
	not rcx
	lea rax, [rcx - 1]
	pop rbp
	ret
